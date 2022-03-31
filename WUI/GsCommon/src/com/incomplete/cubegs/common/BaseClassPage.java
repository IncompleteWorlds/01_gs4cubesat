
package com.incomplete.cubegs.common;

import javax.servlet.ServletContext;

import org.eclipse.rap.rwt.RWT;
import org.eclipse.rap.rwt.service.UISession;
import org.eclipse.rap.rwt.widgets.DialogCallback;
import org.eclipse.swt.SWT;
import org.eclipse.swt.browser.Browser;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.MenuItem;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.swt.widgets.ToolItem;
import org.eclipse.wb.swt.SWTResourceManager;




public abstract class BaseClassPage extends Composite {
	private static final long serialVersionUID = 1L;
	
	protected String viewName = "";
	
	protected Label lblUserName = null;
	
	protected Label lblMissionName = null;
	
	protected Label lblFunctionName = null;
	
	protected Text textUTCTime = null;

	protected Text textNextPass = null;
	
	protected Text textConnStatus = null;
	
	protected boolean isRoot = false;
	
	protected int output = SWT.NO;

	
	public BaseClassPage(String newViewName, Composite parent, int style, boolean inRoot) {
		super(parent, style | SWT.H_SCROLL | SWT.V_SCROLL);
		
		this.viewName = newViewName;
		this.isRoot = inRoot;
		
		GridLayout gridLayout = new GridLayout(1, false);
		gridLayout.verticalSpacing = 3;
		gridLayout.horizontalSpacing = 3;
		gridLayout.marginHeight = 3;
		gridLayout.marginWidth = 3;
		setLayout(gridLayout);
				
		//Composite h = getHeaderComposite(parent, "mission", "function");
		
		//Composite c = new Composite(parent, SWT.NONE);
		
		//c.setSize(800, 600);
		
		//Composite f = getFooterComposite(parent);
	}
	
	public String getViewName() {
		return this.viewName;
	}
		
	public Label getUserName() {
		return lblUserName;
	}

	public void setUserName(String inUserName) {
		this.lblUserName.setText(inUserName);
	}

	public Label getMissionName() {
		return lblMissionName;
	}

	public void setMissionName(String inMissionName) {
		this.lblMissionName.setText(inMissionName);
	}

	public Label getFunctionName() {
		return lblFunctionName;
	}

	public void setFunctionName(String inFunctionName) {
		this.lblFunctionName.setText(inFunctionName);
	}

	public void setUTCTime(String inUTCTime) {
		System.out.println("**** TIME: " + inUTCTime);
		
		this.textUTCTime.setText(inUTCTime);
	}

	public void setNextPass(String inNextPass) {
		this.textNextPass.setText(inNextPass);
	}

	/**
	 * It will be invoked when the view is activated 
	 */
	public void start() {
		//System.out.println("***** Start ***** " + viewName);
		
		// Get current user
		//HttpSession httpSession = RWT.getUISession().getHttpSession();
		ServletContext servletCtx = RWT.getUISession().getHttpSession().getServletContext();
		
		System.out.println(" **** Current context: " + servletCtx.getContextPath() );
	    
        UISession uiSession = RWT.getUISession();
        
		String tmpUserName = (String) uiSession.getAttribute(Constants.USER_NAME);
		if (tmpUserName != null) {			
			setUserName(tmpUserName);
		}
		
		// Get mission
		String tmpMissionName = (String) uiSession.getAttribute(Constants.MISSION_NAME);
		if (tmpMissionName != null) {			
			setMissionName(tmpMissionName);
		} 
		
		// Get current time
		setUTCTime( TimeUtil.getCurrentUTCTimeAsString() );
	}

	
	/**
	 * It will be invoked when the view is de-activated 
	 */
    public void stop() {
    }
    
    /**
     * This callback is invoked when back button is pressed
     */
    public void backButton() {
    	
    }
    
    protected Composite getHeaderComposite(Composite parent, String functionName) {
    	//System.out.println("***** getHeaderComposite ****** " + missionName + functionName + "-" + viewName);
    	
		Composite output = new Composite(parent, SWT.NONE);
		
		GridLayout gl_output = new GridLayout(6, false);
		gl_output.verticalSpacing = 3;
		gl_output.horizontalSpacing = 3;
		gl_output.marginHeight = 3;
		gl_output.marginWidth = 3;
		output.setLayout(gl_output);
		output.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		output.setBackground(SWTResourceManager.getColor(255, 204, 0));
		
		Button lblLogo = new Button(output, SWT.FLAT | SWT.CENTER);
		lblLogo.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Navigate to main page URL
				Browser browser = new Browser( parent, SWT.NONE );
				
				browser.setText( "<a href=\"http://www.google.com/\" target=\"_blank\">Plain Link</a>" );
				
				// Check logout
			}
		});
		lblLogo.setImage(SWTResourceManager.getImage(BaseClassPage.class, "/com/incomplete/cubegs/resources/IW-logo-48.png"));
		lblLogo.setBackground(SWTResourceManager.getColor(255, 204, 0));
		
		if (this.isRoot == false) {			
			Button btnBack = new Button(output, SWT.FLAT);
			
			btnBack.addSelectionListener(new SelectionAdapter() {
				private static final long serialVersionUID = 1L;

				@Override
				public void widgetSelected(SelectionEvent e) {
					backButton();
				}
			});
			
			btnBack.setImage(SWTResourceManager.getImage(BaseClassPage.class, "/com/incomplete/cubegs/resources/left_arrow.png"));
		}
		
		
		lblMissionName = new Label(output, SWT.CENTER);
		lblMissionName.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		lblMissionName.setFont(SWTResourceManager.getFont("Verdana", 18, SWT.NORMAL));
     	lblMissionName.setText("No mission");

		lblFunctionName = new Label(output, SWT.CENTER);
		lblFunctionName.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		lblFunctionName.setFont(SWTResourceManager.getFont("Verdana", 18, SWT.NORMAL));
		if (functionName != null) {
			lblFunctionName.setText(functionName);			
		}
		
	    lblUserName = new Label(output, SWT.CENTER);
	    lblUserName.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblUserName.setBackground(SWTResourceManager.getColor(255, 204, 0));
		lblUserName.setAlignment(SWT.CENTER);
		lblUserName.setFont(SWTResourceManager.getFont("Arial", 11, SWT.BOLD));
		lblUserName.setText("");
		lblUserName.setSize(75, 30);
		
	    
	    ToolBar toolBar = new ToolBar(output, SWT.FLAT | SWT.RIGHT);
	    toolBar.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
	    
	    ToolItem tltmDropdownItem = new ToolItem(toolBar, SWT.DROP_DOWN);
	    tltmDropdownItem.setImage(SWTResourceManager.getImage(BaseClassPage.class, "/com/incomplete/cubegs/resources/settings_32_32.png"));
	    tltmDropdownItem.setToolTipText("Settings");
	    
        DropdownSelectionListener listenerOne = new DropdownSelectionListener(tltmDropdownItem); //, this);
        
        MenuItem menuItemUser = new MenuItem( listenerOne.getMenu(), SWT.NONE);
        
        menuItemUser.setText(Constants.USER_PROFILE);
        menuItemUser.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // TODO: Show user profile dialog
            }
        });
        
        MenuItem menuItemLogout = new MenuItem( listenerOne.getMenu(), SWT.NONE);
        
        menuItemLogout.setText(Constants.LOGOUT);
        menuItemLogout.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            public void widgetSelected(SelectionEvent event) {
                // TODO: Logout. M&C server
                // M&C will notify all other servers
                
                MessageBox messageBox = new MessageBox(getShell(), SWT.ICON_QUESTION | SWT.YES | SWT.NO);
                
                messageBox.setMessage("Do you really want to logout?");
                messageBox.setText("Logout Application");
                
                messageBox.open(new DialogCallback() {
					private static final long serialVersionUID = 1L;

					@Override
                    public void dialogClosed(int returnCode) {
                        if (returnCode == SWT.YES) {
                        	doLogout();
//                            if (doLogout() == 0) {
//                                // Come back to Login page
//                                // Get access to views
//                                SingletonViews views = SingletonViews.getInstance();
//                                
//                                views.changeView(Constants.LOGIN_VIEW_NAME);
//                            }
                            
                                                        
                            // Dispose all resources
                            //SWTResourceManager.dispose();
                            
                            //System.exit(0);
                        }
                    }
                });
            }
        });
        
        tltmDropdownItem.addSelectionListener(listenerOne);	        

	    toolBar.pack();
	    
	    return output;
	}
    
    /**
     * Delegate the logout operation to the base class of each subsystem
     * @return  true - if an error happened, false - otherwise
     */
    abstract protected boolean doLogout();
    
    /**
     * Send a message to the server to logout the current user
     * 
     * @return 0 - successful logout
     *         -1 - Error
     */
//    protected int doLogout() {
//        int output = -1;
//        
//        // Get current user
//        ServletContext servletCtx = RWT.getUISession().getHttpSession().getServletContext();
//        
//        String userId = (String) servletCtx.getAttribute(Constants.USER_ID);
//        String jwtToken = (String) servletCtx.getAttribute(Constants.JWT_TOKEN);
//        
//        if (jwtToken == null || jwtToken.isEmpty() == true) {
//            showError("Authorisation token is empty. Nothing is done");
//            return output;
//        }
//        
//        if (userId != null) {          
//            LogoutMessage logoutMsg = new LogoutMessage(userId);
//            
//            logoutMsg.setAuthenticationKey(jwtToken);
//            
//            // Send the message. Store the answer
//            try {
//                LogoutResponse logoutResponse = HttpManager.sendRequest(logoutMsg, LogoutResponse.class);
//                
//                if (logoutResponse.getStatus() == HttpURLConnection.HTTP_OK) {  
//                    showWarning("User correctly logged out");
//                    output = 0;
//                } else {
//                    showError(logoutResponse.getDetail());
//                }
//            } catch (Exception e) {
//                e.printStackTrace();
//                
//                showError("Exception: " + e.toString());
//            }
//        } else {
//            showWarning("No logged user. Nothing is done");
//            output = 0;
//        }
//        
//        return output;
//    }
	
	protected Composite getFooterComposite(Composite parent) {	
		//System.out.println("***** getFooterComposite ******");
		
	    Composite output = new Composite(parent, SWT.NONE);
		
		GridLayout gl_output = new GridLayout(7, false);
		gl_output.verticalSpacing = 3;
		gl_output.horizontalSpacing = 3;
		gl_output.marginHeight = 3;
		gl_output.marginWidth = 3;
		output.setLayout(gl_output);
		output.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		output.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Label lblIW = new Label(output, SWT.NONE);
		lblIW.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		lblIW.setBackground(SWTResourceManager.getColor(255, 255, 255));
		lblIW.setFont(SWTResourceManager.getFont("Verdana", 11, SWT.BOLD));
		lblIW.setAlignment(SWT.CENTER);
		lblIW.setText(Constants.COPYRIGHT_TEXT);
		
		// Next Pass
		Label lblNextPass = new Label(output, SWT.NONE);
		lblNextPass.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblNextPass.setText("Next pass:");
		
		textNextPass = new Text(output, SWT.NONE);
		textNextPass.setEnabled(false);
		textNextPass.setEditable(false);
		textNextPass.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		
		// Connection Status
		Label lblConnStatus = new Label(output, SWT.NONE);
		lblConnStatus.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblConnStatus.setText("Conn. status:");
		
		textConnStatus = new Text(output, SWT.NONE);
		textConnStatus.setEnabled(false);
		textConnStatus.setEditable(false);
		textConnStatus.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		
		// UTC Time
		Label label = new Label(output, SWT.NONE);
		label.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		label.setText("Current UTC Time: ");
		
		textUTCTime = new Text(output, SWT.NONE);
		textUTCTime.setEnabled(false);
		textUTCTime.setEditable(false);
		GridData gd_textUTCTime = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_textUTCTime.widthHint = 135;
		textUTCTime.setLayoutData(gd_textUTCTime);
		new Label(output, SWT.NONE);
		
		return output;
	}
	
	public void showError(String inMessage) {
		final String tmpErrorMessage = inMessage;
        
        // Show error
        this.getDisplay().syncExec(new Runnable() {
            public void run() {
                MessageBox msg = new MessageBox(getShell(), SWT.APPLICATION_MODAL);
                msg.setText("Error");
                msg.setMessage(tmpErrorMessage);

                msg.open(null);
            }
        });
	}
	
	public void showWarning(String inMessage) {
		final String tmpErrorMessage = inMessage;
        
        // Show error
        this.getDisplay().syncExec(new Runnable() {
            public void run() {
                MessageBox msg = new MessageBox(getShell(), SWT.APPLICATION_MODAL);
                msg.setText("Warning");
                msg.setMessage(tmpErrorMessage);

                msg.open(null);
            }
        });
	}
	
//	protected int yesNoQuestion(String inTitle, String inQuestion) {
//		this.output = SWT.NO;
//		
//		MessageBox messageBox = new MessageBox(getShell(), SWT.APPLICATION_MODAL | SWT.ICON_QUESTION | SWT.YES | SWT.NO);
//        
//        messageBox.setMessage(inQuestion);
//        messageBox.setText(inTitle);
//        
//        messageBox.open(new DialogCallback() {
//			private static final long serialVersionUID = 1L;
//
//			@Override
//            public void dialogClosed(int returnCode) {
//                if (returnCode == SWT.YES) {                    
//                	setYesNoQuestionOutput(SWT.YES);
//                }
//            }
//        });
//        
//		return this.output;
//	}
	
	protected void setYesNoQuestionOutput(int inReturnCode) {
		this.output = inReturnCode;
	}
}
