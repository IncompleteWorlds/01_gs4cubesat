package com.incomplete.cubegs.mainwui.messages;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import com.incomplete.cubegs.common.EnumHttpOperationType;
import com.incomplete.cubegs.common.ServerMessage;

import com.fasterxml.jackson.annotation.JsonProperty;


public class M_CLoginMessage extends ServerMessage {    
    @JsonProperty("username_email")
    private String userName;
   
    private String password;
    
    public M_CLoginMessage(String inUserName, String inPassword) throws Exception {
        super("/gsaas/login", EnumHttpOperationType.HTTP_POST, "login", "");

        setUserName(inUserName);
        setPassword(inPassword);
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
        // Calculate the hash
        this.password = calculateSha(password);
    }
    
    private String calculateSha(String inText) {
        String output = null;
        boolean errorFlag = false;

        MessageDigest md = null;

        try {
            md = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException e2) {
            // TODO Auto-generated catch block
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
