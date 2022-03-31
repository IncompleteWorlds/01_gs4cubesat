package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;


public class RemoveSubsystemMessage extends BaseMessage {

//	public RemoveSubsystemMessage(String inSatelliteName, String inSubsystemName) throws Exception {
//		createMessage(inSatelliteName, inSubsystemName);
//	}
//
//	private void createMessage(String inSatelliteName, String inSubsystemName) throws Exception {
//        try {
//            // Encode message
//            MsgRemoveSubsystem  msgRequest = new MsgRemoveSubsystem("TODO", inSatelliteName, inSubsystemName);
//            byte[]              msgData = null;
//
//            msgData = encodeMessage(MsgRemoveSubsystem.class, msgRequest);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_DELETE_SUBSYSTEM);
//            this.requestMessage.setDataBytes(msgData);
//        } catch (Exception e) {
//            // TODO Auto-generated catch block
//            e.printStackTrace();
//            
//            String errorMessage = "Exception: Creating message: " + e.getMessage();
//            throw new Exception(errorMessage);
//        }
//    }
}
