/**
 * Ground Segment As A Service (GSaaS).
 * CubeGS
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
 * @update Oct 2021
 */


package com.incomplete.cubegs.toolswui;

import org.eclipse.rap.rwt.application.AbstractEntryPoint;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;

import com.incomplete.cubegs.toolswui.view.ToolsConfigureMissionPage;
import com.incomplete.cubegs.toolswui.view.ToolsConfigurePage;
import com.incomplete.cubegs.toolswui.view.ToolsEditMissionPage;
import com.incomplete.cubegs.toolswui.view.ToolsMainPage;
import com.incomplete.cubegs.toolswui.view.ToolsOperatorsPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.HttpManager;
import com.incomplete.cubegs.common.SingletonViews;



public class ToolsEntryPoint extends AbstractEntryPoint {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
	protected void createContents(Composite parent) {
		System.out.println("INFO: Starting Tools WUI");

		try {
		    // Loading HTTP properties
            HttpManager unusedManager = new HttpManager();

			// Create views and register them
			SingletonViews views = SingletonViews.getInstance();

			views.initialize(parent);

			// Load first panel
			ToolsMainPage mainPage = new ToolsMainPage(Constants.TOOLS_MAIN_VIEW_NAME, views.getContainer(), SWT.NONE);

			// Edit parameters of the system
			ToolsConfigurePage configPage = new ToolsConfigurePage(Constants.TOOLS_CONFIG_VIEW_NAME,
					views.getContainer(), SWT.NONE);
			// Edit Mission parameters
			ToolsEditMissionPage editMssionPage = new ToolsEditMissionPage(Constants.TOOLS_EDIT_MISSION_VIEW_NAME,
					views.getContainer(), SWT.NONE);
			// Edit Satellites, Subsystems of the Mission
			ToolsConfigureMissionPage missionPage = new ToolsConfigureMissionPage(
					Constants.TOOLS_CONFIGURE_MISSION_VIEW_NAME, views.getContainer(), SWT.NONE);
			// Edit mission Operators
			ToolsOperatorsPage userPage = new ToolsOperatorsPage(Constants.TOOLS_OPERATOR_VIEW_NAME,
					views.getContainer(), SWT.NONE);

			views.registerView(Constants.TOOLS_MAIN_VIEW_NAME, mainPage);

			views.registerView(Constants.TOOLS_CONFIG_VIEW_NAME, configPage);
			views.registerView(Constants.TOOLS_EDIT_MISSION_VIEW_NAME, editMssionPage);
			views.registerView(Constants.TOOLS_CONFIGURE_MISSION_VIEW_NAME, missionPage);
			views.registerView(Constants.TOOLS_OPERATOR_VIEW_NAME, userPage);

			// Activate first page
			views.changeView(Constants.TOOLS_MAIN_VIEW_NAME);
		} catch (Exception e) {
			e.printStackTrace();

			System.err.println("ERROR: Exception: " + e);

			System.exit(-1);
		}
    }

}
