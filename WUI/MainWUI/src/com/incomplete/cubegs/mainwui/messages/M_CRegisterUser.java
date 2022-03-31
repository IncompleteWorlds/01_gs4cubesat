package com.incomplete.cubegs.mainwui.messages;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import com.incomplete.cubegs.common.ServerMessage;
import com.incomplete.cubegs.common.data.User;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.incomplete.cubegs.common.EnumHttpOperationType;
import com.incomplete.cubegs.common.EnumRole;


/**
 * Register a new user in the CubeGS. It calculates the hash function and send to the server
 * @author alberto
 *
 */


/*
    {   
        "version" :               "1.0",
        "msg_code_id" :           "register",
        "authentication_key" :    "",
        "msg_id" :                "2",
        "user_id" :               "",
        "timestamp" :             0,
    
        "first_ame" :             "my first",
        "last_name" :             "last",
        "role_id" :               "mission_administrator",
        "username" :              "user01",
        "password" :              "aad415a73c4cef1ef94a5c00b2642b571a3e5494536328ad960db61889bd9368",
        "email" :                 "john_doe@someaddress.com",
        "license" :               "Demo"
    }

Response:
    {  
        "msg_id":"0001",
        "msg_code_id":"error_response",
        "status":-1,
        "detail":"ERROR: Authentication key not found. IGNORED"
    }
 */
public class M_CRegisterUser extends ServerMessage {
    
//    private User    user;
    //private Mission mission;
    
    @JsonProperty("first_name")
    private String firstName;
    
    @JsonProperty("last_name")
    private String lastName;
    
    @JsonProperty("username")
    private String userName;
    
    private String password;
    private String email;
    
    @JsonProperty("role_id")
    private EnumRole roleId;
    
    @JsonProperty("license_id")
    private String licenseId;

	public M_CRegisterUser(User inUser) throws Exception {
	    super("/gsaas/register", EnumHttpOperationType.HTTP_PUT, "register", "");

	    createMessage(inUser);
    }
        
    private void createMessage(User inUser) throws Exception {
        this.firstName   = inUser.getFirstName();
        this.lastName    = inUser.getLastName();
        this.userName    = inUser.getUserName();
        this.password    = calculateSha(inUser.getPassword());
        this.email       = inUser.getEmail();
        this.roleId      = inUser.getRoleId();
        this.licenseId   = inUser.getLicenseId();
    }
	
    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public EnumRole getRoleId() {
        return roleId;
    }

    public void setRoleId(EnumRole roleId) {
        this.roleId = roleId;
    }

    public String getLicenseId() {
        return licenseId;
    }

    public void setLicenseId(String licenseId) {
        this.licenseId = licenseId;
    }

    private String calculateSha(String inText) {
        String output = null;
        boolean errorFlag = false;

        MessageDigest md = null;

        try {
            md = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException e2) {
            e2.printStackTrace();
            errorFlag = true;
        }

        if (errorFlag == false) {
            md.update(inText.getBytes());

            byte byteData[] = md.digest();

            // Convert the byte to hex format method 1
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < byteData.length; i++) {
                sb.append(Integer.toString((byteData[i] & 0xff) + 0x100, 16).substring(1));
            }

            /*
              //convert the byte to hex format method 2 
              StringBuffer hexString = new StringBuffer(); 
              for (int i=0;i<byteData.length;i++) {
                  String hex=Integer.toHexString(0xff & byteData[i]); 
                  if (hex.length()==1) 
                      hexString.append('0'); 
                  hexString.append(hex); 
              }
              System.out.println("Hex format : " + hexString.toString());
             */

            output = sb.toString();
        }

        return output;
    }

}
