package com.incomplete.cubegs.xtceprocessor;

import java.io.FileInputStream;
import java.util.Properties;
import java.util.logging.Logger;

import org.zeromq.ZMQ;

public class ZeroMqManager {
	private static final Logger     logger = Logger.getLogger(ZeroMqManager.class.getName());;
       
    private ZMQ.Context context = null;
    private ZMQ.Socket  server = null;
    private ZMQ.Socket  subscriber = null;

    public ZeroMqManager() {   
    }
    
    TODO CONVERT INTO A SINGLETON

    public void connect() throws Exception {
        System.out.println("INFO: Creating sockets");
        
        Properties properties = new Properties();
        
//        InputStream is = this.getClass().getClassLoader().getResourceAsStream("../resources/zeromq.properties");
//        properties.load( is );
        
        properties.load( new FileInputStream("resources/zeromq.properties") );
        
        
        System.out.println("INFO: Properties loaded");
    
        context = ZMQ.context(1);
        
        // Connect with the server
        // Asynchronous calls. User .REQ for synchronous calls
        String tmpURL = properties.getProperty("server.address");
        System.out.println("DEBUG: server.address = " + tmpURL);
        
        if (tmpURL != null && tmpURL.isEmpty() == false) {
            server = context.socket(ZMQ.REQ);
            server.connect(tmpURL.trim());
        } else {
            String errorMessage = "ERROR: Unable to create server socket to address: " + tmpURL;
            System.out.println(errorMessage);
            
            throw new Exception(errorMessage);
        }
        
        
        // Connect with subscriber
        tmpURL = properties.getProperty("subscriber.address");
        System.out.println("DEBUG: subscriber.address = " + tmpURL);
        
        if (tmpURL != null && tmpURL.isEmpty() == false) {            
            subscriber = context.socket(ZMQ.SUB);
            subscriber.connect(tmpURL.trim());
            
            String filter = "";
            subscriber.subscribe(filter.getBytes());
        } else {
            String errorMessage = "ERROR: Unable to create subscriber socket to address: " + tmpURL;
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

                    System.out.println(errorMessage);

                    throw new Exception(errorMessage);
                }
                
                // Send message
                returnCode = server.send(inMessage.getDataBytes(), 0);
                
                if (returnCode == false) {
                    String errorMessage = "ERROR: Unable to send multi-part message";

                    System.out.println(errorMessage);

                    throw new Exception(errorMessage);
                }
            } else {
                String errorMessage = "ERROR: Unable to send message. Null input parameter";

                System.out.println(errorMessage);

                throw new Exception(errorMessage);
            }
        } else {
            String errorMessage = "ERROR: Not connected with server. Unable to send messages";

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

                System.out.println(errorMessage);

                throw new Exception(errorMessage);
            }
        } else {
            String errorMessage = "ERROR: Not connected with server. Unable to receive messages";

            System.out.println(errorMessage);

            throw new Exception(errorMessage);
        }
    }
    
   
}