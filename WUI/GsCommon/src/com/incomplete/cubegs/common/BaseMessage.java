package com.incomplete.cubegs.common;



import com.incomplete.cubegs.common.avro.messages.MsgReturnData;


/*
 * 
 *  NOT USED 
 *  NOT USED
 * 
 * 
 * 
 */

/**
 * This is the base message for all message to be exchanged between the WUI and the Backend
 * @author alberto
 *
 */
public class BaseMessage  {
    protected final int SLEEP_NUMBER_SECONDS = 10;
        
    protected ServerMessage   requestMessage;

    protected ServerMessage   responseMessage;


    
    public BaseMessage() {        
        clear();
    }
    
    // Send the message and wait for the answer
    public ReturnData request() throws Exception {    
        // Send and wait
        ZeroMqManager.getInstance().send(this.requestMessage);
    
        ZeroMqManager.getInstance().receive(this.responseMessage);
        
        return getReturnData();
        
        
        //String finalId = InteractionManager.getInstance().requestMessage(this.message,  this);

        // Store the message Id
        //this.message.setMessageId(finalId);
       
        /*
        // Wait for the answer
        this.waitFlag = true;

        // Create thread and wait for response message
        boolean timeoutFlag = waitForResponseMessage(this.cv);
                
        // Process the response
        if (timeoutFlag == false)
        {
            // Process the reply
            // Delegate to derived classes
            internalProcessReply();
        }
        else
        {
            String tmpMessage = "Timeout invoking API call. Message" + this.message.toShortString();
            
            this.output.set(-1, tmpMessage);
            // Throw an exception
            throw new Exception(tmpMessage);
        }
        */
    }

    protected ReturnData getReturnData() {
        ReturnData      output = new ReturnData();
        
        if (this.responseMessage.getDataSize() != -1) {
            if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_REPLY_MESSAGE.toString()) {
                try {
                    // Decode error
                    MsgReturnData returnMsg = ServerMessage.decodeMessage(MsgReturnData.class, 
                                                                          this.responseMessage.getMessage(),
                                                                          MsgReturnData.getClassSchema());

                    output.setErrorCode(returnMsg.getErrorCode());
                    output.setErrorMessage(returnMsg.getErrorMessage());
                } catch (Exception exc) {
                    exc.printStackTrace();

                    output.set(-1, "Exception: " + exc.getMessage());
                }
            }
        } else {
            output.set(-1, "No data has been received");
        }

        return output;
    }
    
    protected void clear() {
        this.requestMessage = null;
        //this.requestMessage = new ServerMessage();
        
        this.responseMessage = null;
        //this.responseMessage = new ServerMessage();      
    }
    
    

}
