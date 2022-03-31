package com.incomplete.cubegs.common;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpHeaders;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
//import java.net.http.HttpRequest.BodyPublisher;
//import java.net.http.HttpRequest.BodyPublishers;
import java.net.http.HttpRequest.Builder;
import java.time.Duration;
import java.util.Properties;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.json.JsonMapper;
import com.fasterxml.jackson.datatype.jdk8.Jdk8Module;
import com.fasterxml.jackson.datatype.jsr310.JavaTimeModule;




public class HttpManager {
    private static final HttpClient httpClient = HttpClient.newBuilder()
            .version(HttpClient.Version.HTTP_1_1)
            .connectTimeout(Duration.ofSeconds(10))
            .build();
    
    private static ObjectMapper objectMapper = JsonMapper.builder() // or different mapper for other format
            .addModule(new Jdk8Module())
            .addModule(new JavaTimeModule())
            // and possibly other configuration, modules, then:
            .build();
    
    private static Properties properties = new Properties();
    
    public HttpManager() throws Exception {
        // This is required for Tomcat
        InputStream is = this.getClass().getClassLoader().getResourceAsStream("../resources/url.properties");

        properties.load( is );
        
        // This is required for Jetty (inside Eclipse)
        //properties.load( new FileInputStream("resources/url.properties") ); 
        
        System.out.println("INFO: Loaded URL properties");
    }
    
    
    /**
     * Encode a message as a JSON string       
     */
    private static <T> 
    String encodeMessage(T inMsgClass) {
        String output = new String();
    
        try {
            output = objectMapper.writeValueAsString(inMsgClass);
            
        } catch (JsonProcessingException e) {
            e.printStackTrace();
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
    private static <T> 
    T decodeMessage(String inJson, Class<T> classz) {
        T output = null;
        
        if (inJson.isEmpty() == true) {
            output = (T) new ServerResponseMessage("error", "error_response", 
                                                        -1, "Empty HTTP Body received"); 
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
        
    /**
     * Send a message of type T1 and return a message of type T2 or null
     */
    public static <T1, T2> 
    T2 sendRequest(T1 inMessage, Class<T2> classz) throws Exception {
        T2 output = null;
        
        if ((inMessage instanceof ServerMessage) == false) {
            String errorMessage = "Invalid Input Message class type";

            System.out.println(errorMessage);

            throw new Exception(errorMessage);
        }
        
        if (inMessage == null) {
            String errorMessage = "Input message is Null";

            System.out.println(errorMessage);

            throw new Exception(errorMessage);
        }
                
        String jsonPayload = encodeMessage(inMessage);

        // Send and wait
        Builder tmpBuilder = HttpRequest.newBuilder();
        
        // TODO: Fix this error
        String finalURI = properties.getProperty("gateway_url"); // + ((ServerMessage) inMessage).getURIString();
        
        System.out.println("DEBUG: API call URL: " + finalURI);
               
        HttpRequest request = tmpBuilder.uri( URI.create(finalURI ) )
                .setHeader("User-Agent", "GsCommon Bot")
                .setHeader("Content-Type", "application/json")
                .method( "TODO", //((ServerMessage) inMessage).getOperationType().toString(), 
                         HttpRequest.BodyPublishers.ofString(jsonPayload)  )
                .build();
        
        System.out.println("DEBUG HTTP Request: " + jsonPayload);
        
        CompletableFuture<HttpResponse<String>> response = httpClient.sendAsync(request, 
                                                        HttpResponse.BodyHandlers.ofString());

        String  result = response.thenApply(HttpResponse::body).get(5, TimeUnit.SECONDS);
        System.out.println("DEBUG HTTP Response: " + result);
        
        try {
            int statusCode = response.thenApply(HttpResponse::statusCode).get();
            
            System.out.println("DEBUG HTTP Code: " + statusCode);
            
            output = decodeMessage(result, classz);
        } catch (InterruptedException | ExecutionException e) { //| TimeoutException e) {
            String errorMessage = "Exception sending HTTP Request";

            System.out.println(errorMessage);
            e.printStackTrace();

            throw new Exception(errorMessage);
        }
        
        return output;
    }

}
