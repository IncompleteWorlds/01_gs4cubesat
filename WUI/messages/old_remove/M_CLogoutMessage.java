package com.incomplete.cubegs.fdswui.messages;

import com.incomplete.cubegs.common.ServerMessage;


public class M_CLogoutMessage extends ServerMessage {
    private String userName;

    public M_CLogoutMessage(String inUserName) {
        super("logout", "");
        
        this.userName = inUserName;

        //createMessage();
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }
    
    
    
//    private void createMessage() {
//        // Next message
//        getNextMessageId();
//        String tmpCorrelationId = Integer.toString(this.messageId);
//
//        this.message = new ServerMessage(EnumOperationCode.OPER_CODE_LOGOUT, "", tmpCorrelationId, null);
//
//        // Create the message; Avro
//        MsgLogout  logoutMsg = new MsgLogout(this.userName);
//        byte[]     outputMessage =  null;
//
//        try {
//            // Create the message; Avro
//            outputMessage = encodeMessage(MsgLogout.class, logoutMsg);
//            
//            this.message.setDataBytes(outputMessage);
//            this.message.setGroup(InteractionEnum.INTERACTION_REQUEST);
//            this.message.setGroupSequence(0);
//            
//            System.out.println("Output message: " + this.message);    
//        } catch (JMSException | IOException e) {
//            e.printStackTrace();
//            output.set(-1, e.getMessage());
//        } 
//    }
}
