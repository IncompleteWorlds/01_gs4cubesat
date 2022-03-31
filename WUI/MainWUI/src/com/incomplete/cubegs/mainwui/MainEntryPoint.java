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
 * 
 * @update Sep 2021
 */

package com.incomplete.cubegs.mainwui;

//import org.eclipse.rap.rwt.RWT;
import org.eclipse.rap.rwt.application.AbstractEntryPoint;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;

import com.incomplete.cubegs.mainwui.view.ResetPasswordPage;
import com.incomplete.cubegs.mainwui.view.LoginPage;
import com.incomplete.cubegs.mainwui.view.MainPage;
import com.incomplete.cubegs.mainwui.view.RegisterPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.HttpManager;
import com.incomplete.cubegs.common.SingletonViews;



public class MainEntryPoint extends AbstractEntryPoint {
	private static final long serialVersionUID = 1L;
	
    /**
     * @wbp.parser.entryPoint
     */
    @Override
    protected void createContents(Composite parent) {
    	//parent.setLayout( new GridLayout( 1, false ) );
        
        System.out.println("INFO: Starting Main WUI");
        try {                                  
            // Loading HTTP properties
            HttpManager unusedManager = new HttpManager();
            
            // Create views and register them
            SingletonViews views = SingletonViews.getInstance();

            views.initialize(parent);

            // Load first panel
            LoginPage login = new LoginPage(Constants.LOGIN_VIEW_NAME, views.getContainer(), SWT.APPLICATION_MODAL);
            MainPage mainPage = new MainPage(Constants.MAIN_VIEW_NAME, views.getContainer(), SWT.NONE);
            ResetPasswordPage forgetPage = new ResetPasswordPage(Constants.RESET_VIEW_NAME, views.getContainer(), SWT.NONE);
            RegisterPage registerPage = new RegisterPage(Constants.REGISTER_VIEW_NAME, views.getContainer(), SWT.NONE);

            views.registerView(Constants.LOGIN_VIEW_NAME, login);
            views.registerView(Constants.MAIN_VIEW_NAME, mainPage);
            views.registerView(Constants.RESET_VIEW_NAME, forgetPage);
            views.registerView(Constants.REGISTER_VIEW_NAME, registerPage);

            // Activate first page
            views.changeView(Constants.LOGIN_VIEW_NAME);

        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.err.println("ERROR: Exception: " + e);
            
            System.exit(-1);
        }
    }

}


