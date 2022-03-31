package com.incomplete.cubegs.fdswui.view;

import org.eclipse.swt.widgets.Composite;


import javax.servlet.ServletContext;

import org.eclipse.rap.rwt.RWT;
import org.eclipse.rap.rwt.service.UISession;

import com.incomplete.cubegs.common.BaseClassPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.common.SingletonViews;
import com.incomplete.cubegs.fdswui.AuthorizationManager;



public class FdsBasePage extends BaseClassPage  {
	private static final long serialVersionUID = 1L;

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public FdsBasePage(String newViewName, Composite parent, int style, boolean inRoot) {
		super(newViewName, parent, style, inRoot);
	}

    /**
     * Log out the current user
     * @return  true - if an error happened, false - otherwise
     */
	@Override
	protected boolean doLogout() {
		String errorMessage = "";
		boolean errorFlag = false;
		
		// Store current user
		//ServletContext servletCtx = RWT.getUISession().getHttpSession().getServletContext();

		//int userId = (int) servletCtx.getAttribute(Constants.USER_ID);

		UISession uiSession = RWT.getUISession();
		
		if (uiSession != null) {
		    int userId = (int) uiSession.getAttribute(Constants.USER_ID);
		    
		    ReturnData rc = AuthorizationManager.doLogout(userId);
		    
		    if (rc.getErrorCode() == 0) {
		        // Reset current user
		        uiSession.removeAttribute(Constants.USER_NAME);
		        uiSession.removeAttribute(Constants.USER_ID);
		        uiSession.removeAttribute(Constants.ROLE_ID);
		        uiSession.removeAttribute(Constants.ROLE_NAME);
		        uiSession.removeAttribute(Constants.MISSION_NAME);
		        
		        // Go back to Login page		
		        SingletonViews.getInstance().changeView(Constants.LOGIN_VIEW_NAME);			
		    } else {
		        showError(errorMessage);
		    }		    
		}
		
		return errorFlag;
	}

	

	
	
	
	
	
	
	
	
//	protected ToolBar getFdsToolBar(Composite parent) {
//        ToolBar output = new ToolBar(parent, SWT.FLAT | SWT.RIGHT);
//        output.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1));
//        
//        
//        
//        
//        
//        // Real time HK TM
//        createHKTMMenu(output);
//        
//        // Offline HK TM
//        createOfflineHKTMMenu(output);
//        
//        // Telecommands
//        ToolItem tltmTc = new ToolItem(output, SWT.NONE);
//        tltmTc.addSelectionListener(new SelectionAdapter() {
//            /**
//			 * 
//			 */
//			private static final long serialVersionUID = 1L;
//
//			@Override
//            public void widgetSelected(SelectionEvent e) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_TC_VIEW_NAME);
//            }
//        });
//        tltmTc.setText("TC");
//        
//        // Files Manager
//        ToolItem tltmFilesManager = new ToolItem(output, SWT.NONE);
//        tltmFilesManager.addSelectionListener(new SelectionAdapter() {
//            /**
//			 * 
//			 */
//			private static final long serialVersionUID = 1L;
//
//			@Override
//            public void widgetSelected(SelectionEvent e) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_FILES_MANAGER_VIEW_NAME);
//            }
//        });
//        tltmFilesManager.setText("Files Manager");
//        
//        // Playback
//        ToolItem tltmPlayback = new ToolItem(output, SWT.NONE);
//        tltmPlayback.addSelectionListener(new SelectionAdapter() {
//            /**
//			 * 
//			 */
//			private static final long serialVersionUID = 1L;
//
//			@Override
//            public void widgetSelected(SelectionEvent e) {
//            }
//        });
//        tltmPlayback.setText("Playback");
//        
//        // Settings
//        createSettignsMenu(output);
//        
//        // Temporary. Manual G/S Connection
//        ToolItem tltmGsConnection = new ToolItem(output, SWT.NONE);
//        tltmGsConnection.addSelectionListener(new SelectionAdapter() {
//            /**
//			 * 
//			 */
//			private static final long serialVersionUID = 1L;
//
//			@Override
//            public void widgetSelected(SelectionEvent e) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_GS_CONNECTION_VIEW_NAME);
//            }
//        });
//        tltmGsConnection.setText("G/S Connection");
//        
//        return output;
//    }
//
//    /**
//     * REAL TIME Telemetry
//     * 
//     * @param inToolBar
//     */
//    private void createHKTMMenu(ToolBar inToolBar) {
//        ToolItem tltmHkTm = new ToolItem(inToolBar, SWT.DROP_DOWN);
//        tltmHkTm.setText(Constants.HK_TM_NAME);
//
//        DropdownSelectionListener listenerHkTm = new DropdownSelectionListener(tltmHkTm);
//        
//        MenuItem menuRtHkTm = new MenuItem( listenerHkTm.getMenu(), SWT.NONE);
//        
//        menuRtHkTm.setText(Constants.RT_HK_TM_NAME);
//        menuRtHkTm.addSelectionListener(new SelectionAdapter() {
//            private static final long serialVersionUID = 1L;
//
//            public void widgetSelected(SelectionEvent event) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_MAIN_VIEW_NAME);
//            }
//        });
//        
//        MenuItem menuRtPlot = new MenuItem( listenerHkTm.getMenu(), SWT.NONE);
//        
//        menuRtPlot.setText(Constants.RT_PLOT_NAME);
//        menuRtPlot.addSelectionListener(new SelectionAdapter() {
//            private static final long serialVersionUID = 1L;
//
//            public void widgetSelected(SelectionEvent event) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_RT_PLOT_VIEW_NAME);
//            }
//        });
//        
//        tltmHkTm.addSelectionListener(listenerHkTm);
//    }
//
//	/**
//	 * OFFLINE or BACK ORBIT Telemetry
//	 * 
//	 * @param inToolBar
//	 */
//    private void createOfflineHKTMMenu(ToolBar inToolBar) {
//        ToolItem tltmOfflineHkTm = new ToolItem(inToolBar, SWT.DROP_DOWN);
//        tltmOfflineHkTm.setText(Constants.OFFLINE_HK_TM_NAME);
//        
//        DropdownSelectionListener listenerOfflineHkTm = new DropdownSelectionListener(tltmOfflineHkTm);
//        
//        MenuItem menuOffHkTm = new MenuItem( listenerOfflineHkTm.getMenu(), SWT.NONE);
//        
//        menuOffHkTm.setText(Constants.OFFLINE_HK_TM_NAME);
//        menuOffHkTm.addSelectionListener(new SelectionAdapter() {
//            private static final long serialVersionUID = 1L;
//
//            public void widgetSelected(SelectionEvent event) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_OFFLINE_HK_TM_VIEW_NAME);
//            }
//        });
//
//        MenuItem menuOffPlot = new MenuItem( listenerOfflineHkTm.getMenu(), SWT.NONE);
//        
//        menuOffPlot.setText(Constants.OFFLINE_PLOT_NAME);
//        menuOffPlot.addSelectionListener(new SelectionAdapter() {
//            private static final long serialVersionUID = 1L;
//
//            public void widgetSelected(SelectionEvent event) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_OFFLINE_PLOT_VIEW_NAME);
//            }
//        });
//        
//        tltmOfflineHkTm.addSelectionListener(listenerOfflineHkTm);
//    }
//	
//	/**
//	 * SETTINGS
//	 * @param inToolBar
//	 */
//	private void createSettignsMenu(ToolBar inToolBar) {
//        ToolItem tlSettings = new ToolItem(inToolBar, SWT.DROP_DOWN);
//        tlSettings.setText(Constants.SETTINGS_NAME);
//
//        DropdownSelectionListener listenerSettings = new DropdownSelectionListener(tlSettings);
//        
//        MenuItem menuTcDef = new MenuItem( listenerSettings.getMenu(), SWT.NONE);
//        
//        menuTcDef.setText(Constants.SC_DB_NAME);
//        menuTcDef.addSelectionListener(new SelectionAdapter() {
//            private static final long serialVersionUID = 1L;
//
//            public void widgetSelected(SelectionEvent event) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_SC_DB_VIEW_NAME);
//            }
//        });
//        
//        MenuItem menuTmDef = new MenuItem( listenerSettings.getMenu(), SWT.NONE);
//        
//        menuTmDef.setText(Constants.FRAMES_NAME);
//        menuTmDef.addSelectionListener(new SelectionAdapter() {
//            private static final long serialVersionUID = 1L;
//
//            public void widgetSelected(SelectionEvent event) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_FRAMES_VIEW_NAME);
//            }
//        });
//        
//        MenuItem menuScreenDef = new MenuItem( listenerSettings.getMenu(), SWT.NONE);
//        
//        menuScreenDef.setText(Constants.SCREEN_NAME);
//        menuScreenDef.addSelectionListener(new SelectionAdapter() {
//            private static final long serialVersionUID = 1L;
//
//            public void widgetSelected(SelectionEvent event) {
//                // Activate the page
//                SingletonViews.getInstance().changeView(Constants.MCS_SCREEN_VIEW_NAME);
//            }
//        });
//                
//        tlSettings.addSelectionListener(listenerSettings);
//    }
//	
	
}
