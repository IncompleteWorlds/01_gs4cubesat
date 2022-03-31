/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This message removes a TM Parameter. If the TM Parameter Id is null, it will use the Node and Channel parameters. */
@org.apache.avro.specific.AvroGenerated
public class MsgRemoveTmParameter extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 1119885717872695268L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"MsgRemoveTmParameter\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This message removes a TM Parameter. If the TM Parameter Id is null, it will use the Node and Channel parameters.\",\"fields\":[{\"name\":\"authorizationToken\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Authorization token\"},{\"name\":\"tmParameterId\",\"type\":\"int\",\"doc\":\"TM Parameter identifier\"},{\"name\":\"nodeId\",\"type\":\"int\",\"doc\":\"Node or subsystem identifier\"},{\"name\":\"channelId\",\"type\":\"int\",\"doc\":\"Channel identifier or tm point identifier within subsystem\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Authorization token */
  @Deprecated public java.lang.String authorizationToken;
  /** TM Parameter identifier */
  @Deprecated public int tmParameterId;
  /** Node or subsystem identifier */
  @Deprecated public int nodeId;
  /** Channel identifier or tm point identifier within subsystem */
  @Deprecated public int channelId;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public MsgRemoveTmParameter() {}

  /**
   * All-args constructor.
   * @param authorizationToken Authorization token
   * @param tmParameterId TM Parameter identifier
   * @param nodeId Node or subsystem identifier
   * @param channelId Channel identifier or tm point identifier within subsystem
   */
  public MsgRemoveTmParameter(java.lang.String authorizationToken, java.lang.Integer tmParameterId, java.lang.Integer nodeId, java.lang.Integer channelId) {
    this.authorizationToken = authorizationToken;
    this.tmParameterId = tmParameterId;
    this.nodeId = nodeId;
    this.channelId = channelId;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return authorizationToken;
    case 1: return tmParameterId;
    case 2: return nodeId;
    case 3: return channelId;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: authorizationToken = (java.lang.String)value$; break;
    case 1: tmParameterId = (java.lang.Integer)value$; break;
    case 2: nodeId = (java.lang.Integer)value$; break;
    case 3: channelId = (java.lang.Integer)value$; break;
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
   * Gets the value of the 'tmParameterId' field.
   * @return TM Parameter identifier
   */
  public java.lang.Integer getTmParameterId() {
    return tmParameterId;
  }

  /**
   * Sets the value of the 'tmParameterId' field.
   * TM Parameter identifier
   * @param value the value to set.
   */
  public void setTmParameterId(java.lang.Integer value) {
    this.tmParameterId = value;
  }

  /**
   * Gets the value of the 'nodeId' field.
   * @return Node or subsystem identifier
   */
  public java.lang.Integer getNodeId() {
    return nodeId;
  }

  /**
   * Sets the value of the 'nodeId' field.
   * Node or subsystem identifier
   * @param value the value to set.
   */
  public void setNodeId(java.lang.Integer value) {
    this.nodeId = value;
  }

  /**
   * Gets the value of the 'channelId' field.
   * @return Channel identifier or tm point identifier within subsystem
   */
  public java.lang.Integer getChannelId() {
    return channelId;
  }

  /**
   * Sets the value of the 'channelId' field.
   * Channel identifier or tm point identifier within subsystem
   * @param value the value to set.
   */
  public void setChannelId(java.lang.Integer value) {
    this.channelId = value;
  }

  /**
   * Creates a new MsgRemoveTmParameter RecordBuilder.
   * @return A new MsgRemoveTmParameter RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder();
  }

  /**
   * Creates a new MsgRemoveTmParameter RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new MsgRemoveTmParameter RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder(other);
  }

  /**
   * Creates a new MsgRemoveTmParameter RecordBuilder by copying an existing MsgRemoveTmParameter instance.
   * @param other The existing instance to copy.
   * @return A new MsgRemoveTmParameter RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder(other);
  }

  /**
   * RecordBuilder for MsgRemoveTmParameter instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<MsgRemoveTmParameter>
    implements org.apache.avro.data.RecordBuilder<MsgRemoveTmParameter> {

    /** Authorization token */
    private java.lang.String authorizationToken;
    /** TM Parameter identifier */
    private int tmParameterId;
    /** Node or subsystem identifier */
    private int nodeId;
    /** Channel identifier or tm point identifier within subsystem */
    private int channelId;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.tmParameterId)) {
        this.tmParameterId = data().deepCopy(fields()[1].schema(), other.tmParameterId);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.nodeId)) {
        this.nodeId = data().deepCopy(fields()[2].schema(), other.nodeId);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.channelId)) {
        this.channelId = data().deepCopy(fields()[3].schema(), other.channelId);
        fieldSetFlags()[3] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing MsgRemoveTmParameter instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.tmParameterId)) {
        this.tmParameterId = data().deepCopy(fields()[1].schema(), other.tmParameterId);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.nodeId)) {
        this.nodeId = data().deepCopy(fields()[2].schema(), other.nodeId);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.channelId)) {
        this.channelId = data().deepCopy(fields()[3].schema(), other.channelId);
        fieldSetFlags()[3] = true;
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
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder setAuthorizationToken(java.lang.String value) {
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
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder clearAuthorizationToken() {
      authorizationToken = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'tmParameterId' field.
      * TM Parameter identifier
      * @return The value.
      */
    public java.lang.Integer getTmParameterId() {
      return tmParameterId;
    }

    /**
      * Sets the value of the 'tmParameterId' field.
      * TM Parameter identifier
      * @param value The value of 'tmParameterId'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder setTmParameterId(int value) {
      validate(fields()[1], value);
      this.tmParameterId = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'tmParameterId' field has been set.
      * TM Parameter identifier
      * @return True if the 'tmParameterId' field has been set, false otherwise.
      */
    public boolean hasTmParameterId() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'tmParameterId' field.
      * TM Parameter identifier
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder clearTmParameterId() {
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'nodeId' field.
      * Node or subsystem identifier
      * @return The value.
      */
    public java.lang.Integer getNodeId() {
      return nodeId;
    }

    /**
      * Sets the value of the 'nodeId' field.
      * Node or subsystem identifier
      * @param value The value of 'nodeId'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder setNodeId(int value) {
      validate(fields()[2], value);
      this.nodeId = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'nodeId' field has been set.
      * Node or subsystem identifier
      * @return True if the 'nodeId' field has been set, false otherwise.
      */
    public boolean hasNodeId() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'nodeId' field.
      * Node or subsystem identifier
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder clearNodeId() {
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'channelId' field.
      * Channel identifier or tm point identifier within subsystem
      * @return The value.
      */
    public java.lang.Integer getChannelId() {
      return channelId;
    }

    /**
      * Sets the value of the 'channelId' field.
      * Channel identifier or tm point identifier within subsystem
      * @param value The value of 'channelId'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder setChannelId(int value) {
      validate(fields()[3], value);
      this.channelId = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'channelId' field has been set.
      * Channel identifier or tm point identifier within subsystem
      * @return True if the 'channelId' field has been set, false otherwise.
      */
    public boolean hasChannelId() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'channelId' field.
      * Channel identifier or tm point identifier within subsystem
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgRemoveTmParameter.Builder clearChannelId() {
      fieldSetFlags()[3] = false;
      return this;
    }

    @Override
    public MsgRemoveTmParameter build() {
      try {
        MsgRemoveTmParameter record = new MsgRemoveTmParameter();
        record.authorizationToken = fieldSetFlags()[0] ? this.authorizationToken : (java.lang.String) defaultValue(fields()[0]);
        record.tmParameterId = fieldSetFlags()[1] ? this.tmParameterId : (java.lang.Integer) defaultValue(fields()[1]);
        record.nodeId = fieldSetFlags()[2] ? this.nodeId : (java.lang.Integer) defaultValue(fields()[2]);
        record.channelId = fieldSetFlags()[3] ? this.channelId : (java.lang.Integer) defaultValue(fields()[3]);
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
