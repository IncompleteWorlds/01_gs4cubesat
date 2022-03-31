package com.incomplete.cubegs.common;

import java.time.Clock;
import java.time.Instant;

import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonProperty;



/*
 {
    "msg_id":              "001", 
    "msg_code":            "login", 

    "version":             "1.0", 
    "authentication_key":  "", 
    "timestamp":           0, 

    "username_email":      "user01", 
    "password":            "aad415a73c4cef1ef94a5c00b2642b571a3e5494536328ad960db61889bd9368"
} 
 * 
 */

public class ServerMessage extends BaseMessage {
    @JsonIgnore
    static private int msg_id_counter = 0;
    	
	// Fields to be included in the JSON
	private String version = "1.0";
		
	@JsonProperty("authentication_key")
    private String authenticationKey;
		
    private Instant timestamp;
    
    public ServerMessage() {
    	this.msgCode = "";
    	this.authenticationKey = "";
    	this.timestamp = Clock.systemUTC().instant();
    	
    	nextMsgId();
    }
    
    public ServerMessage(String inMsgCodeId, String inAuthenticationKey) {
    	this.msgCode = inMsgCodeId;
    	this.authenticationKey = inAuthenticationKey;
    	this.timestamp = Clock.systemUTC().instant();

    	nextMsgId();
    	
//    	@JsonFormat(
//    	        shape = JsonFormat.Shape.STRING,
//    	        pattern = "dd-MM-yyyy hh:mm:ss")
//    	DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm a z");
    	
    	//objectMapper.setDateFormat(df);
//        this.dataBytes = inDataBytes;    	
    }
    
    

	public String getVersion() {
		return version;
	}

	public void setVersion(String version) {
		this.version = version;
	}

	public String getAuthenticationKey() {
		return authenticationKey;
	}

	public void setAuthenticationKey(String authentication_key) {
		this.authenticationKey = authentication_key;
	}

	public Instant getTimestamp() {
		return timestamp;
	}

	public void setTimestamp(Instant timestamp) {
		this.timestamp = timestamp;
	}
	
//	public String getTimestamp() {
//        return timestamp.toString();
//    }
//
//	public void setTimestamp(String inTimestamp) {
//		try {
//            this.timestamp = Instant.parse(inTimestamp);
//		} catch (Exception e) {
//		}
//	}

	@Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        
        sb.append("Operation: ")
          .append("  Version: ").append(this.version)
          .append("  Message Code Id: ").append(this.msgCode)
          .append("  Message Id: ").append(this.msgId)
          .append("  Timestamp: ").append(this.timestamp.toString());
        
        return sb.toString();
    }
    
	private void nextMsgId() {
	    // Next message
        ServerMessage.msg_id_counter ++;

        this.msgId = Integer.toString(ServerMessage.msg_id_counter);
	}
    

}
