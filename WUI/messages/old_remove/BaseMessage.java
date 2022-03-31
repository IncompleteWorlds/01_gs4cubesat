package com.incomplete.cubegs.common;

import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.json.JsonMapper;
import com.fasterxml.jackson.datatype.jdk8.Jdk8Module;
import com.fasterxml.jackson.datatype.jsr310.JavaTimeModule;




public class BaseMessage  {
    @JsonIgnore
    static private ObjectMapper objectMapper = JsonMapper.builder() // or different mapper for other format
            .addModule(new Jdk8Module())
            .addModule(new JavaTimeModule())
            // and possibly other configuration, modules, then:
            .build();
    
    @JsonProperty("msg_id")
    protected String msgId;
    
    @JsonProperty("msg_code")
    protected String msgCode;

    public BaseMessage() {        
        this.msgId = "";
        this.msgCode = "";
    }
    
    public BaseMessage(String msg_id, String msg_code_id) {
        this.msgId = msg_id;
        this.msgCode = msg_code_id;
    }
    
    public String getMsgId() {
        return msgId;
    }

    public void setMsgId(String msgId) {
        this.msgId = msgId;
    }

    public String getMsgCode() {
        return msgCode;
    }

    public void setMsgCode(String msgCode) {
        this.msgCode = msgCode;
    }
        
    /**
     * Encode a message as a JSON string       
     * @throws JsonProcessingException
     */
    public <T> 
    String encodeMessage(T inMsgClass) throws JsonProcessingException {
        String output = new String();
    
        try {
            output = objectMapper.writeValueAsString(inMsgClass);
            
        } catch (JsonProcessingException e) {
            e.printStackTrace();
            throw e;
        }
        
        return output;
    }
    
    /**
     * Decode a JSON string and create an object of type T
     * @param <T> - Type of the message
     * @param inMsgClass
     * @param inJson
     * @return
     */
    @SuppressWarnings("unchecked")
    public <T> 
    T decodeMessage(String inJson, Class<T> classz) {
        T output = null;
        
        if (inJson.isEmpty() == true) {
            output = (T) new ServerResponseMessage("error", "error_response", 
                                                        -1, "Empty Body received"); 
            return output;
        }
                
        try {
            output = (T) objectMapper.readValue(inJson, classz);
        } catch (JsonProcessingException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            
            output = (T) new ServerResponseMessage("error", "error_response", 
                                                       -1, "Exception: " + e.toString()); 
        }   
        
        return output;
    }

}
