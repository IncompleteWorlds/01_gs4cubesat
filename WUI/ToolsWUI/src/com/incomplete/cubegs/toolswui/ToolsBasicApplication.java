package com.incomplete.cubegs.toolswui;

import java.util.HashMap;
import java.util.Map;

import org.eclipse.rap.rwt.application.Application;
import org.eclipse.rap.rwt.application.ApplicationConfiguration;
import org.eclipse.rap.rwt.client.WebClient;

import com.incomplete.cubegs.common.Constants;


public class ToolsBasicApplication implements ApplicationConfiguration {

    public void configure(Application application) {
        Map<String, String> properties = new HashMap<String, String>();
        
        properties.put(WebClient.PAGE_TITLE, "Tools");
        
        application.addEntryPoint(Constants.TOOLS_WUI_PATH, ToolsEntryPoint.class, properties);
    }

}
