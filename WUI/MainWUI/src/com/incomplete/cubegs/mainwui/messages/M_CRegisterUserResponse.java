package com.incomplete.cubegs.mainwui.messages;

import com.incomplete.cubegs.common.ServerResponseMessage;

/*
 Response:
         { 
            "msg_id":"0001",
            "msg_code_id":"error_response",
            
            "user_id" :  "0fc1c0e1-878a-4562-ba81-86e20b9b07ab",
            
            "status":-1,
            "detail":"ERROR: Authentication key not found. IGNORED"
        }
*/
public class M_CRegisterUserResponse extends ServerResponseMessage {
    private String user_id;
    
    public M_CRegisterUserResponse() {
    }

    public M_CRegisterUserResponse(String user_id) {
        super();
        this.user_id = user_id;
    }

    public String getUser_id() {
        return user_id;
    }

    public void setUser_id(String user_id) {
        this.user_id = user_id;
    }
}
