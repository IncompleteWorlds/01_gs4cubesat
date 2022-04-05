package com.incomplete.cubegs.xtceprocessor;

import java.io.File;
import java.io.FileInputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.xtce.toolkit.XTCEContainerContentModel;
import org.xtce.toolkit.XTCEDatabase;
import org.xtce.toolkit.XTCEDatabaseException;
import org.xtce.toolkit.XTCETMContainer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author AJFG
 */
public class FrameDecoder {
    private static final Logger logger = Logger.getLogger(FrameDecoder.class.getName());
            
    private static FrameDecoder instance = null;
    
    private XTCEDatabase db = null;

    static FrameDecoder getInstance() {
        if (instance == null) {
            instance = new FrameDecoder();
        }
        return instance;
    }
	
    protected FrameDecoder() {

    }

    public void loadDatabase(String inDbFileName) {
        if (inDbFileName == null || inDbFileName.isEmpty() == true) {
            logger.log(Level.SEVERE, "Database file name is emtpy or null");
            return;
        }
		
        try {
            
            if (db != null) {
                logger.log(Level.SEVERE, "Database is already opened");
                return;
            }

            // Load the database file provided in read-only with XInclude.
            db = new XTCEDatabase(new File(inDbFileName),
  								true, // XSD validate flag
									true, // XInclude flag
									true); // ReadOnly flag
        } catch (Exception ex) {
            System.err.println(ex.getClass().getName());
            System.err.println("Exception: " + ex.getLocalizedMessage());
            System.exit(-1);
        }
    }
    
    public void closeDatabase() {
        if (db != null) {
            db = null; 
            logger.info("Database is closed");
        }
    }

    public ProcessedFrame decodeFrame(String inContainerName, RawFrame inFrame) {
        try {
            // Retrieve the container object from the database using the full
            // path, which is the quickest for this demo, but findContainers()
            // in the API is much more flexible.
            XTCETMContainer container = db.getContainer(inContainerName);

            // Get a stream object for the provided binary file contents.
            byte[]  dataBuffer = inFrame.getData();

            // Decode/process the container in the stream using the container
            // returned from db.getContainer() above.
            XTCEContainerContentModel model = db.processContainer(container, dataBuffer);
			
			List<XTCEContainerContentEntry> entries = model.getContentList();

            long items = 0;

            for ( XTCEContainerContentEntry entry : entries ) {

				
				
                switch (entry.getName()) {
				}
			}
        
        } catch (XTCEDatabaseException ex) {
            Logger.getLogger(FrameDecoder.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
}
