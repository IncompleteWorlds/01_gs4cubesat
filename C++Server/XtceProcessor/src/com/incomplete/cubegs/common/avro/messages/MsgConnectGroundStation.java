/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This message connects to a ground station. It returns the connection id (pair key-value) */
@org.apache.avro.specific.AvroGenerated
public class MsgConnectGroundStation extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = -5145947396812461415L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"MsgConnectGroundStation\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This message connects to a ground station. It returns the connection id (pair key-value)\",\"fields\":[{\"name\":\"authorizationToken\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Authorization token\"},{\"name\":\"groundStationId\",\"type\":\"int\",\"doc\":\"Ground Station identifier\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Authorization token */
  @Deprecated public java.lang.String authorizationToken;
  /** Ground Station identifier */
  @Deprecated public int groundStationId;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public MsgConnectGroundStation() {}

  /**
   * All-args constructor.
   * @param authorizationToken Authorization token
   * @param groundStationId Ground Station identifier
   */
  public MsgConnectGroundStation(java.lang.String authorizationToken, java.lang.Integer groundStationId) {
    this.authorizationToken = authorizationToken;
    this.groundStationId = groundStationId;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return authorizationToken;
    case 1: return groundStationId;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: authorizationToken = (java.lang.String)value$; break;
    case 1: groundStationId = (java.lang.Integer)value$; break;
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
   * Gets the value of the 'groundStationId' field.
   * @return Ground Station identifier
   */
  public java.lang.Integer getGroundStationId() {
    return groundStationId;
  }

  /**
   * Sets the value of the 'groundStationId' field.
   * Ground Station identifier
   * @param value the value to set.
   */
  public void setGroundStationId(java.lang.Integer value) {
    this.groundStationId = value;
  }

  /**
   * Creates a new MsgConnectGroundStation RecordBuilder.
   * @return A new MsgConnectGroundStation RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder();
  }

  /**
   * Creates a new MsgConnectGroundStation RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new MsgConnectGroundStation RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder(other);
  }

  /**
   * Creates a new MsgConnectGroundStation RecordBuilder by copying an existing MsgConnectGroundStation instance.
   * @param other The existing instance to copy.
   * @return A new MsgConnectGroundStation RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder(other);
  }

  /**
   * RecordBuilder for MsgConnectGroundStation instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<MsgConnectGroundStation>
    implements org.apache.avro.data.RecordBuilder<MsgConnectGroundStation> {

    /** Authorization token */
    private java.lang.String authorizationToken;
    /** Ground Station identifier */
    private int groundStationId;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.groundStationId)) {
        this.groundStationId = data().deepCopy(fields()[1].schema(), other.groundStationId);
        fieldSetFlags()[1] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing MsgConnectGroundStation instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.groundStationId)) {
        this.groundStationId = data().deepCopy(fields()[1].schema(), other.groundStationId);
        fieldSetFlags()[1] = true;
      }
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
    public com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder setAuthorizationToken(java.lang.String value) {
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
    public com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder clearAuthorizationToken() {
      authorizationToken = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'groundStationId' field.
      * Ground Station identifier
      * @return The value.
      */
    public java.lang.Integer getGroundStationId() {
      return groundStationId;
    }

    /**
      * Sets the value of the 'groundStationId' field.
      * Ground Station identifier
      * @param value The value of 'groundStationId'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder setGroundStationId(int value) {
      validate(fields()[1], value);
      this.groundStationId = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'groundStationId' field has been set.
      * Ground Station identifier
      * @return True if the 'groundStationId' field has been set, false otherwise.
      */
    public boolean hasGroundStationId() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'groundStationId' field.
      * Ground Station identifier
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgConnectGroundStation.Builder clearGroundStationId() {
      fieldSetFlags()[1] = false;
      return this;
    }

    @Override
    public MsgConnectGroundStation build() {
      try {
        MsgConnectGroundStation record = new MsgConnectGroundStation();
        record.authorizationToken = fieldSetFlags()[0] ? this.authorizationToken : (java.lang.String) defaultValue(fields()[0]);
        record.groundStationId = fieldSetFlags()[1] ? this.groundStationId : (java.lang.Integer) defaultValue(fields()[1]);
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
