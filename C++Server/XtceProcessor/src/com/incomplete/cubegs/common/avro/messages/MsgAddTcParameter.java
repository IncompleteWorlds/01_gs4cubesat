/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This message adds a new TC Parameter to a node or subsystem */
@org.apache.avro.specific.AvroGenerated
public class MsgAddTcParameter extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 6163148643935963928L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"MsgAddTcParameter\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This message adds a new TC Parameter to a node or subsystem\",\"fields\":[{\"name\":\"authorizationToken\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Authorization token\"},{\"name\":\"tcParameter\",\"type\":{\"type\":\"record\",\"name\":\"TC_Parameter\",\"doc\":\"A TC Parameter\",\"fields\":[{\"name\":\"identifier\",\"type\":\"int\",\"doc\":\"Unique identifier of the parameter in the DB\"},{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the parameter\"},{\"name\":\"displayName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name to be displayed\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the parameter\"},{\"name\":\"parentName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of Parent command\"},{\"name\":\"subsystem\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Subsystem name\"},{\"name\":\"node\",\"type\":\"int\",\"doc\":\"Node or subsystem identifier\"},{\"name\":\"channel\",\"type\":\"int\",\"doc\":\"Channel identifier ot tc identifier within the subsystem\"},{\"name\":\"lengthBits\",\"type\":\"int\",\"doc\":\"Length of the field in bits\"},{\"name\":\"abstractFlag\",\"type\":\"int\",\"doc\":\"1 - True, 0 - False\"},{\"name\":\"listArgument\",\"type\":{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"TC_Argument\",\"doc\":\"It defines an argument of a TC\",\"fields\":[{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Argument name\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the argument\"},{\"name\":\"tcName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"TC name\"},{\"name\":\"relativePosition\",\"type\":\"int\",\"doc\":\"Relative position within the TC frame\"},{\"name\":\"lengthBits\",\"type\":\"int\",\"doc\":\"Length in bits of the argument\"},{\"name\":\"argType\",\"type\":\"int\",\"doc\":\"Argument type. Raw type\"},{\"name\":\"argSubType\",\"type\":\"int\",\"doc\":\"Argument sub type\"},{\"name\":\"engType\",\"type\":\"int\",\"doc\":\"Argument engineering type\"},{\"name\":\"units\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Argument units\"},{\"name\":\"prependSize\",\"type\":\"int\",\"doc\":\"Prepend size of a string\"},{\"name\":\"stringTerminator\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"String terminator\"},{\"name\":\"littleEndian\",\"type\":\"int\",\"doc\":\"Little endian flag\"},{\"name\":\"functionName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Function name for converting the argument\"},{\"name\":\"defaultValue\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Argument deafult value\"},{\"name\":\"rangeLow\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Argument range low value\"},{\"name\":\"rangeHigh\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Argument range high value\"}]}},\"doc\":\"List of Argument of a TC\"},{\"name\":\"listArgumentAssignment\",\"type\":{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"TC_ArgumentAssignment\",\"doc\":\"It defines a value assigned to an argument of a TC\",\"fields\":[{\"name\":\"tcName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"TC name\"},{\"name\":\"argument\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Argument name\"},{\"name\":\"value\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Argument value\"}]}},\"doc\":\"List of Argument assignment of a TC\"},{\"name\":\"listOptions\",\"type\":{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"TC_ParameterOptions\",\"doc\":\"It defines the options of a Parameter in terms of; constraints, transmission options, severity level\",\"fields\":[{\"name\":\"tcName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"TC name\"},{\"name\":\"significance\",\"type\":\"int\",\"doc\":\"Argument name\"},{\"name\":\"significanceReason\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Argument value\"}]}},\"doc\":\"List of TC Options\"},{\"name\":\"listOptConstraints\",\"type\":{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"TC_ParameterOptConstraints\",\"doc\":\"It defines the options of a Parameter in terms of; constraints, transmission options, severity level\",\"fields\":[{\"name\":\"tcName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"TC name\"},{\"name\":\"constraint\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Constraint name\"},{\"name\":\"timeout\",\"type\":\"int\",\"doc\":\"The timeout of the constraint. A command stays in the queue for that many milliseconds\"}]}},\"doc\":\"List of TC Options Constraints\"},{\"name\":\"listVerifications\",\"type\":{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"TC_ParameterVerifier\",\"doc\":\"It defines the stages of veritying a TC\",\"fields\":[{\"name\":\"tcName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"TC name\"},{\"name\":\"tcStage\",\"type\":{\"type\":\"enum\",\"name\":\"TcStageEnum\",\"symbols\":[\"TC_STAGE_TRANSFERRED\",\"TC_STAGE_SENT\",\"TC_STAGE_RECEIVED\",\"TC_STAGE_ACCEPTED\",\"TC_STAGE_QUEUED\",\"TC_STAGE_EXECUTION\",\"TC_STAGE_COMPLETED\",\"TC_STAGE_FAILED\"]},\"doc\":\"Any stage is accepted\"},{\"name\":\"verifierType\",\"type\":\"int\",\"doc\":\"Type of verifier\"},{\"name\":\"verifierText\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Text of verifier\"},{\"name\":\"startTimeCheckWindow\",\"type\":\"int\",\"doc\":\"Start time of the window in milliseconds\"},{\"name\":\"stopTimeCheckWindow\",\"type\":\"int\",\"doc\":\"Stop time of the window in milliseconds\"},{\"name\":\"checkWindow\",\"type\":\"int\",\"doc\":\"Check window\"},{\"name\":\"onSuccess\",\"type\":\"int\",\"doc\":\"Defines what happens when the verification returns true\"},{\"name\":\"onFail\",\"type\":\"int\",\"doc\":\"Same like OnSuccess but the event is generated in case the verifier returns false\"},{\"name\":\"onTimeout\",\"type\":\"int\",\"doc\":\"Defines what happens when the verification returns true\"}]}},\"doc\":\"List of TC Verifications\"}]},\"doc\":\"New TC Parameter object\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Authorization token */
  @Deprecated public java.lang.String authorizationToken;
  /** New TC Parameter object */
  @Deprecated public com.incomplete.cubegs.common.avro.messages.TC_Parameter tcParameter;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public MsgAddTcParameter() {}

  /**
   * All-args constructor.
   * @param authorizationToken Authorization token
   * @param tcParameter New TC Parameter object
   */
  public MsgAddTcParameter(java.lang.String authorizationToken, com.incomplete.cubegs.common.avro.messages.TC_Parameter tcParameter) {
    this.authorizationToken = authorizationToken;
    this.tcParameter = tcParameter;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return authorizationToken;
    case 1: return tcParameter;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: authorizationToken = (java.lang.String)value$; break;
    case 1: tcParameter = (com.incomplete.cubegs.common.avro.messages.TC_Parameter)value$; break;
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
   * Gets the value of the 'tcParameter' field.
   * @return New TC Parameter object
   */
  public com.incomplete.cubegs.common.avro.messages.TC_Parameter getTcParameter() {
    return tcParameter;
  }

  /**
   * Sets the value of the 'tcParameter' field.
   * New TC Parameter object
   * @param value the value to set.
   */
  public void setTcParameter(com.incomplete.cubegs.common.avro.messages.TC_Parameter value) {
    this.tcParameter = value;
  }

  /**
   * Creates a new MsgAddTcParameter RecordBuilder.
   * @return A new MsgAddTcParameter RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder();
  }

  /**
   * Creates a new MsgAddTcParameter RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new MsgAddTcParameter RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder(other);
  }

  /**
   * Creates a new MsgAddTcParameter RecordBuilder by copying an existing MsgAddTcParameter instance.
   * @param other The existing instance to copy.
   * @return A new MsgAddTcParameter RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter other) {
    return new com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder(other);
  }

  /**
   * RecordBuilder for MsgAddTcParameter instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<MsgAddTcParameter>
    implements org.apache.avro.data.RecordBuilder<MsgAddTcParameter> {

    /** Authorization token */
    private java.lang.String authorizationToken;
    /** New TC Parameter object */
    private com.incomplete.cubegs.common.avro.messages.TC_Parameter tcParameter;
    private com.incomplete.cubegs.common.avro.messages.TC_Parameter.Builder tcParameterBuilder;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.tcParameter)) {
        this.tcParameter = data().deepCopy(fields()[1].schema(), other.tcParameter);
        fieldSetFlags()[1] = true;
      }
      if (other.hasTcParameterBuilder()) {
        this.tcParameterBuilder = com.incomplete.cubegs.common.avro.messages.TC_Parameter.newBuilder(other.getTcParameterBuilder());
      }
    }

    /**
     * Creates a Builder by copying an existing MsgAddTcParameter instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.authorizationToken)) {
        this.authorizationToken = data().deepCopy(fields()[0].schema(), other.authorizationToken);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.tcParameter)) {
        this.tcParameter = data().deepCopy(fields()[1].schema(), other.tcParameter);
        fieldSetFlags()[1] = true;
      }
      this.tcParameterBuilder = null;
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
    public com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder setAuthorizationToken(java.lang.String value) {
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
    public com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder clearAuthorizationToken() {
      authorizationToken = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'tcParameter' field.
      * New TC Parameter object
      * @return The value.
      */
    public com.incomplete.cubegs.common.avro.messages.TC_Parameter getTcParameter() {
      return tcParameter;
    }

    /**
      * Sets the value of the 'tcParameter' field.
      * New TC Parameter object
      * @param value The value of 'tcParameter'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder setTcParameter(com.incomplete.cubegs.common.avro.messages.TC_Parameter value) {
      validate(fields()[1], value);
      this.tcParameterBuilder = null;
      this.tcParameter = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'tcParameter' field has been set.
      * New TC Parameter object
      * @return True if the 'tcParameter' field has been set, false otherwise.
      */
    public boolean hasTcParameter() {
      return fieldSetFlags()[1];
    }

    /**
     * Gets the Builder instance for the 'tcParameter' field and creates one if it doesn't exist yet.
     * New TC Parameter object
     * @return This builder.
     */
    public com.incomplete.cubegs.common.avro.messages.TC_Parameter.Builder getTcParameterBuilder() {
      if (tcParameterBuilder == null) {
        if (hasTcParameter()) {
          setTcParameterBuilder(com.incomplete.cubegs.common.avro.messages.TC_Parameter.newBuilder(tcParameter));
        } else {
          setTcParameterBuilder(com.incomplete.cubegs.common.avro.messages.TC_Parameter.newBuilder());
        }
      }
      return tcParameterBuilder;
    }

    /**
     * Sets the Builder instance for the 'tcParameter' field
     * New TC Parameter object
     * @param value The builder instance that must be set.
     * @return This builder.
     */
    public com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder setTcParameterBuilder(com.incomplete.cubegs.common.avro.messages.TC_Parameter.Builder value) {
      clearTcParameter();
      tcParameterBuilder = value;
      return this;
    }

    /**
     * Checks whether the 'tcParameter' field has an active Builder instance
     * New TC Parameter object
     * @return True if the 'tcParameter' field has an active Builder instance
     */
    public boolean hasTcParameterBuilder() {
      return tcParameterBuilder != null;
    }

    /**
      * Clears the value of the 'tcParameter' field.
      * New TC Parameter object
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.MsgAddTcParameter.Builder clearTcParameter() {
      tcParameter = null;
      tcParameterBuilder = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    @Override
    public MsgAddTcParameter build() {
      try {
        MsgAddTcParameter record = new MsgAddTcParameter();
        record.authorizationToken = fieldSetFlags()[0] ? this.authorizationToken : (java.lang.String) defaultValue(fields()[0]);
        if (tcParameterBuilder != null) {
          record.tcParameter = this.tcParameterBuilder.build();
        } else {
          record.tcParameter = fieldSetFlags()[1] ? this.tcParameter : (com.incomplete.cubegs.common.avro.messages.TC_Parameter) defaultValue(fields()[1]);
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
