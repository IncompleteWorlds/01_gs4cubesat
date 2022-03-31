/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This structure defines a field of a TM Frame */
@org.apache.avro.specific.AvroGenerated
public class TM_FrameField extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 3338280441084872386L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"TM_FrameField\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This structure defines a field of a TM Frame\",\"fields\":[{\"name\":\"frameName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the TM Frame this condition belongs to\"},{\"name\":\"parameterName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the parameter\"},{\"name\":\"relativePosition\",\"type\":\"int\",\"doc\":\"Start position of the parameter in the Container, in bits\"},{\"name\":\"sequenceNumber\",\"type\":\"int\",\"doc\":\"Index of the field inside of the sequence that composes the frame\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Name of the TM Frame this condition belongs to */
  @Deprecated public java.lang.String frameName;
  /** Name of the parameter */
  @Deprecated public java.lang.String parameterName;
  /** Start position of the parameter in the Container, in bits */
  @Deprecated public int relativePosition;
  /** Index of the field inside of the sequence that composes the frame */
  @Deprecated public int sequenceNumber;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public TM_FrameField() {}

  /**
   * All-args constructor.
   * @param frameName Name of the TM Frame this condition belongs to
   * @param parameterName Name of the parameter
   * @param relativePosition Start position of the parameter in the Container, in bits
   * @param sequenceNumber Index of the field inside of the sequence that composes the frame
   */
  public TM_FrameField(java.lang.String frameName, java.lang.String parameterName, java.lang.Integer relativePosition, java.lang.Integer sequenceNumber) {
    this.frameName = frameName;
    this.parameterName = parameterName;
    this.relativePosition = relativePosition;
    this.sequenceNumber = sequenceNumber;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return frameName;
    case 1: return parameterName;
    case 2: return relativePosition;
    case 3: return sequenceNumber;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: frameName = (java.lang.String)value$; break;
    case 1: parameterName = (java.lang.String)value$; break;
    case 2: relativePosition = (java.lang.Integer)value$; break;
    case 3: sequenceNumber = (java.lang.Integer)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'frameName' field.
   * @return Name of the TM Frame this condition belongs to
   */
  public java.lang.String getFrameName() {
    return frameName;
  }

  /**
   * Sets the value of the 'frameName' field.
   * Name of the TM Frame this condition belongs to
   * @param value the value to set.
   */
  public void setFrameName(java.lang.String value) {
    this.frameName = value;
  }

  /**
   * Gets the value of the 'parameterName' field.
   * @return Name of the parameter
   */
  public java.lang.String getParameterName() {
    return parameterName;
  }

  /**
   * Sets the value of the 'parameterName' field.
   * Name of the parameter
   * @param value the value to set.
   */
  public void setParameterName(java.lang.String value) {
    this.parameterName = value;
  }

  /**
   * Gets the value of the 'relativePosition' field.
   * @return Start position of the parameter in the Container, in bits
   */
  public java.lang.Integer getRelativePosition() {
    return relativePosition;
  }

  /**
   * Sets the value of the 'relativePosition' field.
   * Start position of the parameter in the Container, in bits
   * @param value the value to set.
   */
  public void setRelativePosition(java.lang.Integer value) {
    this.relativePosition = value;
  }

  /**
   * Gets the value of the 'sequenceNumber' field.
   * @return Index of the field inside of the sequence that composes the frame
   */
  public java.lang.Integer getSequenceNumber() {
    return sequenceNumber;
  }

  /**
   * Sets the value of the 'sequenceNumber' field.
   * Index of the field inside of the sequence that composes the frame
   * @param value the value to set.
   */
  public void setSequenceNumber(java.lang.Integer value) {
    this.sequenceNumber = value;
  }

  /**
   * Creates a new TM_FrameField RecordBuilder.
   * @return A new TM_FrameField RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder();
  }

  /**
   * Creates a new TM_FrameField RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new TM_FrameField RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder(other);
  }

  /**
   * Creates a new TM_FrameField RecordBuilder by copying an existing TM_FrameField instance.
   * @param other The existing instance to copy.
   * @return A new TM_FrameField RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.TM_FrameField other) {
    return new com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder(other);
  }

  /**
   * RecordBuilder for TM_FrameField instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<TM_FrameField>
    implements org.apache.avro.data.RecordBuilder<TM_FrameField> {

    /** Name of the TM Frame this condition belongs to */
    private java.lang.String frameName;
    /** Name of the parameter */
    private java.lang.String parameterName;
    /** Start position of the parameter in the Container, in bits */
    private int relativePosition;
    /** Index of the field inside of the sequence that composes the frame */
    private int sequenceNumber;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.frameName)) {
        this.frameName = data().deepCopy(fields()[0].schema(), other.frameName);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.parameterName)) {
        this.parameterName = data().deepCopy(fields()[1].schema(), other.parameterName);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.relativePosition)) {
        this.relativePosition = data().deepCopy(fields()[2].schema(), other.relativePosition);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.sequenceNumber)) {
        this.sequenceNumber = data().deepCopy(fields()[3].schema(), other.sequenceNumber);
        fieldSetFlags()[3] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing TM_FrameField instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.TM_FrameField other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.frameName)) {
        this.frameName = data().deepCopy(fields()[0].schema(), other.frameName);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.parameterName)) {
        this.parameterName = data().deepCopy(fields()[1].schema(), other.parameterName);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.relativePosition)) {
        this.relativePosition = data().deepCopy(fields()[2].schema(), other.relativePosition);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.sequenceNumber)) {
        this.sequenceNumber = data().deepCopy(fields()[3].schema(), other.sequenceNumber);
        fieldSetFlags()[3] = true;
      }
    }

    /**
      * Gets the value of the 'frameName' field.
      * Name of the TM Frame this condition belongs to
      * @return The value.
      */
    public java.lang.String getFrameName() {
      return frameName;
    }

    /**
      * Sets the value of the 'frameName' field.
      * Name of the TM Frame this condition belongs to
      * @param value The value of 'frameName'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder setFrameName(java.lang.String value) {
      validate(fields()[0], value);
      this.frameName = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'frameName' field has been set.
      * Name of the TM Frame this condition belongs to
      * @return True if the 'frameName' field has been set, false otherwise.
      */
    public boolean hasFrameName() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'frameName' field.
      * Name of the TM Frame this condition belongs to
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder clearFrameName() {
      frameName = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'parameterName' field.
      * Name of the parameter
      * @return The value.
      */
    public java.lang.String getParameterName() {
      return parameterName;
    }

    /**
      * Sets the value of the 'parameterName' field.
      * Name of the parameter
      * @param value The value of 'parameterName'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder setParameterName(java.lang.String value) {
      validate(fields()[1], value);
      this.parameterName = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'parameterName' field has been set.
      * Name of the parameter
      * @return True if the 'parameterName' field has been set, false otherwise.
      */
    public boolean hasParameterName() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'parameterName' field.
      * Name of the parameter
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder clearParameterName() {
      parameterName = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'relativePosition' field.
      * Start position of the parameter in the Container, in bits
      * @return The value.
      */
    public java.lang.Integer getRelativePosition() {
      return relativePosition;
    }

    /**
      * Sets the value of the 'relativePosition' field.
      * Start position of the parameter in the Container, in bits
      * @param value The value of 'relativePosition'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder setRelativePosition(int value) {
      validate(fields()[2], value);
      this.relativePosition = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'relativePosition' field has been set.
      * Start position of the parameter in the Container, in bits
      * @return True if the 'relativePosition' field has been set, false otherwise.
      */
    public boolean hasRelativePosition() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'relativePosition' field.
      * Start position of the parameter in the Container, in bits
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder clearRelativePosition() {
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'sequenceNumber' field.
      * Index of the field inside of the sequence that composes the frame
      * @return The value.
      */
    public java.lang.Integer getSequenceNumber() {
      return sequenceNumber;
    }

    /**
      * Sets the value of the 'sequenceNumber' field.
      * Index of the field inside of the sequence that composes the frame
      * @param value The value of 'sequenceNumber'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder setSequenceNumber(int value) {
      validate(fields()[3], value);
      this.sequenceNumber = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'sequenceNumber' field has been set.
      * Index of the field inside of the sequence that composes the frame
      * @return True if the 'sequenceNumber' field has been set, false otherwise.
      */
    public boolean hasSequenceNumber() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'sequenceNumber' field.
      * Index of the field inside of the sequence that composes the frame
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_FrameField.Builder clearSequenceNumber() {
      fieldSetFlags()[3] = false;
      return this;
    }

    @Override
    public TM_FrameField build() {
      try {
        TM_FrameField record = new TM_FrameField();
        record.frameName = fieldSetFlags()[0] ? this.frameName : (java.lang.String) defaultValue(fields()[0]);
        record.parameterName = fieldSetFlags()[1] ? this.parameterName : (java.lang.String) defaultValue(fields()[1]);
        record.relativePosition = fieldSetFlags()[2] ? this.relativePosition : (java.lang.Integer) defaultValue(fields()[2]);
        record.sequenceNumber = fieldSetFlags()[3] ? this.sequenceNumber : (java.lang.Integer) defaultValue(fields()[3]);
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
