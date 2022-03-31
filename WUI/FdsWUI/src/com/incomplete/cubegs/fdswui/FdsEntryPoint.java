package com.incomplete.cubegs.fdswui;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.eclipse.rap.rwt.RWT;
import org.eclipse.rap.rwt.application.AbstractEntryPoint;
import org.eclipse.rap.rwt.service.ApplicationContext;
import org.eclipse.rap.rwt.service.UISession;
import org.eclipse.rap.rwt.service.UISessionEvent;
import org.eclipse.rap.rwt.service.UISessionListener;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;
import org.mariadb.jdbc.MariaDbPoolDataSource;

import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.common.SingletonViews;
import com.incomplete.cubegs.common.ZeroMqManager;
import com.incomplete.cubegs.fdswui.view.FdsMainPage;
import com.incomplete.cubegs.fdswui.view.LoginPage;
import com.incomplete.cubegs.fdswui.view.RegisterPage;
import com.incomplete.cubegs.fdswui.view.ResetPasswordPage;



public class FdsEntryPoint extends AbstractEntryPoint {
    private static final long serialVersionUID = 1L;

    @Override
    protected void createContents(Composite parent) {
//        parent.setLayout(new GridLayout(2, false));
        
        System.out.println("INFO: Starting FDS WUI");
        
        try {
            try {
                ZeroMqManager.getInstance().connect();
            } catch(Exception e) {
                // Ignore it
            }
            
            // Close the session or browser
            RWT.getUISession().addUISessionListener( new UISessionListener() {
                private static final long serialVersionUID = 1L;

                public void beforeDestroy( UISessionEvent event ) {
                    // Perform cleanup    
                    
                    // Close NNG links
                    System.out.println("INFO: Closing NNG links");
                    ZeroMqManager.getInstance().disconnect();
                
                    // Close the user connection. Set as not logged, if he is still logged
                    System.out.println("INFO: Logging out current user");
                    
                    UISession uiSession = RWT.getUISession();
                    if (uiSession != null) {                        
                        int userId = (int) uiSession.getAttribute(Constants.USER_ID);
                        
                        ReturnData rc = DataManager.setUserAsLogged(userId, false);
                    }
                }
              } );

                        
            // Create connectio pool
            createConnectionPool();
            
            // Create views and register them
            SingletonViews views = SingletonViews.getInstance();

            views.initialize(parent);

            // Create pages
            FdsMainPage mainPage = new FdsMainPage(Constants.FDS_MAIN_VIEW_NAME, views.getContainer(), SWT.NONE);
            LoginPage login = new LoginPage(Constants.LOGIN_VIEW_NAME, views.getContainer(), SWT.APPLICATION_MODAL);
            ResetPasswordPage forgetPage = new ResetPasswordPage(Constants.RESET_VIEW_NAME, views.getContainer(), SWT.NONE);
            RegisterPage registerPage = new RegisterPage(Constants.REGISTER_VIEW_NAME, views.getContainer(), SWT.NONE);

            // Register pages
            views.registerView(Constants.FDS_MAIN_VIEW_NAME, mainPage);        
            views.registerView(Constants.LOGIN_VIEW_NAME, login);
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

	private void createConnectionPool() {
		Properties properties = new Properties();
		
		// This is required for Tomcat
		InputStream is = this.getClass().getClassLoader().getResourceAsStream("../resources/db.properties");

		try {
			properties.load( is );
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

		// This is required for Jetty (inside Eclipse)
		//properties.load( new FileInputStream("resources/url.properties") ); 

		// FDS DB
		// ----------------------------------------------------
		String fds_db_url = properties.getProperty("fds_db_url");
		String fds_db_user = properties.getProperty("fds_db_user");
		String fds_db_pwd = properties.getProperty("fds_db_pwd");
		
		String tmpUrl = "jdbc:mariadb:" + fds_db_url + 
				        "?user=" + fds_db_user + 
				        "&password=" + fds_db_pwd + 
				        "&maxPoolSize=10";
		//System.out.println("tmpUrl = " + tmpUrl);
		
//		MariaDbPoolDataSource fdsPool = new MariaDbPoolDataSource("jdbc:mariadb://server/db?user=myUser&maxPoolSize=10");
		MariaDbPoolDataSource fdsPool = new MariaDbPoolDataSource(tmpUrl);
		
		// Global for all the UI Sessions
		ApplicationContext appContext = RWT.getApplicationContext();

		appContext.setAttribute(Constants.FDS_POOL, fdsPool);
		

		
		// COMMON DB
		// ----------------------------------------------------
		String common_db_url = properties.getProperty("common_db_url");
		String common_db_user = properties.getProperty("common_db_user");
		String common_db_pwd = properties.getProperty("common_db_pwd");
		
		
		tmpUrl = "jdbc:mariadb:" + common_db_url + 
		         "?user=" + common_db_user + 
			     "&password=" + common_db_pwd + 
			     "&maxPoolSize=10";
		//System.out.println("tmpUrl = " + tmpUrl);
		
//		MariaDbPoolDataSource fdsPool = new MariaDbPoolDataSource("jdbc:mariadb://server/db?user=myUser&maxPoolSize=10");
		MariaDbPoolDataSource commonPool = new MariaDbPoolDataSource(tmpUrl);
		
		appContext.setAttribute(Constants.COMMON_POOL, commonPool);	
	}
}
