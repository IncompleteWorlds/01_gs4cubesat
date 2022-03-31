package com.incomplete.cubegs.mcswui.messages;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;



public class DisconnectGsnMessage extends BaseMessage {
    private String connectionId;
    
    // Connect to a GSn
    public DisconnectGsnMessage(String inGsId) throws Exception {
        connectionId = inGsId;
        
        createMessage();
    }

    private void createMessage() throws Exception {
//        // Create first level message
//        MsgDisconnectGroundStation  tmpMsg = new MsgDisconnectGroundStation();
//        
//        tmpMsg.setConnectionId(this.connectionId);
//        tmpMsg.setAuthorizationToken("");
//                
//        try {
//            // Create level 2 message
//            byte[]   tmpMsgData = null;
//
//            tmpMsgData = encodeMessage(MsgDisconnectGroundStation.class, tmpMsg);
//            
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_DISCONNECT_GROUND_STATION);
//            this.requestMessage.setDataBytes(tmpMsgData);
//        } catch (Exception e) {
//            // TODO Auto-generated catch block
//            e.printStackTrace();
//            
//            String errorMessage = "Exception: Creating message: " + e.getMessage();
//            throw new Exception(errorMessage);
//        }
    }
}
