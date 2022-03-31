package com.incomplete.cubegs.mcswui.messages;


import com.incomplete.cubegs.common.BaseMessage;
import com.incomplete.cubegs.common.EnumOperationCode;


public class GetGsnMessage extends BaseMessage {
    private String stationId;
    private String stationCode;
    
    //private ListGroundStations  listGS;
    
    // Read all GSn
    public GetGsnMessage() throws Exception {
        stationId = "";
        stationCode = "";
       // listGS = null;
        
        createMessage();
    }
    
    public GetGsnMessage(String inGroundStationId, String inGroundStationCode) throws Exception {
        stationId = inGroundStationId;
        stationCode = inGroundStationCode;
        
        createMessage();
    }
    
//    public ListGroundStations getResponse() throws Exception {
//        if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_GET_GROUND_STATION_RESPONSE &&    
//            this.responseMessage.getDataSize() != -1) {
//            
//            try {
//                this.listGS = decodeMessage(ListGroundStations.class, this.responseMessage.getDataBytes());
//            } catch (Exception e) {
//                // TODO Auto-generated catch block
//                e.printStackTrace();
//
//                throw e;
//            }
//        } else
//
//        {
//            String errorMessage = "ERROR: Invalid response received";
//            throw new Exception(errorMessage);
//        }
//
//        return this.listGS;
//    }
    
    private void createMessage() throws Exception {
//        // Create first level message
//        MsgGetGroundStation  tmpMsg = new MsgGetGroundStation();
//        
//        tmpMsg.setGroundStationName("");
//        tmpMsg.setGroundStationCode("");
//        tmpMsg.setAuthorizationToken("");
//        
//        if (this.stationId.isEmpty() == false) {
//            tmpMsg.setGroundStationName(this.stationId);
//        } else {
//            if (this.stationCode.isEmpty() == false) {
//                tmpMsg.setGroundStationCode(this.stationCode);
//            } 
//        }
//        
//        try {
//            // Encode message
//            byte[]   tmpMsgData = null;
//
//            tmpMsgData = encodeMessage(MsgGetGroundStation.class, tmpMsg);
//
//            // Create message
//            this.requestMessage.setOperationCode(EnumOperationCode.CODE_GET_GROUND_STATION);
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
