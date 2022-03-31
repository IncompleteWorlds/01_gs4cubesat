package com.incomplete.cubegs.fdswui;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import org.eclipse.rap.rwt.RWT;
import org.mariadb.jdbc.MariaDbPoolDataSource;

import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.EnumOperationCode;
import com.incomplete.cubegs.common.ReturnData;


public class DataManager {

    /**
     * Retrieve the user data for the login operation
     * The logged flag shall be zero (not logged)
     * @param inUser
     * @param inPassword
     * @param outDbUser
     * @return
     */
    public static ReturnData getUserLogin(String inUser, String inPassword, DbUser outDbUser) {
        ReturnData rc = new ReturnData();
        
        MariaDbPoolDataSource pool = (MariaDbPoolDataSource) RWT.getApplicationContext().getAttribute(Constants.COMMON_POOL);
        Connection connection = null;
        PreparedStatement prepStatement = null;

        try {
            // Open the connection
            connection = pool.getConnection();

            connection.setAutoCommit(false);

            // Read the user data
            prepStatement = connection.prepareStatement("SELECT t_user.identifier, t_user.role_id, t_role.name "
                                        + "FROM t_user, t_role WHERE USER_NAME = ? AND "
                                        + "PASSWORD = PASSWORD(?) AND "
                                        + "t_role.identifier = t_user.role_id");

            prepStatement.setString(1, inUser);
            prepStatement.setString(2, inPassword);

            ResultSet rs = prepStatement.executeQuery();

            // TODO Read mission ID

            if (rs != null && rs.next() == true) {
                outDbUser.setId(rs.getInt(1));
                outDbUser.setUserName(inUser);
                outDbUser.setRoleId(rs.getInt(2));
                outDbUser.setRoleName(rs.getString(3));
                
                // Check user is not logged in
                PreparedStatement prepStatement1 = connection.prepareStatement("SELECT t_user.identifier "
                                        + "FROM t_user, t_role WHERE USER_NAME = ? AND "
                                        + "PASSWORD = PASSWORD(?) AND "
                                        + "t_user.logged_flag = 0");

                prepStatement1.setString(1, inUser);
                prepStatement1.setString(2, inPassword);

                ResultSet rs1 = prepStatement1.executeQuery();
                if (rs1 != null && rs1.next() == true) {
                    outDbUser.setLogged(false);
                } else {
                    rc.set(-1, "User is already logged in. Please, log out from all sessions");
                }   
            } else {
                rc.set(-1, "Unable to read user or incorrect password");
            }
        } catch (SQLException e) {
            e.printStackTrace();

            rc.set(-1, "SQL Exception: " + e.getMessage()); 
        } finally {
            try {
                prepStatement.close();
            } catch (SQLException e1) {
                e1.printStackTrace();
                rc.set(-1, "SQLException: " + e1.getMessage());
            }

            if (connection != null) {
                try {
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();

                    rc.set(-1, "SQL Exception: " + e.getMessage());
                }
            }
        } 
        
        return rc;
    }

    /**
     * Set the logged flag of an user to true. It indicates that the user is already logged in in the 
     * system
     * @param inUserId
     * @return true - if an error has happened, false - otherwise
     */
    public static ReturnData setUserAsLogged(int inUserId, boolean inFlag) {
        ReturnData rc = new ReturnData();
        
        MariaDbPoolDataSource pool = (MariaDbPoolDataSource) RWT.getApplicationContext().getAttribute(Constants.COMMON_POOL);
        Connection connection = null;
        PreparedStatement prepStatement = null;

        try {
            // Open the connection
            connection = pool.getConnection();

            connection.setAutoCommit(true);
            
            prepStatement = connection.prepareStatement("UPDATE t_user SET logged_flag = ? WHERE identifier = ?");
            
            prepStatement.setInt(2, inUserId);
            prepStatement.setInt(1, (inFlag == true ? 1 : 0));
            
            int numberRows = prepStatement.executeUpdate();
            
            if (numberRows != 1) {
                rc.set(-1, "Unable to set the user as logged");
            }
        } catch (SQLException e) {
            e.printStackTrace();

            rc.set(-1,  "SQL Exception: " + e.getMessage()); 
        } finally {
            try {
                prepStatement.close();
            } catch (SQLException e1) {
                e1.printStackTrace();
                rc.set(-1, "SQL Exception: " + e1.getMessage());
            }

            if (connection != null) {
                try {
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();

                    rc.set(-1, "SQL Exception: " + e.getMessage());
                }
            }
        } 
        
        return rc;
    }

    /** 
     * Add a new user to the database
     * @param inNewUser
     * @return true - if an error has happened, false - otherwise
     */
    public static ReturnData registerUser(DbUser inNewUser) {
        ReturnData rc = new ReturnData();
        
        MariaDbPoolDataSource pool = (MariaDbPoolDataSource) RWT.getApplicationContext().getAttribute(Constants.COMMON_POOL);
        Connection connection = null;
        PreparedStatement prepStatement = null;

        try {
            // Open the connection
            connection = pool.getConnection();

            connection.setAutoCommit(true);

            // Read the user data
            prepStatement = connection.prepareStatement(
                    "INSERT INTO t_user (user_name,password,first_name,last_name,email_address,role_id,logged_flag)" +
                    "VALUES (?,PASSWORD(?),?,?,?,?,0)");

            prepStatement.setString(1, inNewUser.getUserName());
            prepStatement.setString(2, inNewUser.getPassword());
            prepStatement.setString(3, inNewUser.getFirstName());
            prepStatement.setString(4, inNewUser.getLastName());
            prepStatement.setString(5, inNewUser.getEmail());
            prepStatement.setInt(6, inNewUser.getRoleId());
            
            //INSERT INTO t_user (identifier,user_name,password,first_name,last_name,email_address,role_id) 
            //VALUES (0 /*not nullable*/,'s' /*not nullable*/,'s' /*not nullable*/,'s' /*not nullable*/,'s' /*not nullable*/,'s' /*not nullable*/,0 /*not nullable*/);

            int numberRows = prepStatement.executeUpdate();

            if (numberRows != 1) {
                rc.set(-1, "Error: User not created");
            }
        } catch (SQLException e) {
            e.printStackTrace();

            rc.set(-1, "SQL Exception: " + e.getMessage()); 
        } finally {
            try {
                prepStatement.close();
            } catch (SQLException e1) {
                e1.printStackTrace();
                
                rc.set(-1, "SQL Exception: " + e1.getMessage());
            }

            if (connection != null) {
                try {
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();

                    rc.set(-1, "SQL Exception: " + e.getMessage());
                }
            }
        } 
        
        return rc;
    }

    static public <T1> 
    ReturnData addOperation(EnumOperationCode inOperationCode, T1 inMessage, OperationDb inOperation) {
        ReturnData rc = new ReturnData();
        // TODO
        // Assign an operation code
        
        // Create Operation
        
        // Add record to the table
        return rc;
    }

    static public
    ReturnData finishOperation(OperationDb inOperation) {
        ReturnData rc = new ReturnData();
        // TODO Auto-generated method stub
        return rc;
    }

}
