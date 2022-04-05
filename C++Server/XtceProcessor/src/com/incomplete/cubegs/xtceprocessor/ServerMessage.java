package com.incomplete.cubegs.xtceprocessor;


public class ServerMessage {
    private EnumOperationCode operationCode;
    private String messageId;
    private String correlationId;
    private byte[] dataBytes;
    
    
    public ServerMessage() {
        this.operationCode = EnumOperationCode.CODE_NONE;
        this.messageId = "";
        this.correlationId = "";
        this.dataBytes = null;
    }
    
    public ServerMessage(EnumOperationCode inOperationCode, String inMessageId, String inCorrelationId, byte[] inDataBytes) {
        this.operationCode = inOperationCode;
        this.messageId = inMessageId;
        this.correlationId = inCorrelationId;
        this.dataBytes = inDataBytes;
    }

    public EnumOperationCode getOperationCode() {
        return operationCode;
    }

    public void setOperationCode(EnumOperationCode operationCode) {
        this.operationCode = operationCode;
    }
    
    public int getOperationCodeAsInt() {
        return this.operationCode.getValue();
    }

    public void setOperationCodeAsInt(int operationCode) {
        try {
            this.operationCode = EnumOperationCode.getType(operationCode);
        } catch (Exception e) {
            // Do nothing. Ignore error
        }
    }

    public String getOperationCodeAsString() {
        return Integer.toString( this.operationCode.getValue() );
    }

    public void setOperationCodeAsString(String operationCode) {        
        try {
            int tmpOperationCode = Integer.valueOf(operationCode);
            
            this.operationCode = EnumOperationCode.getType(tmpOperationCode);
        } catch (Exception e) {
            // Do nothing. Ignore error
        }
    }

    public String getMessageId() {
        return messageId;
    }

    public void setMessageId(String messageId) {
        this.messageId = messageId;
    }

    public String getCorrelationId() {
        return correlationId;
    }

    public void setCorrelationId(String correlationId) {
        this.correlationId = correlationId;
    }

    public byte[] getDataBytes() {
        return dataBytes;
    }

    public void setDataBytes(byte[] dataBytes) {
        this.dataBytes = dataBytes;
    }
    
    public int getDataSize() {
        int output = -1;
        if (dataBytes != null) {
            output = dataBytes.length;
        }
        
        return output;
    }
    
    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        
        sb.append("Operation: ").append(this.operationCode)
          .append(" Message Id: ").append(this.messageId)
          .append(" Correlation Id: ").append(this.correlationId);
        
        return sb.toString();
    }
    
}