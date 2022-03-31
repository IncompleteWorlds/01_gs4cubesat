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
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Group;





public class ToolsCreateMissionPage2  extends BaseClassPage {
    private static final long serialVersionUID = 1L;
    
    // They have to be local otherwise WindowsBuiler does not work
    private Composite compHeader = null; 
    private ScrolledComposite scCompContent;
    private Composite compFooter = null;
    private Text textName;
    private Text textDescription;
    private Text textCountry;
    private Text textOwner;
    private Table tableSatellite;

    public ToolsCreateMissionPage2(String newViewName, Composite parent, int style) {
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
        GridData gd_scCompContent = new GridData(SWT.FILL, SWT.TOP, true, true, 1, 1);
        gd_scCompContent.heightHint = 758;
        scCompContent.setLayoutData(gd_scCompContent);
        
        Composite compContent = new Composite(scCompContent, SWT.NONE);
        compContent.setLayout(new GridLayout(2, false));
        
        Label lblCreateANew = new Label(compContent, SWT.NONE);
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
        
        Group grpSatellites = new Group(compContent, SWT.BORDER | SWT.SHADOW_IN);
        grpSatellites.setText("Satellites");
        grpSatellites.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 2, 1));
        grpSatellites.setLayout(new GridLayout(2, false));
        
        Label lblListOfSatellites = new Label(grpSatellites, SWT.NONE);
        lblListOfSatellites.setText("List of Satellites");
        new Label(grpSatellites, SWT.NONE);
        
        Composite composite = new Composite(grpSatellites, SWT.NONE);
        composite.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 2, 1));
        composite.setLayout(new GridLayout(1, false));
        
        tableSatellite = new Table(composite, SWT.BORDER | SWT.FULL_SELECTION);
        GridData gd_tableSatellite = new GridData(SWT.FILL, SWT.FILL, false, false, 1, 1);
        gd_tableSatellite.heightHint = 250;
        tableSatellite.setLayoutData(gd_tableSatellite);
        tableSatellite.setLinesVisible(true);
        tableSatellite.setHeaderVisible(true);
        //table.setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
        //table.setBackground(SWTResourceManager.getColor(255, 255, 204));
        
        TableColumn tableColumn = new TableColumn(tableSatellite, SWT.NONE);
        tableColumn.setWidth(100);
        tableColumn.setText("Identifier");
        
        TableColumn tableColumn_1 = new TableColumn(tableSatellite, SWT.NONE);
        tableColumn_1.setWidth(100);
        tableColumn_1.setText("Name");
        
        TableColumn tableColumn_2 = new TableColumn(tableSatellite, SWT.NONE);
        tableColumn_2.setWidth(150);
        tableColumn_2.setText("Description");
        
        TableColumn tblclmnCode = new TableColumn(tableSatellite, SWT.NONE);
        tblclmnCode.setWidth(100);
        tblclmnCode.setText("Code");
        
        TableColumn tblclmnLaunchDate = new TableColumn(tableSatellite, SWT.NONE);
        tblclmnLaunchDate.setWidth(100);
        tblclmnLaunchDate.setText("Launch Date");
        
        Composite composite_1 = new Composite(grpSatellites, SWT.NONE);
        composite_1.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 2, 1));
        composite_1.setLayout(new GridLayout(4, false));
        
        Button btnRemove = new Button(composite_1, SWT.NONE);
        btnRemove.setImage(SWTResourceManager.getImage(ToolsCreateMissionPage2.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
        btnRemove.setToolTipText("Remove");
        btnRemove.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
            	doRemoveSatellite();
            }
        });
        GridData gd_btnRemove = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_btnRemove.widthHint = 80;
        btnRemove.setLayoutData(gd_btnRemove);
        
        Button btnEdit = new Button(composite_1, SWT.NONE);
        btnEdit.setImage(SWTResourceManager.getImage(ToolsCreateMissionPage2.class, "/com/incomplete/cubegs/resources/edit_32_32.png"));
        btnEdit.setToolTipText("Edit");
        btnEdit.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
            	doEditSatellite();
            }
        });
        GridData gd_btnEdit = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_btnEdit.widthHint = 80;
        btnEdit.setLayoutData(gd_btnEdit);
        
        Button btnAdd = new Button(composite_1, SWT.NONE);
        btnAdd.setImage(SWTResourceManager.getImage(ToolsCreateMissionPage2.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
        btnAdd.setToolTipText("Add");
        btnAdd.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
            	doAddSatellite();
            }
        });
        GridData gd_btnAdd = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_btnAdd.widthHint = 80;
        btnAdd.setLayoutData(gd_btnAdd);
        
        Button btnRefresh = new Button(composite_1, SWT.NONE);
        btnRefresh.setImage(SWTResourceManager.getImage(ToolsCreateMissionPage2.class, "/com/incomplete/cubegs/resources/refresh_32_32.png"));
        btnRefresh.setToolTipText("Refresh");
        btnRefresh.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
                doRefresh();
            }
        });
        GridData gd_btnRefresh = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_btnRefresh.widthHint = 80;
        btnRefresh.setLayoutData(gd_btnRefresh);
        
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
        btnAddMission.setImage(SWTResourceManager.getImage(ToolsCreateMissionPage2.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
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
        btnCancel.setImage(SWTResourceManager.getImage(ToolsCreateMissionPage2.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
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
    
    protected void doRemoveSatellite() {
		// TODO Auto-generated method stub
		
	}

	protected void doEditSatellite() {
		// TODO Auto-generated method stub
		
	}

	protected void doAddSatellite() {
		// TODO Auto-generated method stub
		
	}

	protected void doAddMission() {
        String  errorMessage = "";
        
    	try {
    		
//    		// Retrieve list of satellites
//    		ArrayList<Satellite> listSatellites = new ArrayList<Satellite>();
//    	
//    		for(TableItem current: this.tableSatellite.getItems()) {
//    			
//    			//read all columns of a satellite
//    			
//    			
//    			current.getText(0);
//    		}
    		
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

    /** 
     * THIS IS TBD. A NEW MISSION DOES NOT HAVE A LIST OF SATELLITES
     */
	private void doRefresh() {
		
		/*
        boolean errorFlag = false;
        String errorMessage = null;

        try {
            // Read again the list of Ground Stations from Tools component
            GetListSatellites msg = new GetListSatellites();

            ReturnData returnData = msg.request();

            if (returnData.getErrorCode() == 0) {

                ListSatellites tmpListSatellites = msg.getResponse();

                // Clean the table
                tableSatellite.removeAll();
                tableSatellite.clearAll();
                
                

                // Refresh the table
                for (Satellite currentSatellite : tmpListSatellites.getListGroundStations()) {
                    TableItem newItem = new TableItem(tableSatellite, SWT.NONE);

                    // Set a property with the identifier
                    //newItem.setData(GS_IDENTIFIER_PROPERTY, currentSatellite.getIdentifier());

                    // Name
                    newItem.setText(0, currentSatellite.getName());

                    // Code
                    newItem.setText(1, currentSatellite.getCode());

                    // Owner
                    newItem.setText(2, currentSatellite.getOwner());

                    // Latitude
                    newItem.setText(3, Double.toString(currentSatellite.getLatitude()));

                    // Longitude
                    newItem.setText(4, Double.toString(currentSatellite.getLongitude()));
                    
                    // Type
                    newItem.setText(5, currentSatellite.getConnectionType().name());
                                        
                    if (currentSatellite.getConnectionType() == ConnectionTypeEnum.TCP) {
                        // Address/Com
                        newItem.setText(6, currentSatellite.getUrl());
                        
                        // Port/Speed
                        newItem.setText(7, Integer.toString(currentSatellite.getPort()));                        
                    } else {                        
                        // Address/Com
                        newItem.setText(6, currentSatellite.getComPort());
                        
                        // Port/Speed
                        newItem.setText(7, Double.toString(currentSatellite.getSpeed()));
                    }
                }
            } else {
                errorFlag = true;
                errorMessage = returnData.getErrorMessage();
            }
        } catch (Exception e) {
            errorFlag = true;
            errorMessage = "Exception: Reading the list of Ground Stations: " + e.getMessage();
        }

        if (errorFlag == true) {
            // TODO: Log the error

            // Show error
            final String finalErrorMessage = errorMessage;
            
            this.getDisplay().syncExec(new Runnable() {
                public void run() {
                    MessageBox msg = new MessageBox(getShell(), SWT.APPLICATION_MODAL);

                    msg.setText("Error");
                    msg.setMessage(finalErrorMessage);
                    msg.open(null);
                }
            });
        }
        */
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
