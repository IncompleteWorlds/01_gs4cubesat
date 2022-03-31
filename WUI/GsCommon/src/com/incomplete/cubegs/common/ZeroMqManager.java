package com.incomplete.cubegs.common;

import java.io.InputStream;
import java.util.Properties;

import org.eclipse.rap.rwt.SingletonUtil;
import org.zeromq.ZMQ;




public class ZeroMqManager {
    // Only to be executed within the UISession thread
    static public ZeroMqManager getInstance() {
        return SingletonUtil.getSessionInstance( ZeroMqManager.class );
    }
        
    private ZMQ.Context context = null;
    private ZMQ.Socket  server = null;
    private ZMQ.Socket  subscriber = null;


    public void connect() throws Exception {
        System.out.println("INFO: Creating sockets");
        
        Properties properties = new Properties();
        
        // This is required for Tomcat
        InputStream is = this.getClass().getClassLoader().getResourceAsStream("../resources/zeromq.properties");
        properties.load( is );
        
        // This is required for Jetty
        //properties.load( new FileInputStream("resources/zeromq.properties") );
        
        
        System.out.println("INFO: Properties loaded");
    
        context = ZMQ.context(1);
        
        // Connect with the server
        // Asynchronous calls. User .REQ for synchronous calls
        String tmpURL = properties.getProperty("server.address");
        System.out.println("DEBUG: server.address = " + tmpURL);
        
        int timeout = Constants.NNG_DEFAULT_TIMEOUT_MILLISECONDS;

        try {
            timeout = Integer.parseInt(properties.getProperty("subscriber.timeout"));
        } catch (Exception e) {
            // Do nothing
        }
        
        if (tmpURL != null && tmpURL.isEmpty() == false) {
            server = context.socket(ZMQ.PUSH);
            if (server == null) {
                String errorMessage = "ERROR: Unable to create server socket to address: " + tmpURL;
                System.out.println(errorMessage);
                
                throw new Exception(errorMessage);
            }

            server.setReceiveTimeOut(timeout);
            server.setSendTimeOut(timeout);
            
            server.bind(tmpURL.trim());
            
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
            if (subscriber == null) {
                String errorMessage = "ERROR: Unable to create server socket to address: " + tmpURL;
                System.out.println(errorMessage);
                
                throw new Exception(errorMessage);
            }
            
            subscriber.setReceiveTimeOut(timeout);
            subscriber.setSendTimeOut(timeout);
            
            // client
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
    
    public void send(String inMessage) throws Exception {
        if (server != null) {
            if (inMessage != null) {
                boolean returnCode;
                
                returnCode = server.send(inMessage);
                if (returnCode == false) {
                    String errorMessage = "ERROR: Unable to send message (String)";
    
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
    

    // If an error is generated, pass the server socket to the message directly
    // So, the message will use it directly
    public void send(ServerMessage inMessage) throws Exception {
        if (server != null) {
            if (inMessage != null) {
                boolean returnCode;
                
//                // Send message code plus authorizationToken
//                String msgCode = inMessage.getCodeAndAuthToken();
//
//                returnCode = server.sendMore(msgCode);
//                
//                if (returnCode == false) {
//                    String errorMessage = "ERROR: Unable to send multi-part message";
//
//                    System.out.println(errorMessage);
//
//                    throw new Exception(errorMessage);
//                }
//                
//                // Send message
//                returnCode = server.send(inMessage.getDataBytes(), 0);
//                
//                if (returnCode == false) {
//                    String errorMessage = "ERROR: Unable to send multi-part message";
//
//                    System.out.println(errorMessage);
//
//                    throw new Exception(errorMessage);
//                }
                
                returnCode = server.send(inMessage.getMessage());
                if (returnCode == false) {
                    String errorMessage = "ERROR: Unable to send message";
    
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

    public String receive() throws Exception {
        byte[]  tmpMessage = null;
        String  outMessage = null;

        if (server != null) {
//                // Receive message code plus authorization token
//                tmpMessage = server.recv();
//                String msgCode = new String(tmpMessage);
//
//                outMessage.extractCodeAndAuthToken(msgCode);
//
//                // Receive message
//                tmpMessage = server.recv(0);
//                outMessage.setDataBytes(tmpMessage);

            tmpMessage = subscriber.recv();
            if (tmpMessage != null) {                
                outMessage = new String(tmpMessage);
            }

            return outMessage;
        } else {
            String errorMessage = "ERROR: Not connected with server. Unable to receive messages";

            System.out.println(errorMessage);

            throw new Exception(errorMessage);
        }
    }
    
    public void receive(ServerMessage outMessage) throws Exception {
        byte[] tmpMessage = null;

        if (server != null) {
            if (outMessage != null) {
//                // Receive message code plus authorization token
//                tmpMessage = server.recv();
//                String msgCode = new String(tmpMessage);
//
//                outMessage.extractCodeAndAuthToken(msgCode);
//
//                // Receive message
//                tmpMessage = server.recv(0);
//                outMessage.setDataBytes(tmpMessage);

                tmpMessage = subscriber.recv();
                if (tmpMessage != null) {                    
                    outMessage.setDataBytes(tmpMessage);
                }
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
    
    protected ZeroMqManager() {   
    }
}
