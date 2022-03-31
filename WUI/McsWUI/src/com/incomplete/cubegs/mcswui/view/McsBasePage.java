package com.incomplete.cubegs.mcswui.view;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import com.incomplete.cubegs.common.BaseClassPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.DropdownSelectionListener;
import com.incomplete.cubegs.common.SingletonViews;

import org.eclipse.swt.widgets.MenuItem;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.swt.widgets.ToolItem;



public class McsBasePage extends BaseClassPage  {
	private static final long serialVersionUID = 1L;

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public McsBasePage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style, true);
	}
	
	protected ToolBar getMcsToolBar(Composite parent) {
        ToolBar output = new ToolBar(parent, SWT.FLAT | SWT.RIGHT);
        output.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1));
        
        // Real time HK TM
        createHKTMMenu(output);
        
        // Offline HK TM
        createOfflineHKTMMenu(output);
        
        // Telecommands
        ToolItem tltmTc = new ToolItem(output, SWT.NONE);
        tltmTc.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_TC_VIEW_NAME);
            }
        });
        tltmTc.setText("TC");
        
        // Files Manager
        ToolItem tltmFilesManager = new ToolItem(output, SWT.NONE);
        tltmFilesManager.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_FILES_MANAGER_VIEW_NAME);
            }
        });
        tltmFilesManager.setText("Files Manager");
        
        // Playback
        ToolItem tltmPlayback = new ToolItem(output, SWT.NONE);
        tltmPlayback.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
            }
        });
        tltmPlayback.setText("Playback");
        
        // Settings
        createSettignsMenu(output);
        
        // Temporary. Manual G/S Connection
        ToolItem tltmGsConnection = new ToolItem(output, SWT.NONE);
        tltmGsConnection.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_GS_CONNECTION_VIEW_NAME);
            }
        });
        tltmGsConnection.setText("G/S Connection");
        
        return output;
    }

    /**
     * REAL TIME Telemetry
     * 
     * @param inToolBar
     */
    private void createHKTMMenu(ToolBar inToolBar) {
        ToolItem tltmHkTm = new ToolItem(inToolBar, SWT.DROP_DOWN);
        tltmHkTm.setText(Constants.HK_TM_NAME);

        DropdownSelectionListener listenerHkTm = new DropdownSelectionListener(tltmHkTm);
        
        MenuItem menuRtHkTm = new MenuItem( listenerHkTm.getMenu(), SWT.NONE);
        
        menuRtHkTm.setText(Constants.RT_HK_TM_NAME);
        menuRtHkTm.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_MAIN_VIEW_NAME);
            }
        });
        
        MenuItem menuRtPlot = new MenuItem( listenerHkTm.getMenu(), SWT.NONE);
        
        menuRtPlot.setText(Constants.RT_PLOT_NAME);
        menuRtPlot.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_RT_PLOT_VIEW_NAME);
            }
        });
        
        tltmHkTm.addSelectionListener(listenerHkTm);
    }

	/**
	 * OFFLINE or BACK ORBIT Telemetry
	 * 
	 * @param inToolBar
	 */
    private void createOfflineHKTMMenu(ToolBar inToolBar) {
        ToolItem tltmOfflineHkTm = new ToolItem(inToolBar, SWT.DROP_DOWN);
        tltmOfflineHkTm.setText(Constants.OFFLINE_HK_TM_NAME);
        
        DropdownSelectionListener listenerOfflineHkTm = new DropdownSelectionListener(tltmOfflineHkTm);
        
        MenuItem menuOffHkTm = new MenuItem( listenerOfflineHkTm.getMenu(), SWT.NONE);
        
        menuOffHkTm.setText(Constants.OFFLINE_HK_TM_NAME);
        menuOffHkTm.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_OFFLINE_HK_TM_VIEW_NAME);
            }
        });

        MenuItem menuOffPlot = new MenuItem( listenerOfflineHkTm.getMenu(), SWT.NONE);
        
        menuOffPlot.setText(Constants.OFFLINE_PLOT_NAME);
        menuOffPlot.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_OFFLINE_PLOT_VIEW_NAME);
            }
        });
        
        tltmOfflineHkTm.addSelectionListener(listenerOfflineHkTm);
    }
	
	/**
	 * SETTINGS
	 * @param inToolBar
	 */
	private void createSettignsMenu(ToolBar inToolBar) {
        ToolItem tlSettings = new ToolItem(inToolBar, SWT.DROP_DOWN);
        tlSettings.setText(Constants.SETTINGS_NAME);

        DropdownSelectionListener listenerSettings = new DropdownSelectionListener(tlSettings);
        
        MenuItem menuTcDef = new MenuItem( listenerSettings.getMenu(), SWT.NONE);
        
        menuTcDef.setText(Constants.SC_DB_NAME);
        menuTcDef.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_SC_DB_VIEW_NAME);
            }
        });
        
        MenuItem menuTmDef = new MenuItem( listenerSettings.getMenu(), SWT.NONE);
        
        menuTmDef.setText(Constants.FRAMES_NAME);
        menuTmDef.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_FRAMES_VIEW_NAME);
            }
        });
        
        MenuItem menuScreenDef = new MenuItem( listenerSettings.getMenu(), SWT.NONE);
        
        menuScreenDef.setText(Constants.SCREEN_NAME);
        menuScreenDef.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // Activate the page
                SingletonViews.getInstance().changeView(Constants.MCS_SCREEN_VIEW_NAME);
            }
        });
                
        tlSettings.addSelectionListener(listenerSettings);
    }
	
	
}
