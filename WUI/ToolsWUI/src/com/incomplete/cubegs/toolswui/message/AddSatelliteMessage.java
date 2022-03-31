package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;



public class AddSatelliteMessage extends BaseMessage {
	
//	public AddSatelliteMessage(String inMissionName, Satellite inSatellite) throws Exception {
//        createMessage(inMissionName, inSatellite);
//	}
//	
//	public Satellite getResponse() throws Exception {
//		Satellite output = null;
//		
//        if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_ADD_SATELLITE_RESPONSE && 
//            this.responseMessage.getDataSize() != -1) {
//        
//            try {
//                output = decodeMessage(Satellite.class, this.responseMessage.getDataBytes());
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
//    private void createMessage(String inMissionName, Satellite inSatellite) throws Exception {
//        try {
//            MsgAddSatellite msg = new MsgAddSatellite("TODO", inMissionName, inSatellite);
//   
//            // Encode message
//            byte[]   importData = null;
//
//            importData = encodeMessage(MsgAddSatellite.class, msg);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_ADD_SATELLITE);
//            this.requestMessage.setDataBytes(importData);
//        } catch (Exception e) {
//            e.printStackTrace();
//            
//            String errorMessage = "Exception: Creating message: " + e.getMessage();
//            throw new Exception(errorMessage);
//        }
//    }
}

