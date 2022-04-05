/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __SECURITYACCESS_IF__
#define __SECURITYACCESS_IF__

#include <string>

using namespace std;


#include "AvroTypes.h"

#include "OperationCodeEnum.h"
#include "RoleEnum.h"

class SecurityAccessIF
{
    public:
        // Singleton
        static SecurityAccessIF& getInstance()
        {
            static SecurityAccessIF instance;

            return instance;
        }
        virtual ~SecurityAccessIF();

        // -- OPERATIONS ----------
        void login(const string& inUserName, const string& inHashPwd, RoleEnum &outRole,
                   IW::MsgReturnData& outReturnData);

        bool authorize(const OperationCodeEnum& inOperCode, const RoleEnum &inRole);

    protected:
        SecurityAccessIF();

    private:
        void init();
};

#endif
