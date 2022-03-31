package com.incomplete.cubegs.fdswui.messages;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.incomplete.cubegs.common.ServerResponseMessage;

/*
{
    "msg_id" :             "001",
    "jwt_token" :          "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJmZHNhYXMiLCJzdWIiOiJEZW1vIiwiZXhwIjoxNjA5MTgxNTI0LCJpZCI6IjQ0NTIwYjEzLTVkYjktNGM4Ni1hNWFjLWVhNzI1MzNmOGFlZSJ9.I7JFn-eJTxu6MnmNVl7T_mQLBEV_Ca1d9eczCxdx3Bs",
    "user_id" :            "a7e49ef0-1189-4fa8-a26e-bd54d51a6927",
    "error_code" :         0,
    "error_message" :      ""
}

{
    "msg_id":"2",
    "msg_code_id":"login_response",
    "status":0,
    "detail":"",
    "jwt_token":"eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJpd19nc2FhcyIsInN1YiI6IkRlbW8iLCJleHAiOjE2MzE0ODM2NzksImlkIjoiZDE1M2E2NjUtZWE0Yy00ZmUxLWFlNTctNWM2M2Y0ODQwNmMwIn0.XnCUDUIWvIUCKUTQnqBmBhznhIL2nBbfSLRgQw6L72E",
    "license":"Demo",
    "user_id":"d153a665-ea4c-4fe1-ae57-5c63f48406c0"
}
*/
public class M_CLoginResponse extends ServerResponseMessage {    
    @JsonProperty("jwt_token")
    private String jwtToken;
    
    @JsonProperty("user_id")
    private String userId;
    
    @JsonProperty("role_id")
    private String roleId;
    
    private String license;
    
    
    public M_CLoginResponse() {
        super();
        
        this.jwtToken = "";
        this.userId = "";
        this.roleId = "";
        
        this.license = ""; 
    }

    public String getJwtToken() {
        return jwtToken;
    }

    public void setJwtToken(String jwt_token) {
        this.jwtToken = jwt_token;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String user_id) {
        this.userId = user_id;
    }

    public String getRoleId() {
        return roleId;
    }

    public void setRoleId(String role_id) {
        this.roleId = role_id;
    }

    public String getLicense() {
        return license;
    }

    public void setLicense(String license) {
        this.license = license;
    }

}
