package com.incomplete.cubegs.mcswui.messages;

import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;


public class ConnectGsnMessage extends BaseMessage {
    private Integer stationId;
    private String connectionId;
    
    static private String CONNECTION_ID_TAG = "connectionId";
    
    // Connect to a GSn
    public ConnectGsnMessage(Integer inGsId) throws Exception {
        stationId = inGsId;
        connectionId = "";
        
        createMessage();
    }

    public String getResponse() throws Exception {
//        if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_CONNECT_GROUND_STATION_RESPONSE &&    
//            this.responseMessage.getDataSize() != -1) {
//        
//            try {
//               KeyValue tmpPair = decodeMessage(KeyValue.class, this.responseMessage.getDataBytes());
//               
//               if (CONNECTION_ID_TAG.equals(tmpPair.getKey()) == true) {
//                   this.connectionId = tmpPair.getValue();
//               } else {
//                   String errorMessage = "ERROR: Invalid response received";  
//                   throw new Exception(errorMessage);
//               }
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
        
        return this.connectionId;
    }
    
    private void createMessage() throws Exception {
//        // Create first level message
//        MsgConnectGroundStation  tmpMsg = new MsgConnectGroundStation();
//        
//        tmpMsg.setGroundStationId(this.stationId);
//        tmpMsg.setAuthorizationToken("");
//                
//        try {
//            // Create level 2 message
//            byte[]   tmpMsgData = null;
//
//            tmpMsgData = encodeMessage(MsgConnectGroundStation.class, tmpMsg);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_CONNECT_GROUND_STATION);
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
