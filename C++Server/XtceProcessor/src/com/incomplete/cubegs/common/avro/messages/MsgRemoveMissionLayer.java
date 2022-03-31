/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This message removes a Communication Layers of the mission. */
@org.apache.avro.specific.AvroGenerated
public class MsgRemoveMissionLayer extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = -1953332258867969944L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"MsgRemoveMissionLayer\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This message removes a Communication Layers of the mission.\",\"fields\":[{\"name\":\"authorizationToken\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Authorization token\"},{\"name\":\"missionName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Mission identifier\"},{\"name\":\"layerName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Unique name of the Layer\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Authorization token */
  @Deprecated public java.lang.String authorizationToken;
  /** Mission identifier */
  @Deprecated public java.lang.String missionName;
  /** Unique name of the Layer */
  @Deprecated public java.lang.String layerName;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public MsgRemoveMissionLayer() {}

  /**
   * All-args constructor.
   * @param authorizationToken Authorization token
   * @param missionName Mission identifier
   * @param layerName Unique name of the Layer
   */
  public MsgRemoveMissionLayer(java.lang.String authorizationToken, java.lang.String missionName, java.lang.String layerName) {
    this.authorizationToken = authorizationToken;
    this.missionName = missionName;
    this.layerName = layerName;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return authorizationToken;
    case 1: return missionName;
    case 2: return layerName;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: authorizationToken = (java.lang.String)value$; break;
    case 1: missionName = (java.lang.String)value$; break;
    case 2: layerName = (java.lang.String)value$; break;
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
   * Gets the value of the 'layerName' field.
   * @return Unique name of the Layer
   */
  public java.lang.String getLayerName() {
    return layerName;
  }

  /**
   * Sets the value of the 'layerName' field.
   * Unique name of the Layer
   * @param value the value to set.
   */
  public void setLayerName(java.lang.String value) {
    this.layerName = value;
  }

  /**
   * Creates a new MsgRemoveMissionLayer RecordBuilder.
   * @return A new MsgRemoveMissionLayer RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder();
  }

  /**
   * Creates a new MsgRemoveMissionLayer RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new MsgRemoveMissionLayer RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder(other);
  }

  /**
   * Creates a new MsgRemoveMissionLayer RecordBuilder by copying an existing MsgRemoveMissionLayer instance.
   * @param other The existing instance to copy.
   * @return A new MsgRemoveMissionLayer RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder(other);
  }

  /**
   * RecordBuilder for MsgRemoveMissionLayer instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<MsgRemoveMissionLayer>
    implements org.apache.avro.data.RecordBuilder<MsgRemoveMissionLayer> {

    /** Authorization token */
    private java.lang.String authorizationToken;
    /** Mission identifier */
    private java.lang.String missionName;
    /** Unique name of the Layer */
    private java.lang.String layerName;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.missionName)) {
        this.missionName = data().deepCopy(fields()[1].schema(), other.missionName);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.layerName)) {
        this.layerName = data().deepCopy(fields()[2].schema(), other.layerName);
        fieldSetFlags()[2] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing MsgRemoveMissionLayer instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.missionName)) {
        this.missionName = data().deepCopy(fields()[1].schema(), other.missionName);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.layerName)) {
        this.layerName = data().deepCopy(fields()[2].schema(), other.layerName);
        fieldSetFlags()[2] = true;
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
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder setAuthorizationToken(java.lang.String value) {
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
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder clearAuthorizationToken() {
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
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder setMissionName(java.lang.String value) {
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
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder clearMissionName() {
      missionName = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'layerName' field.
      * Unique name of the Layer
      * @return The value.
      */
    public java.lang.String getLayerName() {
      return layerName;
    }

    /**
      * Sets the value of the 'layerName' field.
      * Unique name of the Layer
      * @param value The value of 'layerName'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder setLayerName(java.lang.String value) {
      validate(fields()[2], value);
      this.layerName = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'layerName' field has been set.
      * Unique name of the Layer
      * @return True if the 'layerName' field has been set, false otherwise.
      */
    public boolean hasLayerName() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'layerName' field.
      * Unique name of the Layer
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveMissionLayer.Builder clearLayerName() {
      layerName = null;
      fieldSetFlags()[2] = false;
      return this;
    }

    @Override
    public MsgRemoveMissionLayer build() {
      try {
        MsgRemoveMissionLayer record = new MsgRemoveMissionLayer();
        record.authorizationToken = fieldSetFlags()[0] ? this.authorizationToken : (java.lang.String) defaultValue(fields()[0]);
        record.missionName = fieldSetFlags()[1] ? this.missionName : (java.lang.String) defaultValue(fields()[1]);
        record.layerName = fieldSetFlags()[2] ? this.layerName : (java.lang.String) defaultValue(fields()[2]);
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
