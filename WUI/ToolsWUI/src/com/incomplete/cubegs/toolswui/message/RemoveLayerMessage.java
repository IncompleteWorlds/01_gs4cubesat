package com.incomplete.cubegs.toolswui.message;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;



public class RemoveLayerMessage extends BaseMessage {

//    public RemoveLayerMessage(String inMissionName, String inLayerName) throws Exception {       
//        createMessage(inMissionName, inLayerName);
//    }
//    
//    private void createMessage(String inMissionName, String inLayerName) throws Exception {
//        try {
//            // Encode message
//            MsgRemoveMissionLayer  msgRequest = new MsgRemoveMissionLayer("TODO", inMissionName, inLayerName);
//            byte[]                 msgData = null;
//
//            msgData = encodeMessage(MsgRemoveMissionLayer.class, msgRequest);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_DELETE_MISSION_LAYER);
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