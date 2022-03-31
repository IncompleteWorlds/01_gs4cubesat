/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** An Event that a component or system publishes */
@org.apache.avro.specific.AvroGenerated
public class Event extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 2427951710521759563L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"Event\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"An Event that a component or system publishes\",\"fields\":[{\"name\":\"type\",\"type\":\"int\",\"doc\":\"Event type\"},{\"name\":\"eventTime\",\"type\":\"long\",\"doc\":\"Event creation time in milliseconds\"},{\"name\":\"data\",\"type\":\"bytes\",\"doc\":\"Array of bytes\"},{\"name\":\"dataLength\",\"type\":\"int\",\"doc\":\"Number of bytes to be sent\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Event type */
  @Deprecated public int type;
  /** Event creation time in milliseconds */
  @Deprecated public long eventTime;
  /** Array of bytes */
  @Deprecated public java.nio.ByteBuffer data;
  /** Number of bytes to be sent */
  @Deprecated public int dataLength;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public Event() {}

  /**
   * All-args constructor.
   * @param type Event type
   * @param eventTime Event creation time in milliseconds
   * @param data Array of bytes
   * @param dataLength Number of bytes to be sent
   */
  public Event(java.lang.Integer type, java.lang.Long eventTime, java.nio.ByteBuffer data, java.lang.Integer dataLength) {
    this.type = type;
    this.eventTime = eventTime;
    this.data = data;
    this.dataLength = dataLength;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return type;
    case 1: return eventTime;
    case 2: return data;
    case 3: return dataLength;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: type = (java.lang.Integer)value$; break;
    case 1: eventTime = (java.lang.Long)value$; break;
    case 2: data = (java.nio.ByteBuffer)value$; break;
    case 3: dataLength = (java.lang.Integer)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'type' field.
   * @return Event type
   */
  public java.lang.Integer getType() {
    return type;
  }

  /**
   * Sets the value of the 'type' field.
   * Event type
   * @param value the value to set.
   */
  public void setType(java.lang.Integer value) {
    this.type = value;
  }

  /**
   * Gets the value of the 'eventTime' field.
   * @return Event creation time in milliseconds
   */
  public java.lang.Long getEventTime() {
    return eventTime;
  }

  /**
   * Sets the value of the 'eventTime' field.
   * Event creation time in milliseconds
   * @param value the value to set.
   */
  public void setEventTime(java.lang.Long value) {
    this.eventTime = value;
  }

  /**
   * Gets the value of the 'data' field.
   * @return Array of bytes
   */
  public java.nio.ByteBuffer getData() {
    return data;
  }

  /**
   * Sets the value of the 'data' field.
   * Array of bytes
   * @param value the value to set.
   */
  public void setData(java.nio.ByteBuffer value) {
    this.data = value;
  }

  /**
   * Gets the value of the 'dataLength' field.
   * @return Number of bytes to be sent
   */
  public java.lang.Integer getDataLength() {
    return dataLength;
  }

  /**
   * Sets the value of the 'dataLength' field.
   * Number of bytes to be sent
   * @param value the value to set.
   */
  public void setDataLength(java.lang.Integer value) {
    this.dataLength = value;
  }

  /**
   * Creates a new Event RecordBuilder.
   * @return A new Event RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Event.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.Event.Builder();
  }

  /**
   * Creates a new Event RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new Event RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Event.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Event.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.Event.Builder(other);
  }

  /**
   * Creates a new Event RecordBuilder by copying an existing Event instance.
   * @param other The existing instance to copy.
   * @return A new Event RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Event.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Event other) {
    return new com.incomplete.cubegs.common.avro.messages.Event.Builder(other);
  }

  /**
   * RecordBuilder for Event instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<Event>
    implements org.apache.avro.data.RecordBuilder<Event> {

    /** Event type */
    private int type;
    /** Event creation time in milliseconds */
    private long eventTime;
    /** Array of bytes */
    private java.nio.ByteBuffer data;
    /** Number of bytes to be sent */
    private int dataLength;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Event.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.type)) {
        this.type = data().deepCopy(fields()[0].schema(), other.type);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.eventTime)) {
        this.eventTime = data().deepCopy(fields()[1].schema(), other.eventTime);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.data)) {
        this.data = data().deepCopy(fields()[2].schema(), other.data);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.dataLength)) {
        this.dataLength = data().deepCopy(fields()[3].schema(), other.dataLength);
        fieldSetFlags()[3] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing Event instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Event other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.type)) {
        this.type = data().deepCopy(fields()[0].schema(), other.type);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.eventTime)) {
        this.eventTime = data().deepCopy(fields()[1].schema(), other.eventTime);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.data)) {
        this.data = data().deepCopy(fields()[2].schema(), other.data);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.dataLength)) {
        this.dataLength = data().deepCopy(fields()[3].schema(), other.dataLength);
        fieldSetFlags()[3] = true;
      }
    }

    /**
      * Gets the value of the 'type' field.
      * Event type
      * @return The value.
      */
    public java.lang.Integer getType() {
      return type;
    }

    /**
      * Sets the value of the 'type' field.
      * Event type
      * @param value The value of 'type'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Event.Builder setType(int value) {
      validate(fields()[0], value);
      this.type = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'type' field has been set.
      * Event type
      * @return True if the 'type' field has been set, false otherwise.
      */
    public boolean hasType() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'type' field.
      * Event type
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Event.Builder clearType() {
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'eventTime' field.
      * Event creation time in milliseconds
      * @return The value.
      */
    public java.lang.Long getEventTime() {
      return eventTime;
    }

    /**
      * Sets the value of the 'eventTime' field.
      * Event creation time in milliseconds
      * @param value The value of 'eventTime'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Event.Builder setEventTime(long value) {
      validate(fields()[1], value);
      this.eventTime = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'eventTime' field has been set.
      * Event creation time in milliseconds
      * @return True if the 'eventTime' field has been set, false otherwise.
      */
    public boolean hasEventTime() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'eventTime' field.
      * Event creation time in milliseconds
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Event.Builder clearEventTime() {
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'data' field.
      * Array of bytes
      * @return The value.
      */
    public java.nio.ByteBuffer getData() {
      return data;
    }

    /**
      * Sets the value of the 'data' field.
      * Array of bytes
      * @param value The value of 'data'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Event.Builder setData(java.nio.ByteBuffer value) {
      validate(fields()[2], value);
      this.data = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'data' field has been set.
      * Array of bytes
      * @return True if the 'data' field has been set, false otherwise.
      */
    public boolean hasData() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'data' field.
      * Array of bytes
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Event.Builder clearData() {
      data = null;
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'dataLength' field.
      * Number of bytes to be sent
      * @return The value.
      */
    public java.lang.Integer getDataLength() {
      return dataLength;
    }

    /**
      * Sets the value of the 'dataLength' field.
      * Number of bytes to be sent
      * @param value The value of 'dataLength'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Event.Builder setDataLength(int value) {
      validate(fields()[3], value);
      this.dataLength = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'dataLength' field has been set.
      * Number of bytes to be sent
      * @return True if the 'dataLength' field has been set, false otherwise.
      */
    public boolean hasDataLength() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'dataLength' field.
      * Number of bytes to be sent
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Event.Builder clearDataLength() {
      fieldSetFlags()[3] = false;
      return this;
    }

    @Override
    public Event build() {
      try {
        Event record = new Event();
        record.type = fieldSetFlags()[0] ? this.type : (java.lang.Integer) defaultValue(fields()[0]);
        record.eventTime = fieldSetFlags()[1] ? this.eventTime : (java.lang.Long) defaultValue(fields()[1]);
        record.data = fieldSetFlags()[2] ? this.data : (java.nio.ByteBuffer) defaultValue(fields()[2]);
        record.dataLength = fieldSetFlags()[3] ? this.dataLength : (java.lang.Integer) defaultValue(fields()[3]);
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
