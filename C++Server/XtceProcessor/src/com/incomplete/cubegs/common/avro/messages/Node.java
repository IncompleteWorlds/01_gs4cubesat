/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This record contains the definition of a Node */
@org.apache.avro.specific.AvroGenerated
public class Node extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = 8961857324606231332L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"Node\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This record contains the definition of a Node\",\"fields\":[{\"name\":\"identifier\",\"type\":\"int\",\"doc\":\"Unique identifier of the Node\"},{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Node name\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the Node\"},{\"name\":\"subsystemName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Subsystem name\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Unique identifier of the Node */
  @Deprecated public int identifier;
  /** Node name */
  @Deprecated public java.lang.String name;
  /** Description of the Node */
  @Deprecated public java.lang.String description;
  /** Subsystem name */
  @Deprecated public java.lang.String subsystemName;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public Node() {}

  /**
   * All-args constructor.
   * @param identifier Unique identifier of the Node
   * @param name Node name
   * @param description Description of the Node
   * @param subsystemName Subsystem name
   */
  public Node(java.lang.Integer identifier, java.lang.String name, java.lang.String description, java.lang.String subsystemName) {
    this.identifier = identifier;
    this.name = name;
    this.description = description;
    this.subsystemName = subsystemName;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return identifier;
    case 1: return name;
    case 2: return description;
    case 3: return subsystemName;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: identifier = (java.lang.Integer)value$; break;
    case 1: name = (java.lang.String)value$; break;
    case 2: description = (java.lang.String)value$; break;
    case 3: subsystemName = (java.lang.String)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'identifier' field.
   * @return Unique identifier of the Node
   */
  public java.lang.Integer getIdentifier() {
    return identifier;
  }

  /**
   * Sets the value of the 'identifier' field.
   * Unique identifier of the Node
   * @param value the value to set.
   */
  public void setIdentifier(java.lang.Integer value) {
    this.identifier = value;
  }

  /**
   * Gets the value of the 'name' field.
   * @return Node name
   */
  public java.lang.String getName() {
    return name;
  }

  /**
   * Sets the value of the 'name' field.
   * Node name
   * @param value the value to set.
   */
  public void setName(java.lang.String value) {
    this.name = value;
  }

  /**
   * Gets the value of the 'description' field.
   * @return Description of the Node
   */
  public java.lang.String getDescription() {
    return description;
  }

  /**
   * Sets the value of the 'description' field.
   * Description of the Node
   * @param value the value to set.
   */
  public void setDescription(java.lang.String value) {
    this.description = value;
  }

  /**
   * Gets the value of the 'subsystemName' field.
   * @return Subsystem name
   */
  public java.lang.String getSubsystemName() {
    return subsystemName;
  }

  /**
   * Sets the value of the 'subsystemName' field.
   * Subsystem name
   * @param value the value to set.
   */
  public void setSubsystemName(java.lang.String value) {
    this.subsystemName = value;
  }

  /**
   * Creates a new Node RecordBuilder.
   * @return A new Node RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Node.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.Node.Builder();
  }

  /**
   * Creates a new Node RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new Node RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Node.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Node.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.Node.Builder(other);
  }

  /**
   * Creates a new Node RecordBuilder by copying an existing Node instance.
   * @param other The existing instance to copy.
   * @return A new Node RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Node.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Node other) {
    return new com.incomplete.cubegs.common.avro.messages.Node.Builder(other);
  }

  /**
   * RecordBuilder for Node instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<Node>
    implements org.apache.avro.data.RecordBuilder<Node> {

    /** Unique identifier of the Node */
    private int identifier;
    /** Node name */
    private java.lang.String name;
    /** Description of the Node */
    private java.lang.String description;
    /** Subsystem name */
    private java.lang.String subsystemName;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Node.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.identifier)) {
        this.identifier = data().deepCopy(fields()[0].schema(), other.identifier);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.name)) {
        this.name = data().deepCopy(fields()[1].schema(), other.name);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.description)) {
        this.description = data().deepCopy(fields()[2].schema(), other.description);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.subsystemName)) {
        this.subsystemName = data().deepCopy(fields()[3].schema(), other.subsystemName);
        fieldSetFlags()[3] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing Node instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Node other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.identifier)) {
        this.identifier = data().deepCopy(fields()[0].schema(), other.identifier);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.name)) {
        this.name = data().deepCopy(fields()[1].schema(), other.name);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.description)) {
        this.description = data().deepCopy(fields()[2].schema(), other.description);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.subsystemName)) {
        this.subsystemName = data().deepCopy(fields()[3].schema(), other.subsystemName);
        fieldSetFlags()[3] = true;
      }
    }

    /**
      * Gets the value of the 'identifier' field.
      * Unique identifier of the Node
      * @return The value.
      */
    public java.lang.Integer getIdentifier() {
      return identifier;
    }

    /**
      * Sets the value of the 'identifier' field.
      * Unique identifier of the Node
      * @param value The value of 'identifier'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Node.Builder setIdentifier(int value) {
      validate(fields()[0], value);
      this.identifier = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'identifier' field has been set.
      * Unique identifier of the Node
      * @return True if the 'identifier' field has been set, false otherwise.
      */
    public boolean hasIdentifier() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'identifier' field.
      * Unique identifier of the Node
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Node.Builder clearIdentifier() {
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'name' field.
      * Node name
      * @return The value.
      */
    public java.lang.String getName() {
      return name;
    }

    /**
      * Sets the value of the 'name' field.
      * Node name
      * @param value The value of 'name'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Node.Builder setName(java.lang.String value) {
      validate(fields()[1], value);
      this.name = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'name' field has been set.
      * Node name
      * @return True if the 'name' field has been set, false otherwise.
      */
    public boolean hasName() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'name' field.
      * Node name
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Node.Builder clearName() {
      name = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'description' field.
      * Description of the Node
      * @return The value.
      */
    public java.lang.String getDescription() {
      return description;
    }

    /**
      * Sets the value of the 'description' field.
      * Description of the Node
      * @param value The value of 'description'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Node.Builder setDescription(java.lang.String value) {
      validate(fields()[2], value);
      this.description = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'description' field has been set.
      * Description of the Node
      * @return True if the 'description' field has been set, false otherwise.
      */
    public boolean hasDescription() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'description' field.
      * Description of the Node
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Node.Builder clearDescription() {
      description = null;
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'subsystemName' field.
      * Subsystem name
      * @return The value.
      */
    public java.lang.String getSubsystemName() {
      return subsystemName;
    }

    /**
      * Sets the value of the 'subsystemName' field.
      * Subsystem name
      * @param value The value of 'subsystemName'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Node.Builder setSubsystemName(java.lang.String value) {
      validate(fields()[3], value);
      this.subsystemName = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'subsystemName' field has been set.
      * Subsystem name
      * @return True if the 'subsystemName' field has been set, false otherwise.
      */
    public boolean hasSubsystemName() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'subsystemName' field.
      * Subsystem name
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Node.Builder clearSubsystemName() {
      subsystemName = null;
      fieldSetFlags()[3] = false;
      return this;
    }

    @Override
    public Node build() {
      try {
        Node record = new Node();
        record.identifier = fieldSetFlags()[0] ? this.identifier : (java.lang.Integer) defaultValue(fields()[0]);
        record.name = fieldSetFlags()[1] ? this.name : (java.lang.String) defaultValue(fields()[1]);
        record.description = fieldSetFlags()[2] ? this.description : (java.lang.String) defaultValue(fields()[2]);
        record.subsystemName = fieldSetFlags()[3] ? this.subsystemName : (java.lang.String) defaultValue(fields()[3]);
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
