package com.incomplete.cubegs.fdswui.view;


import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.ControlAdapter;
import org.eclipse.swt.events.ControlEvent;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.wb.swt.SWTResourceManager;

import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.EnumRole;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.common.SingletonViews;
import com.incomplete.cubegs.fdswui.DataManager;
import com.incomplete.cubegs.fdswui.DbUser;




public class RegisterPage extends FdsBasePage {
	private static final long serialVersionUID = 1L;

	private Text textUserName;
	private Text textEmail1;
	private Text textEmail2;
	private Text textPassword1;
	private Text textPassword2;
	private Text textFirstName;
	private Text textLastName;
//	private Text textMissionName;
//	private Text textMissionDescription;
//	private Text textOwner;
//	private Text textCountry;
	
	// They have to be local otherwise WindowsBuiler does not work
	protected Composite compHeader = null; 
	protected Composite compContent = null;
	protected Composite compFooter = null;
	protected ScrolledComposite scrollComposite = null;
	protected Composite compRegContent = null;
	
	
	public RegisterPage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style, true);
	
		setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
		setBackground(SWTResourceManager.getColor(255, 255, 255));
		setLayout(new GridLayout(1, false));
		
		// Header
	    compHeader = getHeaderComposite(this, "Register");
	
		
	    // Central Content
	    compContent = new Composite(this, SWT.NONE);	    
        compContent.setLayout(new GridLayout(1, false));
        compContent.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
        compContent.setBackground(SWTResourceManager.getColor(255, 255, 255));      
        

        // Add Scroll
        ScrolledComposite scrollComposite = new ScrolledComposite(compContent, SWT.V_SCROLL | SWT.H_SCROLL | SWT.BORDER);
        scrollComposite.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
        	      
	    compRegContent = new Composite(scrollComposite, SWT.NONE);
	    compRegContent.setLayout(new GridLayout(1, false));
	    compRegContent.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, true, 1, 1));

		Label lblNewLabel = new Label(compRegContent, SWT.NONE);
		lblNewLabel.setText("Please, enter your user name and password.");

		Label lblNoteYouWill = new Label(compRegContent, SWT.NONE);
		lblNoteYouWill.setText("NOTE: You will become the Administrator of the mission. If you need to create Operators, go to Tools menu and select User Management");

		Label lblNewLabel_3 = new Label(compRegContent, SWT.NONE);
		lblNewLabel_3.setText("You will only be able to create one Mission");
		GridData lblPleaseEnterYourLData = new GridData();
		lblPleaseEnterYourLData.widthHint = 107;
		lblPleaseEnterYourLData.heightHint = 21;
		GridData gd_userNameText = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_userNameText.widthHint = 150;
		new Label(compRegContent, SWT.NONE);

		Group grpUserDetails = new Group(compRegContent, SWT.NONE);
		grpUserDetails.setText("User Details");
		grpUserDetails.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 2, 1));
		grpUserDetails.setLayout(new GridLayout(2, false));

		Label lblNewLabel_2 = new Label(grpUserDetails, SWT.NONE);
		lblNewLabel_2.setFont(SWTResourceManager.getFont("Liberation Sans", 12, SWT.NORMAL));
		lblNewLabel_2.setText("First Name");

		textFirstName = new Text(grpUserDetails, SWT.BORDER);
		GridData gd_textFirstName = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textFirstName.widthHint = 200;
		textFirstName.setLayoutData(gd_textFirstName);

		Label lblLastName = new Label(grpUserDetails, SWT.NONE);
		lblLastName.setText("Last Name");
		lblLastName.setFont(SWTResourceManager.getFont("Liberation Sans", 12, SWT.NORMAL));

		textLastName = new Text(grpUserDetails, SWT.BORDER);
		GridData gd_textLastName = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textLastName.widthHint = 200;
		textLastName.setLayoutData(gd_textLastName);

		Label lblPleaseEnterYour = new Label(grpUserDetails, SWT.WRAP);
		lblPleaseEnterYour.setFont(SWTResourceManager.getFont("Liberation Mono", 12, SWT.NORMAL));
		lblPleaseEnterYour.setText("User name");

		textUserName = new Text(grpUserDetails, SWT.BORDER);
		GridData gd_textUserName = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textUserName.widthHint = 150;
		textUserName.setLayoutData(gd_textUserName);

		Label lblPassword = new Label(grpUserDetails, SWT.WRAP);
		lblPassword.setText("Password");
		lblPassword.setFont(SWTResourceManager.getFont("Liberation Mono", 12, SWT.NORMAL));

		textPassword1 = new Text(grpUserDetails, SWT.BORDER | SWT.PASSWORD);
		GridData gd_textPassword1 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textPassword1.widthHint = 150;
		textPassword1.setLayoutData(gd_textPassword1);

		Label lblReenterPassword = new Label(grpUserDetails, SWT.WRAP);
		lblReenterPassword.setText("Re-enter password");
		lblReenterPassword.setFont(SWTResourceManager.getFont("Liberation Mono", 12, SWT.NORMAL));

		textPassword2 = new Text(grpUserDetails, SWT.BORDER | SWT.PASSWORD);
		GridData gd_textPassword2 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textPassword2.widthHint = 150;
		textPassword2.setLayoutData(gd_textPassword2);

		Label lblNewLabel_1 = new Label(grpUserDetails, SWT.NONE);
		lblNewLabel_1.setFont(SWTResourceManager.getFont("Liberation Mono", 12, SWT.NORMAL));
		lblNewLabel_1.setText("Email address");

		textEmail1 = new Text(grpUserDetails, SWT.BORDER);
		GridData gd_textEmail1 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textEmail1.widthHint = 250;
		textEmail1.setLayoutData(gd_textEmail1);

		Label lblEnterYourEmail = new Label(grpUserDetails, SWT.WRAP);
		lblEnterYourEmail.setFont(SWTResourceManager.getFont("Liberation Mono", 12, SWT.NORMAL));
		lblEnterYourEmail.setText("Re-enter email address");

		textEmail2 = new Text(grpUserDetails, SWT.BORDER);
		GridData gd_textEmail2 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textEmail2.widthHint = 250;
		textEmail2.setLayoutData(gd_textEmail2);

//		Group grpMissionDetails = new Group(compRegContent, SWT.NONE);
//		grpMissionDetails.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 2, 1));
//		grpMissionDetails.setText("Mission Details");
//		grpMissionDetails.setLayout(new GridLayout(2, false));
//
//		Label label = new Label(grpMissionDetails, SWT.NONE);
//		label.setText("Name");
//
//		textMissionName = new Text(grpMissionDetails, SWT.BORDER);
//		textMissionName.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
//
//		Label label_1 = new Label(grpMissionDetails, SWT.NONE);
//		label_1.setText("Description");
//
//		textMissionDescription = new Text(grpMissionDetails, SWT.BORDER | SWT.MULTI);
//		GridData gd_textMissionDescription = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
//		gd_textMissionDescription.heightHint = 75;
//		gd_textMissionDescription.widthHint = 400;
//		textMissionDescription.setLayoutData(gd_textMissionDescription);
//
//		Label label_3 = new Label(grpMissionDetails, SWT.NONE);
//		label_3.setText("Owner");
//
//		textOwner = new Text(grpMissionDetails, SWT.BORDER);
//		textOwner.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
//
//		Label label_2 = new Label(grpMissionDetails, SWT.NONE);
//		label_2.setText("Country");
//
//		textCountry = new Text(grpMissionDetails, SWT.BORDER);
//		textCountry.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));

		Composite composite = new Composite(compRegContent, SWT.NONE);
		composite.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		composite.setLayout(new GridLayout(2, false));

		Button btnRegister = new Button(composite, SWT.NONE);
		btnRegister.setImage(
				SWTResourceManager.getImage(RegisterPage.class, "/com/incomplete/cubegs/resources/ok_32_32.png"));
		btnRegister.setToolTipText("Register user");
		GridData gd_btnRegister = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
		gd_btnRegister.widthHint = 100;
		btnRegister.setLayoutData(gd_btnRegister);
		btnRegister.setFont(SWTResourceManager.getFont("Sans", 11, SWT.NORMAL));
		btnRegister.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			public void widgetSelected(SelectionEvent evt) {
				doRegister();
			}
		});

		Button btnCancel = new Button(composite, SWT.PUSH | SWT.CENTER);
		btnCancel.setToolTipText("Cancel");
		btnCancel.setImage(
				SWTResourceManager.getImage(RegisterPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		btnCancel.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Change view
				SingletonViews.getInstance().changeView(Constants.LOGIN_VIEW_NAME);
			}
		});
		GridData gd_btnCancel = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnCancel.widthHint = 100;
		btnCancel.setLayoutData(gd_btnCancel);
		btnCancel.setFont(SWTResourceManager.getFont("Sans", 11, SWT.NORMAL));

		GridData lblEnterYourEmailLData = new GridData();
		lblEnterYourEmailLData.widthHint = 240;
		lblEnterYourEmailLData.verticalAlignment = SWT.CENTER;
		lblEnterYourEmailLData.horizontalAlignment = SWT.LEFT;
		lblEnterYourEmailLData.heightHint = 18;
		
		compRegContent.pack();
		
		scrollComposite.setContent(compRegContent);
		scrollComposite.setExpandVertical(true);
	 	scrollComposite.setExpandHorizontal(true);
	 	//scrollComposite.setMinSize(scrollComposite.computeSize(SWT.DEFAULT, SWT.DEFAULT));
		scrollComposite.addControlListener(new ControlAdapter() {
			private static final long serialVersionUID = 1L;
			
			public void controlResized(ControlEvent e) {
				Rectangle r = scrollComposite.getClientArea();
				scrollComposite.setMinSize(parent.computeSize(r.width, SWT.DEFAULT));
			}
		});
		
		compContent.pack();
	 	
		// Footer
		compFooter = getFooterComposite(this);
		
		compFooter.pack();
	}

	protected void doRegister() {
//		User     user  = new User(); 
		//Mission  mission = new Mission();
		
		// Get data
//		user.setFirstName(this.textFirstName.getText());
//		user.setLastName(this.textLastName.getText());
//		user.setUserName(this.textUserName.getText());
//		user.setPassword(this.textPassword1.getText());
//		user.setEmail(this.textEmail1.getText());
//		user.setRoleId(EnumRole.ROLE_MISSION_ADMINISTRATOR.getValue());
//		user.setUserId("");
		
//		mission.setCountry(this.textCountry.getText());
//		mission.setDescription(this.textMissionDescription.getText());
//		mission.setName(this.textMissionName.getText());
//		mission.setOwner(this.textOwner.getText());
//		mission.setAdminUserId("");
//		mission.setCreationTime(null);
//		List<Satellite> tmpSatellites = new ArrayList<Satellite>();
//    	
//		mission.setListSatellites(tmpSatellites);
		
//		boolean  validFlag = checkValidFields(errorMessage);
//		
//		if (validFlag == true) {
//			try {
//				M_CRegisterUser registerMsg = new M_CRegisterUser(user);
//
//				M_CRegisterUserResponse registerResponse = HttpManager.sendRequest(registerMsg, M_CRegisterUserResponse.class);
//				
//                if (registerResponse.getStatus() == HttpURLConnection.HTTP_OK) {   				
//					showWarning("New user correctly created");
//
//					// Change view
//					SingletonViews.getInstance().changeView(Constants.LOGIN_VIEW_NAME);
//				} else {
//					showError(registerResponse.getDetail());
//				}
//			} catch (Exception e) {
//				e.printStackTrace();
//
//				showError("Exception: " + e.getMessage());
//			}
//		} 
		
		
		boolean errorFlag = false;
        String  errorMessage = "";
		
        boolean  validFlag = checkValidFields(errorMessage);
		if (validFlag == true) {
			DbUser newUser = new DbUser(this.textUserName.getText(),
					this.textPassword1.getText(),
					this.textFirstName.getText(),
					this.textLastName.getText(),
					this.textEmail1.getText(),
					EnumRole.ROLE_MISSION_ADMINISTRATOR.getValue());
			
			ReturnData rc = DataManager.registerUser(newUser);
			
			if (rc.getErrorCode() == 0) {
				showWarning("New user correctly created");
				
				// Change view
				SingletonViews.getInstance().changeView(Constants.LOGIN_VIEW_NAME);
			} else {
			    errorFlag = true;
                errorMessage = rc.getErrorMessage();
			}
		} else {
			errorFlag = true;
			errorMessage = "Invalid parameters. Please, enter valid data";
		}

		if (errorFlag == true) {
			showError(errorMessage);
		}		
	}

	// Return true, if all checks are passed
	private boolean checkValidFields(String outErrorMessage) {
		boolean output = false;

		if (textUserName.getText().isEmpty() == false && 
			textEmail1.getText().isEmpty() == false && 
			textEmail2.getText().isEmpty() == false && 
			textPassword1.getText().isEmpty() == false && 
			textPassword2.getText().isEmpty() == false && 
			textFirstName.getText().isEmpty() == false && 
			textLastName.getText().isEmpty() == false) {

			if (textEmail1.getText().equals(textEmail2.getText()) == true) {
				if (textPassword1.getText().equals(textPassword2.getText()) == true) {
					output = true;
				} else {
					output = false;
					showError("Password does not match");
				}
			} else {
				output = false;
				showError("Email address does not match");

			}
		} else {
			output = false;
			showError("Invalid parameters. Please, fill all fields");
		}

		// TODO
		// Check empty
		//
		// Check equal
		//
		// Check minimum length
		//
		// Check uppercase
		//
		// Check number or symbols
		
		return output;
	}

	@Override
	public void start() {
		if (textUserName != null) {
			textUserName.setText("");
		}
		if (textPassword1 != null) {
			textPassword1.setText("");
		}
		if (textPassword2 != null) {
			textPassword2.setText("");
		}
		if (textEmail1 != null) {
			textEmail1.setText("");
		}
		if (textEmail2 != null) {
			textEmail2.setText("");
		}
		if (textFirstName != null) {
			textFirstName.setText("");
		}
		if (textLastName != null) {
			textLastName.setText("");
		}
	}

	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
	
	
}
