package com.incomplete.cubegs.xtceprocessor;

import com.incomplete.cubegs.common.avro.messages.ProcessedField;
import com.incomplete.cubegs.common.avro.messages.GroupProcessedField;
import com.incomplete.cubegs.common.avro.messages.ListTC_Parameters;
import com.incomplete.cubegs.common.avro.messages.TC_Parameter;
import com.incomplete.cubegs.common.avro.messages.XTCE_ProcessedFrame;

import java.io.File;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.xtce.toolkit.XTCEContainerContentEntry;
import org.xtce.toolkit.XTCEContainerContentEntry.FieldType;

import org.xtce.toolkit.XTCEContainerContentModel;
import org.xtce.toolkit.XTCEContainerEntryValue;
import org.xtce.toolkit.XTCEDatabase;
import org.xtce.toolkit.XTCEDatabaseException;
import org.xtce.toolkit.XTCEFunctions;
import org.xtce.toolkit.XTCEItemValue;
import org.xtce.toolkit.XTCEParameter;
import org.xtce.toolkit.XTCETMContainer;
import org.xtce.toolkit.XTCETypedObject.RawType;
import org.xtce.toolkit.XTCEValidRange;

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

    private static volatile FrameDecoder instance = null;

    private static final Logger LOGGER = Logger.getLogger(FrameDecoder.class.getName());

    private XTCEDatabase  db = null;
    private Integer       lastFrameId;

    // Singleton
    public static FrameDecoder getInstance() {
        if (instance == null) {
            synchronized (FrameDecoder.class) {
                instance = new FrameDecoder();
            }
        }
        return instance;
    }
    

    // Close the database
    // Release the singleton
    public void shutdown() {
        closeDatabase();

        instance = null;
    }

    // Load the XTCE XML Database
    public void loadDatabase(String inDbFileName) {
        if (inDbFileName == null || inDbFileName.isEmpty() == true) {
            LOGGER.log(Level.SEVERE, "Database file name is emtpy or null");
            return;
        }

        try {
            if (db != null) {
                LOGGER.log(Level.SEVERE, "Database is already opened");
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
            LOGGER.info("Database is closed");
        }
    }

    public XTCE_ProcessedFrame decodeTmFrame(String inContainerName, byte[] inRawFrame) {
        XTCE_ProcessedFrame output = null;

        try {
            // Retrieve the container object from the database using the full
            // path, which is the quickest for this demo, but findContainers()
            // in the API is much more flexible.
            XTCETMContainer container = db.getContainer(inContainerName);
            
            // Decode/process the container in the stream using the container
            // returned from db.getContainer() above.
            XTCEContainerContentModel model = db.processContainer(container, inRawFrame);

            List<XTCEContainerContentEntry> entries = model.getContentList();

            // Create list
            ArrayList<ProcessedField>  listFields = new ArrayList<ProcessedField>();
            ArrayList<Integer>         listOolFields = new ArrayList<Integer>();
            
            int fieldCounter = 0;

            for (XTCEContainerContentEntry entry : entries) {
                // Skip entries that represent container transitions and
                // parameters shown as informative but do not exist in the
                // specific binary container processed content.  This can apply
                // to ARRAY and AGGREGATE parameters where the parent is in the
                // output but only the children have values to process.
                if ((entry.getEntryType() != FieldType.PARAMETER) || (entry.getValue() == null)) {
                    continue;
                }

                // Some databases choose to use aliases for parameters.  This
                // example shows displaying all of them with their namespace
                // name prepended.  A program might more like use two false
                // arguments with the preferred namespace name string.
                String alias = XTCEFunctions.makeAliasDisplayString(entry.getParameter(),
                                                                    true, // use all NS
                                                                    false, // show NS
                                                                    "");  // preferred

                LOGGER.log(Level.FINE, "Processing entry: {0}", entry.getName());
                
                // Convert to a Processed field
                ProcessedField newField = new ProcessedField();
                
                newField.setIndex(fieldCounter);
                // FIXME
                newField.setFieldTypeId(-1);
                newField.setFieldName(entry.getParameter().getName());        
                newField.setValue(entry.getValue().getCalibratedValue());
                newField.setRawValue(entry.getValue().getRawValueHex());
                
                listFields.add(newField);
                
                // Check OOL
                XTCEValidRange parameterRange = entry.getParameter().getValidRange();

                // Does it have a valid range? If not, skip the OOL check
                if (parameterRange.isValidRangeApplied() == true) {    
                    // If the field is in OOL, add to the list
                    Boolean  tmpOolFlag = false;
         
                    tmpOolFlag = checkOOL(entry);

                    if (tmpOolFlag == true) {
                        LOGGER.log(Level.FINE, "Parameter: {0} is OOL: ", entry.getParameter().getName());
                        listOolFields.add(fieldCounter);
                    }
                }
                
                // Next field
                fieldCounter ++;
            }

            // Create output XTCE frame
            output = new XTCE_ProcessedFrame();
            
            output.setId(this.lastFrameId);
            output.setContainerName(inContainerName);
            output.setCreationTime(System.currentTimeMillis());
            // Increase frame counter
            this.lastFrameId ++;
            
            // Create the unique group
            GroupProcessedField  oneGroup = new GroupProcessedField();
            
            oneGroup.setId(0);
            if (listOolFields.isEmpty() == true) {
                oneGroup.setOolFlag(false);
            } else {
                oneGroup.setOolFlag(true);
            }
            
            // Add list of fields
            oneGroup.setFields(listFields);
            oneGroup.setOolFields(listOolFields);
            
            ArrayList<GroupProcessedField>  listGroups = new ArrayList<GroupProcessedField>();

            // Add the unique group
            listGroups.add(oneGroup);
            output.setGroups(listGroups);
            
            LOGGER.fine("XTCE frame created");
        } catch (XTCEDatabaseException ex) {
            LOGGER.log(Level.SEVERE, "Exception: {0}", ex);
        }

        return output;
    }

    public byte[] encodeTcFrame(String inContainerName, ListTC_Parameters inTC) {
        byte[] output = new byte[0];
        
        return output;
    }
    
    
    protected FrameDecoder() {
        this.lastFrameId = 0;
    }    

    private Boolean checkOOL(XTCEContainerContentEntry inEntry) {
        boolean  output = false;
        
        XTCEItemValue  itemValue = new XTCEItemValue(inEntry.getParameter());
                
        BitSet      rawValue = inEntry.getValue().getRawValue();
        BigInteger  rawInteger = itemValue.bitSetToNumber(rawValue);
        BigDecimal  rawDouble = new BigDecimal(rawInteger);
        
        RawType     rawType = inEntry.getParameter().getRawType();
        
        // Check whether we can encode the number. If not, then it is out of limit
        if (rawType == RawType.unsigned || rawType == RawType.signMagnitude ||
            rawType == RawType.onesComplement || rawType == RawType.twosComplement) {
            output = itemValue.isIntegerRawValueReasonable(rawInteger);
        }
            
        if (rawType == RawType.IEEE754_1985) {
            output = itemValue.isFloatRawValueReasonable(rawDouble.doubleValue());
        }
                    
        return output;
    }
}
