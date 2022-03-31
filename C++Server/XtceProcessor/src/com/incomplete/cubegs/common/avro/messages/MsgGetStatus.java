/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This message retrieves the status of all components or systems */
@org.apache.avro.specific.AvroGenerated
public class MsgGetStatus extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = -9191305559929757681L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"MsgGetStatus\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This message retrieves the status of all components or systems\",\"fields\":[{\"name\":\"componentId\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Target component or system\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Target component or system */
  @Deprecated public java.lang.String componentId;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public MsgGetStatus() {}

  /**
   * All-args constructor.
   * @param componentId Target component or system
   */
  public MsgGetStatus(java.lang.String componentId) {
    this.componentId = componentId;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return componentId;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: componentId = (java.lang.String)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'componentId' field.
   * @return Target component or system
   */
  public java.lang.String getComponentId() {
    return componentId;
  }

  /**
   * Sets the value of the 'componentId' field.
   * Target component or system
   * @param value the value to set.
   */
  public void setComponentId(java.lang.String value) {
    this.componentId = value;
  }

  /**
   * Creates a new MsgGetStatus RecordBuilder.
   * @return A new MsgGetStatus RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder();
  }

  /**
   * Creates a new MsgGetStatus RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new MsgGetStatus RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder(other);
  }

  /**
   * Creates a new MsgGetStatus RecordBuilder by copying an existing MsgGetStatus instance.
   * @param other The existing instance to copy.
   * @return A new MsgGetStatus RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgGetStatus other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder(other);
  }

  /**
   * RecordBuilder for MsgGetStatus instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<MsgGetStatus>
    implements org.apache.avro.data.RecordBuilder<MsgGetStatus> {

    /** Target component or system */
    private java.lang.String componentId;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.componentId)) {
        this.componentId = data().deepCopy(fields()[0].schema(), other.componentId);
        fieldSetFlags()[0] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing MsgGetStatus instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgGetStatus other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.componentId)) {
        this.componentId = data().deepCopy(fields()[0].schema(), other.componentId);
        fieldSetFlags()[0] = true;
      }
    }

    /**
      * Gets the value of the 'componentId' field.
      * Target component or system
      * @return The value.
      */
    public java.lang.String getComponentId() {
      return componentId;
    }

    /**
      * Sets the value of the 'componentId' field.
      * Target component or system
      * @param value The value of 'componentId'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder setComponentId(java.lang.String value) {
      validate(fields()[0], value);
      this.componentId = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'componentId' field has been set.
      * Target component or system
      * @return True if the 'componentId' field has been set, false otherwise.
      */
    public boolean hasComponentId() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'componentId' field.
      * Target component or system
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgGetStatus.Builder clearComponentId() {
      componentId = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    @Override
    public MsgGetStatus build() {
      try {
        MsgGetStatus record = new MsgGetStatus();
        record.componentId = fieldSetFlags()[0] ? this.componentId : (java.lang.String) defaultValue(fields()[0]);
        return record;
      } catch (Exception e) {
        throw new org.apache.avro.AvroRuntimeException(e);
      }
    }
  }

  private static final org.apache.avro.io.DatumWriter
    WRITER$ = new org.apache.avro.specific.SpecificDatumWriter(SCHEMA$);

  @Override public void writeExternal(java.io.ObjectOutput out)
    throws java.io.IOException {
    WRITER$.write(this, SpecificData.getEncoder(out));
  }

  private static final org.apache.avro.io.DatumReader
    READER$ = new org.apache.avro.specific.SpecificDatumReader(SCHEMA$);

  @Override public void readExternal(java.io.ObjectInput in)
    throws java.io.IOException {
    READER$.read(this, SpecificData.getDecoder(in));
  }

}
