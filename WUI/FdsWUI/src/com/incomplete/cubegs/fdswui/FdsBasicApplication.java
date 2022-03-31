package com.incomplete.cubegs.fdswui;

import java.util.HashMap;
import java.util.Map;

import org.eclipse.rap.rwt.application.Application;
import org.eclipse.rap.rwt.application.ApplicationConfiguration;
import org.eclipse.rap.rwt.application.Application.OperationMode;
import org.eclipse.rap.rwt.client.WebClient;

import com.incomplete.cubegs.common.Constants;



public class FdsBasicApplication implements ApplicationConfiguration {

    public void configure(Application application) {        
        Map<String, String> properties = new HashMap<String, String>();
        properties.put(WebClient.PAGE_TITLE, "FDS");
        
        System.out.println("INFO: Starting FDS Application");
        
        application.setOperationMode( OperationMode.SWT_COMPATIBILITY );
        
        application.addEntryPoint(Constants.FDS_WUI_PATH, FdsEntryPoint.class, properties);

        // NOTE: Sockets could be created at this stage and added to the ApplicationContext
    }
    
}
