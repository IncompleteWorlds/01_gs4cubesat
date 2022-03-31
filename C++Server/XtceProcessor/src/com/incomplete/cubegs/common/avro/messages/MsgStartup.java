/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This message commands a component to start up itself */
@org.apache.avro.specific.AvroGenerated
public class MsgStartup extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = -698672364324730187L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"MsgStartup\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This message commands a component to start up itself\",\"fields\":[{\"name\":\"message\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Message from component\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Message from component */
  @Deprecated public java.lang.String message;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public MsgStartup() {}

  /**
   * All-args constructor.
   * @param message Message from component
   */
  public MsgStartup(java.lang.String message) {
    this.message = message;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return message;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: message = (java.lang.String)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'message' field.
   * @return Message from component
   */
  public java.lang.String getMessage() {
    return message;
  }

  /**
   * Sets the value of the 'message' field.
   * Message from component
   * @param value the value to set.
   */
  public void setMessage(java.lang.String value) {
    this.message = value;
  }

  /**
   * Creates a new MsgStartup RecordBuilder.
   * @return A new MsgStartup RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder();
  }

  /**
   * Creates a new MsgStartup RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new MsgStartup RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder(other);
  }

  /**
   * Creates a new MsgStartup RecordBuilder by copying an existing MsgStartup instance.
   * @param other The existing instance to copy.
   * @return A new MsgStartup RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgStartup other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder(other);
  }

  /**
   * RecordBuilder for MsgStartup instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<MsgStartup>
    implements org.apache.avro.data.RecordBuilder<MsgStartup> {

    /** Message from component */
    private java.lang.String message;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.message)) {
        this.message = data().deepCopy(fields()[0].schema(), other.message);
        fieldSetFlags()[0] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing MsgStartup instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgStartup other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.message)) {
        this.message = data().deepCopy(fields()[0].schema(), other.message);
        fieldSetFlags()[0] = true;
      }
    }

    /**
      * Gets the value of the 'message' field.
      * Message from component
      * @return The value.
      */
    public java.lang.String getMessage() {
      return message;
    }

    /**
      * Sets the value of the 'message' field.
      * Message from component
      * @param value The value of 'message'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder setMessage(java.lang.String value) {
      validate(fields()[0], value);
      this.message = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'message' field has been set.
      * Message from component
      * @return True if the 'message' field has been set, false otherwise.
      */
    public boolean hasMessage() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'message' field.
      * Message from component
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgStartup.Builder clearMessage() {
      message = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    @Override
    public MsgStartup build() {
      try {
        MsgStartup record = new MsgStartup();
        record.message = fieldSetFlags()[0] ? this.message : (java.lang.String) defaultValue(fields()[0]);
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
