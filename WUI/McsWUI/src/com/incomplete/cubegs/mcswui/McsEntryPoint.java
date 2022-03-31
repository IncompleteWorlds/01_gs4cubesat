package com.incomplete.cubegs.mcswui;

import org.eclipse.rap.rwt.application.AbstractEntryPoint;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;

import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.HttpManager;
import com.incomplete.cubegs.common.SingletonViews;
import com.incomplete.cubegs.mcswui.view.McsFramesPage;
import com.incomplete.cubegs.mcswui.view.McsGsConnectionPage;
import com.incomplete.cubegs.mcswui.view.McsFilesManagerPage;
import com.incomplete.cubegs.mcswui.view.McsOfflineHkTmPage;
import com.incomplete.cubegs.mcswui.view.McsOfflinePlotPage;
import com.incomplete.cubegs.mcswui.view.McsRtHkTmPage;
import com.incomplete.cubegs.mcswui.view.McsRtPlotPage;
import com.incomplete.cubegs.mcswui.view.McsTcPage;
import com.incomplete.cubegs.mcswui.view.McsSC_DBPage;
import com.incomplete.cubegs.mcswui.view.McsScreenPage;
import com.incomplete.cubegs.mcswui.view.McsTcHistoryPage;


public class McsEntryPoint extends AbstractEntryPoint {
    private static final long serialVersionUID = 1L;

    @Override
    protected void createContents(Composite parent) {
//        parent.setLayout(new GridLayout(2, false));
        
        
        System.out.println("INFO: Starting MCS WUI");
        
        try {
            // Loading HTTP properties
            HttpManager unusedManager = new HttpManager();
            
            // Create views and register them
            SingletonViews views = SingletonViews.getInstance();

            views.initialize(parent);

            // Create pages
            McsRtHkTmPage mainPage = new McsRtHkTmPage(Constants.MCS_MAIN_VIEW_NAME, views.getContainer(), SWT.NONE);
            McsRtPlotPage rtPlotPage = new McsRtPlotPage(Constants.MCS_RT_PLOT_VIEW_NAME, views.getContainer(), SWT.NONE);
            
            McsOfflineHkTmPage offlineHkTmPage = new McsOfflineHkTmPage(Constants.MCS_OFFLINE_HK_TM_VIEW_NAME, views.getContainer(), SWT.NONE);
            McsOfflinePlotPage offlinePlotPage = new McsOfflinePlotPage(Constants.MCS_OFFLINE_PLOT_VIEW_NAME, views.getContainer(), SWT.NONE);
            
            McsFilesManagerPage filesManagerPage = new McsFilesManagerPage(Constants.MCS_FILES_MANAGER_VIEW_NAME, views.getContainer(), SWT.NONE);
            
            McsTcPage tcPage = new McsTcPage(Constants.MCS_TC_VIEW_NAME, views.getContainer(), SWT.NONE);
            
            McsTcHistoryPage tcHistoryPage = new McsTcHistoryPage(Constants.MCS_TC_HISTORY_VIEW_NAME, views.getContainer(), SWT.NONE);
            
            McsFramesPage framesPage = new McsFramesPage(Constants.MCS_FRAMES_VIEW_NAME, views.getContainer(), SWT.NONE);
            McsScreenPage screenPage = new McsScreenPage(Constants.MCS_SCREEN_VIEW_NAME, views.getContainer(), SWT.NONE);
            
            McsSC_DBPage scDbPage = new McsSC_DBPage(Constants.MCS_SC_DB_VIEW_NAME, views.getContainer(), SWT.NONE);
            
            McsGsConnectionPage gsConnectionPage = new McsGsConnectionPage(Constants.MCS_GS_CONNECTION_VIEW_NAME, views.getContainer(), SWT.NONE);
            
            // Register pages
            views.registerView(Constants.MCS_MAIN_VIEW_NAME, mainPage);
            views.registerView(Constants.MCS_RT_PLOT_VIEW_NAME, rtPlotPage);
            
            views.registerView(Constants.MCS_OFFLINE_HK_TM_VIEW_NAME, offlineHkTmPage);
            views.registerView(Constants.MCS_OFFLINE_PLOT_VIEW_NAME, offlinePlotPage);
            
            views.registerView(Constants.MCS_FILES_MANAGER_VIEW_NAME, filesManagerPage);
            
            views.registerView(Constants.MCS_TC_VIEW_NAME, tcPage);
            
            views.registerView(Constants.MCS_TC_HISTORY_VIEW_NAME, tcHistoryPage);
            
            views.registerView(Constants.MCS_FRAMES_VIEW_NAME, framesPage);
            views.registerView(Constants.MCS_SCREEN_VIEW_NAME, screenPage);
            
            views.registerView(Constants.MCS_SC_DB_VIEW_NAME, scDbPage);
            
            views.registerView(Constants.MCS_GS_CONNECTION_VIEW_NAME, gsConnectionPage);
            

            // Activate first page
            views.changeView(Constants.MCS_MAIN_VIEW_NAME);

        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.err.println("ERROR: Exception: " + e);
            
            System.exit(-1);
        }
    }

}
