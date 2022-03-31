/**
 * Ground Segment As A Service (GSaaS).
 * 
 * <P>Main Web User Interface (WUI) of the Ground Segment As A Service platform
 * of Incomplete Worlds 
 *  
 * The WUI includes link to the main components of the platform like MCS, 
 * Configuration, etc.
 *  
 * @author Alberto Fernandez
 * @version Beta 0.1
 * @date April 2016
 */

package com.incomplete.cubegs.mainwui;

import java.util.HashMap;
import java.util.Map;

import org.eclipse.rap.rwt.application.Application;
import org.eclipse.rap.rwt.application.Application.OperationMode;
import org.eclipse.rap.rwt.application.ApplicationConfiguration;
import org.eclipse.rap.rwt.client.WebClient;


import com.incomplete.cubegs.common.Constants;


public class MainBasicApplication implements ApplicationConfiguration {

    public void configure(Application application) {
        Map<String, String> properties = new HashMap<String, String>();
        
        properties.put(WebClient.PAGE_TITLE, "GS As A Service ");
        
        application.setOperationMode( OperationMode.SWT_COMPATIBILITY );
        
        // Same as in web.xml
        application.addEntryPoint(Constants.MAIN_WUI_PATH,   MainEntryPoint.class, properties);
    }
}

