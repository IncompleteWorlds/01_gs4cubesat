package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;



public class GetMissionLayersMessage extends BaseMessage {
//	private ListLayers msgResponse;
//
//    public GetMissionLayersMessage(String inMissionName) throws Exception {       
//        this.msgResponse = null;
//
//        createMessage(inMissionName);
//    }
//    
//    public ListLayers getResponse() throws Exception {
//        if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_GET_MISSION_LAYERS_RESPONSE && 
//            this.responseMessage.getDataSize() != -1) {
//            try {
//                this.msgResponse = decodeMessage(ListLayers.class, this.responseMessage.getDataBytes());
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
//            MsgGetMissionLayers  msgRequest = new MsgGetMissionLayers("TODO", inName);
//            byte[]           msgData = null;
//
//            msgData = encodeMessage(MsgGetMissionLayers.class, msgRequest);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_GET_MISSION_LAYERS);
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
