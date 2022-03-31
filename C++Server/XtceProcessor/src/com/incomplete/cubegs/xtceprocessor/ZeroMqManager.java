package com.incomplete.cubegs.xtceprocessor;

import java.util.Properties;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.zeromq.ZMQ;

public class ZeroMqManager {
    private static volatile ZeroMqManager instance = null;
 
    private static final Logger     LOGGER = Logger.getLogger(ZeroMqManager.class.getName());;
       
    private ZMQ.Context context = null;
    private ZMQ.Socket  server = null;
    private ZMQ.Socket  subscriber = null;

        
    public static ZeroMqManager getInstance() {
        if (instance == null) {
            synchronized (ZeroMqManager.class) {
                instance = new ZeroMqManager();
            }
        }
        return instance;
    }

    public void connect(Properties properties) throws Exception {
        LOGGER.info("Creating sockets");
        
        //Properties properties = new Properties();
        
//        InputStream is = this.getClass().getClassLoader().getResourceAsStream("../resources/zeromq.properties");
//        properties.load( is );
        
        //properties.load( new FileInputStream("resources/zeromq.properties") );
        
        //LOGGER.info("Properties loaded");
        //System.out.println("INFO: Properties loaded");
    
        context = ZMQ.context(1);
        
        // Connect with the server
        // Asynchronous calls. User .REQ for synchronous calls
        String tmpURL = properties.getProperty("ZMQ.server.address");
        LOGGER.log(Level.FINE, "ZMQ.server.address = {0}", tmpURL);
        
        if (tmpURL != null && tmpURL.isEmpty() == false) {
            server = context.socket(ZMQ.REQ);
            server.connect(tmpURL.trim());
        } else {
            String errorMessage = "ERROR: Unable to create server socket to address: " + tmpURL;
            LOGGER.severe(errorMessage);
            System.out.println(errorMessage);
            
            throw new Exception(errorMessage);
        }
        
        
        // Connect with subscriber
        tmpURL = properties.getProperty("ZMQ.subscriber.address");
        LOGGER.log(Level.FINE, "ZMQ.subscriber.address = {0}", tmpURL);
        
        if (tmpURL != null && tmpURL.isEmpty() == false) {            
            subscriber = context.socket(ZMQ.SUB);
            subscriber.connect(tmpURL.trim());
            
            String filter = "";
            subscriber.subscribe(filter.getBytes());
        } else {
            String errorMessage = "ERROR: Unable to create subscriber socket to address: " + tmpURL;
            LOGGER.severe(errorMessage);
            System.out.println(errorMessage);
            
            throw new Exception(errorMessage);
        }   
    }
    
    public void disconnect() {
        if (server != null) {
            server.close();
        }
        
        if (subscriber != null) {
            subscriber.close();
        }
        
        if (context != null) {
            context.close();
            context.term();            
        }
    }
    

    // If an error is generated, pass the server socket to the message directly
    // So, the message will use it directly
    public void send(ServerMessage inMessage) throws Exception {
        if (server != null) {
            if (inMessage != null) {
                boolean returnCode;
                
                // Send message code
                String msgCode = inMessage.getOperationCodeAsString();
                returnCode = server.sendMore(msgCode);
                
                if (returnCode == false) {
                    String errorMessage = "ERROR: Unable to send multi-part message";

                    LOGGER.severe(errorMessage);
                    System.out.println(errorMessage);

                    throw new Exception(errorMessage);
                }
                
                // Send message
                returnCode = server.send(inMessage.getDataBytes(), 0);
                
                if (returnCode == false) {
                    String errorMessage = "ERROR: Unable to send multi-part message";

                    LOGGER.severe(errorMessage);
                    System.out.println(errorMessage);

                    throw new Exception(errorMessage);
                }
            } else {
                String errorMessage = "ERROR: Unable to send message. Null input parameter";

                LOGGER.severe(errorMessage);
                System.out.println(errorMessage);

                throw new Exception(errorMessage);
            }
        } else {
            String errorMessage = "ERROR: Not connected with server. Unable to send messages";

            LOGGER.severe(errorMessage);
            System.out.println(errorMessage);

            throw new Exception(errorMessage);
        }
    }

    
    public void receive(ServerMessage outMessage) throws Exception {
        byte[] tmpMessage = null;

        if (server != null) {
            if (outMessage != null) {
                // Receive message code
                tmpMessage = server.recv();
                String msgCode = new String(tmpMessage);

                outMessage.setOperationCodeAsString(msgCode);

                // Receive message
                tmpMessage = server.recv(0);
                outMessage.setDataBytes(tmpMessage);

            } else {
                String errorMessage = "ERROR: Unable to receive message. Null input parameter";

                LOGGER.severe(errorMessage);
                System.out.println(errorMessage);

                throw new Exception(errorMessage);
            }
        } else {
            String errorMessage = "ERROR: Not connected with server. Unable to receive messages";

            LOGGER.severe(errorMessage);
            System.out.println(errorMessage);

            throw new Exception(errorMessage);
        }
    }
    
    protected ZeroMqManager() {   
    }

}