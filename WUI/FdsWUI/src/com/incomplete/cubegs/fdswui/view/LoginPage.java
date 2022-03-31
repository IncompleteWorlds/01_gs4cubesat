package com.incomplete.cubegs.fdswui.view;

import org.eclipse.swt.widgets.Composite;

//import javax.servlet.ServletContext;

import org.eclipse.rap.rwt.RWT;
import org.eclipse.rap.rwt.service.UISession;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.browser.Browser;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Link;
import org.eclipse.swt.widgets.MessageBox;

import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.common.SingletonViews;
import com.incomplete.cubegs.fdswui.AuthorizationManager;
import com.incomplete.cubegs.fdswui.DbUser;

import org.eclipse.swt.events.TraverseListener;
import org.eclipse.swt.events.TraverseEvent;



public class LoginPage extends FdsBasePage {
	private static final long serialVersionUID = 1L;
	
	private Text textUserName;
	private Text textPasswd;

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public LoginPage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style, true);
		
		setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
		setBackground(SWTResourceManager.getColor(255, 255, 255));
		setLayout(new GridLayout(1, false));
		
		Composite compHeader = new Composite(this, SWT.NONE);
		compHeader.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		compHeader.setBackground(SWTResourceManager.getColor(255, 204, 0));
		RowLayout rl_compHeader = new RowLayout(SWT.HORIZONTAL);
		rl_compHeader.fill = true;
		rl_compHeader.wrap = false;
		compHeader.setLayout(rl_compHeader);
		
		Button lblLogo = new Button(compHeader, SWT.FLAT | SWT.CENTER);
		lblLogo.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Navigate to main page URL
				Browser browser = new Browser( parent, SWT.NONE );
				
				browser.setText( "<a href=\"http://google.com/\" target=\"_blank\">Plain Link</a>" );
				// Check logout
			}
		});
		lblLogo.setImage(SWTResourceManager.getImage(LoginPage.class, "/com/incomplete/cubegs/resources/IW-logo.png"));
		lblLogo.setBackground(SWTResourceManager.getColor(255, 204, 0));
		
		Composite compContent = new Composite(this, SWT.NONE);
		compContent.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, true, 1, 1));
		compContent.setBackground(SWTResourceManager.getColor(255, 255, 255));
		RowLayout rl_compContent = new RowLayout(SWT.HORIZONTAL);
		rl_compContent.justify = true;
		rl_compContent.wrap = false;
		rl_compContent.center = true;
		rl_compContent.fill = true;
		rl_compContent.marginRight = 50;
		rl_compContent.marginLeft = 50;
		rl_compContent.marginTop = 50;
		rl_compContent.marginBottom = 50;
		compContent.setLayout(rl_compContent);
		
		Composite composite = new Composite(compContent, SWT.BORDER);
		composite.setBackground(SWTResourceManager.getColor(255, 255, 255));
		GridLayout gl_composite = new GridLayout(2, false);
		gl_composite.verticalSpacing = 10;
		gl_composite.marginTop = 5;
		gl_composite.marginRight = 5;
		gl_composite.marginLeft = 5;
		gl_composite.marginBottom = 5;
		composite.setLayout(gl_composite);
		
		Label lblEnterUserDetails = new Label(composite, SWT.NONE);
		lblEnterUserDetails.setForeground(SWTResourceManager.getColor(255, 255, 255));
		lblEnterUserDetails.setBackground(SWTResourceManager.getColor(153, 204, 255));
		GridData gd_lblEnterUserDetails = new GridData(SWT.FILL, SWT.CENTER, false, false, 2, 1);
		gd_lblEnterUserDetails.widthHint = 374;
		gd_lblEnterUserDetails.heightHint = 30;
		lblEnterUserDetails.setLayoutData(gd_lblEnterUserDetails);
		lblEnterUserDetails.setAlignment(SWT.CENTER);
		lblEnterUserDetails.setText("Enter user details");
		lblEnterUserDetails.setFont(SWTResourceManager.getFont("Verdana", 14, SWT.BOLD));
		
		Label lblUserName = new Label(composite, SWT.NONE);
		//lblUserName.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		GridData gd_lblUserName = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_lblUserName.widthHint = 152;
		lblUserName.setLayoutData(gd_lblUserName);
		lblUserName.setFont(SWTResourceManager.getFont("Verdana", 14, SWT.NORMAL));
		lblUserName.setText("User name");
		
		textUserName = new Text(composite, SWT.BORDER);
		textUserName.addTraverseListener(new TraverseListener() {
			private static final long serialVersionUID = 1L;

			public void keyTraversed(TraverseEvent e) {
				if (e.detail == SWT.TRAVERSE_RETURN) {
					doLogin();
				}
			}
		});
		textUserName.setToolTipText("");
		textUserName.setFont(SWTResourceManager.getFont("Verdana", 14, SWT.NORMAL));
		GridData gd_textUserName = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textUserName.widthHint = 150;
		textUserName.setLayoutData(gd_textUserName);
		textUserName.setFocus();
		
		Label lblPassword = new Label(composite, SWT.NONE);
		//lblPassword.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		lblPassword.setFont(SWTResourceManager.getFont("Verdana", 14, SWT.NORMAL));
		lblPassword.setText("Password");
		
		textPasswd = new Text(composite, SWT.BORDER | SWT.PASSWORD);
		textPasswd.addTraverseListener(new TraverseListener() {
			private static final long serialVersionUID = 1L;

			public void keyTraversed(TraverseEvent e) {
				if (e.detail == SWT.TRAVERSE_RETURN) {
					doLogin();
				}
			}
		});

		GridData gd_textPasswd = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textPasswd.widthHint = 150;
		textPasswd.setLayoutData(gd_textPasswd);
		textPasswd.setFont(SWTResourceManager.getFont("Verdana", 14, SWT.NORMAL));
		
		Composite composite_1 = new Composite(composite, SWT.NONE);
		composite_1.setBackground(SWTResourceManager.getColor(255, 255, 255));
		composite_1.setLayoutData(new GridData(SWT.CENTER, SWT.FILL, true, false, 2, 1));
		composite_1.setLayout(new GridLayout(4, false));
		
		Link linkForget = new Link(composite_1, SWT.NONE);
		GridData gd_linkForget = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_linkForget.widthHint = 140;
		linkForget.setLayoutData(gd_linkForget);
		linkForget.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
			    // Change view
                SingletonViews.getInstance().changeView( Constants.RESET_VIEW_NAME );  
			}
		});
		linkForget.setFont(SWTResourceManager.getFont("Sans", 12, SWT.NORMAL));
		linkForget.setBackground(SWTResourceManager.getColor(255, 255, 255));
		linkForget.setText("<a>Forget password</a>");
		
		Button btnLogin = new Button(composite_1, SWT.NONE);
		GridData gd_btnLogin = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
		gd_btnLogin.heightHint = 35;
		gd_btnLogin.widthHint = 100;
		btnLogin.setLayoutData(gd_btnLogin);
		btnLogin.setFont(SWTResourceManager.getFont("Sans", 12, SWT.NORMAL));
		btnLogin.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				doLogin();
			}
		});
		btnLogin.setText("Login");
		
		Label lblOr = new Label(composite_1, SWT.NONE);
		lblOr.setText("or");
		
		Button btnRegister = new Button(composite_1, SWT.NONE);
		GridData gd_btnRegister = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnRegister.widthHint = 100;
		gd_btnRegister.heightHint = 35;
		btnRegister.setLayoutData(gd_btnRegister);
		btnRegister.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Change view
                SingletonViews.getInstance().changeView( Constants.REGISTER_VIEW_NAME );
			}
		});
		btnRegister.setFont(SWTResourceManager.getFont("Sans", 12, SWT.NORMAL));
		btnRegister.setText("Register");
		
		Composite compBottom = new Composite(this, SWT.NONE);
		compBottom.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		compBottom.setBackground(SWTResourceManager.getColor(255, 255, 255));
		RowLayout rl_compBottom = new RowLayout(SWT.HORIZONTAL);
		rl_compBottom.fill = true;
		rl_compBottom.wrap = false;
		compBottom.setLayout(rl_compBottom);
		
		Label lblIW = new Label(compBottom, SWT.NONE);
		lblIW.setBackground(SWTResourceManager.getColor(255, 255, 255));
		lblIW.setFont(SWTResourceManager.getFont("Verdana", 11, SWT.BOLD));
		lblIW.setAlignment(SWT.CENTER);
		lblIW.setText(Constants.COPYRIGHT_TEXT);
	}


	@Override
	public void start() {
	    if (textUserName != null) {	        
	        textUserName.setText("");
	    }
	    if (textPasswd != null) { 
	        textPasswd.setText("");
	    }
	}

	@Override
	public void stop() {
	}
	
    private void doLogin() {
        boolean  errorFlag = false;
        String   errorMessage = "";

        if (textUserName.getText().isEmpty() == false && textPasswd.getText().isEmpty() == false) {
        	DbUser dbUser = new DbUser();
        	
        	ReturnData rc = AuthorizationManager.doLogin(textUserName.getText(), textPasswd.getText(), dbUser);
                      
        	if (rc.getErrorCode() == 0) {
        		// Store current user
//        		ServletContext servletCtx = RWT.getUISession().getHttpSession().getServletContext();
        		UISession uiSession = RWT.getUISession();

        		uiSession.setAttribute(Constants.USER_NAME,      dbUser.getUserName());
        		uiSession.setAttribute(Constants.USER_ID,        dbUser.getId());
        		uiSession.setAttribute(Constants.ROLE_ID,        dbUser.getRoleId());
        		uiSession.setAttribute(Constants.ROLE_NAME,      dbUser.getRoleName());
        		uiSession.setAttribute(Constants.MISSION_NAME,   "mission1");
                uiSession.setAttribute(Constants.SATELLITE_NAME, "NONE");
        		
        		// Change view
        		SingletonViews.getInstance().changeView(Constants.FDS_MAIN_VIEW_NAME);
        	} else {
        	    errorFlag = true;
        	    errorMessage = rc.getErrorMessage();
        	}
        	
//            Future future = MyThreadPool.getInstance().getService().submit(new Callable(){
//                public Object call() throws Exception {
//                }
//            });
//
//            try {
//                returnData = (MsgLoginResponse) future.get();
//            } catch (InterruptedException | ExecutionException e) {
//            }
            
//                    } catch (Exception e) {
//                        getDisplay().syncExec(new Runnable() {
//                            public void run() {
//                                MessageBox msg = new MessageBox(getShell(), SWT.APPLICATION_MODAL);
//                                msg.setText("Error");
//                                msg.setMessage(e.getMessage());
//                                msg.open();
//                            }
//                        });
//                    }
//                }
//            });
        } else {
            errorFlag = true;
            errorMessage = "Invalid parameters. Please, enter valid data";
        }
        
        if (errorFlag == true) {
            final String tmpErrorMessage = errorMessage;
            
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
    }

	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
}
