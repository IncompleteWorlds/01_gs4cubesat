package com.incomplete.cubegs.fdswui;

import com.incomplete.cubegs.common.ReturnData;

public class AuthorizationManager {

	/**
	 * Do an user login.
	 * 	Check the user password
	 *  Set the user as logged
	 * @param inUser
	 * @param inPassword
	 * @param outDdUser 
	 * @param errorFlag
	 * @param outErrorMessage
	 * @return true if an error has happened,  false  otherwise
	 */
	public static ReturnData doLogin(String inUser, String inPassword, DbUser outDdUser) {
	    ReturnData rc = new ReturnData();

		// Either there is an error reading the user data or the password is incorrect
	    ReturnData dbError = DataManager.getUserLogin(inUser, inPassword, outDdUser);

		if (dbError.getErrorCode() != 0) {
			return dbError;
		}

		// Set the user as logged
		dbError = DataManager.setUserAsLogged(outDdUser.getId(), true);
		if (dbError.getErrorCode() != 0) {
			return dbError;
		}

		return rc;
	}

	/**
	 * Log the current user out. 
	 * Set also the logged flag to false. Remove context attributes
	 * @param inUserId
	 * @param outErrorMessage
	 * @return true if an error has happened,  false  otherwise
	 */
	public static ReturnData doLogout(int inUserId) {
	    ReturnData rc = new ReturnData();

		// Set the user as logged
		ReturnData dbErrorFlag = DataManager.setUserAsLogged(inUserId, false);
		if (dbErrorFlag.getErrorCode() != 0) {
			return dbErrorFlag;
		}

		return rc;
	}
}
