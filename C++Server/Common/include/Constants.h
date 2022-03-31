/**
 *  CubeGS
 *  An online Ground Segment for Cubesats and Small Sats
 *  (c) 2016 Incomplete Worlds
 *
 */

#ifndef __CONSTANTS_H_INCLUDED__
#define __CONSTANTS_H_INCLUDED__

#include <string>

using namespace std;



// GENERAL
// ----------------------------------------------------



// QPID IF
// ----------------------------------------------------
static const string QPID_BROKER_DEFAULT_URL = "127.0.0.1:5672";

static const string M_C_DEFAULT_QUEUE_NAME = "m_c";
static const string M_C_WUI_DEFAULT_QUEUE_NAME = "m_c_wui";

static const string MCS_DEFAULT_QUEUE_NAME = "mcs";
static const string MCS_WUI_DEFAULT_QUEUE_NAME = "mcs_wui";

static const string FDS_DEFAULT_QUEUE_NAME = "fds";
static const string FDS_WUI_DEFAULT_QUEUE_NAME = "fds_wui";

static const string TOOLS_DEFAULT_QUEUE_NAME = "tools";
static const string TOOLS_WUI_DEFAULT_QUEUE_NAME = "tools_wui";

// Number of messages a queue can receive and store
static const int    DEFAULT_QUEUE_CREDIT = 15;


#endif // __CONSTANTS_H_INCLUDED__
