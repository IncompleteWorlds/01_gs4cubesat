/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.incomplete.cubegs.xtceprocessor;

import java.util.Properties;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import org.zeromq.ZMQ;
import org.zeromq.ZContext;
import org.zeromq.ZMQ.Socket;


/**
 *
 * @author alberto
 */
public class XtceProcessor {
    private static final Logger     logger = Logger.getLogger(XtceProcessor.class.getName());

    private ZContext   context = null;
    private Socket     server = null;
    private Socket     subscriber = null;

	private Properties properties = null;
     
    public XtceProcessor() {
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        XtceProcessor  xtce = new XtceProcessor();
        
        xtce.run(args);
    }
    
   
    private void run(String[] args) {
        try {
			// Write some log information
            int major, minor, patch;

            zmq::version(&major, &minor, &patch);
            
            logger.log(LEVEL.INFO, "info correctly loaded");
            
            String tmpMessage = "Current ZeroMQ version: " + to_string(major) + "," + to_string(minor) + "," + to_string(patch);
            logger.log(LEVEL.INFO, tmpMessage);

            // Open ZeroMQ connections
			connect();
		
			while (!Thread.currentThread().isInterrupted()) {
				try {
					byte[] reply = server.recv(0);

					System.out.println("Received " + ": [" + "]");

					String response = "world";
					server.send(response.getBytes(), 0);

					Thread.sleep(1000); // Do some 'work'

//                message = subscriber.recvStr(0).trim();
//            String[] result = message.split(" ");
//            System.out.println("exchange: " + result[0] + ", update: " + result[1]);
				} catch (InterruptedException ex) {
					logger.log(Level.SEVERE, null, ex);
				}
			}

        } catch (Exception e) {
			e.printStackTrace();
		} finally {			
			disconnect();
		}
    }
    
     private void connect() throws Exception {
        // Read the configuration file
        readConfiguration();
        
        // Connect with the server
        String tmpURL = properties.getProperty("server.address");
        logger.info("DEBUG: server.address = " + tmpURL);
        
        if (tmpURL != null && tmpURL.isEmpty() == false) {
            server = context.createSocket(ZMQ.REP);
            server.bind(tmpURL.trim());
        } else {
            String errorMessage = "ERROR: Unable to create server socket to address: " + tmpURL;
            logger.severe(errorMessage);
            
            throw new Exception(errorMessage);
        }
        
        
        // Connect with subscriber
        tmpURL = properties.getProperty("subscriber.address");
        logger.info("DEBUG: subscriber.address = " + tmpURL);
        
        if (tmpURL != null && tmpURL.isEmpty() == false) {            
            subscriber = context.createSocket(ZMQ.SUB);
            subscriber.connect(tmpURL.trim());
            
            String filter = "";
            subscriber.subscribe(filter.getBytes());
        } else {
            String errorMessage = "ERROR: Unable to create subscriber socket to address: " + tmpURL;
            logger.severe(errorMessage);
            
            throw new Exception(errorMessage);
        }
    }

     private void readConfiguration() {
    	 properties = new Properties();
         
//         InputStream is = this.getClass().getClassLoader().getResourceAsStream("../resources/zeromq.properties");
//         properties.load( is );
         try {
			properties.load( new FileInputStream("resources/zeromq.properties") );
		} catch (IOException e) {
			logger.severe("Exception: Reading ZeroMQ properties file");
			e.printStackTrace();
		}
         
         logger.info("Properties loaded");
     }
    
    private void processMessage(String inMessage) {
        logger.info("Processing message: " + inMessage);
        
        if (inMessage.equalsIgnoreCase("shutdown") == true ) {
        	disconnect();
        }
    }
    
    /**
     * Shutdown the processor. Close all the sotckets
     */
    private void disconnect() {
        logger.info("Shutting down XTCE Processor");
        
        if (server != null) {
            server.close();
        }
        
        if (subscriber != null) {
            subscriber.close();
        }
        
        if (context != null) {
            context.close();
            context.destroy();            
        }
    }
}
