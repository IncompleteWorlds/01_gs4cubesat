/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.incomplete.cubegs.xtceprocessor;

import java.util.ArrayList;

/**
 *
 * @author AcerTablet
 */
class ProcessedFrame {
    ArrayList<ProcessedField>   fields;
    
    public ProcessedFrame() {
    }

    public ArrayList<ProcessedField> getFields() {
        if (fields == null) {
            fields = new ArrayList<ProcessedField>();
        }
        return fields;
    }
    
    public void addField(ProcessedField inNewField) {
        if (inNewField != null) {
            getFields().add(inNewField);
        }
    }
    
    public void addField(String inFieldId, String inFieldName, String inFieldValue) {
        if (inFieldId != null && inFieldValue != null) {
            ProcessedField  tmpField = new ProcessedField(inFieldId, inFieldName, inFieldValue);
            
            getFields().add(tmpField);
        }
    }
    
    
    byte[] getDataBytes() {
        byte[]  output = null;
        if (fields != null) {
            
        }
        
        return output;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        
        sb.append("Frame: \n");
        for(ProcessedField current: getFields()) {
            sb.append(current.toString());
        }
         
        return sb.toString();
    }
}
