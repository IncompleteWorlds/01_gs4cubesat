/**
 * Autogenerated by Avro
 *
 * DO NOT EDIT DIRECTLY
 */
package com.incomplete.cubegs.common.avro.messages;

import org.apache.avro.specific.SpecificData;

@SuppressWarnings("all")
/** This record contains the mission parameters */
@org.apache.avro.specific.AvroGenerated
public class Mission extends org.apache.avro.specific.SpecificRecordBase implements org.apache.avro.specific.SpecificRecord {
  private static final long serialVersionUID = -5017845133545134390L;
  public static final org.apache.avro.Schema SCHEMA$ = new org.apache.avro.Schema.Parser().parse("{\"type\":\"record\",\"name\":\"Mission\",\"namespace\":\"com.incomplete.cubegs.common.avro.messages\",\"doc\":\"This record contains the mission parameters\",\"fields\":[{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Unique Mission name\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the mission\"},{\"name\":\"country\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Country of the company / entity owning the mission\"},{\"name\":\"owner\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Company / entity that owns the mission\"},{\"name\":\"creationTime\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Creation time. Format: YYYY-MM-DDTHH:mm:SS\"},{\"name\":\"adminIdentifier\",\"type\":\"int\",\"doc\":\"Mission administrator\"},{\"name\":\"emailAddress\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Email address of the Owner\"},{\"name\":\"phoneNumber\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Contact number of the Owner\"},{\"name\":\"listSatellites\",\"type\":[\"null\",{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"Satellite\",\"doc\":\"This record contains the Satellite parameters\",\"fields\":[{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the satellite\"},{\"name\":\"missionName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Name of the mission\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the satellite\"},{\"name\":\"code\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Short code of the satellite\"},{\"name\":\"launchDate\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Launch date. Format: YYYY-MM-DDTHH:mm:SS\"},{\"name\":\"listSubsystems\",\"type\":[\"null\",{\"type\":\"array\",\"items\":{\"type\":\"record\",\"name\":\"Subsystem\",\"doc\":\"This record contains the definition of a subsystem\",\"fields\":[{\"name\":\"name\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Subsystem name\"},{\"name\":\"description\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Description of the Subsystem\"},{\"name\":\"satelliteName\",\"type\":{\"type\":\"string\",\"avro.java.string\":\"String\"},\"doc\":\"Satellite name\"}]}}],\"doc\":\"List of subsystems of the satellite\"}]}}],\"doc\":\"List of satellites that belong to the mission\"}]}");
  public static org.apache.avro.Schema getClassSchema() { return SCHEMA$; }
  /** Unique Mission name */
  @Deprecated public java.lang.String name;
  /** Description of the mission */
  @Deprecated public java.lang.String description;
  /** Country of the company / entity owning the mission */
  @Deprecated public java.lang.String country;
  /** Company / entity that owns the mission */
  @Deprecated public java.lang.String owner;
  /** Creation time. Format: YYYY-MM-DDTHH:mm:SS */
  @Deprecated public java.lang.String creationTime;
  /** Mission administrator */
  @Deprecated public int adminIdentifier;
  /** Email address of the Owner */
  @Deprecated public java.lang.String emailAddress;
  /** Contact number of the Owner */
  @Deprecated public java.lang.String phoneNumber;
  /** List of satellites that belong to the mission */
  @Deprecated public java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite> listSatellites;

  /**
   * Default constructor.  Note that this does not initialize fields
   * to their default values from the schema.  If that is desired then
   * one should use <code>newBuilder()</code>.
   */
  public Mission() {}

  /**
   * All-args constructor.
   * @param name Unique Mission name
   * @param description Description of the mission
   * @param country Country of the company / entity owning the mission
   * @param owner Company / entity that owns the mission
   * @param creationTime Creation time. Format: YYYY-MM-DDTHH:mm:SS
   * @param adminIdentifier Mission administrator
   * @param emailAddress Email address of the Owner
   * @param phoneNumber Contact number of the Owner
   * @param listSatellites List of satellites that belong to the mission
   */
  public Mission(java.lang.String name, java.lang.String description, java.lang.String country, java.lang.String owner, java.lang.String creationTime, java.lang.Integer adminIdentifier, java.lang.String emailAddress, java.lang.String phoneNumber, java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite> listSatellites) {
    this.name = name;
    this.description = description;
    this.country = country;
    this.owner = owner;
    this.creationTime = creationTime;
    this.adminIdentifier = adminIdentifier;
    this.emailAddress = emailAddress;
    this.phoneNumber = phoneNumber;
    this.listSatellites = listSatellites;
  }

  public org.apache.avro.Schema getSchema() { return SCHEMA$; }
  // Used by DatumWriter.  Applications should not call.
  public java.lang.Object get(int field$) {
    switch (field$) {
    case 0: return name;
    case 1: return description;
    case 2: return country;
    case 3: return owner;
    case 4: return creationTime;
    case 5: return adminIdentifier;
    case 6: return emailAddress;
    case 7: return phoneNumber;
    case 8: return listSatellites;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  // Used by DatumReader.  Applications should not call.
  @SuppressWarnings(value="unchecked")
  public void put(int field$, java.lang.Object value$) {
    switch (field$) {
    case 0: name = (java.lang.String)value$; break;
    case 1: description = (java.lang.String)value$; break;
    case 2: country = (java.lang.String)value$; break;
    case 3: owner = (java.lang.String)value$; break;
    case 4: creationTime = (java.lang.String)value$; break;
    case 5: adminIdentifier = (java.lang.Integer)value$; break;
    case 6: emailAddress = (java.lang.String)value$; break;
    case 7: phoneNumber = (java.lang.String)value$; break;
    case 8: listSatellites = (java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite>)value$; break;
    default: throw new org.apache.avro.AvroRuntimeException("Bad index");
    }
  }

  /**
   * Gets the value of the 'name' field.
   * @return Unique Mission name
   */
  public java.lang.String getName() {
    return name;
  }

  /**
   * Sets the value of the 'name' field.
   * Unique Mission name
   * @param value the value to set.
   */
  public void setName(java.lang.String value) {
    this.name = value;
  }

  /**
   * Gets the value of the 'description' field.
   * @return Description of the mission
   */
  public java.lang.String getDescription() {
    return description;
  }

  /**
   * Sets the value of the 'description' field.
   * Description of the mission
   * @param value the value to set.
   */
  public void setDescription(java.lang.String value) {
    this.description = value;
  }

  /**
   * Gets the value of the 'country' field.
   * @return Country of the company / entity owning the mission
   */
  public java.lang.String getCountry() {
    return country;
  }

  /**
   * Sets the value of the 'country' field.
   * Country of the company / entity owning the mission
   * @param value the value to set.
   */
  public void setCountry(java.lang.String value) {
    this.country = value;
  }

  /**
   * Gets the value of the 'owner' field.
   * @return Company / entity that owns the mission
   */
  public java.lang.String getOwner() {
    return owner;
  }

  /**
   * Sets the value of the 'owner' field.
   * Company / entity that owns the mission
   * @param value the value to set.
   */
  public void setOwner(java.lang.String value) {
    this.owner = value;
  }

  /**
   * Gets the value of the 'creationTime' field.
   * @return Creation time. Format: YYYY-MM-DDTHH:mm:SS
   */
  public java.lang.String getCreationTime() {
    return creationTime;
  }

  /**
   * Sets the value of the 'creationTime' field.
   * Creation time. Format: YYYY-MM-DDTHH:mm:SS
   * @param value the value to set.
   */
  public void setCreationTime(java.lang.String value) {
    this.creationTime = value;
  }

  /**
   * Gets the value of the 'adminIdentifier' field.
   * @return Mission administrator
   */
  public java.lang.Integer getAdminIdentifier() {
    return adminIdentifier;
  }

  /**
   * Sets the value of the 'adminIdentifier' field.
   * Mission administrator
   * @param value the value to set.
   */
  public void setAdminIdentifier(java.lang.Integer value) {
    this.adminIdentifier = value;
  }

  /**
   * Gets the value of the 'emailAddress' field.
   * @return Email address of the Owner
   */
  public java.lang.String getEmailAddress() {
    return emailAddress;
  }

  /**
   * Sets the value of the 'emailAddress' field.
   * Email address of the Owner
   * @param value the value to set.
   */
  public void setEmailAddress(java.lang.String value) {
    this.emailAddress = value;
  }

  /**
   * Gets the value of the 'phoneNumber' field.
   * @return Contact number of the Owner
   */
  public java.lang.String getPhoneNumber() {
    return phoneNumber;
  }

  /**
   * Sets the value of the 'phoneNumber' field.
   * Contact number of the Owner
   * @param value the value to set.
   */
  public void setPhoneNumber(java.lang.String value) {
    this.phoneNumber = value;
  }

  /**
   * Gets the value of the 'listSatellites' field.
   * @return List of satellites that belong to the mission
   */
  public java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite> getListSatellites() {
    return listSatellites;
  }

  /**
   * Sets the value of the 'listSatellites' field.
   * List of satellites that belong to the mission
   * @param value the value to set.
   */
  public void setListSatellites(java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite> value) {
    this.listSatellites = value;
  }

  /**
   * Creates a new Mission RecordBuilder.
   * @return A new Mission RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Mission.Builder newBuilder() {
    return new com.incomplete.cubegs.common.avro.messages.Mission.Builder();
  }

  /**
   * Creates a new Mission RecordBuilder by copying an existing Builder.
   * @param other The existing builder to copy.
   * @return A new Mission RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Mission.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Mission.Builder other) {
    return new com.incomplete.cubegs.common.avro.messages.Mission.Builder(other);
  }

  /**
   * Creates a new Mission RecordBuilder by copying an existing Mission instance.
   * @param other The existing instance to copy.
   * @return A new Mission RecordBuilder
   */
  public static com.incomplete.cubegs.common.avro.messages.Mission.Builder newBuilder(com.incomplete.cubegs.common.avro.messages.Mission other) {
    return new com.incomplete.cubegs.common.avro.messages.Mission.Builder(other);
  }

  /**
   * RecordBuilder for Mission instances.
   */
  public static class Builder extends org.apache.avro.specific.SpecificRecordBuilderBase<Mission>
    implements org.apache.avro.data.RecordBuilder<Mission> {

    /** Unique Mission name */
    private java.lang.String name;
    /** Description of the mission */
    private java.lang.String description;
    /** Country of the company / entity owning the mission */
    private java.lang.String country;
    /** Company / entity that owns the mission */
    private java.lang.String owner;
    /** Creation time. Format: YYYY-MM-DDTHH:mm:SS */
    private java.lang.String creationTime;
    /** Mission administrator */
    private int adminIdentifier;
    /** Email address of the Owner */
    private java.lang.String emailAddress;
    /** Contact number of the Owner */
    private java.lang.String phoneNumber;
    /** List of satellites that belong to the mission */
    private java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite> listSatellites;

    /** Creates a new Builder */
    private Builder() {
      super(SCHEMA$);
    }

    /**
     * Creates a Builder by copying an existing Builder.
     * @param other The existing Builder to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Mission.Builder other) {
      super(other);
      if (isValidValue(fields()[0], other.name)) {
        this.name = data().deepCopy(fields()[0].schema(), other.name);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.description)) {
        this.description = data().deepCopy(fields()[1].schema(), other.description);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.country)) {
        this.country = data().deepCopy(fields()[2].schema(), other.country);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.owner)) {
        this.owner = data().deepCopy(fields()[3].schema(), other.owner);
        fieldSetFlags()[3] = true;
      }
      if (isValidValue(fields()[4], other.creationTime)) {
        this.creationTime = data().deepCopy(fields()[4].schema(), other.creationTime);
        fieldSetFlags()[4] = true;
      }
      if (isValidValue(fields()[5], other.adminIdentifier)) {
        this.adminIdentifier = data().deepCopy(fields()[5].schema(), other.adminIdentifier);
        fieldSetFlags()[5] = true;
      }
      if (isValidValue(fields()[6], other.emailAddress)) {
        this.emailAddress = data().deepCopy(fields()[6].schema(), other.emailAddress);
        fieldSetFlags()[6] = true;
      }
      if (isValidValue(fields()[7], other.phoneNumber)) {
        this.phoneNumber = data().deepCopy(fields()[7].schema(), other.phoneNumber);
        fieldSetFlags()[7] = true;
      }
      if (isValidValue(fields()[8], other.listSatellites)) {
        this.listSatellites = data().deepCopy(fields()[8].schema(), other.listSatellites);
        fieldSetFlags()[8] = true;
      }
    }

    /**
     * Creates a Builder by copying an existing Mission instance
     * @param other The existing instance to copy.
     */
    private Builder(com.incomplete.cubegs.common.avro.messages.Mission other) {
            super(SCHEMA$);
      if (isValidValue(fields()[0], other.name)) {
        this.name = data().deepCopy(fields()[0].schema(), other.name);
        fieldSetFlags()[0] = true;
      }
      if (isValidValue(fields()[1], other.description)) {
        this.description = data().deepCopy(fields()[1].schema(), other.description);
        fieldSetFlags()[1] = true;
      }
      if (isValidValue(fields()[2], other.country)) {
        this.country = data().deepCopy(fields()[2].schema(), other.country);
        fieldSetFlags()[2] = true;
      }
      if (isValidValue(fields()[3], other.owner)) {
        this.owner = data().deepCopy(fields()[3].schema(), other.owner);
        fieldSetFlags()[3] = true;
      }
      if (isValidValue(fields()[4], other.creationTime)) {
        this.creationTime = data().deepCopy(fields()[4].schema(), other.creationTime);
        fieldSetFlags()[4] = true;
      }
      if (isValidValue(fields()[5], other.adminIdentifier)) {
        this.adminIdentifier = data().deepCopy(fields()[5].schema(), other.adminIdentifier);
        fieldSetFlags()[5] = true;
      }
      if (isValidValue(fields()[6], other.emailAddress)) {
        this.emailAddress = data().deepCopy(fields()[6].schema(), other.emailAddress);
        fieldSetFlags()[6] = true;
      }
      if (isValidValue(fields()[7], other.phoneNumber)) {
        this.phoneNumber = data().deepCopy(fields()[7].schema(), other.phoneNumber);
        fieldSetFlags()[7] = true;
      }
      if (isValidValue(fields()[8], other.listSatellites)) {
        this.listSatellites = data().deepCopy(fields()[8].schema(), other.listSatellites);
        fieldSetFlags()[8] = true;
      }
    }

    /**
      * Gets the value of the 'name' field.
      * Unique Mission name
      * @return The value.
      */
    public java.lang.String getName() {
      return name;
    }

    /**
      * Sets the value of the 'name' field.
      * Unique Mission name
      * @param value The value of 'name'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setName(java.lang.String value) {
      validate(fields()[0], value);
      this.name = value;
      fieldSetFlags()[0] = true;
      return this;
    }

    /**
      * Checks whether the 'name' field has been set.
      * Unique Mission name
      * @return True if the 'name' field has been set, false otherwise.
      */
    public boolean hasName() {
      return fieldSetFlags()[0];
    }


    /**
      * Clears the value of the 'name' field.
      * Unique Mission name
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearName() {
      name = null;
      fieldSetFlags()[0] = false;
      return this;
    }

    /**
      * Gets the value of the 'description' field.
      * Description of the mission
      * @return The value.
      */
    public java.lang.String getDescription() {
      return description;
    }

    /**
      * Sets the value of the 'description' field.
      * Description of the mission
      * @param value The value of 'description'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setDescription(java.lang.String value) {
      validate(fields()[1], value);
      this.description = value;
      fieldSetFlags()[1] = true;
      return this;
    }

    /**
      * Checks whether the 'description' field has been set.
      * Description of the mission
      * @return True if the 'description' field has been set, false otherwise.
      */
    public boolean hasDescription() {
      return fieldSetFlags()[1];
    }


    /**
      * Clears the value of the 'description' field.
      * Description of the mission
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearDescription() {
      description = null;
      fieldSetFlags()[1] = false;
      return this;
    }

    /**
      * Gets the value of the 'country' field.
      * Country of the company / entity owning the mission
      * @return The value.
      */
    public java.lang.String getCountry() {
      return country;
    }

    /**
      * Sets the value of the 'country' field.
      * Country of the company / entity owning the mission
      * @param value The value of 'country'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setCountry(java.lang.String value) {
      validate(fields()[2], value);
      this.country = value;
      fieldSetFlags()[2] = true;
      return this;
    }

    /**
      * Checks whether the 'country' field has been set.
      * Country of the company / entity owning the mission
      * @return True if the 'country' field has been set, false otherwise.
      */
    public boolean hasCountry() {
      return fieldSetFlags()[2];
    }


    /**
      * Clears the value of the 'country' field.
      * Country of the company / entity owning the mission
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearCountry() {
      country = null;
      fieldSetFlags()[2] = false;
      return this;
    }

    /**
      * Gets the value of the 'owner' field.
      * Company / entity that owns the mission
      * @return The value.
      */
    public java.lang.String getOwner() {
      return owner;
    }

    /**
      * Sets the value of the 'owner' field.
      * Company / entity that owns the mission
      * @param value The value of 'owner'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setOwner(java.lang.String value) {
      validate(fields()[3], value);
      this.owner = value;
      fieldSetFlags()[3] = true;
      return this;
    }

    /**
      * Checks whether the 'owner' field has been set.
      * Company / entity that owns the mission
      * @return True if the 'owner' field has been set, false otherwise.
      */
    public boolean hasOwner() {
      return fieldSetFlags()[3];
    }


    /**
      * Clears the value of the 'owner' field.
      * Company / entity that owns the mission
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearOwner() {
      owner = null;
      fieldSetFlags()[3] = false;
      return this;
    }

    /**
      * Gets the value of the 'creationTime' field.
      * Creation time. Format: YYYY-MM-DDTHH:mm:SS
      * @return The value.
      */
    public java.lang.String getCreationTime() {
      return creationTime;
    }

    /**
      * Sets the value of the 'creationTime' field.
      * Creation time. Format: YYYY-MM-DDTHH:mm:SS
      * @param value The value of 'creationTime'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setCreationTime(java.lang.String value) {
      validate(fields()[4], value);
      this.creationTime = value;
      fieldSetFlags()[4] = true;
      return this;
    }

    /**
      * Checks whether the 'creationTime' field has been set.
      * Creation time. Format: YYYY-MM-DDTHH:mm:SS
      * @return True if the 'creationTime' field has been set, false otherwise.
      */
    public boolean hasCreationTime() {
      return fieldSetFlags()[4];
    }


    /**
      * Clears the value of the 'creationTime' field.
      * Creation time. Format: YYYY-MM-DDTHH:mm:SS
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearCreationTime() {
      creationTime = null;
      fieldSetFlags()[4] = false;
      return this;
    }

    /**
      * Gets the value of the 'adminIdentifier' field.
      * Mission administrator
      * @return The value.
      */
    public java.lang.Integer getAdminIdentifier() {
      return adminIdentifier;
    }

    /**
      * Sets the value of the 'adminIdentifier' field.
      * Mission administrator
      * @param value The value of 'adminIdentifier'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setAdminIdentifier(int value) {
      validate(fields()[5], value);
      this.adminIdentifier = value;
      fieldSetFlags()[5] = true;
      return this;
    }

    /**
      * Checks whether the 'adminIdentifier' field has been set.
      * Mission administrator
      * @return True if the 'adminIdentifier' field has been set, false otherwise.
      */
    public boolean hasAdminIdentifier() {
      return fieldSetFlags()[5];
    }


    /**
      * Clears the value of the 'adminIdentifier' field.
      * Mission administrator
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearAdminIdentifier() {
      fieldSetFlags()[5] = false;
      return this;
    }

    /**
      * Gets the value of the 'emailAddress' field.
      * Email address of the Owner
      * @return The value.
      */
    public java.lang.String getEmailAddress() {
      return emailAddress;
    }

    /**
      * Sets the value of the 'emailAddress' field.
      * Email address of the Owner
      * @param value The value of 'emailAddress'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setEmailAddress(java.lang.String value) {
      validate(fields()[6], value);
      this.emailAddress = value;
      fieldSetFlags()[6] = true;
      return this;
    }

    /**
      * Checks whether the 'emailAddress' field has been set.
      * Email address of the Owner
      * @return True if the 'emailAddress' field has been set, false otherwise.
      */
    public boolean hasEmailAddress() {
      return fieldSetFlags()[6];
    }


    /**
      * Clears the value of the 'emailAddress' field.
      * Email address of the Owner
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearEmailAddress() {
      emailAddress = null;
      fieldSetFlags()[6] = false;
      return this;
    }

    /**
      * Gets the value of the 'phoneNumber' field.
      * Contact number of the Owner
      * @return The value.
      */
    public java.lang.String getPhoneNumber() {
      return phoneNumber;
    }

    /**
      * Sets the value of the 'phoneNumber' field.
      * Contact number of the Owner
      * @param value The value of 'phoneNumber'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setPhoneNumber(java.lang.String value) {
      validate(fields()[7], value);
      this.phoneNumber = value;
      fieldSetFlags()[7] = true;
      return this;
    }

    /**
      * Checks whether the 'phoneNumber' field has been set.
      * Contact number of the Owner
      * @return True if the 'phoneNumber' field has been set, false otherwise.
      */
    public boolean hasPhoneNumber() {
      return fieldSetFlags()[7];
    }


    /**
      * Clears the value of the 'phoneNumber' field.
      * Contact number of the Owner
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearPhoneNumber() {
      phoneNumber = null;
      fieldSetFlags()[7] = false;
      return this;
    }

    /**
      * Gets the value of the 'listSatellites' field.
      * List of satellites that belong to the mission
      * @return The value.
      */
    public java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite> getListSatellites() {
      return listSatellites;
    }

    /**
      * Sets the value of the 'listSatellites' field.
      * List of satellites that belong to the mission
      * @param value The value of 'listSatellites'.
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder setListSatellites(java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite> value) {
      validate(fields()[8], value);
      this.listSatellites = value;
      fieldSetFlags()[8] = true;
      return this;
    }

    /**
      * Checks whether the 'listSatellites' field has been set.
      * List of satellites that belong to the mission
      * @return True if the 'listSatellites' field has been set, false otherwise.
      */
    public boolean hasListSatellites() {
      return fieldSetFlags()[8];
    }


    /**
      * Clears the value of the 'listSatellites' field.
      * List of satellites that belong to the mission
      * @return This builder.
      */
    public com.incomplete.cubegs.common.avro.messages.Mission.Builder clearListSatellites() {
      listSatellites = null;
      fieldSetFlags()[8] = false;
      return this;
    }

    @Override
    public Mission build() {
      try {
        Mission record = new Mission();
        record.name = fieldSetFlags()[0] ? this.name : (java.lang.String) defaultValue(fields()[0]);
        record.description = fieldSetFlags()[1] ? this.description : (java.lang.String) defaultValue(fields()[1]);
        record.country = fieldSetFlags()[2] ? this.country : (java.lang.String) defaultValue(fields()[2]);
        record.owner = fieldSetFlags()[3] ? this.owner : (java.lang.String) defaultValue(fields()[3]);
        record.creationTime = fieldSetFlags()[4] ? this.creationTime : (java.lang.String) defaultValue(fields()[4]);
        record.adminIdentifier = fieldSetFlags()[5] ? this.adminIdentifier : (java.lang.Integer) defaultValue(fields()[5]);
        record.emailAddress = fieldSetFlags()[6] ? this.emailAddress : (java.lang.String) defaultValue(fields()[6]);
        record.phoneNumber = fieldSetFlags()[7] ? this.phoneNumber : (java.lang.String) defaultValue(fields()[7]);
        record.listSatellites = fieldSetFlags()[8] ? this.listSatellites : (java.util.List<com.incomplete.cubegs.common.avro.messages.Satellite>) defaultValue(fields()[8]);
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
