package com.incomplete.cubegs.toolswui.view;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.wb.swt.SWTResourceManager;

import com.incomplete.cubegs.common.BaseClassPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.SingletonViews;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Text;


public class ToolsEditMissionPage extends BaseClassPage {
	private static final long serialVersionUID = 1L;
	
	// They have to be local otherwise WindowsBuiler does not work
	private Composite compHeader = null; 
	private ScrolledComposite scCompContent;
	private Composite compFooter = null;
	private Text textName;
	private Text textDescription;
	private Text textOwner;
	private Text textCountry;
	private Text textAdmin;
	private Text textEmail;
	private Text textPhone;
	
	
	public ToolsEditMissionPage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style, false);
		
		setFont(SWTResourceManager.getFont("Lucida Console", 13, SWT.NORMAL));
		setBackground(SWTResourceManager.getColor(255, 255, 255));
		GridLayout gridLayout = new GridLayout(1, false);
		gridLayout.marginWidth = 3;
		gridLayout.marginHeight = 3;
		gridLayout.verticalSpacing = 3;
		gridLayout.horizontalSpacing = 3;
		setLayout(gridLayout);
		
		// Header
		compHeader = getHeaderComposite(this, "Configure Parameters");
		
		// Central content
		scCompContent = new ScrolledComposite(this, SWT.H_SCROLL | SWT.V_SCROLL);
		scCompContent.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, true, 1, 1));
		
	    Composite compContent = new Composite(scCompContent, SWT.NONE);
	    
	    GridLayout gl_compContent = new GridLayout(1, false);
		gl_compContent.verticalSpacing = 3;
		gl_compContent.horizontalSpacing = 3;
		gl_compContent.marginHeight = 3;
		gl_compContent.marginWidth = 3;
		compContent.setLayout(gl_compContent);
		
		Group group = new Group(compContent, SWT.NONE);
		group.setText("Mission Details");
		group.setLayout(new GridLayout(2, false));
		
		Label label = new Label(group, SWT.NONE);
		label.setText("Name");
		
		textName = new Text(group, SWT.BORDER);
		textName.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		
		Label label_1 = new Label(group, SWT.NONE);
		GridData gd_label_1 = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_label_1.widthHint = 100;
		label_1.setLayoutData(gd_label_1);
		label_1.setText("Description");
		
		textDescription = new Text(group, SWT.BORDER | SWT.MULTI);
		GridData gd_textDescription = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
		gd_textDescription.widthHint = 400;
		gd_textDescription.heightHint = 75;
		textDescription.setLayoutData(gd_textDescription);
		
		Label label_2 = new Label(group, SWT.NONE);
		label_2.setText("Owner");
		
		textOwner = new Text(group, SWT.BORDER);
		textOwner.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		
		Label label_3 = new Label(group, SWT.NONE);
		label_3.setText("Country");
		
		textCountry = new Text(group, SWT.BORDER);
		textCountry.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		
		Label lblAdministrator = new Label(group, SWT.NONE);
		lblAdministrator.setText("Administrator");
		
		textAdmin = new Text(group, SWT.BORDER);
		textAdmin.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		
		Label lblEmail = new Label(group, SWT.NONE);
		lblEmail.setText("Email");
		
		textEmail = new Text(group, SWT.BORDER);
		textEmail.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		
		Label lblPhone = new Label(group, SWT.NONE);
		lblPhone.setText("Phone");
		
		textPhone = new Text(group, SWT.BORDER);
		textPhone.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		
		Composite composite = new Composite(compContent, SWT.NONE);
		composite.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		composite.setLayout(new GridLayout(2, false));
		
		Button btnUpdateMission = new Button(composite, SWT.NONE);
		btnUpdateMission.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});
		GridData gd_btnUpdateMission = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
		gd_btnUpdateMission.widthHint = 100;
		btnUpdateMission.setLayoutData(gd_btnUpdateMission);
		btnUpdateMission.setToolTipText("Update Mission");
		btnUpdateMission.setImage(SWTResourceManager.getImage(ToolsEditMissionPage.class, "/com/incomplete/cubegs/resources/ok_32_32.png"));
		btnUpdateMission.setFont(SWTResourceManager.getFont("Sans", 11, SWT.NORMAL));
		
		Button btnCancel = new Button(composite, SWT.CENTER);
		btnCancel.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});
		GridData gd_btnCancel = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnCancel.widthHint = 100;
		btnCancel.setLayoutData(gd_btnCancel);
		btnCancel.setToolTipText("Cancel");
		btnCancel.setImage(SWTResourceManager.getImage(ToolsEditMissionPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		btnCancel.setFont(SWTResourceManager.getFont("Sans", 11, SWT.NORMAL));
		
	    
		// Footer
		compFooter = getFooterComposite(this);

		// Scroll
		scCompContent.setContent(compContent);

		scCompContent.setMinSize( compContent.computeSize(SWT.DEFAULT,SWT.DEFAULT) );

		scCompContent.setExpandHorizontal(true);
		scCompContent.setExpandVertical(true);
	}

	@Override
    public void backButton() {
		// Back to GS main page
		SingletonViews.getInstance().changeView( Constants.TOOLS_MAIN_VIEW_NAME);
    }

	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
}
