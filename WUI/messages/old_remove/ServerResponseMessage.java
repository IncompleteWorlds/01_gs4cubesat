package com.incomplete.cubegs.common;


/*
{ 
   "msg_id":"0001",
   "msg_code":"error_response",
   "status": 401,
   "detail":"ERROR: Authentication key not found. IGNORED"
}

*/

public class ServerResponseMessage extends BaseMessage {
    
    private int status;
        
    private String detail;

    public ServerResponseMessage() {
        this.status = 0;
        this.detail = "";
    }

    public ServerResponseMessage(String msg_id, String msg_code_id, int error_code, String error_message) {
        super(msg_id, msg_code_id);
        
        this.status = error_code;
        this.detail = error_message;
    }

    public int getStatus() {
        return status;
    }

    public void setStatus(int status) {
        this.status = status;
    }

    public String getDetail() {
        return detail;
    }

    public void setDetail(String detail) {
        this.detail = detail;
    }
    
}
