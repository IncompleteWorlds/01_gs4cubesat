package com.incomplete.cubegs.fdswui.messages;

import java.util.*;

import com.incomplete.cubegs.common.EnumOperationCode;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.common.ServerMessage;
import com.incomplete.cubegs.common.avro.messages.MsgPropagateSGP4Response;
import com.incomplete.cubegs.common.avro.data_model.StateVector;


public class M_SGP4SimpleResponse extends ServerMessage {
    private MsgPropagateSGP4Response  avroMessage;
    
    public M_SGP4SimpleResponse() {
        super( EnumOperationCode.msg_propagate_sgp4_response.toString() );
        
        this.avroMessage = new MsgPropagateSGP4Response();
    }

    public String getEphemerisText() {
        return this.avroMessage.getEphemerisText();
    }
    
    public ArrayList<StateVector> getEphemeris() {
        return (ArrayList<StateVector>) this.avroMessage.getEphemeris();
    }
    
    public String getType() {
        return this.avroMessage.getOutputFormat();
    }
    
    public ReturnData getReturnData() {
        return new ReturnData(this.avroMessage.getErrorData().getErrorCode(), 
                              this.avroMessage.getErrorData().getErrorMessage() );
    }

    @Override
    public String encode() {
        try {
            return ServerMessage.encodeMessage(MsgPropagateSGP4Response.class, this.avroMessage, this.avroMessage.getSchema());
        } catch(Exception e) {
            System.err.println(this.avroMessage.getSchema().toString(true));
            System.err.println("Input message: " + this.avroMessage.toString());
            
            e.printStackTrace();
            return new String();
        }
    }
    
    @Override
    public void decode(String inMsgBuffer) {
        if (inMsgBuffer.isEmpty() == false) {
            try {
                this.avroMessage = ServerMessage.decodeMessage(MsgPropagateSGP4Response.class, inMsgBuffer, this.avroMessage.getSchema());
            } catch(Exception e) {
                System.err.println(this.avroMessage.getSchema().toString(true));
                System.err.println("Input message: " + inMsgBuffer);
                
                e.printStackTrace();
            }            
        }
    }
    
    @SuppressWarnings("unchecked")
    @Override
    public MsgPropagateSGP4Response get() {
        return this.avroMessage;
    }
    
    
}
