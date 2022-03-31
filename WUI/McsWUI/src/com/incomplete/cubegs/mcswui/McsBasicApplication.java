package com.incomplete.cubegs.mcswui;

import java.util.HashMap;
import java.util.Map;

import org.eclipse.rap.rwt.application.Application;
import org.eclipse.rap.rwt.application.ApplicationConfiguration;
import org.eclipse.rap.rwt.client.WebClient;

import com.incomplete.cubegs.common.Constants;


public class McsBasicApplication implements ApplicationConfiguration {

    public void configure(Application application) {
        Map<String, String> properties = new HashMap<String, String>();
        properties.put(WebClient.PAGE_TITLE, "MCS");
        
        application.addEntryPoint(Constants.MCS_WUI_PATH, McsEntryPoint.class, properties);
    }

}
