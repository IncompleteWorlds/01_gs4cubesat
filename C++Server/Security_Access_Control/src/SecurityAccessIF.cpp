/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2017 Incomplete Worlds
 *
 */
#include <iostream>

using namespace std;

#include "GSException.h"
#include "ConfigurationManager.h"

#include "SecurityAccessIF.h"

SecurityAccessIF::SecurityAccessIF()
{
    // Read permissions from the database
    init();
}

SecurityAccessIF::~SecurityAccessIF()
{
}

void SecurityAccessIF::init()
{
    auto toolsServerAddress = ConfigurationManager::getInstance().getValue(ConfigurationManager::KEY_TOOLS_SERVER_ADDRESS);

    // Create context

    // Create socket

    // Read the list of roles

    // For each role, read the list of authorized functions
    // Administrator role has all functions

    // Read permissions per role from a table of a database
    // Store permissions in maps per role

}

/** @brief login
  *
  * Perform an user login. It will check the name and verify the password.
  * The password will be coded using a hash function
  */
void SecurityAccessIF::login(const string& inUserName, const string& inHashPwd, RoleEnum &outRole,
                             IW::MsgReturnData& outReturnData)
{
    cout << "DEBUG Login. User: " << inUserName << endl;

    // Generic error
    outReturnData.errorCode = -1;
    outReturnData.errorMessage = "Invalid user name or password";

    if (inUserName.empty() == false && inHashPwd.empty() == false) {

        // TODO: Verify user name and password. Check password matches with
        // stored password

        if (inUserName == "user01" || inUserName == "normal") {
            outRole = RoleEnum::ROLE_NORMAL;
            outReturnData.errorCode = 0;
            outReturnData.errorMessage = "";
        }

        if (inUserName == "read_only" || inUserName == "read only") {
            outRole = RoleEnum::ROLE_READ_ONLY;
            outReturnData.errorCode = 0;
            outReturnData.errorMessage = "";
        }

        if (inUserName == "admin" || inUserName == "administrator") {
            outRole = RoleEnum::ROLE_ADMINISTRATOR;
            outReturnData.errorCode = 0;
            outReturnData.errorMessage = "";
        }
    }

    cout << "DEBUG Role: " << (int) outRole << endl;
    cout << "DEBUG SecurityIF.output: " << outReturnData.errorCode << " " << outReturnData.errorMessage << endl;
}

/** @brief authorize
  *
  * Authorize an operation. It will verify that the role is allowed to execute it
  */
bool SecurityAccessIF::authorize(const OperationCodeEnum& inOperCode, const RoleEnum &inRole)
{
    bool output = false;

    if (inRole == RoleEnum::ROLE_READ_ONLY) {
        // TODO: Implement map

        /*
        if (readOnlyMap[inOperCode] == true) {
            output = true;
        }
        */
        output = true;
    }

    if (inRole == RoleEnum::ROLE_NORMAL) {
        /*
        if (normalMap[inOperCode] == true) {
            output = true;
        }
        */
        output = true;
    }

    if (inRole == RoleEnum::ROLE_ADMINISTRATOR) {
        /*
        if (administratorMap[inOperCode] == true) {
            output = true;
        }
        */
        output = true;
    }

    return output;
}


