/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** Calibration function. It will apply to a TM Parameter */
@org.apache.avro.specific.AvroGenerated
public class Calibration extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 7000951370987631811L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"Calibration\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"Calibration function. It will apply to a TM Parameter\",\"fields\":[{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the Calibration function\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the Calibration function\"},{\"name\":\"calibrationType\",\"type\":{\"type\":\"enum\",\"name\":\"TmCalibrationTypeEnum\",\"symbols\":[\"TM_CALIBRATION_ENUMERATION\",\"TM_CALIBRATION_POLYNOMIAL\",\"TM_CALIBRATION_SPLINE\",\"TM_CALIBRATION_EXPRESSION\"]},\"doc\":\"Calibration types\"},{\"name\":\"subsystem\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Subsystem name\"},{\"name\":\"listCalibrationItems\",\"type\":{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"CalibrationItem\",\"doc\":\"Calibration Item. It contains an item of a Calibration function\",\"fields\":[{\"name\":\"calibration1\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"First calibration value\"},{\"name\":\"calibration2\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Second calibration value\"},{\"name\":\"calibration2_text\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Descriptin of Second calibration value\"}]}},\"doc\":\"List of Calibration items\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Name of the Calibration function */
  @Deprecated public java.lang.String name;
  /** Description of the Calibration function */
  @Deprecated public java.lang.String description;
  /** Calibration types */
  @Deprecated public com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum calibrationType;
  /** Subsystem name */
  @Deprecated public java.lang.String subsystem;
  /** List of Calibration items */
  @Deprecated public java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem> listCalibrationItems;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public Calibration() {}

  /**
   * All-args constructor.
   * @param name Name of the Calibration function
   * @param description Description of the Calibration function
   * @param calibrationType Calibration types
   * @param subsystem Subsystem name
   * @param listCalibrationItems List of Calibration items
   */
  public Calibration(java.lang.String name, java.lang.String description, com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum calibrationType, java.lang.String subsystem, java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem> listCalibrationItems) {
    this.name = name;
    this.description = description;
    this.calibrationType = calibrationType;
    this.subsystem = subsystem;
    this.listCalibrationItems = listCalibrationItems;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return name;
    case 1: return description;
    case 2: return calibrationType;
    case 3: return subsystem;
    case 4: return listCalibrationItems;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: name = (java.lang.String)value$; break;
    case 1: description = (java.lang.String)value$; break;
    case 2: calibrationType = (com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum)value$; break;
    case 3: subsystem = (java.lang.String)value$; break;
    case 4: listCalibrationItems = (java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem>)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'name' field.
   * @return Name of the Calibration function
   */
  public java.lang.String getName() {
    return name;
  }

  /**
   * Sets the value of the 'name' field.
   * Name of the Calibration function
   * @param value the value to set.
   */
  public void setName(java.lang.String value) {
    this.name = value;
  }

  /**
   * Gets the value of the 'description' field.
   * @return Description of the Calibration function
   */
  public java.lang.String getDescription() {
    return description;
  }

  /**
   * Sets the value of the 'description' field.
   * Description of the Calibration function
   * @param value the value to set.
   */
  public void setDescription(java.lang.String value) {
    this.description = value;
  }

  /**
   * Gets the value of the 'calibrationType' field.
   * @return Calibration types
   */
  public com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum getCalibrationType() {
    return calibrationType;
  }

  /**
   * Sets the value of the 'calibrationType' field.
   * Calibration types
   * @param value the value to set.
   */
  public void setCalibrationType(com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum value) {
    this.calibrationType = value;
  }

  /**
   * Gets the value of the 'subsystem' field.
   * @return Subsystem name
   */
  public java.lang.String getSubsystem() {
    return subsystem;
  }

  /**
   * Sets the value of the 'subsystem' field.
   * Subsystem name
   * @param value the value to set.
   */
  public void setSubsystem(java.lang.String value) {
    this.subsystem = value;
  }

  /**
   * Gets the value of the 'listCalibrationItems' field.
   * @return List of Calibration items
   */
  public java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem> getListCalibrationItems() {
    return listCalibrationItems;
  }

  /**
   * Sets the value of the 'listCalibrationItems' field.
   * List of Calibration items
   * @param value the value to set.
   */
  public void setListCalibrationItems(java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem> value) {
    this.listCalibrationItems = value;
  }

  /**
   * Creates a new Calibration RecordBuilder.
   * @return A new Calibration RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Calibration.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.Calibration.Builder();
  }

  /**
   * Creates a new Calibration RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new Calibration RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Calibration.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Calibration.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.Calibration.Builder(other);
  }

  /**
   * Creates a new Calibration RecordBuilder by copying an existing Calibration instance.
   * @param other The existing instance to copy.
   * @return A new Calibration RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Calibration.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Calibration other) {
    return new com.incomplete.cubegs.common.avro.messages.Calibration.Builder(other);
  }

  /**
   * RecordBuilder for Calibration instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<Calibration>
    implements org.apache.avro.data.RecordBuilder<Calibration> {

    /** Name of the Calibration function */
    private java.lang.String name;
    /** Description of the Calibration function */
    private java.lang.String description;
    /** Calibration types */
    private com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum calibrationType;
    /** Subsystem name */
    private java.lang.String subsystem;
    /** List of Calibration items */
    private java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem> listCalibrationItems;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Calibration.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.name)) {
        this.name = data().deepCopy(fields()[0].schema(), other.name);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.description)) {
        this.description = data().deepCopy(fields()[1].schema(), other.description);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.calibrationType)) {
        this.calibrationType = data().deepCopy(fields()[2].schema(), other.calibrationType);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.subsystem)) {
        this.subsystem = data().deepCopy(fields()[3].schema(), other.subsystem);
        fieldSetFlags()[3] = true;
      }
      if (isValidValue(fields()[4], other.listCalibrationItems)) {
        this.listCalibrationItems = data().deepCopy(fields()[4].schema(), other.listCalibrationItems);
        fieldSetFlags()[4] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing Calibration instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Calibration other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.name)) {
        this.name = data().deepCopy(fields()[0].schema(), other.name);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.description)) {
        this.description = data().deepCopy(fields()[1].schema(), other.description);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.calibrationType)) {
        this.calibrationType = data().deepCopy(fields()[2].schema(), other.calibrationType);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.subsystem)) {
        this.subsystem = data().deepCopy(fields()[3].schema(), other.subsystem);
        fieldSetFlags()[3] = true;
      }
      if (isValidValue(fields()[4], other.listCalibrationItems)) {
        this.listCalibrationItems = data().deepCopy(fields()[4].schema(), other.listCalibrationItems);
        fieldSetFlags()[4] = true;
      }
    }

    /**
      * Gets the value of the 'name' field.
      * Name of the Calibration function
      * @return The value.
      */
    public java.lang.String getName() {
      return name;
    }

    /**
      * Sets the value of the 'name' field.
      * Name of the Calibration function
      * @param value The value of 'name'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder setName(java.lang.String value) {
      validate(fields()[0], value);
      this.name = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'name' field has been set.
      * Name of the Calibration function
      * @return True if the 'name' field has been set, false otherwise.
      */
    public boolean hasName() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'name' field.
      * Name of the Calibration function
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder clearName() {
      name = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'description' field.
      * Description of the Calibration function
      * @return The value.
      */
    public java.lang.String getDescription() {
      return description;
    }

    /**
      * Sets the value of the 'description' field.
      * Description of the Calibration function
      * @param value The value of 'description'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder setDescription(java.lang.String value) {
      validate(fields()[1], value);
      this.description = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'description' field has been set.
      * Description of the Calibration function
      * @return True if the 'description' field has been set, false otherwise.
      */
    public boolean hasDescription() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'description' field.
      * Description of the Calibration function
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder clearDescription() {
      description = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'calibrationType' field.
      * Calibration types
      * @return The value.
      */
    public com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum getCalibrationType() {
      return calibrationType;
    }

    /**
      * Sets the value of the 'calibrationType' field.
      * Calibration types
      * @param value The value of 'calibrationType'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder setCalibrationType(com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum value) {
      validate(fields()[2], value);
      this.calibrationType = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'calibrationType' field has been set.
      * Calibration types
      * @return True if the 'calibrationType' field has been set, false otherwise.
      */
    public boolean hasCalibrationType() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'calibrationType' field.
      * Calibration types
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder clearCalibrationType() {
      calibrationType = null;
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'subsystem' field.
      * Subsystem name
      * @return The value.
      */
    public java.lang.String getSubsystem() {
      return subsystem;
    }

    /**
      * Sets the value of the 'subsystem' field.
      * Subsystem name
      * @param value The value of 'subsystem'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder setSubsystem(java.lang.String value) {
      validate(fields()[3], value);
      this.subsystem = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'subsystem' field has been set.
      * Subsystem name
      * @return True if the 'subsystem' field has been set, false otherwise.
      */
    public boolean hasSubsystem() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'subsystem' field.
      * Subsystem name
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder clearSubsystem() {
      subsystem = null;
      fieldSetFlags()[3] = false;
      return this;
    }

    /**
      * Gets the value of the 'listCalibrationItems' field.
      * List of Calibration items
      * @return The value.
      */
    public java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem> getListCalibrationItems() {
      return listCalibrationItems;
    }

    /**
      * Sets the value of the 'listCalibrationItems' field.
      * List of Calibration items
      * @param value The value of 'listCalibrationItems'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder setListCalibrationItems(java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem> value) {
      validate(fields()[4], value);
      this.listCalibrationItems = value;
      fieldSetFlags()[4] = true;
      return this;
    }

    /**
      * Checks whether the 'listCalibrationItems' field has been set.
      * List of Calibration items
      * @return True if the 'listCalibrationItems' field has been set, false otherwise.
      */
    public boolean hasListCalibrationItems() {
      return fieldSetFlags()[4];
    }


    /**
      * Clears the value of the 'listCalibrationItems' field.
      * List of Calibration items
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Calibration.Builder clearListCalibrationItems() {
      listCalibrationItems = null;
      fieldSetFlags()[4] = false;
      return this;
    }

    @Override
    public Calibration build() {
      try {
        Calibration record = new Calibration();
        record.name = fieldSetFlags()[0] ? this.name : (java.lang.String) defaultValue(fields()[0]);
        record.description = fieldSetFlags()[1] ? this.description : (java.lang.String) defaultValue(fields()[1]);
        record.calibrationType = fieldSetFlags()[2] ? this.calibrationType : (com.incomplete.cubegs.common.avro.messages.TmCalibrationTypeEnum) defaultValue(fields()[2]);
        record.subsystem = fieldSetFlags()[3] ? this.subsystem : (java.lang.String) defaultValue(fields()[3]);
        record.listCalibrationItems = fieldSetFlags()[4] ? this.listCalibrationItems : (java.util.List<com.incomplete.cubegs.common.avro.messages.CalibrationItem>) defaultValue(fields()[4]);
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
