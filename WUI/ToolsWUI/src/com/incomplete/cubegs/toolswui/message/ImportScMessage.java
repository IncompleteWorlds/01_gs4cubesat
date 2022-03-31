package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;

public class ImportScMessage extends BaseMessage {
    private String fileNamePath;
    
    private byte[] dataBuffer;
    

    public ImportScMessage(String inFileNamePath) throws Exception {
        this.fileNamePath = inFileNamePath;
        this.dataBuffer       = null; 
     
        createMessage();
    }
    
    private void createMessage() throws Exception {
//        try {
//            /* 
//            MsgImportScDatabase(java.lang.String authorizationToken, 
//                                java.lang.String fileName, 
//                                java.lang.Integer fileType, 
//                                java.lang.Integer fileSize, 
//                                java.lang.Integer numberOfChunks, 
//                                java.lang.Integer chunkNumber, 
//                                java.lang.String buffer) 
//                                
//            */
//            // File type: 0 - Excel, 1 - CSV, 2 - XTCE
//            // Encode message
//            String   tmpBuffer = null;
//            MsgImportScDatabase importMsg = new MsgImportScDatabase("TODO", this.fileNamePath, 1, 1, 23, 0, tmpBuffer);
//            byte[]              importData = null;
//
//            importData = encodeMessage(MsgImportScDatabase.class, importMsg);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_IMPORT_SC_DATABASE);
//            this.requestMessage.setDataBytes(importData);
//        } catch (Exception e) {
//            // TODO Auto-generated catch block
//            e.printStackTrace();
//            
//            String errorMessage = "Exception: Creating message: " + e.getMessage();
//            throw new Exception(errorMessage);
//        }
    }
}
