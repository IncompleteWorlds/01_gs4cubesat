/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This message adds a new Satellite to a Mission. It returns a Satellite object */
@org.apache.avro.specific.AvroGenerated
public class MsgAddSatellite extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 5197371576556681825L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"MsgAddSatellite\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This message adds a new Satellite to a Mission. It returns a Satellite object\",\"fields\":[{\"name\":\"authorizationToken\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Authorization token\"},{\"name\":\"missionName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Mission identifier\"},{\"name\":\"satellite\",\"type\":{\"type\":\"record\",\"name\":\"Satellite\",\"doc\":\"This record contains the Satellite parameters\",\"fields\":[{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the satellite\"},{\"name\":\"missionName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the mission\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the satellite\"},{\"name\":\"code\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Short code of the satellite\"},{\"name\":\"launchDate\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Launch date. Format: YYYY-MM-DDTHH:mm:SS\"},{\"name\":\"listSubsystems\",\"type\":[\"null\",{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"Subsystem\",\"doc\":\"This record contains the definition of a subsystem\",\"fields\":[{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Subsystem name\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the Subsystem\"},{\"name\":\"satelliteName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Satellite name\"}]}}],\"doc\":\"List of subsystems of the satellite\"}]},\"doc\":\"New Satellite object\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Authorization token */
  @Deprecated public java.lang.String authorizationToken;
  /** Mission identifier */
  @Deprecated public java.lang.String missionName;
  /** New Satellite object */
  @Deprecated public com.incomplete.cubegs.common.avro.messages.Satellite satellite;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public MsgAddSatellite() {}

  /**
   * All-args constructor.
   * @param authorizationToken Authorization token
   * @param missionName Mission identifier
   * @param satellite New Satellite object
   */
  public MsgAddSatellite(java.lang.String authorizationToken, java.lang.String missionName, com.incomplete.cubegs.common.avro.messages.Satellite satellite) {
    this.authorizationToken = authorizationToken;
    this.missionName = missionName;
    this.satellite = satellite;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return authorizationToken;
    case 1: return missionName;
    case 2: return satellite;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: authorizationToken = (java.lang.String)value$; break;
    case 1: missionName = (java.lang.String)value$; break;
    case 2: satellite = (com.incomplete.cubegs.common.avro.messages.Satellite)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'authorizationToken' field.
   * @return Authorization token
   */
  public java.lang.String getAuthorizationToken() {
    return authorizationToken;
  }

  /**
   * Sets the value of the 'authorizationToken' field.
   * Authorization token
   * @param value the value to set.
   */
  public void setAuthorizationToken(java.lang.String value) {
    this.authorizationToken = value;
  }

  /**
   * Gets the value of the 'missionName' field.
   * @return Mission identifier
   */
  public java.lang.String getMissionName() {
    return missionName;
  }

  /**
   * Sets the value of the 'missionName' field.
   * Mission identifier
   * @param value the value to set.
   */
  public void setMissionName(java.lang.String value) {
    this.missionName = value;
  }

  /**
   * Gets the value of the 'satellite' field.
   * @return New Satellite object
   */
  public com.incomplete.cubegs.common.avro.messages.Satellite getSatellite() {
    return satellite;
  }

  /**
   * Sets the value of the 'satellite' field.
   * New Satellite object
   * @param value the value to set.
   */
  public void setSatellite(com.incomplete.cubegs.common.avro.messages.Satellite value) {
    this.satellite = value;
  }

  /**
   * Creates a new MsgAddSatellite RecordBuilder.
   * @return A new MsgAddSatellite RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder();
  }

  /**
   * Creates a new MsgAddSatellite RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new MsgAddSatellite RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder(other);
  }

  /**
   * Creates a new MsgAddSatellite RecordBuilder by copying an existing MsgAddSatellite instance.
   * @param other The existing instance to copy.
   * @return A new MsgAddSatellite RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgAddSatellite other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder(other);
  }

  /**
   * RecordBuilder for MsgAddSatellite instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<MsgAddSatellite>
    implements org.apache.avro.data.RecordBuilder<MsgAddSatellite> {

    /** Authorization token */
    private java.lang.String authorizationToken;
    /** Mission identifier */
    private java.lang.String missionName;
    /** New Satellite object */
    private com.incomplete.cubegs.common.avro.messages.Satellite satellite;
    private com.incomplete.cubegs.common.avro.messages.Satellite.Builder satelliteBuilder;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.missionName)) {
        this.missionName = data().deepCopy(fields()[1].schema(), other.missionName);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.satellite)) {
        this.satellite = data().deepCopy(fields()[2].schema(), other.satellite);
        fieldSetFlags()[2] = true;
      }
      if (other.hasSatelliteBuilder()) {
        this.satelliteBuilder = com.incomplete.cubegs.common.avro.messages.Satellite.newBuilder(other.getSatelliteBuilder());
      }
    }

    /**
     * Creates a Builder by copying an existing MsgAddSatellite instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgAddSatellite other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.missionName)) {
        this.missionName = data().deepCopy(fields()[1].schema(), other.missionName);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.satellite)) {
        this.satellite = data().deepCopy(fields()[2].schema(), other.satellite);
        fieldSetFlags()[2] = true;
      }
      this.satelliteBuilder = null;
    }

    /**
      * Gets the value of the 'authorizationToken' field.
      * Authorization token
      * @return The value.
      */
    public java.lang.String getAuthorizationToken() {
      return authorizationToken;
    }

    /**
      * Sets the value of the 'authorizationToken' field.
      * Authorization token
      * @param value The value of 'authorizationToken'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder setAuthorizationToken(java.lang.String value) {
      validate(fields()[0], value);
      this.authorizationToken = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'authorizationToken' field has been set.
      * Authorization token
      * @return True if the 'authorizationToken' field has been set, false otherwise.
      */
    public boolean hasAuthorizationToken() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'authorizationToken' field.
      * Authorization token
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder clearAuthorizationToken() {
      authorizationToken = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'missionName' field.
      * Mission identifier
      * @return The value.
      */
    public java.lang.String getMissionName() {
      return missionName;
    }

    /**
      * Sets the value of the 'missionName' field.
      * Mission identifier
      * @param value The value of 'missionName'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder setMissionName(java.lang.String value) {
      validate(fields()[1], value);
      this.missionName = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'missionName' field has been set.
      * Mission identifier
      * @return True if the 'missionName' field has been set, false otherwise.
      */
    public boolean hasMissionName() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'missionName' field.
      * Mission identifier
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder clearMissionName() {
      missionName = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'satellite' field.
      * New Satellite object
      * @return The value.
      */
    public com.incomplete.cubegs.common.avro.messages.Satellite getSatellite() {
      return satellite;
    }

    /**
      * Sets the value of the 'satellite' field.
      * New Satellite object
      * @param value The value of 'satellite'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder setSatellite(com.incomplete.cubegs.common.avro.messages.Satellite value) {
      validate(fields()[2], value);
      this.satelliteBuilder = null;
      this.satellite = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'satellite' field has been set.
      * New Satellite object
      * @return True if the 'satellite' field has been set, false otherwise.
      */
    public boolean hasSatellite() {
      return fieldSetFlags()[2];
    }

    /**
     * Gets the Builder instance for the 'satellite' field and creates one if it doesn't exist yet.
     * New Satellite object
     * @return This builder.
     */
    public com.incomplete.cubegs.common.avro.messages.Satellite.Builder getSatelliteBuilder() {
      if (satelliteBuilder == null) {
        if (hasSatellite()) {
          setSatelliteBuilder(com.incomplete.cubegs.common.avro.messages.Satellite.newBuilder(satellite));
        } else {
          setSatelliteBuilder(com.incomplete.cubegs.common.avro.messages.Satellite.newBuilder());
        }
      }
      return satelliteBuilder;
    }

    /**
     * Sets the Builder instance for the 'satellite' field
     * New Satellite object
     * @param value The builder instance that must be set.
     * @return This builder.
     */
    public com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder setSatelliteBuilder(com.incomplete.cubegs.common.avro.messages.Satellite.Builder value) {
      clearSatellite();
      satelliteBuilder = value;
      return this;
    }

    /**
     * Checks whether the 'satellite' field has an active Builder instance
     * New Satellite object
     * @return True if the 'satellite' field has an active Builder instance
     */
    public boolean hasSatelliteBuilder() {
      return satelliteBuilder != null;
    }

    /**
      * Clears the value of the 'satellite' field.
      * New Satellite object
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgAddSatellite.Builder clearSatellite() {
      satellite = null;
      satelliteBuilder = null;
      fieldSetFlags()[2] = false;
      return this;
    }

    @Override
    public MsgAddSatellite build() {
      try {
        MsgAddSatellite record = new MsgAddSatellite();
        record.authorizationToken = fieldSetFlags()[0] ? this.authorizationToken : (java.lang.String) defaultValue(fields()[0]);
        record.missionName = fieldSetFlags()[1] ? this.missionName : (java.lang.String) defaultValue(fields()[1]);
        if (satelliteBuilder != null) {
          record.satellite = this.satelliteBuilder.build();
        } else {
          record.satellite = fieldSetFlags()[2] ? this.satellite : (com.incomplete.cubegs.common.avro.messages.Satellite) defaultValue(fields()[2]);
        }
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
