package com.incomplete.cubegs.common;


import com.fasterxml.jackson.annotation.JsonProperty;


public class LogoutMessage extends ServerMessage {
    @JsonProperty("user_id")
    private String userId;
    
    public LogoutMessage(String inUserId) {
        super("logout", "");
        
        this.userId = inUserId;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

}
