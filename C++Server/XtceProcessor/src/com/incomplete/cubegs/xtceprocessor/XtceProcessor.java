/**
 * Copyright Incomplete Worlds (c) 2019
 *
 */
package com.incomplete.cubegs.xtceprocessor;

import com.incomplete.cubegs.common.avro.messages.MsgProcessRawFrame;
import com.incomplete.cubegs.common.avro.messages.XTCE_ProcessedFrame;
//import com.incomplete.cubegs.xtceprocessor.BaseMessage.decodeMessage;
import java.util.Properties;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;
import java.io.FileInputStream;
import java.io.IOException;

import org.zeromq.ZMQ;

/**
 *
 * @author alberto
 */
public class XtceProcessor {
    private static final Logger LOGGER = Logger.getLogger(XtceProcessor.class.getName());

    private Properties properties = null;

    public XtceProcessor() {
    }

    /**
     * @param args the command line arguments
     *
     * config_file_name = <filename_and_path>/config_filename.json"
     */
    public static void main(String[] args) {
        XtceProcessor xtce = new XtceProcessor();

        xtce.run(args);
    }

    private void run(String[] args) {
        try {
            // Write some log information
            int major = ZMQ.getMajorVersion();
            int minor = ZMQ.getMinorVersion();
            int patch = ZMQ.getPatchVersion();

            System.out.println("INFO: XTCE Processor started");
            
            String tmpMessage = "Current ZeroMQ version: " + Integer.toString(major) + "," + Integer.toString(minor) + "," + Integer.toString(patch) + ZMQ.getVersionString();
            System.out.println("INFO: tmpMessage");

            String configFileName = "resources/xtceprocessor.properties";

            if (args[0] != null && args[0].isEmpty() == false) {
                configFileName = args[0];
            }

            // Read the configuration file
            readConfiguration(configFileName);

            // Load mission database (XTCE XML file)
            loadMissionDatabase();

            // Open ZeroMQ connections
            ZeroMqManager.getInstance().connect(properties);
           
            // TODO
            // Send Startup message to the M&C
            LOGGER.log(Level.INFO, "XTCE Processor correctly initialised");

            while (!Thread.currentThread().isInterrupted()) {
                try {
                    ServerMessage currentMsg =  new ServerMessage();
                    
                    ZeroMqManager.getInstance().receive(currentMsg);

                    processMessage(currentMsg);

                    // FIX ME: Do I need this????
                    Thread.sleep(1000); // Do some 'work'

                } catch (InterruptedException ex) {
                    LOGGER.log(Level.SEVERE, null, ex);
                }
            }

        } catch (Exception e) {
            LOGGER.log(Level.SEVERE, "Exception: {0}", e);

            e.printStackTrace();
        } finally {
            disconnect();
        }
    }


    // Read module configuration file
    private void readConfiguration(String inFileName) {
        properties = new Properties();

//         InputStream is = this.getClass().getClassLoader().getResourceAsStream("../resources/zeromq.properties");
//         properties.load( is );
        try {
            properties.load(new FileInputStream(inFileName));
        } catch (IOException e) {
            System.out.println("EXCEPTION: while reading configuration properties");
            
            LOGGER.log(Level.SEVERE, "Exception: Reading configuration properties file: {0}", inFileName);
            e.printStackTrace();
        }
        
        String logFileName = properties.getProperty("general.log_file");
        
        if (logFileName != null && logFileName.isEmpty() == false) {
            
            try {
                LogManager.getLogManager().readConfiguration( new FileInputStream(logFileName) );
            } catch (Exception ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } 
        }

        LOGGER.log(Level.INFO, "Configuration correcct loaded. File: {0}", inFileName);
    }

    // Load mission database (XTCE XML file)
    private void loadMissionDatabase() throws Exception {
        String missionDatabase = properties.getProperty("general.mission_database");
        LOGGER.log(Level.FINE, "Mission database = {0}", missionDatabase);

        if (missionDatabase != null && missionDatabase.isEmpty() == false) {
            FrameDecoder.getInstance().loadDatabase(missionDatabase);

            LOGGER.log(Level.INFO, "Misson database correctly loaded: {0}", missionDatabase);
        } else {
            String errorMessage = "ERROR: Unable to load misson database: " + missionDatabase;
            LOGGER.log(Level.SEVERE, errorMessage);

            throw new Exception(errorMessage);
        }
    }

    /**
     * Shutdown the processor. Close all the sotckets
     */
    private void disconnect() {
        LOGGER.info("Shutting down XTCE Processor");
        
        // Close the Frame decoder
        FrameDecoder.getInstance().shutdown();
    }

    private void processMessage(ServerMessage inMessage) {
        // If null, just ignore it
        if (inMessage == null) {
            return;
        }

        LOGGER.log(Level.INFO, "Processing message: {0}", inMessage.toString());

        // FIX ME
        // if (inMessage.getOperationCode() == EnumOperationCode.CODE_LOGOUT) {
        // if (inMessage.getOperationCode() == EnumOperationCode.CODE_END_PROCESSING) {
        if (inMessage.toString().equalsIgnoreCase("shutdown") == true) {
            disconnect();
        } else {
            switch (inMessage.getOperationCode())
            {
                case CODE_SHUTDOWN:
                    disconnect();
                    break;
                case CODE_DECODE_RAW_FRAME:
                    decodeRawFrame(inMessage);
                    break;
                    
                case CODE_ENCODE_RAW_FRAME:
                    encodeRawFrame(inMessage);
                    break;
            }
        }
    }
    
    private void decodeRawFrame(ServerMessage inMessage) {
        try {
            // Decode error
            MsgProcessRawFrame avroMsg = BaseMessage.decodeMessage(MsgProcessRawFrame.class, inMessage.getDataBytes());
            
            // Process the raw frame
            XTCE_ProcessedFrame processed = FrameDecoder.getInstance().decodeTmFrame(avroMsg.getContainerName(), 
                                                                                     avroMsg.getRawFrame().array());
            
            // Create the output message
            byte[] dataBuffer = BaseMessage.encodeMessage(XTCE_ProcessedFrame.class, processed);
            
            ServerMessage outputMessage = new ServerMessage();
            
            // FIXME
            // Do I have to fill in these fields
            outputMessage.setMessageId("");
            outputMessage.setOperationCode(EnumOperationCode.CODE_ADD_NODE);
            
            outputMessage.setCorrelationId(inMessage.getMessageId());
            outputMessage.setDataBytes(dataBuffer);
            
            // Send output message
            ZeroMqManager.getInstance().send(outputMessage);
        } catch (Exception ex) {
            LOGGER.log(Level.SEVERE, "Exception: {0}", ex);
        }
    }
    
    private void encodeRawFrame(ServerMessage inMessage) {
        try {
            // Decode error
//            MsgEncodeRawFrame avroMsg = BaseMessage.decodeMessage(MsgEncodeRawFrame.class, inMessage.getDataBytes());
//            
//            // Process the raw frame
//            byte[] dataBuffer = FrameDecoder.getInstance().encodeTcFrame(avroMsg.getContainerName(), 
//                                                                         avroMsg.getFields());
//            
//            // Create the output message
//            ServerMessage outputMessage = new ServerMessage();
//
//            // FIXME
//            outputMessage.setMessageId("");
//            outputMessage.setOperationCode(EnumOperationCode.CODE_ADD_NODE);
//            
//            outputMessage.setCorrelationId(inMessage.getMessageId());
//            outputMessage.setDataBytes(dataBuffer);
//            
//            // Send output message
//            ZeroMqManager.getInstance().send(outputMessage);
        } catch (Exception ex) {
            LOGGER.log(Level.SEVERE, "Exception: {0}", ex);
        }
    }

}
