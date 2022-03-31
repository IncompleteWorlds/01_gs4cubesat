/**
 * Copyright Incomplete Worlds (c) 2019
 *
 */
package com.incomplete.cubegs.xtceprocessor;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;


import org.apache.avro.io.DatumReader;
import org.apache.avro.io.DatumWriter;
import org.apache.avro.io.Decoder;
import org.apache.avro.io.DecoderFactory;
import org.apache.avro.io.Encoder;
import org.apache.avro.io.EncoderFactory;
import org.apache.avro.specific.SpecificDatumReader;
import org.apache.avro.specific.SpecificDatumWriter;
import org.apache.avro.specific.SpecificRecordBase;

import com.incomplete.cubegs.common.avro.messages.MsgReturnData;



public class BaseMessage implements IMessageProcessor {
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
            if (this.responseMessage.getOperationCode() == EnumOperationCode.CODE_REPLY_MESSAGE) {
                try {
                    // Decode error
                    MsgReturnData returnMsg = decodeMessage(MsgReturnData.class, this.responseMessage.getDataBytes());

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
        this.requestMessage = new ServerMessage();
        
        this.responseMessage = null;
        this.responseMessage = new ServerMessage();      
    }
    
    // Encode a message using Apache Avro
    protected static <T extends SpecificRecordBase> 
    byte[] encodeMessage(Class<T> c, T t) throws IOException {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        
        DatumWriter<T> w = new SpecificDatumWriter<T>(c);

        Encoder e = EncoderFactory.get().binaryEncoder(out, null);
        
        w.write(t, e);
        e.flush();
        
        return out.toByteArray();
    }


    // Decode a message using Apache Avro
    protected static <T extends SpecificRecordBase> 
    //T decodeMessage(Class<T> c, byte[] inDataBytes) throws Exception, IOException {
    T decodeMessage(Class<? extends Object> class1, byte[] inDataBytes) throws Exception, IOException {
        ByteArrayInputStream in = new ByteArrayInputStream(inDataBytes);

        //DatumReader<T> reader = new SpecificDatumReader<T>(c);
        DatumReader<T> reader = new SpecificDatumReader<T>((Class<T>) class1);

        Decoder d = DecoderFactory.get().binaryDecoder(in, null);

        T t = reader.read(null, d);

        return t;
    }

    @Override
    public void processMessage(ServerMessage inMessage) {
        // Empty
    }
        
}
