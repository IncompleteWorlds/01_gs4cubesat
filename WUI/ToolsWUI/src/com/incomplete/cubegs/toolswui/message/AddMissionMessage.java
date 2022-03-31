package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;


public class AddMissionMessage extends BaseMessage {

	public AddMissionMessage(String inName, String inDescription, String inCountry, String inOwner) throws Exception {		
//        createMessage(inName, inDescription, inCountry, inOwner);
    }
	
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
//    private void createMessage(String inName, String inDescription, String inCountry, String inOwner) throws Exception {
//        try {
//        	String creationTime = "YYYY-MM-DDTHH:mm:SS";
//        	
//        	// FIX ME
//        	Mission  tmpMission = new Mission(inName, inDescription, inCountry, inOwner, creationTime, 0, "email@email.com", "914421590", null);	 
//        		 
//            MsgAddMission msg = new MsgAddMission("TODO", tmpMission);
//   
//            // Encode message
//            byte[]   importData = null;
//
//            importData = encodeMessage(MsgAddMission.class, msg);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_ADD_MISSION);
//            this.requestMessage.setDataBytes(importData);
//        } catch (Exception e) {
//            e.printStackTrace();
//            
//            String errorMessage = "Exception: Creating message: " + e.getMessage();
//            throw new Exception(errorMessage);
//        }
//    }
}
