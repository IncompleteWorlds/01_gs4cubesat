package com.incomplete.cubegs.fdswui;

import com.incomplete.cubegs.common.EnumOperationCode;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.common.ServerMessage;
import com.incomplete.cubegs.common.ZeroMqManager;


public class ModuleManager {

	/**
	 * It executes an operation
	 * @param inOperationCode - Code of the Operation to be executed
	 * @param inMessage - The message to be sent to the module 
	 * @param outResponseMsg2 
	 * @param outErrorMessage
	 * @return true - if an error has happened, false - otherwise
	 */
    
	static public //<T1, T2> 
	ReturnData run(EnumOperationCode inOperationCode, ServerMessage inMessage, ServerMessage outResponseMsg) { //,Class<T2> classT2) {	    
	    ReturnData rc = new ReturnData();

		// Add operation and store in the DB
	    OperationDb operation = new OperationDb();
	    
	    rc = DataManager.addOperation(inOperationCode, inMessage, operation);
	    if (rc.getErrorCode() != 0) {
	        return rc;
	    }
		
		// Call GMAT
	    try {
	        ZeroMqManager.getInstance().send( inMessage.encode() );
        } catch (Exception e) {
            rc.set(-1, "Error sending message to the backend");
            return rc;
        }
	    
		
		// Wait for answer
	    String responseMsg = null;
	    try {
            responseMsg = ZeroMqManager.getInstance().receive();
        } catch (Exception e) {
            e.printStackTrace();
            rc.set(-1, e.toString());
            return rc;
        }
	    	    
		// Flag operation as completed. Update recod in the DB
		rc = DataManager.finishOperation(operation);
		if (rc.getErrorCode() != 0) {
            return rc;
        }
		
		// Return answer
		if (responseMsg != null) {
		    outResponseMsg.decode(responseMsg);
		    
		    rc.clear();
		    
		    // Not really needed but useful
		    rc.setResponse(responseMsg);		    
		} else {
		    rc.set(-1, "Null message received from the backend");
		}
	    
		return rc;
	}

}
