package com.incomplete.cubegs.mcswui.view;

import org.eclipse.swt.widgets.Composite;


import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.TableItem;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.wb.swt.SWTResourceManager;

import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.mcswui.messages.ConnectGsnMessage;
import com.incomplete.cubegs.mcswui.messages.DisconnectGsnMessage;
import com.incomplete.cubegs.mcswui.messages.GetGsnMessage;

import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;


public class McsGsConnectionPage extends McsBasePage {
    private static final String GS_IDENTIFIER_PROPERTY = "identifier";

    private static final long serialVersionUID = 1L;
    
    // They have to be local otherwise WindowsBuiler does not work
    protected Composite compHeader = null; 
    protected Composite compContent = null;
    protected Composite compFooter = null;
    
    protected ScrolledComposite sc = null;
    protected Composite compMcsContent = null;
    protected ToolBar toolBar = null;

	private Table tableGS = null;
	
	// Ground Station currently connected
	private Integer gsId = null;
	private String connectionId = null;
	

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public McsGsConnectionPage(String newViewName, Composite parent, int style) {
        super(newViewName, parent, style);

        setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
        setBackground(SWTResourceManager.getColor(255, 255, 255));
        setLayout(new GridLayout(1, false));
        
        // Header
        compHeader = getHeaderComposite(this, "");

        // Central Content
        compContent = new Composite(this, SWT.NONE);
        compContent.setLayout(new GridLayout(1, false));
        compContent.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
        compContent.setBackground(SWTResourceManager.getColor(255, 255, 255));      
        
        // Create the MCS Toolbar
        toolBar = getMcsToolBar(compContent);
        
        Label viewName = new Label(compContent, SWT.NONE);
        viewName.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1));
        viewName.setText(newViewName);

        // Add Scroll
        sc = new ScrolledComposite(compContent, SWT.H_SCROLL | SWT.V_SCROLL);       
        sc.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1));
        
        compMcsContent = new Composite(sc, SWT.NONE);
        compMcsContent.setLayout(new GridLayout(1, false));
        compMcsContent.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, true, 1, 1));
	
		Label lblListOfGround = new Label(compMcsContent, SWT.NONE);
		lblListOfGround.setText("List of Ground Stations");
		
		tableGS = new Table(compMcsContent, SWT.BORDER | SWT.FULL_SELECTION);
		GridData gd_table = new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1);
		gd_table.heightHint = 300;
		gd_table.widthHint = 450;
		tableGS.setLayoutData(gd_table);
		tableGS.setHeaderVisible(true);
		tableGS.setLinesVisible(true);
		
		TableColumn tblclmnName = new TableColumn(tableGS, SWT.NONE);
		tblclmnName.setWidth(150);
		tblclmnName.setText("Name");
		
		TableColumn tblclmnCode = new TableColumn(tableGS, SWT.NONE);
		tblclmnCode.setWidth(100);
		tblclmnCode.setText("Code");
		
		TableColumn tblclmnOwner = new TableColumn(tableGS, SWT.NONE);
		tblclmnOwner.setWidth(150);
		tblclmnOwner.setText("Owner");
		
		TableColumn tblclmnLatitude = new TableColumn(tableGS, SWT.NONE);
		tblclmnLatitude.setWidth(100);
		tblclmnLatitude.setText("Latitude");
		
		TableColumn tblclmnLongitude = new TableColumn(tableGS, SWT.NONE);
		tblclmnLongitude.setWidth(100);
		tblclmnLongitude.setText("Longitude");
		
		TableColumn tblclmnType = new TableColumn(tableGS, SWT.NONE);
		tblclmnType.setWidth(100);
		tblclmnType.setText("Type");
		
		TableColumn tblclmnAddresscom = new TableColumn(tableGS, SWT.NONE);
		tblclmnAddresscom.setWidth(100);
		tblclmnAddresscom.setText("Address/Com");
		
		TableColumn tblclmnPortspeed = new TableColumn(tableGS, SWT.NONE);
		tblclmnPortspeed.setWidth(100);
		tblclmnPortspeed.setText("Port/Speed");
		
		Composite compButtons = new Composite(compMcsContent, SWT.NONE);
		compButtons.setLayoutData(new GridData(SWT.RIGHT, SWT.FILL, false, false, 1, 1));
		compButtons.setLayout(new GridLayout(3, false));
		
		Button btnConnect = new Button(compButtons, SWT.NONE);
		btnConnect.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
			    // Connect to selected Ground Station
			    doConnect();
			}
		});
		btnConnect.setText("Connect");
		
		Button btnDisconnect = new Button(compButtons, SWT.NONE);
		btnDisconnect.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// If connected to a G/S
				//   Disconnect from current connected ground station
			    doDisconnect();
			}
		});
		btnDisconnect.setText("Disconnect");
		
		Button btnRefresh = new Button(compButtons, SWT.NONE);
		btnRefresh.setImage(SWTResourceManager.getImage(McsGsConnectionPage.class, "/com/incomplete/cubegs/resources/refresh_32_32.png"));
		btnRefresh.setToolTipText("Refresh");
		btnRefresh.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Read again the list of Ground Stations from Tools component
				doRefresh();
			}
		});
		
		// Scroll composite
        sc.setContent(compMcsContent);
        sc.setExpandHorizontal(true);
        sc.setExpandVertical(true);

        // Resize the scroll
        sc.addListener( SWT.Resize, event -> { 
            int width = sc.getClientArea().width; 
            sc.setMinSize( this.computeSize( width, SWT.DEFAULT ) ); 
        } );
        
        // Footer
        compFooter = getFooterComposite(this);
	}

	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
	
	@Override
	public void start() {
	    super.start();
	    
	    doRefresh();
	}
	
    private void doRefresh() {
        boolean errorFlag = false;
        String errorMessage = null;

        try {
            // Read again the list of Ground Stations from Tools component
            GetGsnMessage msg = new GetGsnMessage();

            ReturnData returnData = msg.request();

            if (returnData.getErrorCode() == 0) {

//                ListGroundStations tmpListGS = msg.getResponse();
//
//                // Clean the table
//                tableGS.removeAll();
//                tableGS.clearAll();
//
//                // Refresh the table
//                for (GroundStation currentGS : tmpListGS.getListGroundStations()) {
//                    TableItem newItem = new TableItem(tableGS, SWT.NONE);
//
//                    // Set a property with the identifier
//                    newItem.setData(GS_IDENTIFIER_PROPERTY, currentGS.getIdentifier());
//
//                    // Name
//                    newItem.setText(0, currentGS.getName());
//
//                    // Code
//                    newItem.setText(1, currentGS.getCode());
//
//                    // Owner
//                    newItem.setText(2, currentGS.getOwner());
//
//                    // Latitude
//                    newItem.setText(3, Double.toString(currentGS.getLatitude()));
//
//                    // Longitude
//                    newItem.setText(4, Double.toString(currentGS.getLongitude()));
//                    
//                    // Type
//                    newItem.setText(5, currentGS.getConnectionType().name());
//                                        
//                    if (currentGS.getConnectionType() == ConnectionTypeEnum.TCP) {
//                        // Address/Com
//                        newItem.setText(6, currentGS.getUrl());
//                        
//                        // Port/Speed
//                        newItem.setText(7, Integer.toString(currentGS.getPort()));                        
//                    } else {                        
//                        // Address/Com
//                        newItem.setText(6, currentGS.getComPort());
//                        
//                        // Port/Speed
//                        newItem.setText(7, Double.toString(currentGS.getSpeed()));
//                    }
//                }
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
    }
	
    private void doConnect() {
        boolean errorFlag = false;
        String errorMessage = null;
        String titleText = "Error";
        
        if (tableGS.getSelectionCount() > 0) {
            // If a ground station is selected
            // Read the data from table (maybe, from Tools component)
            TableItem[] items = tableGS.getSelection();

            if (items != null && items.length > 0) {
                // Extract the property
                gsId = (Integer) items[0].getData(GS_IDENTIFIER_PROPERTY);
                String gsName = items[0].getText(0);

                try {
                    // Ask to GS Manager component to connect to the selected
                    // ground
                    // station
                    ConnectGsnMessage msg = new ConnectGsnMessage(gsId);

                    ReturnData returnData = msg.request();

                    if (returnData.getErrorCode() == 0) {
                        // Get answer; Connection Id
                        this.connectionId = msg.getResponse();
                        
                        // TODO: Show a message in the Status Line
                        

                    } else {
                        errorFlag = true;
                        errorMessage = returnData.getErrorMessage();
                    }
                } catch (Exception e) {
                    errorFlag = true;
                    errorMessage = "Error: While connecting to Ground Station: " + gsName + 
                                   " Exception: " + e.getMessage(); 
                }
            }
        } else {
            errorFlag = true;
            titleText = "Warning";
            errorMessage = "Please, select a Ground Station";                         
        }
        
        if (errorFlag == true) {
            // TODO: Log the error

            // Show error
            final String finalErrorMessage = errorMessage;
            final String finalTitle = titleText;

            this.getDisplay().syncExec(new Runnable() {
                public void run() {
                    MessageBox msg = new MessageBox(getShell(), SWT.APPLICATION_MODAL);

                    msg.setText(finalTitle);
                    msg.setMessage(finalErrorMessage);
                    msg.open(null);
                }
            });
        }
    }    

    private void doDisconnect() {
        boolean errorFlag = false;
        String errorMessage = null;

        if (this.connectionId.isEmpty() == false) {
            try {
                // Ask to GS Manager component to connect to the selected
                // ground
                // station
                DisconnectGsnMessage msg = new DisconnectGsnMessage(this.connectionId);

                ReturnData returnData = msg.request();

                if (returnData.getErrorCode() == 0) {

                } else {
                    errorFlag = true;
                    errorMessage = returnData.getErrorMessage();
                }
            } catch (Exception e) {
                errorFlag = true;
                errorMessage = "Error: While disconnecting from Ground Station: " + this.gsId + 
                               " Exception: " + e.getMessage();
            }

        } else {
            errorFlag = true;
            errorMessage = "Please, connect to a Ground Station first";
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
    }
	
}
