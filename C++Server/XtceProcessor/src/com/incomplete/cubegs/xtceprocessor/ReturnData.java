/**
 * Copyright Incomplete Worlds (c) 2019
 *
 */
package com.incomplete.cubegs.xtceprocessor;

/**
 * This class is returned by all API calls
 * @author alberto
 *
 */
public class ReturnData {
    private int    errorCode;
    private String errorMessage;
    
    public ReturnData() {
        this.errorCode = 0;
        this.errorMessage = "";
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
}
