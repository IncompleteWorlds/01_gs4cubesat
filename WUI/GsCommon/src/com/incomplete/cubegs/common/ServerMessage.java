package com.incomplete.cubegs.common;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;

import org.apache.avro.Schema;
import org.apache.avro.io.DatumReader;
import org.apache.avro.io.DatumWriter;
import org.apache.avro.io.DecoderFactory;
import org.apache.avro.io.EncoderFactory;
import org.apache.avro.io.JsonDecoder;
import org.apache.avro.io.JsonEncoder;
import org.apache.avro.specific.SpecificDatumReader;
import org.apache.avro.specific.SpecificDatumWriter;
import org.apache.avro.specific.SpecificRecordBase;

import com.incomplete.cubegs.common.avro.messages.MsgHeader;

/**
 * Base class for all messages exchanged between the WUI and FDS Engine
 * @author alberto
 *
 */
public abstract class ServerMessage {
    public static int counter = 0;
    
    private MsgHeader header;
        
    // Used for coding and decoding the message
    private byte[] dataBytes;
    private String message;
    

    public ServerMessage() {
        int nextCounter = nextMessageId();
        
        this.header = new MsgHeader( "1.0", Integer.toString(nextCounter), "", "", "", "" );
        
        this.dataBytes = null;
        this.message = "";
    }
    
    public ServerMessage(String inMessageId, String inOperationCode) {
        this.header = new MsgHeader("1.0", inMessageId, inOperationCode, "", "", "");
        
        this.dataBytes = null;
        this.message = "";
    }
    
    public ServerMessage(String inOperationCode) {
        int nextCounter = nextMessageId();
        
        this.header = new MsgHeader("1.0", Integer.toString(nextCounter), inOperationCode, "", "", "");
        
        this.dataBytes = null;
        this.message = "";
    }
    
    public abstract String encode();
    
    public abstract void decode(String inMsgBuffer);
    
    public abstract <T> T get();

    public String getOperationCode() {
        return this.header.getMsgCode();
    }

    public void setOperationCode(String operationCode) {
        this.header.setMsgCode(operationCode);
    }

    public MsgHeader getHeader() {
        return header;
    }

    public void setHeader(MsgHeader header) {
        this.header = header;
    }

    public String getMessageId() {
        return this.header.getMsgId();
    }

    public void setMessageId(String messageId) {
        this.header.setMsgId(messageId);
    }

    public byte[] getDataBytes() {
        return dataBytes;
    }

    public void setDataBytes(byte[] dataBytes) {
        this.dataBytes = dataBytes;
    }
    
    public int getDataSize() {
        int output = -1;
        if (dataBytes != null) {
            output = dataBytes.length;
        }
        
        return output;
    }
    
    public String getMessage() {
        return message;
    }
    
    public void setMessage(String message) {
        this.message = message;
    }
    
    public void setUserId(String inUserId) {
        this.header.setUserId(inUserId);
    }
    
    public String getUserId() {
        return this.header.getUserId();
    }
    
	@Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        
        sb.append("Operation: ").append(this.header.getMsgCode())
          .append(" Message Id: ").append(this.header.getMsgId());
        
        return sb.toString();
    }

    // Encode a message using Apache Avro as a JSON
    protected static <T extends SpecificRecordBase> 
    String encodeMessage(Class<T> c, T t, Schema s) throws IOException {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        
        DatumWriter<T> w = new SpecificDatumWriter<T>(c);

        //Encoder e = EncoderFactory.get().binaryEncoder(out, null);
        // NOTE: Do we need the schema
        JsonEncoder e = EncoderFactory.get().jsonEncoder(s, out, false);
        
        w.write(t, e);
        e.flush();
        
        return out.toString();
    }


    // Decode a message using Apache Avro from a JSON string
    protected static <T extends SpecificRecordBase> 
    //T decodeMessage(Class<T> c, byte[] inDataBytes) throws Exception, IOException {
    T decodeMessage(Class<? extends Object> class1, String inDataBytes, Schema s) throws Exception, IOException {
        ByteArrayInputStream in = new ByteArrayInputStream(inDataBytes.getBytes());

        //DatumReader<T> reader = new SpecificDatumReader<T>(c);
        DatumReader<T> reader = new SpecificDatumReader<T>((Class<T>) class1);

        // Decoder d = DecoderFactory.get().binaryDecoder(in, null);
        // NOTE: Do we need the schema
        JsonDecoder d = DecoderFactory.get().jsonDecoder(s, in);
                
        T t = reader.read(null, d);

        return t;
    }
    
    protected int nextMessageId() {
        return ServerMessage.counter ++;
    }
}
