package com.incomplete.cubegs.common;

/**
 * This Role values shall be aligned with RoleEnum.h counterpart
 * @author alberto
 *
 */
public enum EnumRole {
	ROLE_READ_ONLY(1), 
	ROLE_NORMAL(2), 
	ROLE_ADMINISTRATOR(3),

	ROLE_MISSION_OPERATOR(10), 
	ROLE_MISSION_ADMINISTRATOR(11);

	private int value;

	EnumRole(int newValue) {
		value = newValue;
	}
	
	public int getValue() {
		return value;
	}
	
	/**
     * Returns the Enum type for a given id number
     */
    public static EnumRole getType(int id) throws Exception {
        for (EnumRole type : values())
            if (type.getValue() == id)
                return type;

        throw new Exception("Enum " + id + " not found");
    }
}
