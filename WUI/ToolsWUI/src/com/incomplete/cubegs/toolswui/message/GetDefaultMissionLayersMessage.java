package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;


public class GetDefaultMissionLayersMessage extends BaseMessage {
//	private ListLayers msgResponse;
//
//    public GetDefaultMissionLayersMessage() throws Exception {       
//        this.msgResponse = null;
//
//        createMessage();
//    }
//    
//    public ListLayers getResponse() throws Exception {
//        if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_GET_DEFAULT_MISSION_LAYERS_RESPONSE && 
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
//    private void createMessage() throws Exception {
//        try {
//            // Encode message
//            MsgGetDefaultMissionLayers  msgRequest = new MsgGetDefaultMissionLayers("TODO");
//            byte[]           msgData = null;
//
//            msgData = encodeMessage(MsgGetDefaultMissionLayers.class, msgRequest);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_GET_DEFAULT_MISSION_LAYERS);
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
