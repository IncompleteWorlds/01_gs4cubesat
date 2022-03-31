package com.incomplete.cubegs.common;

public enum EnumHttpOperationType {
    HTTP_GET("GET"),
    HTTP_POST("POST"),
    HTTP_PUT("PUT"),
    HTTP_DELETE("DELETE");
    
    private String value;
   
    private EnumHttpOperationType(String newValue) {
        this.value = newValue;        
    }
    
    public String toString() {
        return value;
    }
}
