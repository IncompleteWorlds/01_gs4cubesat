/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** A pass over a ground station */
@org.apache.avro.specific.AvroGenerated
public class Pass extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 7037560093750538841L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"Pass\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"A pass over a ground station\",\"fields\":[{\"name\":\"identifier\",\"type\":\"int\",\"doc\":\"Unique identifier of the pass\"},{\"name\":\"AOS\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"AOS time. Format: YYYY-MM-DDTHH:mm:SS\"},{\"name\":\"LOS\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"LOS time. Format: YYYY-MM-DDTHH:mm:SS\"},{\"name\":\"duration\",\"type\":\"int\",\"doc\":\"Duration of the pass in seconds\"},{\"name\":\"maxElevation\",\"type\":\"float\",\"doc\":\"Maximum elevation, in decimal degrees\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Unique identifier of the pass */
  @Deprecated public int identifier;
  /** AOS time. Format: YYYY-MM-DDTHH:mm:SS */
  @Deprecated public java.lang.String AOS;
  /** LOS time. Format: YYYY-MM-DDTHH:mm:SS */
  @Deprecated public java.lang.String LOS;
  /** Duration of the pass in seconds */
  @Deprecated public int duration;
  /** Maximum elevation, in decimal degrees */
  @Deprecated public float maxElevation;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public Pass() {}

  /**
   * All-args constructor.
   * @param identifier Unique identifier of the pass
   * @param AOS AOS time. Format: YYYY-MM-DDTHH:mm:SS
   * @param LOS LOS time. Format: YYYY-MM-DDTHH:mm:SS
   * @param duration Duration of the pass in seconds
   * @param maxElevation Maximum elevation, in decimal degrees
   */
  public Pass(java.lang.Integer identifier, java.lang.String AOS, java.lang.String LOS, java.lang.Integer duration, java.lang.Float maxElevation) {
    this.identifier = identifier;
    this.AOS = AOS;
    this.LOS = LOS;
    this.duration = duration;
    this.maxElevation = maxElevation;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return identifier;
    case 1: return AOS;
    case 2: return LOS;
    case 3: return duration;
    case 4: return maxElevation;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: identifier = (java.lang.Integer)value$; break;
    case 1: AOS = (java.lang.String)value$; break;
    case 2: LOS = (java.lang.String)value$; break;
    case 3: duration = (java.lang.Integer)value$; break;
    case 4: maxElevation = (java.lang.Float)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'identifier' field.
   * @return Unique identifier of the pass
   */
  public java.lang.Integer getIdentifier() {
    return identifier;
  }

  /**
   * Sets the value of the 'identifier' field.
   * Unique identifier of the pass
   * @param value the value to set.
   */
  public void setIdentifier(java.lang.Integer value) {
    this.identifier = value;
  }

  /**
   * Gets the value of the 'AOS' field.
   * @return AOS time. Format: YYYY-MM-DDTHH:mm:SS
   */
  public java.lang.String getAOS() {
    return AOS;
  }

  /**
   * Sets the value of the 'AOS' field.
   * AOS time. Format: YYYY-MM-DDTHH:mm:SS
   * @param value the value to set.
   */
  public void setAOS(java.lang.String value) {
    this.AOS = value;
  }

  /**
   * Gets the value of the 'LOS' field.
   * @return LOS time. Format: YYYY-MM-DDTHH:mm:SS
   */
  public java.lang.String getLOS() {
    return LOS;
  }

  /**
   * Sets the value of the 'LOS' field.
   * LOS time. Format: YYYY-MM-DDTHH:mm:SS
   * @param value the value to set.
   */
  public void setLOS(java.lang.String value) {
    this.LOS = value;
  }

  /**
   * Gets the value of the 'duration' field.
   * @return Duration of the pass in seconds
   */
  public java.lang.Integer getDuration() {
    return duration;
  }

  /**
   * Sets the value of the 'duration' field.
   * Duration of the pass in seconds
   * @param value the value to set.
   */
  public void setDuration(java.lang.Integer value) {
    this.duration = value;
  }

  /**
   * Gets the value of the 'maxElevation' field.
   * @return Maximum elevation, in decimal degrees
   */
  public java.lang.Float getMaxElevation() {
    return maxElevation;
  }

  /**
   * Sets the value of the 'maxElevation' field.
   * Maximum elevation, in decimal degrees
   * @param value the value to set.
   */
  public void setMaxElevation(java.lang.Float value) {
    this.maxElevation = value;
  }

  /**
   * Creates a new Pass RecordBuilder.
   * @return A new Pass RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Pass.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.Pass.Builder();
  }

  /**
   * Creates a new Pass RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new Pass RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Pass.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Pass.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.Pass.Builder(other);
  }

  /**
   * Creates a new Pass RecordBuilder by copying an existing Pass instance.
   * @param other The existing instance to copy.
   * @return A new Pass RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Pass.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Pass other) {
    return new com.incomplete.cubegs.common.avro.messages.Pass.Builder(other);
  }

  /**
   * RecordBuilder for Pass instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<Pass>
    implements org.apache.avro.data.RecordBuilder<Pass> {

    /** Unique identifier of the pass */
    private int identifier;
    /** AOS time. Format: YYYY-MM-DDTHH:mm:SS */
    private java.lang.String AOS;
    /** LOS time. Format: YYYY-MM-DDTHH:mm:SS */
    private java.lang.String LOS;
    /** Duration of the pass in seconds */
    private int duration;
    /** Maximum elevation, in decimal degrees */
    private float maxElevation;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Pass.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.identifier)) {
        this.identifier = data().deepCopy(fields()[0].schema(), other.identifier);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.AOS)) {
        this.AOS = data().deepCopy(fields()[1].schema(), other.AOS);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.LOS)) {
        this.LOS = data().deepCopy(fields()[2].schema(), other.LOS);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.duration)) {
        this.duration = data().deepCopy(fields()[3].schema(), other.duration);
        fieldSetFlags()[3] = true;
      }
      if (isValidValue(fields()[4], other.maxElevation)) {
        this.maxElevation = data().deepCopy(fields()[4].schema(), other.maxElevation);
        fieldSetFlags()[4] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing Pass instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Pass other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.identifier)) {
        this.identifier = data().deepCopy(fields()[0].schema(), other.identifier);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.AOS)) {
        this.AOS = data().deepCopy(fields()[1].schema(), other.AOS);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.LOS)) {
        this.LOS = data().deepCopy(fields()[2].schema(), other.LOS);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.duration)) {
        this.duration = data().deepCopy(fields()[3].schema(), other.duration);
        fieldSetFlags()[3] = true;
      }
      if (isValidValue(fields()[4], other.maxElevation)) {
        this.maxElevation = data().deepCopy(fields()[4].schema(), other.maxElevation);
        fieldSetFlags()[4] = true;
      }
    }

    /**
      * Gets the value of the 'identifier' field.
      * Unique identifier of the pass
      * @return The value.
      */
    public java.lang.Integer getIdentifier() {
      return identifier;
    }

    /**
      * Sets the value of the 'identifier' field.
      * Unique identifier of the pass
      * @param value The value of 'identifier'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder setIdentifier(int value) {
      validate(fields()[0], value);
      this.identifier = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'identifier' field has been set.
      * Unique identifier of the pass
      * @return True if the 'identifier' field has been set, false otherwise.
      */
    public boolean hasIdentifier() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'identifier' field.
      * Unique identifier of the pass
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder clearIdentifier() {
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'AOS' field.
      * AOS time. Format: YYYY-MM-DDTHH:mm:SS
      * @return The value.
      */
    public java.lang.String getAOS() {
      return AOS;
    }

    /**
      * Sets the value of the 'AOS' field.
      * AOS time. Format: YYYY-MM-DDTHH:mm:SS
      * @param value The value of 'AOS'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder setAOS(java.lang.String value) {
      validate(fields()[1], value);
      this.AOS = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'AOS' field has been set.
      * AOS time. Format: YYYY-MM-DDTHH:mm:SS
      * @return True if the 'AOS' field has been set, false otherwise.
      */
    public boolean hasAOS() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'AOS' field.
      * AOS time. Format: YYYY-MM-DDTHH:mm:SS
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder clearAOS() {
      AOS = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'LOS' field.
      * LOS time. Format: YYYY-MM-DDTHH:mm:SS
      * @return The value.
      */
    public java.lang.String getLOS() {
      return LOS;
    }

    /**
      * Sets the value of the 'LOS' field.
      * LOS time. Format: YYYY-MM-DDTHH:mm:SS
      * @param value The value of 'LOS'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder setLOS(java.lang.String value) {
      validate(fields()[2], value);
      this.LOS = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'LOS' field has been set.
      * LOS time. Format: YYYY-MM-DDTHH:mm:SS
      * @return True if the 'LOS' field has been set, false otherwise.
      */
    public boolean hasLOS() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'LOS' field.
      * LOS time. Format: YYYY-MM-DDTHH:mm:SS
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder clearLOS() {
      LOS = null;
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'duration' field.
      * Duration of the pass in seconds
      * @return The value.
      */
    public java.lang.Integer getDuration() {
      return duration;
    }

    /**
      * Sets the value of the 'duration' field.
      * Duration of the pass in seconds
      * @param value The value of 'duration'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder setDuration(int value) {
      validate(fields()[3], value);
      this.duration = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'duration' field has been set.
      * Duration of the pass in seconds
      * @return True if the 'duration' field has been set, false otherwise.
      */
    public boolean hasDuration() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'duration' field.
      * Duration of the pass in seconds
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder clearDuration() {
      fieldSetFlags()[3] = false;
      return this;
    }

    /**
      * Gets the value of the 'maxElevation' field.
      * Maximum elevation, in decimal degrees
      * @return The value.
      */
    public java.lang.Float getMaxElevation() {
      return maxElevation;
    }

    /**
      * Sets the value of the 'maxElevation' field.
      * Maximum elevation, in decimal degrees
      * @param value The value of 'maxElevation'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder setMaxElevation(float value) {
      validate(fields()[4], value);
      this.maxElevation = value;
      fieldSetFlags()[4] = true;
      return this;
    }

    /**
      * Checks whether the 'maxElevation' field has been set.
      * Maximum elevation, in decimal degrees
      * @return True if the 'maxElevation' field has been set, false otherwise.
      */
    public boolean hasMaxElevation() {
      return fieldSetFlags()[4];
    }


    /**
      * Clears the value of the 'maxElevation' field.
      * Maximum elevation, in decimal degrees
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Pass.Builder clearMaxElevation() {
      fieldSetFlags()[4] = false;
      return this;
    }

    @Override
    public Pass build() {
      try {
        Pass record = new Pass();
        record.identifier = fieldSetFlags()[0] ? this.identifier : (java.lang.Integer) defaultValue(fields()[0]);
        record.AOS = fieldSetFlags()[1] ? this.AOS : (java.lang.String) defaultValue(fields()[1]);
        record.LOS = fieldSetFlags()[2] ? this.LOS : (java.lang.String) defaultValue(fields()[2]);
        record.duration = fieldSetFlags()[3] ? this.duration : (java.lang.Integer) defaultValue(fields()[3]);
        record.maxElevation = fieldSetFlags()[4] ? this.maxElevation : (java.lang.Float) defaultValue(fields()[4]);
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
