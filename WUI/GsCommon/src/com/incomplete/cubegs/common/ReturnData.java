package com.incomplete.cubegs.common;

/**
 * This class is returned by all API calls
 * @author alberto
 *
 */
public class ReturnData {
    private int    errorCode;
    private String errorMessage;
    private String response;
    
    public ReturnData() {
        clear();
    }
    
    public ReturnData(int inErrorCode, String inErrorMessage) {
        set(inErrorCode, inErrorMessage);
    }
    
    public void set(int inErrorCode, String inErrorMessage) {
        setErrorCode(inErrorCode);
        setErrorMessage(inErrorMessage);
    }

    public int getErrorCode() {
        return errorCode;
    }

    public void setErrorCode(int errorCode) {
        this.errorCode = errorCode;
    }

    public String getErrorMessage() {
        return errorMessage;
    }

    public void setErrorMessage(String errorMessage) {
        this.errorMessage = errorMessage;
    }
    
    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        
        //sb.append("Operation: ").append(getOperationCodeAsInt())
        sb.append("Code: ").append(this.errorCode)
          .append(" Message: ").append(this.errorMessage);
        
        return sb.toString();
    }

    public void setResponse(String inResponseMsg) {
        this.response = inResponseMsg;        
    }
    
    public String getResponse() {
        return this.response;
    }

    public void clear() {
        this.errorCode = 0;
        this.errorMessage = "";
        this.response = "";
    }
}
