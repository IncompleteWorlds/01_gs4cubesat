package com.incomplete.cubegs.toolswui.old;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.wb.swt.SWTResourceManager;

import com.incomplete.cubegs.common.BaseClassPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.common.SingletonViews;
import com.incomplete.cubegs.toolswui.message.AddMissionMessage;

import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;





public class ToolsCreateMissionPage  extends BaseClassPage {
    private static final long serialVersionUID = 1L;
    
    // They have to be local otherwise WindowsBuiler does not work
    private Composite compHeader = null; 
    private ScrolledComposite scCompContent;
    private Composite compFooter = null;
    private Text textName;
    private Text textDescription;
    private Text textCountry;
    private Text textOwner;

    public ToolsCreateMissionPage(String newViewName, Composite parent, int style) {
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
        compHeader = getHeaderComposite(this, "Tools");
        
        // Central content
        scCompContent = new ScrolledComposite(this, SWT.H_SCROLL | SWT.V_SCROLL);
        scCompContent.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, true, 1, 1));
        
        Composite compContent = new Composite(scCompContent, SWT.NONE);
        compContent.setLayout(new GridLayout(2, false));
        
        Label lblCreateANew = new Label(compContent, SWT.NONE);
        lblCreateANew.setFont(SWTResourceManager.getFont("Sans", 12, SWT.NORMAL));
        lblCreateANew.setText("Create a new Mission");
        new Label(compContent, SWT.NONE);
        
        Label lblName = new Label(compContent, SWT.NONE);
        lblName.setText("Name");
        
        textName = new Text(compContent, SWT.BORDER);
        textName.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
        
        Label lblNewLabel = new Label(compContent, SWT.NONE);
        lblNewLabel.setText("Description");
        
        textDescription = new Text(compContent, SWT.BORDER | SWT.MULTI);
        GridData gd_textDescription = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
        gd_textDescription.heightHint = 66;
        gd_textDescription.widthHint = 399;
        textDescription.setLayoutData(gd_textDescription);
        
        Label lblCountery = new Label(compContent, SWT.NONE);
        lblCountery.setText("Country");
        
        textCountry = new Text(compContent, SWT.BORDER);
        textCountry.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
        
        Label lblOwner = new Label(compContent, SWT.NONE);
        lblOwner.setText("Owner");
        
        textOwner = new Text(compContent, SWT.BORDER);
        textOwner.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
        
        Composite composite_2 = new Composite(compContent, SWT.NONE);
        composite_2.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 2, 1));
        composite_2.setLayout(new GridLayout(2, false));
        
        Button btnAddMission = new Button(composite_2, SWT.NONE);
        btnAddMission.addSelectionListener(new SelectionAdapter() {
        	/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
        	public void widgetSelected(SelectionEvent e) {
        		doAddMission();
        	}
        });
        btnAddMission.setImage(SWTResourceManager.getImage(ToolsCreateMissionPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
        btnAddMission.setToolTipText("Add Mission");
        GridData gd_btnAddMission = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_btnAddMission.widthHint = 80;
        btnAddMission.setLayoutData(gd_btnAddMission);
        
        Button btnCancel = new Button(composite_2, SWT.NONE);
        btnCancel.addSelectionListener(new SelectionAdapter() {
        	/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
        	public void widgetSelected(SelectionEvent e) {
        		// Back to Main View
                SingletonViews.getInstance().changeView(Constants.TOOLS_MAIN_VIEW_NAME);
        	}
        });
        btnCancel.setImage(SWTResourceManager.getImage(ToolsCreateMissionPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
        btnCancel.setToolTipText("Cancel");
        GridData gd_btnCancel = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_btnCancel.widthHint = 80;
        btnCancel.setLayoutData(gd_btnCancel);

        // Footer
        compFooter = getFooterComposite(this);

        // Scroll
        scCompContent.setContent(compContent);

        scCompContent.setMinSize( compContent.computeSize(SWT.DEFAULT,SWT.DEFAULT) );

        scCompContent.setExpandHorizontal(true);
        scCompContent.setExpandVertical(true);
    }

	protected void doAddMission() {
        String  errorMessage = "";
        
    	try {
    		// Send message
    		AddMissionMessage msg = new AddMissionMessage(this.textName.getText(), 
										                  this.textDescription.getText(),
										                  this.textCountry.getText(),
										                  this.textOwner.getText());

    		ReturnData returnData = msg.request();

    		if (returnData.getErrorCode() == 0) {
    			// Retrieve mission id
    		    // TODO
    			//Mission  newMission = msg.getResponse();
    			
    			//errorMessage = "New Mission correctly created. Name: " + newMission.getName();
    		} else {
    			errorMessage = returnData.getErrorMessage();
    		}

    	} catch (Exception e) {
    		e.printStackTrace();

    		errorMessage = "Exception: " + e.getMessage();
    	}

    	// Show final dialog
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
