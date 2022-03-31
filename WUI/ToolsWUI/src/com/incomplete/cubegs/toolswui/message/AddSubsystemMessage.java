package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;


public class AddSubsystemMessage extends BaseMessage {
	
//	public AddSubsystemMessage(String inSatelliteName, Subsystem inSubsystem) throws Exception {
//        createMessage(inSatelliteName, inSubsystem);
//	}
//	
//	public Subsystem getResponse() throws Exception {
//		Subsystem output = null;
//		
//        if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_ADD_SUBSYSTEM_RESPONSE && 
//            this.responseMessage.getDataSize() != -1) {
//        
//            try {
//                output = decodeMessage(Subsystem.class, this.responseMessage.getDataBytes());
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
//    private void createMessage(String inSatelliteName, Subsystem inSubsystem) throws Exception {
//        try {
//            MsgAddSubsystem msg = new MsgAddSubsystem("TODO", inSatelliteName, inSubsystem);
//   
//            // Encode message
//            byte[]   importData = null;
//
//            importData = encodeMessage(MsgAddSubsystem.class, msg);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_ADD_SUBSYSTEM);
//            this.requestMessage.setDataBytes(importData);
//        } catch (Exception e) {
//            e.printStackTrace();
//            
//            String errorMessage = "Exception: Creating message: " + e.getMessage();
//            throw new Exception(errorMessage);
//        }
//    }
}
