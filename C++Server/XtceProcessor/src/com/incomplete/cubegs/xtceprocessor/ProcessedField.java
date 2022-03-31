/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.incomplete.cubegs.xtceprocessor;

/**
 *
 * @author ajfg
 */
class ProcessedField {
    private String typeId = null;
    private String value = null;;
    private String name = null;;

    public ProcessedField() {
    }

    ProcessedField(String inFieldId, String inFieldName, String inFieldValue) {
        typeId = inFieldId;
        name = inFieldName;
        value = inFieldValue;
    }
    
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        
        sb.append("Field: \n")
          .append(" Id: ").append(this.typeId)
          .append(" Name: ").append(this.name)
          .append(" Value: ").append(this.value);
        
        return sb.toString();
    }
}
