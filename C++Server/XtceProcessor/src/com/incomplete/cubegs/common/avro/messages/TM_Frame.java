/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This record contains the definition of a TM Frame (aka Container), at application level protocol */
@org.apache.avro.specific.AvroGenerated
public class TM_Frame extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 518668363894533073L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"TM_Frame\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This record contains the definition of a TM Frame (aka Container), at application level protocol\",\"fields\":[{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of Frame Type\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of Frame Type\"},{\"name\":\"expectedInterval\",\"type\":\"int\",\"doc\":\"Expected interval in milliseconds\"},{\"name\":\"lengthBits\",\"type\":\"int\",\"doc\":\"Length of frame in bits. Padding to the right\"},{\"name\":\"flag\",\"type\":{\"type\":\"enum\",\"name\":\"TmFrameFlagEnum\",\"symbols\":[\"TM_FRAME_ARCHIVE\",\"TM_FRAME_LITTLE_ENDIAN\"]},\"doc\":\"Field value subtypes\"},{\"name\":\"frameConditions\",\"type\":[\"null\",{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"TM_FrameCondition\",\"doc\":\"Definition of a Condition that a TM Frame shall meet\",\"fields\":[{\"name\":\"frameName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the TM Frame this condition belongs to\"},{\"name\":\"parameterName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the parameter\"},{\"name\":\"parameterValue\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Value the parameter must have\"}]}}],\"doc\":\"List of TM Frame conditions\"},{\"name\":\"tmFields\",\"type\":{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"TM_FrameField\",\"doc\":\"This structure defines a field of a TM Frame\",\"fields\":[{\"name\":\"frameName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the TM Frame this condition belongs to\"},{\"name\":\"parameterName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the parameter\"},{\"name\":\"relativePosition\",\"type\":\"int\",\"doc\":\"Start position of the parameter in the Container, in bits\"},{\"name\":\"sequenceNumber\",\"type\":\"int\",\"doc\":\"Index of the field inside of the sequence that composes the frame\"}]}},\"doc\":\"List of TM Field\"},{\"name\":\"layerName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Layer identifier the frame belongs to\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Name of Frame Type */
  @Deprecated public java.lang.String name;
  /** Description of Frame Type */
  @Deprecated public java.lang.String description;
  /** Expected interval in milliseconds */
  @Deprecated public int expectedInterval;
  /** Length of frame in bits. Padding to the right */
  @Deprecated public int lengthBits;
  /** Field value subtypes */
  @Deprecated public com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum flag;
  /** List of TM Frame conditions */
  @Deprecated public java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition> frameConditions;
  /** List of TM Field */
  @Deprecated public java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField> tmFields;
  /** Layer identifier the frame belongs to */
  @Deprecated public java.lang.String layerName;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public TM_Frame() {}

  /**
   * All-args constructor.
   * @param name Name of Frame Type
   * @param description Description of Frame Type
   * @param expectedInterval Expected interval in milliseconds
   * @param lengthBits Length of frame in bits. Padding to the right
   * @param flag Field value subtypes
   * @param frameConditions List of TM Frame conditions
   * @param tmFields List of TM Field
   * @param layerName Layer identifier the frame belongs to
   */
  public TM_Frame(java.lang.String name, java.lang.String description, java.lang.Integer expectedInterval, java.lang.Integer lengthBits, com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum flag, java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition> frameConditions, java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField> tmFields, java.lang.String layerName) {
    this.name = name;
    this.description = description;
    this.expectedInterval = expectedInterval;
    this.lengthBits = lengthBits;
    this.flag = flag;
    this.frameConditions = frameConditions;
    this.tmFields = tmFields;
    this.layerName = layerName;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return name;
    case 1: return description;
    case 2: return expectedInterval;
    case 3: return lengthBits;
    case 4: return flag;
    case 5: return frameConditions;
    case 6: return tmFields;
    case 7: return layerName;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: name = (java.lang.String)value$; break;
    case 1: description = (java.lang.String)value$; break;
    case 2: expectedInterval = (java.lang.Integer)value$; break;
    case 3: lengthBits = (java.lang.Integer)value$; break;
    case 4: flag = (com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum)value$; break;
    case 5: frameConditions = (java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition>)value$; break;
    case 6: tmFields = (java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField>)value$; break;
    case 7: layerName = (java.lang.String)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'name' field.
   * @return Name of Frame Type
   */
  public java.lang.String getName() {
    return name;
  }

  /**
   * Sets the value of the 'name' field.
   * Name of Frame Type
   * @param value the value to set.
   */
  public void setName(java.lang.String value) {
    this.name = value;
  }

  /**
   * Gets the value of the 'description' field.
   * @return Description of Frame Type
   */
  public java.lang.String getDescription() {
    return description;
  }

  /**
   * Sets the value of the 'description' field.
   * Description of Frame Type
   * @param value the value to set.
   */
  public void setDescription(java.lang.String value) {
    this.description = value;
  }

  /**
   * Gets the value of the 'expectedInterval' field.
   * @return Expected interval in milliseconds
   */
  public java.lang.Integer getExpectedInterval() {
    return expectedInterval;
  }

  /**
   * Sets the value of the 'expectedInterval' field.
   * Expected interval in milliseconds
   * @param value the value to set.
   */
  public void setExpectedInterval(java.lang.Integer value) {
    this.expectedInterval = value;
  }

  /**
   * Gets the value of the 'lengthBits' field.
   * @return Length of frame in bits. Padding to the right
   */
  public java.lang.Integer getLengthBits() {
    return lengthBits;
  }

  /**
   * Sets the value of the 'lengthBits' field.
   * Length of frame in bits. Padding to the right
   * @param value the value to set.
   */
  public void setLengthBits(java.lang.Integer value) {
    this.lengthBits = value;
  }

  /**
   * Gets the value of the 'flag' field.
   * @return Field value subtypes
   */
  public com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum getFlag() {
    return flag;
  }

  /**
   * Sets the value of the 'flag' field.
   * Field value subtypes
   * @param value the value to set.
   */
  public void setFlag(com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum value) {
    this.flag = value;
  }

  /**
   * Gets the value of the 'frameConditions' field.
   * @return List of TM Frame conditions
   */
  public java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition> getFrameConditions() {
    return frameConditions;
  }

  /**
   * Sets the value of the 'frameConditions' field.
   * List of TM Frame conditions
   * @param value the value to set.
   */
  public void setFrameConditions(java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition> value) {
    this.frameConditions = value;
  }

  /**
   * Gets the value of the 'tmFields' field.
   * @return List of TM Field
   */
  public java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField> getTmFields() {
    return tmFields;
  }

  /**
   * Sets the value of the 'tmFields' field.
   * List of TM Field
   * @param value the value to set.
   */
  public void setTmFields(java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField> value) {
    this.tmFields = value;
  }

  /**
   * Gets the value of the 'layerName' field.
   * @return Layer identifier the frame belongs to
   */
  public java.lang.String getLayerName() {
    return layerName;
  }

  /**
   * Sets the value of the 'layerName' field.
   * Layer identifier the frame belongs to
   * @param value the value to set.
   */
  public void setLayerName(java.lang.String value) {
    this.layerName = value;
  }

  /**
   * Creates a new TM_Frame RecordBuilder.
   * @return A new TM_Frame RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder();
  }

  /**
   * Creates a new TM_Frame RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new TM_Frame RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder(other);
  }

  /**
   * Creates a new TM_Frame RecordBuilder by copying an existing TM_Frame instance.
   * @param other The existing instance to copy.
   * @return A new TM_Frame RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.TM_Frame other) {
    return new com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder(other);
  }

  /**
   * RecordBuilder for TM_Frame instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<TM_Frame>
    implements org.apache.avro.data.RecordBuilder<TM_Frame> {

    /** Name of Frame Type */
    private java.lang.String name;
    /** Description of Frame Type */
    private java.lang.String description;
    /** Expected interval in milliseconds */
    private int expectedInterval;
    /** Length of frame in bits. Padding to the right */
    private int lengthBits;
    /** Field value subtypes */
    private com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum flag;
    /** List of TM Frame conditions */
    private java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition> frameConditions;
    /** List of TM Field */
    private java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField> tmFields;
    /** Layer identifier the frame belongs to */
    private java.lang.String layerName;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.name)) {
        this.name = data().deepCopy(fields()[0].schema(), other.name);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.description)) {
        this.description = data().deepCopy(fields()[1].schema(), other.description);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.expectedInterval)) {
        this.expectedInterval = data().deepCopy(fields()[2].schema(), other.expectedInterval);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.lengthBits)) {
        this.lengthBits = data().deepCopy(fields()[3].schema(), other.lengthBits);
        fieldSetFlags()[3] = true;
      }
      if (isValidValue(fields()[4], other.flag)) {
        this.flag = data().deepCopy(fields()[4].schema(), other.flag);
        fieldSetFlags()[4] = true;
      }
      if (isValidValue(fields()[5], other.frameConditions)) {
        this.frameConditions = data().deepCopy(fields()[5].schema(), other.frameConditions);
        fieldSetFlags()[5] = true;
      }
      if (isValidValue(fields()[6], other.tmFields)) {
        this.tmFields = data().deepCopy(fields()[6].schema(), other.tmFields);
        fieldSetFlags()[6] = true;
      }
      if (isValidValue(fields()[7], other.layerName)) {
        this.layerName = data().deepCopy(fields()[7].schema(), other.layerName);
        fieldSetFlags()[7] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing TM_Frame instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.TM_Frame other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.name)) {
        this.name = data().deepCopy(fields()[0].schema(), other.name);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.description)) {
        this.description = data().deepCopy(fields()[1].schema(), other.description);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.expectedInterval)) {
        this.expectedInterval = data().deepCopy(fields()[2].schema(), other.expectedInterval);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.lengthBits)) {
        this.lengthBits = data().deepCopy(fields()[3].schema(), other.lengthBits);
        fieldSetFlags()[3] = true;
      }
      if (isValidValue(fields()[4], other.flag)) {
        this.flag = data().deepCopy(fields()[4].schema(), other.flag);
        fieldSetFlags()[4] = true;
      }
      if (isValidValue(fields()[5], other.frameConditions)) {
        this.frameConditions = data().deepCopy(fields()[5].schema(), other.frameConditions);
        fieldSetFlags()[5] = true;
      }
      if (isValidValue(fields()[6], other.tmFields)) {
        this.tmFields = data().deepCopy(fields()[6].schema(), other.tmFields);
        fieldSetFlags()[6] = true;
      }
      if (isValidValue(fields()[7], other.layerName)) {
        this.layerName = data().deepCopy(fields()[7].schema(), other.layerName);
        fieldSetFlags()[7] = true;
      }
    }

    /**
      * Gets the value of the 'name' field.
      * Name of Frame Type
      * @return The value.
      */
    public java.lang.String getName() {
      return name;
    }

    /**
      * Sets the value of the 'name' field.
      * Name of Frame Type
      * @param value The value of 'name'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder setName(java.lang.String value) {
      validate(fields()[0], value);
      this.name = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'name' field has been set.
      * Name of Frame Type
      * @return True if the 'name' field has been set, false otherwise.
      */
    public boolean hasName() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'name' field.
      * Name of Frame Type
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder clearName() {
      name = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'description' field.
      * Description of Frame Type
      * @return The value.
      */
    public java.lang.String getDescription() {
      return description;
    }

    /**
      * Sets the value of the 'description' field.
      * Description of Frame Type
      * @param value The value of 'description'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder setDescription(java.lang.String value) {
      validate(fields()[1], value);
      this.description = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'description' field has been set.
      * Description of Frame Type
      * @return True if the 'description' field has been set, false otherwise.
      */
    public boolean hasDescription() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'description' field.
      * Description of Frame Type
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder clearDescription() {
      description = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'expectedInterval' field.
      * Expected interval in milliseconds
      * @return The value.
      */
    public java.lang.Integer getExpectedInterval() {
      return expectedInterval;
    }

    /**
      * Sets the value of the 'expectedInterval' field.
      * Expected interval in milliseconds
      * @param value The value of 'expectedInterval'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder setExpectedInterval(int value) {
      validate(fields()[2], value);
      this.expectedInterval = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'expectedInterval' field has been set.
      * Expected interval in milliseconds
      * @return True if the 'expectedInterval' field has been set, false otherwise.
      */
    public boolean hasExpectedInterval() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'expectedInterval' field.
      * Expected interval in milliseconds
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder clearExpectedInterval() {
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'lengthBits' field.
      * Length of frame in bits. Padding to the right
      * @return The value.
      */
    public java.lang.Integer getLengthBits() {
      return lengthBits;
    }

    /**
      * Sets the value of the 'lengthBits' field.
      * Length of frame in bits. Padding to the right
      * @param value The value of 'lengthBits'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder setLengthBits(int value) {
      validate(fields()[3], value);
      this.lengthBits = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'lengthBits' field has been set.
      * Length of frame in bits. Padding to the right
      * @return True if the 'lengthBits' field has been set, false otherwise.
      */
    public boolean hasLengthBits() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'lengthBits' field.
      * Length of frame in bits. Padding to the right
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder clearLengthBits() {
      fieldSetFlags()[3] = false;
      return this;
    }

    /**
      * Gets the value of the 'flag' field.
      * Field value subtypes
      * @return The value.
      */
    public com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum getFlag() {
      return flag;
    }

    /**
      * Sets the value of the 'flag' field.
      * Field value subtypes
      * @param value The value of 'flag'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder setFlag(com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum value) {
      validate(fields()[4], value);
      this.flag = value;
      fieldSetFlags()[4] = true;
      return this;
    }

    /**
      * Checks whether the 'flag' field has been set.
      * Field value subtypes
      * @return True if the 'flag' field has been set, false otherwise.
      */
    public boolean hasFlag() {
      return fieldSetFlags()[4];
    }


    /**
      * Clears the value of the 'flag' field.
      * Field value subtypes
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder clearFlag() {
      flag = null;
      fieldSetFlags()[4] = false;
      return this;
    }

    /**
      * Gets the value of the 'frameConditions' field.
      * List of TM Frame conditions
      * @return The value.
      */
    public java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition> getFrameConditions() {
      return frameConditions;
    }

    /**
      * Sets the value of the 'frameConditions' field.
      * List of TM Frame conditions
      * @param value The value of 'frameConditions'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder setFrameConditions(java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition> value) {
      validate(fields()[5], value);
      this.frameConditions = value;
      fieldSetFlags()[5] = true;
      return this;
    }

    /**
      * Checks whether the 'frameConditions' field has been set.
      * List of TM Frame conditions
      * @return True if the 'frameConditions' field has been set, false otherwise.
      */
    public boolean hasFrameConditions() {
      return fieldSetFlags()[5];
    }


    /**
      * Clears the value of the 'frameConditions' field.
      * List of TM Frame conditions
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder clearFrameConditions() {
      frameConditions = null;
      fieldSetFlags()[5] = false;
      return this;
    }

    /**
      * Gets the value of the 'tmFields' field.
      * List of TM Field
      * @return The value.
      */
    public java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField> getTmFields() {
      return tmFields;
    }

    /**
      * Sets the value of the 'tmFields' field.
      * List of TM Field
      * @param value The value of 'tmFields'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder setTmFields(java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField> value) {
      validate(fields()[6], value);
      this.tmFields = value;
      fieldSetFlags()[6] = true;
      return this;
    }

    /**
      * Checks whether the 'tmFields' field has been set.
      * List of TM Field
      * @return True if the 'tmFields' field has been set, false otherwise.
      */
    public boolean hasTmFields() {
      return fieldSetFlags()[6];
    }


    /**
      * Clears the value of the 'tmFields' field.
      * List of TM Field
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder clearTmFields() {
      tmFields = null;
      fieldSetFlags()[6] = false;
      return this;
    }

    /**
      * Gets the value of the 'layerName' field.
      * Layer identifier the frame belongs to
      * @return The value.
      */
    public java.lang.String getLayerName() {
      return layerName;
    }

    /**
      * Sets the value of the 'layerName' field.
      * Layer identifier the frame belongs to
      * @param value The value of 'layerName'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder setLayerName(java.lang.String value) {
      validate(fields()[7], value);
      this.layerName = value;
      fieldSetFlags()[7] = true;
      return this;
    }

    /**
      * Checks whether the 'layerName' field has been set.
      * Layer identifier the frame belongs to
      * @return True if the 'layerName' field has been set, false otherwise.
      */
    public boolean hasLayerName() {
      return fieldSetFlags()[7];
    }


    /**
      * Clears the value of the 'layerName' field.
      * Layer identifier the frame belongs to
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.TM_Frame.Builder clearLayerName() {
      layerName = null;
      fieldSetFlags()[7] = false;
      return this;
    }

    @Override
    public TM_Frame build() {
      try {
        TM_Frame record = new TM_Frame();
        record.name = fieldSetFlags()[0] ? this.name : (java.lang.String) defaultValue(fields()[0]);
        record.description = fieldSetFlags()[1] ? this.description : (java.lang.String) defaultValue(fields()[1]);
        record.expectedInterval = fieldSetFlags()[2] ? this.expectedInterval : (java.lang.Integer) defaultValue(fields()[2]);
        record.lengthBits = fieldSetFlags()[3] ? this.lengthBits : (java.lang.Integer) defaultValue(fields()[3]);
        record.flag = fieldSetFlags()[4] ? this.flag : (com.incomplete.cubegs.common.avro.messages.TmFrameFlagEnum) defaultValue(fields()[4]);
        record.frameConditions = fieldSetFlags()[5] ? this.frameConditions : (java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameCondition>) defaultValue(fields()[5]);
        record.tmFields = fieldSetFlags()[6] ? this.tmFields : (java.util.List<com.incomplete.cubegs.common.avro.messages.TM_FrameField>) defaultValue(fields()[6]);
        record.layerName = fieldSetFlags()[7] ? this.layerName : (java.lang.String) defaultValue(fields()[7]);
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
