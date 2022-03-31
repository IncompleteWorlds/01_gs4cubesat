package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;



public class AddMissionLayerMessage extends BaseMessage {

//	public AddMissionLayerMessage(String inMissionName, Layer inLayer) throws Exception {
//		//createMessage(inMissionName, inLayer);
//	}

//	public Mission getResponse() throws Exception {
//		Mission output = null;
//		
//        if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_ADD_MISSION_RESPONSE && 
//            this.responseMessage.getDataSize() != -1) {
//        
//            try {
//                output = decodeMessage(Mission.class, this.responseMessage.getDataBytes());
//            } catch (Exception e) {
//                // TODO Auto-generated catch block
//                e.printStackTrace();
//
//                throw e;
//            }
//
//        } else {
//            String errorMessage = "ERROR: Invalid response received";
//            throw new Exception(errorMessage);
//        }
//        
//        return output;
//    }
//    
//    private void createMessage(String inMissionName, Layer inLayer) throws Exception {
//        try {
//        	MsgAddMissionLayer  msg = new MsgAddMissionLayer("TODO", inMissionName, inLayer);
//        	
//            // Encode message
//            byte[]   importData = null;
//
//            importData = encodeMessage(MsgAddMissionLayer.class, msg);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_ADD_MISSION_LAYER);
//            this.requestMessage.setDataBytes(importData);
//        } catch (Exception e) {
//            e.printStackTrace();
//            
//            String errorMessage = "Exception: Creating message: " + e.getMessage();
//            throw new Exception(errorMessage);
//        }
//    }
}
