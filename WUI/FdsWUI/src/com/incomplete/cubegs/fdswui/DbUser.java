package com.incomplete.cubegs.fdswui;

public class DbUser {

	private int id;
	private int roleId;
	private String roleName;
	private String userName;
	private String password;
	private String firstName;
	private String lastName;
	private String email;
	private boolean loggedFlag;

	public DbUser(String inUserName, String inPassword, String inFirstName, String inLastName, String inEmail, int inRoleId) {
		this.id = 0;
		this.roleId = inRoleId;
		this.roleName = "";
		this.userName = inUserName;
		this.password = inPassword;
		this.firstName = inFirstName;
		this.lastName = inLastName;
		this.email = inEmail;
		this.loggedFlag = false;
	}

	public DbUser() {
		this.id = 0;
		this.roleId = 0;
		this.roleName = "";
		this.userName = "";
		this.password = "";
		this.firstName = "";
		this.lastName = "";
		this.email = "";
		this.loggedFlag = false;
	}

	public void setId(int inId) {
		this.id = inId;
	}

	public void setRoleId(int inRoleId) {
		this.roleId = inRoleId;
	}

	public void setRoleName(String inRoleName) {
		this.roleName = inRoleName;
	}

	public void setUserName(String inUserName) {
		this.userName = inUserName;
	}
	
	public int getId() {
		return this.id;
	}

	public int getRoleId() {
		return this.roleId;
	}

	public String getRoleName() {
		return this.roleName;
	}

	public String getUserName() {
		return this.userName;
	}

	public String getPassword() {
		return this.password;
	}

	public String getFirstName() {
		return this.firstName;
	}

	public String getLastName() {
		return this.lastName;
	}

	public String getEmail() {
		return this.email;
	}
	
	public boolean getLoggedFlag() {
		return this.loggedFlag;
	}

    public void setLogged(boolean inLoggedFlag) {
        this.loggedFlag = inLoggedFlag;
    }
}
