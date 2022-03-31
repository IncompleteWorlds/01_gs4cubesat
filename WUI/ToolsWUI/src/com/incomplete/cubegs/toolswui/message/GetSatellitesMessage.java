package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;




public class GetSatellitesMessage extends BaseMessage {
//	private ListSatellites msgResponse;
//
//    public GetSatellitesMessage(String inMissionName) throws Exception {       
//        this.msgResponse = null;
//
//        createMessage(inMissionName);
//    }
//    
//    public ListSatellites getResponse() throws Exception {
//        if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_GET_SATELLITE_RESPONSE && 
//            this.responseMessage.getDataSize() != -1) {
//            try {
//                this.msgResponse = decodeMessage(ListSatellites.class, this.responseMessage.getDataBytes());
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
//        return this.msgResponse;
//    }
//    
//    private void createMessage(String inName) throws Exception {
//        try {
//            // Encode message
//            MsgGetSatellite  msgRequest = new MsgGetSatellite("TODO", inName, "", "");
//            byte[]           msgData = null;
//
//            msgData = encodeMessage(MsgGetSatellite.class, msgRequest);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_GET_SATELLITE);
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
