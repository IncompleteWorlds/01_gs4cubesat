package com.incomplete.cubegs.common;


public class Constants {
    
    // General
    public static final String COPYRIGHT_TEXT = "Incomplete Worlds (c) 2021";
    public static final String USER_PROFILE = "User Profile";
    public static final String LOGOUT = "Logout";
    
    public static final String ISO_8601_DATE_FORMAT = "yyyy-MM-dd'T'HH:mm:ss.SSS'Z'";

    // 10 seconds
    public static final int NNG_DEFAULT_TIMEOUT_MILLISECONDS = 10000;
    public static final String DEFAULT_EPOCH_FORMAT = "UTCGregorian";
    public static final String DEFAULT_REFERENCE_FRAME = "EarthMJ2000Eq";
        
	// View names
	public static final String LOGIN_VIEW_NAME= "Login";
	public static final String MAIN_VIEW_NAME= "Main";
	//public static final String RESET_VIEW_NAME = "http://localhost" + RESET_WUI_PATH;
    public static final String RESET_VIEW_NAME = "Reset";
    public static final String REGISTER_VIEW_NAME = "Register";
	  
	// Ground Stations View names
	public static final String GS_MAIN_VIEW_NAME= "Ground Stations Main";
	public static final String GS_SETTINGS_VIEW_NAME= "Ground Stations Settings";
	public static final String GS_ADD_VIEW_NAME= "Add Ground Station";
	public static final String GS_PASSES_VIEW_NAME= "Ground Station Passes";
	
	// Tools View names
	public static final String TOOLS_MAIN_VIEW_NAME= "Tools Main";
	public static final String TOOLS_CONFIG_VIEW_NAME= "Configuration";
	public static final String TOOLS_EDIT_MISSION_VIEW_NAME= "Edit Mission";
	public static final String TOOLS_REMOVE_MISSION_VIEW_NAME= "Remove Mission";
	public static final String TOOLS_CONFIGURE_MISSION_VIEW_NAME= "Configure Mission";
	public static final String TOOLS_OPERATOR_VIEW_NAME= "Operator";
	
	// MCS View names
	public static final String MCS_MAIN_VIEW_NAME= "Real Time HK TM";
	public static final String MCS_RT_PLOT_VIEW_NAME = "Real Time Plot";
	
	public static final String MCS_OFFLINE_HK_TM_VIEW_NAME = "Offline HK TM";
	public static final String MCS_OFFLINE_PLOT_VIEW_NAME = "Offline Plots";
	
	public static final String MCS_FILES_MANAGER_VIEW_NAME = "Files Manager";
	public static final String MCS_TC_VIEW_NAME = "TC";
	
	public static final String MCS_TC_HISTORY_VIEW_NAME = "TC History";
    
	public static final String MCS_FRAMES_VIEW_NAME = "Frames";
	public static final String MCS_SCREEN_VIEW_NAME = "Screen";
    
	public static final String MCS_SC_DB_VIEW_NAME = "S/C DB";
    
	public static final String MCS_GS_CONNECTION_VIEW_NAME = "G/S Connection";
	
	public static final String HK_TM_NAME= "HK TM";
	public static final String TC_NAME= "TC";
	public static final String RT_HK_TM_NAME= "HK TM";
	public static final String RT_PLOT_NAME= "Plots";

    public static final String OFFLINE_HK_TM_NAME= "Offline HK TM";
    public static final String OFFLINE_PLOT_NAME= "Offline Plots";
	
    public static final String SETTINGS_NAME= "Settigns";
    public static final String SC_DB_NAME= "S/C DB";
    public static final String SCREEN_NAME= "Screen Definition";
    public static final String FRAMES_NAME= "Frame Definition";
    
    // MCS View names
 	public static final String FDS_MAIN_VIEW_NAME= "FDS Main";
	
	// HTTP Session parameters
    public static final String USER_NAME = "user_name";
    public static final String USER_ID = "user_id";
	public static final String ROLE_ID = "role_id";
	public static final String ROLE_NAME = "role_name";
	//public static final String MISSION_ID = "mission_id";
	public static final String MISSION_NAME = "mission_name";
    //public static final String SATELLITE_ID = "satellite_id";
    public static final String SATELLITE_NAME = "satellite_name";
	public static final String JWT_TOKEN = "jwt_token";
	
	// URLs
	public static final String MAIN_WUI_PATH = "/cubegs";
	public static final String RESET_WUI_PATH = "/reset";	
	public static final String MCS_WUI_PATH = "/mcs";
	public static final String GS_WUI_PATH = "/gs";
	public static final String TOOLS_WUI_PATH = "/tools";
	public static final String FDS_WUI_PATH = "/fds";
	
	public static final String MCS_WUI_CONTEXT = "/McsWUI";
	public static final String GS_WUI_CONTEXT = "/GsWUI";
	public static final String TOOLS_WUI_CONTEXT = "/ToolsWUI";
	public static final String FDS_WUI_CONTEXT = "/FdsWUI";
	
	public static final String MCS_WUI_URL = MCS_WUI_CONTEXT + MCS_WUI_PATH;
	public static final String GS_WUI_URL = GS_WUI_CONTEXT + GS_WUI_PATH;
	public static final String TOOLS_WUI_URL = TOOLS_WUI_CONTEXT + TOOLS_WUI_PATH;
	public static final String FDS_WUI_URL = FDS_WUI_CONTEXT + FDS_WUI_PATH;
	
	// DATABASES
	public static final String COMMON_POOL = "commonPool";
	public static final String FDS_POOL = "fdsPool";
	
	
	
}
