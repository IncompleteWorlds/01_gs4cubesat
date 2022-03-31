/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** It describes a processed frame. It is composed of a list of fields. Each field is composed of fied name, field type id and field value */
@org.apache.avro.specific.AvroGenerated
public class ProcessedFrame extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 8840969914130599781L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"ProcessedFrame\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"It describes a processed frame. It is composed of a list of fields. Each field is composed of fied name, field type id and field value\",\"fields\":[{\"name\":\"id\",\"type\":\"int\",\"doc\":\"Identifier of the frame\"},{\"name\":\"frameTypeId\",\"type\":\"int\",\"doc\":\"Frame Type identifier\"},{\"name\":\"creationTime\",\"type\":\"long\",\"doc\":\"Milliseconds since 1 Jan 1970\"},{\"name\":\"groups\",\"type\":[\"null\",{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"GroupProcessedField\",\"doc\":\"It describes a group of processed fields of frame (TM point) that has been already processed. It could contain all fields of a layer\",\"fields\":[{\"name\":\"id\",\"type\":\"int\",\"doc\":\"Identifier of the group\"},{\"name\":\"fields\",\"type\":{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"ProcessedField\",\"doc\":\"It describes a field of frame (TM point) that has been already processed\",\"fields\":[{\"name\":\"index\",\"type\":\"int\",\"doc\":\"Field index in the frame. Position in the frame\"},{\"name\":\"fieldTypeId\",\"type\":\"int\",\"doc\":\"Field Type identifier\"},{\"name\":\"fieldName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Duplicated with respect to Field Type Definition\"},{\"name\":\"value\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Value of the field\"}]}},\"doc\":\"List of field values (TM points values)\"},{\"name\":\"oolFlag\",\"type\":\"boolean\",\"doc\":\"Flag that indicates whether a fied is OOL\"},{\"name\":\"oolFields\",\"type\":[\"null\",{\"type\":\"array\",\"items\":\"int\"}],\"doc\":\"List of fields that are in OOL state\"}]}}],\"doc\":\"List of group of field values (TM points values)\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Identifier of the frame */
  @Deprecated public int id;
  /** Frame Type identifier */
  @Deprecated public int frameTypeId;
  /** Milliseconds since 1 Jan 1970 */
  @Deprecated public long creationTime;
  /** List of group of field values (TM points values) */
  @Deprecated public java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField> groups;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public ProcessedFrame() {}

  /**
   * All-args constructor.
   * @param id Identifier of the frame
   * @param frameTypeId Frame Type identifier
   * @param creationTime Milliseconds since 1 Jan 1970
   * @param groups List of group of field values (TM points values)
   */
  public ProcessedFrame(java.lang.Integer id, java.lang.Integer frameTypeId, java.lang.Long creationTime, java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField> groups) {
    this.id = id;
    this.frameTypeId = frameTypeId;
    this.creationTime = creationTime;
    this.groups = groups;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return id;
    case 1: return frameTypeId;
    case 2: return creationTime;
    case 3: return groups;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: id = (java.lang.Integer)value$; break;
    case 1: frameTypeId = (java.lang.Integer)value$; break;
    case 2: creationTime = (java.lang.Long)value$; break;
    case 3: groups = (java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField>)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'id' field.
   * @return Identifier of the frame
   */
  public java.lang.Integer getId() {
    return id;
  }

  /**
   * Sets the value of the 'id' field.
   * Identifier of the frame
   * @param value the value to set.
   */
  public void setId(java.lang.Integer value) {
    this.id = value;
  }

  /**
   * Gets the value of the 'frameTypeId' field.
   * @return Frame Type identifier
   */
  public java.lang.Integer getFrameTypeId() {
    return frameTypeId;
  }

  /**
   * Sets the value of the 'frameTypeId' field.
   * Frame Type identifier
   * @param value the value to set.
   */
  public void setFrameTypeId(java.lang.Integer value) {
    this.frameTypeId = value;
  }

  /**
   * Gets the value of the 'creationTime' field.
   * @return Milliseconds since 1 Jan 1970
   */
  public java.lang.Long getCreationTime() {
    return creationTime;
  }

  /**
   * Sets the value of the 'creationTime' field.
   * Milliseconds since 1 Jan 1970
   * @param value the value to set.
   */
  public void setCreationTime(java.lang.Long value) {
    this.creationTime = value;
  }

  /**
   * Gets the value of the 'groups' field.
   * @return List of group of field values (TM points values)
   */
  public java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField> getGroups() {
    return groups;
  }

  /**
   * Sets the value of the 'groups' field.
   * List of group of field values (TM points values)
   * @param value the value to set.
   */
  public void setGroups(java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField> value) {
    this.groups = value;
  }

  /**
   * Creates a new ProcessedFrame RecordBuilder.
   * @return A new ProcessedFrame RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder();
  }

  /**
   * Creates a new ProcessedFrame RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new ProcessedFrame RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder(other);
  }

  /**
   * Creates a new ProcessedFrame RecordBuilder by copying an existing ProcessedFrame instance.
   * @param other The existing instance to copy.
   * @return A new ProcessedFrame RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.ProcessedFrame other) {
    return new com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder(other);
  }

  /**
   * RecordBuilder for ProcessedFrame instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<ProcessedFrame>
    implements org.apache.avro.data.RecordBuilder<ProcessedFrame> {

    /** Identifier of the frame */
    private int id;
    /** Frame Type identifier */
    private int frameTypeId;
    /** Milliseconds since 1 Jan 1970 */
    private long creationTime;
    /** List of group of field values (TM points values) */
    private java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField> groups;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.id)) {
        this.id = data().deepCopy(fields()[0].schema(), other.id);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.frameTypeId)) {
        this.frameTypeId = data().deepCopy(fields()[1].schema(), other.frameTypeId);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.creationTime)) {
        this.creationTime = data().deepCopy(fields()[2].schema(), other.creationTime);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.groups)) {
        this.groups = data().deepCopy(fields()[3].schema(), other.groups);
        fieldSetFlags()[3] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing ProcessedFrame instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.ProcessedFrame other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.id)) {
        this.id = data().deepCopy(fields()[0].schema(), other.id);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.frameTypeId)) {
        this.frameTypeId = data().deepCopy(fields()[1].schema(), other.frameTypeId);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.creationTime)) {
        this.creationTime = data().deepCopy(fields()[2].schema(), other.creationTime);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.groups)) {
        this.groups = data().deepCopy(fields()[3].schema(), other.groups);
        fieldSetFlags()[3] = true;
      }
    }

    /**
      * Gets the value of the 'id' field.
      * Identifier of the frame
      * @return The value.
      */
    public java.lang.Integer getId() {
      return id;
    }

    /**
      * Sets the value of the 'id' field.
      * Identifier of the frame
      * @param value The value of 'id'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder setId(int value) {
      validate(fields()[0], value);
      this.id = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'id' field has been set.
      * Identifier of the frame
      * @return True if the 'id' field has been set, false otherwise.
      */
    public boolean hasId() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'id' field.
      * Identifier of the frame
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder clearId() {
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'frameTypeId' field.
      * Frame Type identifier
      * @return The value.
      */
    public java.lang.Integer getFrameTypeId() {
      return frameTypeId;
    }

    /**
      * Sets the value of the 'frameTypeId' field.
      * Frame Type identifier
      * @param value The value of 'frameTypeId'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder setFrameTypeId(int value) {
      validate(fields()[1], value);
      this.frameTypeId = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'frameTypeId' field has been set.
      * Frame Type identifier
      * @return True if the 'frameTypeId' field has been set, false otherwise.
      */
    public boolean hasFrameTypeId() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'frameTypeId' field.
      * Frame Type identifier
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder clearFrameTypeId() {
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'creationTime' field.
      * Milliseconds since 1 Jan 1970
      * @return The value.
      */
    public java.lang.Long getCreationTime() {
      return creationTime;
    }

    /**
      * Sets the value of the 'creationTime' field.
      * Milliseconds since 1 Jan 1970
      * @param value The value of 'creationTime'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder setCreationTime(long value) {
      validate(fields()[2], value);
      this.creationTime = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'creationTime' field has been set.
      * Milliseconds since 1 Jan 1970
      * @return True if the 'creationTime' field has been set, false otherwise.
      */
    public boolean hasCreationTime() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'creationTime' field.
      * Milliseconds since 1 Jan 1970
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder clearCreationTime() {
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'groups' field.
      * List of group of field values (TM points values)
      * @return The value.
      */
    public java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField> getGroups() {
      return groups;
    }

    /**
      * Sets the value of the 'groups' field.
      * List of group of field values (TM points values)
      * @param value The value of 'groups'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder setGroups(java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField> value) {
      validate(fields()[3], value);
      this.groups = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'groups' field has been set.
      * List of group of field values (TM points values)
      * @return True if the 'groups' field has been set, false otherwise.
      */
    public boolean hasGroups() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'groups' field.
      * List of group of field values (TM points values)
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.ProcessedFrame.Builder clearGroups() {
      groups = null;
      fieldSetFlags()[3] = false;
      return this;
    }

    @Override
    public ProcessedFrame build() {
      try {
        ProcessedFrame record = new ProcessedFrame();
        record.id = fieldSetFlags()[0] ? this.id : (java.lang.Integer) defaultValue(fields()[0]);
        record.frameTypeId = fieldSetFlags()[1] ? this.frameTypeId : (java.lang.Integer) defaultValue(fields()[1]);
        record.creationTime = fieldSetFlags()[2] ? this.creationTime : (java.lang.Long) defaultValue(fields()[2]);
        record.groups = fieldSetFlags()[3] ? this.groups : (java.util.List<com.incomplete.cubegs.common.avro.messages.GroupProcessedField>) defaultValue(fields()[3]);
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
