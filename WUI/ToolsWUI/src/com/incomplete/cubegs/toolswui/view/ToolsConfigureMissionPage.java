package com.incomplete.cubegs.toolswui.view;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

import javax.servlet.ServletContext;

import org.eclipse.rap.rwt.RWT;
import org.eclipse.rap.rwt.service.UISession;
import org.eclipse.rap.rwt.widgets.DialogCallback;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.SashForm;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.RowData;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.DateTime;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.TreeItem;
import org.eclipse.wb.swt.SWTResourceManager;

import com.incomplete.cubegs.common.BaseClassPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.common.SingletonViews;
import com.incomplete.cubegs.common.TimeUtil;
import com.incomplete.cubegs.toolswui.message.AddMissionLayerMessage;
import com.incomplete.cubegs.toolswui.message.AddSatelliteMessage;
import com.incomplete.cubegs.toolswui.message.AddSubsystemMessage;
import com.incomplete.cubegs.toolswui.message.GetDefaultMissionLayersMessage;
import com.incomplete.cubegs.toolswui.message.GetMissionLayersMessage;
import com.incomplete.cubegs.toolswui.message.GetSatellitesMessage;
import com.incomplete.cubegs.toolswui.message.RemoveLayerMessage;
import com.incomplete.cubegs.toolswui.message.RemoveSatelliteMessage;
import com.incomplete.cubegs.toolswui.message.RemoveSubsystemMessage;




public class ToolsConfigureMissionPage extends BaseClassPage {
    private static final long serialVersionUID = 1L;
    
    // They have to be local otherwise WindowsBuiler does not work
    protected Composite compHeader = null; 
    protected Composite compContent = null;
    protected Composite compFooter = null;
    
    protected ScrolledComposite sc = null;
    protected Composite compToolsContent = null;
    protected ToolBar toolBar = null;
    
	private Text textSatName;
	private Text textSatDescription;
	private Text textSatCode;
	private Text textSubName;
	private Text textSubDescription;
	private Text textLayerName;
	
	private String missionName = null;
	private String currentSelection = null;
	
	private Tree tree = null;
	private TreeItem trtmGroundStations;
	private TreeItem trtmLayers;
	private TreeItem trtmSatellites;
	private Group grpSatellite;
	private Group grpSubsystem;
	private Group grpLayer;
	private Group grpGroundStation;
	private Composite compRight;
	private Composite compRightHidden;

//	private ArrayList<Satellite>      satellitesList = null;
//	private ArrayList<Layer>          layersList = null;
//    private ArrayList<GroundStation>  stationsList = null;	
    private Text textSequenceNumber;
    private Text textLayerDescription;
    
    
    private Text textName;
	private Text textAcronym;
	private Text textDescription;
	private Text textLatitude;
	private Text textLongitude;
	private Text textAltitude;
	private Table tableMaskPoints;
	private Text textImport;
	private Text text;
	private Text textIpAddress;
	private Text textPort;

//	private ListLayers   defaultListLayers = null;
	private Combo comboLayerProtocol;
	private org.eclipse.swt.widgets.List listOrderLayers = null;
	private Group groupAddLayer = null;
	
	
	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public ToolsConfigureMissionPage(String newViewName, Composite parent, int style) {
        super(newViewName, parent, style, false);
        
        // Retrieve Mission name
        //ServletContext servletCtx = RWT.getUISession().getHttpSession().getServletContext();
        
        //missionName = (String) servletCtx.getAttribute(Constants.MISSION_NAME);
        UISession uiSession = RWT.getUISession();
        
        missionName = (String) uiSession.getAttribute(Constants.MISSION_NAME);

        setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
        setBackground(SWTResourceManager.getColor(255, 255, 255));
        setLayout(new GridLayout(1, false));
        
        // Header
        compHeader = getHeaderComposite(this, "Configure Mission Parameters");

        // Central Content
        compContent = new Composite(this, SWT.NONE);
        compContent.setLayout(new GridLayout(1, false));
        compContent.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
        compContent.setBackground(SWTResourceManager.getColor(255, 255, 255));      
                
        Label viewName = new Label(compContent, SWT.NONE);
        viewName.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1));
        viewName.setText(newViewName);

        // Add Scroll
        sc = new ScrolledComposite(compContent, SWT.H_SCROLL | SWT.V_SCROLL);       
        sc.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
        
        compToolsContent = new Composite(sc, SWT.NONE);
        compToolsContent.setLayout(new GridLayout(1, false));
        compToolsContent.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, true, 1, 1));
		
		SashForm sashForm = new SashForm(compToolsContent, SWT.BORDER);
		sashForm.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
		sashForm.setLocation(0, 0);
		
		Composite compLeft = new Composite(sashForm, SWT.NONE);
		compLeft.setLayout(new GridLayout(2, false));
		
	    tree = new Tree(compLeft, SWT.BORDER);
		
		tree.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {				
				TreeItem[] selection = tree.getSelection();
				
				if (selection != null && selection.length > 0) {
					TreeItem  tmpItem = selection[0];
					
					if (tmpItem.getText().equalsIgnoreCase("Layers") == true) {
						showLayerGroup();
					}
				}
				
//				if (Satellite shows satellite data)
//					
//				if (Subsystem)
//					show subsystem
//					
//				if (Layer)
//					show layer
				
				//for (int i = 0; i < selection.length; i++)
				//	string += selection[i] + " ";
				//System.out.println("Selection={" + string + "}" + item1.getText());
			}
		});
				
		final Menu menu = new Menu(tree);
	    tree.setMenu(menu);
	    
	    // Add Satellite
	    MenuItem mntmAdd = new MenuItem(menu, SWT.NONE);
	    mntmAdd.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
	    	public void widgetSelected(SelectionEvent e) {			
				showSatelliteGroup();
	    	}
	    });
	    mntmAdd.setText("Add Satellite");
	    
	    // Remove Satellite
	    MenuItem mntmRemove = new MenuItem(menu, SWT.NONE);
	    mntmRemove.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
	    	public void widgetSelected(SelectionEvent e) {			
				TreeItem[] selection = tree.getSelection();
				
				if (selection != null && selection.length > 0) {
					TreeItem item1 = selection[0];
					
					currentSelection = item1.getText();
					
					removeSatellite(currentSelection);
				}
	    	}
	    });
	    mntmRemove.setText("Remove Satellite");
	    
	    // Add Subsystem
	    MenuItem mntmAddSubsystem = new MenuItem(menu, SWT.NONE);
	    mntmAddSubsystem.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
	    	public void widgetSelected(SelectionEvent e) {			
				TreeItem[] selection = tree.getSelection();
				
				if (selection != null && selection.length > 0) {
					TreeItem item1 = selection[0];
					
					currentSelection = item1.getText();
					
					// Look for the Satellite
					// Remove a Satellite
//					for(Satellite current: satellitesList) {
//						if (currentSelection.equals(current.getName()) == true) {
//							showSubsystemGroup();
//							break;
//						} else {
//							showWarning("Please, select a satellite");
//						}
//					}						
				} else {
					showWarning("Please, select a satellite");
				}
	    	}
	    });
	    mntmAddSubsystem.setText("Add Subsystem");
	    
	    // Remove subsystem
	    MenuItem mntmRemoveSubsystem = new MenuItem(menu, SWT.NONE);
	    mntmRemoveSubsystem.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
	    	public void widgetSelected(SelectionEvent e) {	
				TreeItem[] selection = tree.getSelection();
				
				if (selection != null && selection.length > 0) {
					TreeItem item1 = selection[0];
					
					currentSelection = item1.getText();
					
					removeSubsystem(currentSelection);
				}
	    	}
	    });
	    mntmRemoveSubsystem.setText("Remove Subsystem");
	    
	    
	    // Add GroundStation
	    MenuItem mntmAddGroundStation = new MenuItem(menu, SWT.NONE);
	    mntmAddGroundStation.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
	    	public void widgetSelected(SelectionEvent e) {			
				TreeItem[] selection = tree.getSelection();
				
				if (selection != null && selection.length > 0) {
					TreeItem item1 = selection[0];
					
					// Add a Ground Station
					if (item1.getText().equals(trtmGroundStations.getText()) == true) {
						
					}
				}
	    	}
	    });
	    mntmAddGroundStation.setText("Add GroundStation");
	    
	    // Remove GroundStation
	    MenuItem mntmRemoveGroundStation = new MenuItem(menu, SWT.NONE);
	    mntmRemoveGroundStation.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
	    	public void widgetSelected(SelectionEvent e) {			
				TreeItem[] selection = tree.getSelection();
				
				if (selection != null && selection.length > 0) {
					TreeItem item1 = selection[0];
					
					// Remove a GroundStation
					if (item1.getText().equals(trtmGroundStations.getText()) == true) {
//						if (yesNoQuestion("Remove Ground Station", "Remove Ground Station?") == SWT.YES) {
//							
//						}
						
						hideGroundStationsGroup();
					}
				}
	    	}
	    });
	    mntmRemoveGroundStation.setText("Remove GroundStation");
	    
	    
		GridData gd_tree = new GridData(SWT.FILL, SWT.FILL, true, false, 2, 1);
		gd_tree.heightHint = 400;
		gd_tree.widthHint = 200;
		tree.setLayoutData(gd_tree);
		tree.setBounds(0, 0, 85, 85);
		
		trtmSatellites = new TreeItem(tree, SWT.NONE);
		trtmSatellites.setText("Satellites");
		
		trtmLayers = new TreeItem(tree, SWT.NONE);
		trtmLayers.setText("Layers");
		
		trtmGroundStations = new TreeItem(tree, SWT.NONE);
		trtmGroundStations.setText("Ground Stations");
		
		Composite compositeSatellite = new Composite(compLeft, SWT.NONE);
		compositeSatellite.setLayout(new GridLayout(3, false));
		
		Label lblSatellite = new Label(compositeSatellite, SWT.NONE);
		lblSatellite.setText("Satellite");
		
		Button btnAddSatellite = new Button(compositeSatellite, SWT.NONE);
		btnAddSatellite.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAddSatellite.setToolTipText("Add Satellite");
		
		Button btnRemoveSat = new Button(compositeSatellite, SWT.NONE);
		btnRemoveSat.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemoveSat.setToolTipText("Remove Satellite");
		
		Composite compositeSubsystem = new Composite(compLeft, SWT.NONE);
		compositeSubsystem.setLayout(new GridLayout(3, false));
		
		Label lblSubsystem = new Label(compositeSubsystem, SWT.NONE);
		lblSubsystem.setText("Subsystem");
		
		Button btnAddSubsystem = new Button(compositeSubsystem, SWT.NONE);
		btnAddSubsystem.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAddSubsystem.setToolTipText("Add Subsystem");
		
		Button btnRemoveSub = new Button(compositeSubsystem, SWT.NONE);
		btnRemoveSub.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemoveSub.setToolTipText("Remove Subsystem");
		
			
		Composite compositeLayer = new Composite(compLeft, SWT.NONE);
		compositeLayer.setLayout(new GridLayout(3, false));
		
		Label lblLayer = new Label(compositeLayer, SWT.NONE);
		lblLayer.setText("Layer");
		
		Button btnAddLayer = new Button(compositeLayer, SWT.NONE);
		btnAddLayer.setToolTipText("Add Layer");
		btnAddLayer.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		
		Button btnRemoveLayer = new Button(compositeLayer, SWT.NONE);
		btnRemoveLayer.setToolTipText("Remove Layer");
		btnRemoveLayer.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		
		Composite compositeGS = new Composite(compLeft, SWT.NONE);
		compositeGS.setLayout(new GridLayout(3, false));
		
		Label lblGs = new Label(compositeGS, SWT.NONE);
		lblGs.setText("Ground Station");
		
		Button btnAddGroundStation = new Button(compositeGS, SWT.NONE);
		btnAddGroundStation.setToolTipText("Add Ground Station");
		btnAddGroundStation.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		
		Button btnRemoveGroundStatin = new Button(compositeGS, SWT.NONE);
		btnRemoveGroundStatin.setToolTipText("Remove Ground Station");
		btnRemoveGroundStatin.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		
		
		compRight = new Composite(sashForm, SWT.NONE);
		compRight.setLayout(new GridLayout(2, false));

		//compRightHidden = new Composite(parent, SWT.NONE);
		
		// For redraw. Visible in Eclipse
		compRightHidden = compRight;
		
		grpSatellite = new Group(compRightHidden, SWT.NONE);
		grpSatellite.setLayout(new GridLayout(2, false));
		grpSatellite.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, false, 1, 1));
		grpSatellite.setText("Satellite");
		
		Label lblName_1 = new Label(grpSatellite, SWT.NONE);
		lblName_1.setText("Name:");
		
		textSatName = new Text(grpSatellite, SWT.BORDER);
		GridData gd_textSatName = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_textSatName.widthHint = 150;
		textSatName.setLayoutData(gd_textSatName);
		
		Label lblDescription_1 = new Label(grpSatellite, SWT.NONE);
		lblDescription_1.setText("Description:");
		
		textSatDescription = new Text(grpSatellite, SWT.BORDER | SWT.MULTI);
		GridData gd_textSatDescription = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_textSatDescription.heightHint = 75;
		gd_textSatDescription.widthHint = 300;
		textSatDescription.setLayoutData(gd_textSatDescription);
		
		Label lblCode = new Label(grpSatellite, SWT.NONE);
		lblCode.setText("Code:");
		
		textSatCode = new Text(grpSatellite, SWT.BORDER);
		textSatCode.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label lblLaunchDate = new Label(grpSatellite, SWT.NONE);
		lblLaunchDate.setText("Launch Date:");
		
		DateTime launchDate = new DateTime(grpSatellite, SWT.BORDER);
		
		Composite compTableButton = new Composite(grpSatellite, SWT.NONE);
		compTableButton.setLayout(new GridLayout(2, false));
		compTableButton.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 2, 1));
		compTableButton.setSize(64, 64);
		
		Button btnAddSat = new Button(compTableButton, SWT.NONE);
		btnAddSat.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/ok_32_32.png"));
		btnAddSat.setToolTipText("Add or Update");
		btnAddSat.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
//				Satellite newSatellite = new Satellite();
//				
//				newSatellite.setCode(textSatCode.getText());
//				newSatellite.setDescription(textSatDescription.getText());
//				
//				Calendar tmpLaunchDate =  Calendar.getInstance();
//				
//				tmpLaunchDate.set(Calendar.YEAR, launchDate.getYear());
//				tmpLaunchDate.set(Calendar.MONTH, launchDate.getMonth());
//				tmpLaunchDate.set(Calendar.DAY_OF_MONTH, launchDate.getDay());
//				
//				newSatellite.setLaunchDate( TimeUtil.getDateString(tmpLaunchDate.getTime()) );
//				newSatellite.setMissionName(missionName);
//				newSatellite.setName(textSatName.getText());
//				newSatellite.setListSubsystems(new ArrayList<Subsystem>());
//				
//				// Send the message to server
//				addSatellite(newSatellite);
//				
//				// Hide the group
//				hideSatelliteGroup();
			}
		});
		
		Button btnCloseSat = new Button(compTableButton, SWT.NONE);
		btnCloseSat.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		btnCloseSat.setToolTipText("Close");
		btnCloseSat.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Hide the group
				hideSatelliteGroup();
			}
		});
		
		grpSubsystem = new Group(compRightHidden, SWT.NONE);
		grpSubsystem.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, false, 1, 1));
		grpSubsystem.setText("Subsystem");
		grpSubsystem.setLayout(new GridLayout(2, false));
		
		Label label_1 = new Label(grpSubsystem, SWT.NONE);
		label_1.setText("Name:");
		
		textSubName = new Text(grpSubsystem, SWT.BORDER);
		GridData gd_textSubName = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_textSubName.widthHint = 150;
		textSubName.setLayoutData(gd_textSubName);
		
		Label label_2 = new Label(grpSubsystem, SWT.NONE);
		GridData gd_label_2 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_label_2.widthHint = 93;
		label_2.setLayoutData(gd_label_2);
		label_2.setText("Description:");
		
		textSubDescription = new Text(grpSubsystem, SWT.BORDER | SWT.MULTI);
		GridData gd_textSubDescription = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_textSubDescription.heightHint = 75;
		gd_textSubDescription.widthHint = 300;
		textSubDescription.setLayoutData(gd_textSubDescription);
		
		Composite composite_3 = new Composite(grpSubsystem, SWT.NONE);
		composite_3.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 2, 1));
		composite_3.setLayout(new GridLayout(2, false));
		
		Button buttonAddSubsystem = new Button(composite_3, SWT.NONE);
		buttonAddSubsystem.setToolTipText("Add or Update");
		buttonAddSubsystem.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/ok_32_32.png"));
		buttonAddSubsystem.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
//				Subsystem newSubsystem = new Subsystem();
//				
//				newSubsystem.setName(textSubName.getText());
//				newSubsystem.setDescription(textSubDescription.getText());
//				newSubsystem.setSatelliteName(currentSelection);
//				
//				// Send the message to server
//				addSubsystem(newSubsystem);
//				
//				// Hide the group
//				hideSubsystemGroup();
			}
		});
		
		Button buttonCloseSubsystem = new Button(composite_3, SWT.NONE);
		buttonCloseSubsystem.setToolTipText("Close");
		buttonCloseSubsystem.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		buttonCloseSubsystem.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Hide the group
				hideSubsystemGroup();
			}
		});
		
		
		// Uncomment before deploy it
		grpLayer = new Group(compRightHidden, SWT.NONE);
		
		// In Eclipse. it shows the group. Comment before deploy it
		//grpLayer = new Group(compRight, SWT.NONE);
		
		Composite compLayerOrder = new Composite(grpLayer, SWT.NONE);
		compLayerOrder.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		compLayerOrder.setLayout(new GridLayout(2, false));
		
		Label lblNewLabel = new Label(compLayerOrder, SWT.NONE);
		lblNewLabel.setText("Layers");
		new Label(compLayerOrder, SWT.NONE);
		
		listOrderLayers = new org.eclipse.swt.widgets.List(compLayerOrder, SWT.BORDER | SWT.V_SCROLL);
		GridData gd_listOrderLayers = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_listOrderLayers.widthHint = 250;
		gd_listOrderLayers.heightHint = 200;
		listOrderLayers.setLayoutData(gd_listOrderLayers);
		
		listOrderLayers.setSize(125, 125);
		
		Composite composite_1 = new Composite(compLayerOrder, SWT.NONE);
		composite_1.setLayout(new RowLayout(SWT.VERTICAL));
		composite_1.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		
		Button btnUp = new Button(composite_1, SWT.NONE);
		btnUp.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				// Get select item of the combo
				int selectedIdx = listOrderLayers.getSelectionIndex();
				
				if (selectedIdx != -1) {
					//int numberItems = layersList.size();
					
					// If it is a the top, do not move it anymore
					if (selectedIdx > 0) {
						// Move the item up in the combo
						
						// Get items
//						Layer tmpLayerIdx   = layersList.get(selectedIdx);
//						Layer tmpLayerIdx_1 = layersList.get(selectedIdx - 1);
//						
//						tmpLayerIdx.setSequenceNumber(selectedIdx - 1);
//						tmpLayerIdx_1.setSequenceNumber(selectedIdx);
//						
//						// Swap them				
//						layersList.set(selectedIdx,     tmpLayerIdx_1);
//						layersList.set(selectedIdx - 1, tmpLayerIdx);
						
//						listOrderLayers.setItem(selectedIdx,     tmpLayerIdx_1.getName());
//						listOrderLayers.setItem(selectedIdx - 1, tmpLayerIdx.getName());
						
						// Update views
						updateTree();
					}
				}
			}
		});
		btnUp.setToolTipText("Up");
		btnUp.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/upload_32_32.png"));
		
		Button btnLayerDown = new Button(composite_1, SWT.NONE);
		btnLayerDown.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				// Get select item of the combo
				int selectedIdx = listOrderLayers.getSelectionIndex();
				
				if (selectedIdx != -1) {
//					int numberItems = layersList.size();
//					
//					// If it is a the top, do not move it anymore
//					if (selectedIdx < (numberItems-1)) {
//						// Move the item up in the combo
//						
//						// Get items
//						Layer tmpLayerIdx   = layersList.get(selectedIdx);
//						Layer tmpLayerIdx_1 = layersList.get(selectedIdx + 1);
//						
//						tmpLayerIdx.setSequenceNumber(selectedIdx + 1);
//						tmpLayerIdx_1.setSequenceNumber(selectedIdx);
//						
//						// Swap them				
//						layersList.set(selectedIdx,     tmpLayerIdx_1);
//						layersList.set(selectedIdx + 1, tmpLayerIdx);
//						
//						listOrderLayers.setItem(selectedIdx,     tmpLayerIdx_1.getName());
//						listOrderLayers.setItem(selectedIdx + 1, tmpLayerIdx.getName());
//						
//						// Update views
//						updateTree();
//					}
				}
			}
		});
		btnLayerDown.setToolTipText("Down");
		btnLayerDown.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/download_32_32.png"));
		
		Composite composite = new Composite(compLayerOrder, SWT.NONE);
		composite.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		RowLayout rl_composite = new RowLayout(SWT.HORIZONTAL);
		rl_composite.spacing = 10;
		composite.setLayout(rl_composite);
		
		Button btnAddLayerGroup = new Button(composite, SWT.NONE);
		btnAddLayerGroup.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				// Show and activate the layer group
				showAddLayerGroup();
			}
		});
		btnAddLayerGroup.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAddLayerGroup.setToolTipText("Add Layer");
		
		Button btnRemoveLayerGroup = new Button(composite, SWT.NONE);
		btnRemoveLayerGroup.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				String[] selectedLayers = listOrderLayers.getSelection();
				
				if (selectedLayers != null && selectedLayers.length > 0) {
					removeLayer(selectedLayers[0]);
				} else {
					showError("Please, select a layer");
				}
			}
		});
		btnRemoveLayerGroup.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemoveLayerGroup.setToolTipText("Remove layer");
		new Label(compLayerOrder, SWT.NONE);
		
		grpLayer.setLayout(new GridLayout(1, false));
		grpLayer.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, false, 1, 1));
		grpLayer.setText("Layer");
		
		Composite composite_2 = new Composite(grpLayer, SWT.NONE);
		composite_2.setLayoutData(new GridData(SWT.CENTER, SWT.FILL, false, false, 1, 1));
		composite_2.setLayout(new GridLayout(2, false));
		
		Button btnCloseLayer = new Button(composite_2, SWT.NONE);
		btnCloseLayer.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				// Read list of items from the combo box
				
				// Send message to the server
				
				// Close/hide Layers group
				hideLayerGroup();
			}
		});
		btnCloseLayer.setToolTipText("Update Layers");
		btnCloseLayer.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/ok_32_32.png"));
		
		Button btnCancelLayer = new Button(composite_2, SWT.NONE);
		btnCancelLayer.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				// Close/hide Layers group
				hideLayerGroup();
			}
		});
		btnCancelLayer.setToolTipText("Close");
		btnCancelLayer.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		
		groupAddLayer = new Group(grpLayer, SWT.NONE);
		groupAddLayer.setLayout(new GridLayout(3, false));
		groupAddLayer.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1));
		groupAddLayer.setVisible(false);
		
		Label lblName = new Label(groupAddLayer, SWT.NONE);
		lblName.setText("Name");
		
		textLayerName = new Text(groupAddLayer, SWT.BORDER);
		GridData gd_textLayerName = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
		gd_textLayerName.widthHint = 150;
		textLayerName.setLayoutData(gd_textLayerName);
		new Label(groupAddLayer, SWT.NONE);
		
		Label lblDescription = new Label(groupAddLayer, SWT.NONE);
		lblDescription.setText("Description");
		
		textLayerDescription = new Text(groupAddLayer, SWT.BORDER | SWT.MULTI);
		GridData gd_textLayerDescription = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
		gd_textLayerDescription.heightHint = 75;
		gd_textLayerDescription.widthHint = 250;
		textLayerDescription.setLayoutData(gd_textLayerDescription);
		new Label(groupAddLayer, SWT.NONE);
		
		Label lblSequenceNumber = new Label(groupAddLayer, SWT.NONE);
		lblSequenceNumber.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblSequenceNumber.setText("Sequence Number");
		
		textSequenceNumber = new Text(groupAddLayer, SWT.BORDER);
		GridData gd_textSequenceNumber = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textSequenceNumber.widthHint = 100;
		textSequenceNumber.setLayoutData(gd_textSequenceNumber);
		new Label(groupAddLayer, SWT.NONE);
		
		Group groupLayerType = new Group(groupAddLayer, SWT.NONE);
		groupLayerType.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 1, 2));
		groupLayerType.setLayout(new GridLayout(1, false));
		
		Button btnFixLayer = new Button(groupLayerType, SWT.RADIO);
		btnFixLayer.setText("Default Layer");
		
		Button btnCustomLayer = new Button(groupLayerType, SWT.RADIO);
		btnCustomLayer.setText("Custom Layer");
		
		Label lblProtocol = new Label(groupAddLayer, SWT.NONE);
		lblProtocol.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblProtocol.setText("Protocol");
		
		comboLayerProtocol = new Combo(groupAddLayer, SWT.NONE);
		GridData gd_comboLayerProtocol = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_comboLayerProtocol.widthHint = 200;
		comboLayerProtocol.setLayoutData(gd_comboLayerProtocol);
		
		Label lblFrameType = new Label(groupAddLayer, SWT.NONE);
		lblFrameType.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblFrameType.setText("Frame Type");
		
		Combo comboCustomFrame = new Combo(groupAddLayer, SWT.NONE);
		GridData gd_comboCustomFrame = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_comboCustomFrame.widthHint = 200;
		comboCustomFrame.setLayoutData(gd_comboCustomFrame);
		
		Composite compositeLayerButton = new Composite(groupAddLayer, SWT.NONE);
		compositeLayerButton.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 2, 1));
		compositeLayerButton.setLayout(new GridLayout(2, false));
		
		Button btnAddLayer1 = new Button(compositeLayerButton, SWT.NONE);
		btnAddLayer1.setToolTipText("Add or Update");
		btnAddLayer1.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/ok_32_32.png"));
		btnAddLayer1.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
//				// Create Layer object
//                Layer newLayer = new Layer();
//				
//				newLayer.setName(textLayerName.getText());
//				newLayer.setDescription(textLayerDescription.getText());
//				newLayer.setSequenceNumber( Integer.parseInt( textSequenceNumber.getText()) );
//				newLayer.setMissionName(missionName);
//				
//				// TODO: PROTOCOL
//				if (btnFixLayer.getSelection() == true) {
//					int index = comboLayerProtocol.getSelectionIndex();
//					
//					if (index != -1) {
//						newLayer.setDefaultFlag(true);
//					}
//				} else if (btnCustomLayer.getSelection() == true) {
//					int index = comboCustomFrame.getSelectionIndex();
//					
//					if (index != -1) {
//						newLayer.setDefaultFlag(false);
//					}
//				}
				
				// Send the message to server
//				addLayer(newLayer);
				
				// Add to the list
//				listOrderLayers.add(newLayer.getName());
				
				// Clean fields
				textLayerName.setText("");
				textLayerDescription.setText("");
				textSequenceNumber.setText("");
				
				// Hide the group
				hideAddLayerGroup();
			}
		});
		
		Button btrnCloseLayer = new Button(compositeLayerButton, SWT.NONE);
		btrnCloseLayer.setToolTipText("Close");
		btrnCloseLayer.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		new Label(groupAddLayer, SWT.NONE);
		btrnCloseLayer.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Hide the group
				hideAddLayerGroup();
			}
		});
		
		// Uncomment before deploy it
		grpGroundStation = new Group(compRightHidden, SWT.NONE);
		
		
		// In Eclipse. it shows the group. Comment before deploy it
		//grpGroundStation = new Group(compRight, SWT.NONE);

		grpGroundStation.setText("Ground Station");
		grpGroundStation.setLayout(new GridLayout(2, false));
		
		Group grpGeneral = new Group(grpGroundStation, SWT.NONE);
		grpGeneral.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		grpGeneral.setText("General");
		grpGeneral.setLayout(new GridLayout(2, false));
		
		Label lblName1 = new Label(grpGeneral, SWT.NONE);
		
		lblName1.setText("Name");
		
		textName = new Text(grpGeneral, SWT.BORDER);
		GridData gd_textName = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textName.widthHint = 200;
		textName.setLayoutData(gd_textName);
		
		Label lblNewLabel1 = new Label(grpGeneral, SWT.NONE);
		
		lblNewLabel1.setText("Acronym");
		
		textAcronym = new Text(grpGeneral, SWT.BORDER);
		GridData gd_textAcronym = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textAcronym.widthHint = 75;
		textAcronym.setLayoutData(gd_textAcronym);
		
		Label lblDescription1 = new Label(grpGeneral, SWT.NONE);
		
		lblDescription1.setText("Description");
		
		textDescription = new Text(grpGeneral, SWT.BORDER);
		GridData gd_textDescription = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
		gd_textDescription.heightHint = 75;
		gd_textDescription.widthHint = 300;
		textDescription.setLayoutData(gd_textDescription);
		new Label(grpGroundStation, SWT.NONE);
		
		Group grpPosition = new Group(grpGroundStation, SWT.NONE);
		grpPosition.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		grpPosition.setLayout(new GridLayout(6, false));
		grpPosition.setText("Position");
		
		Label lblLongitude = new Label(grpPosition, SWT.NONE);
		lblLongitude.setText("Longitude");
		
		textLongitude = new Text(grpPosition, SWT.BORDER);
		
		Label lblLatitude = new Label(grpPosition, SWT.NONE);
		lblLatitude.setText("Latitude");
		
		textLatitude = new Text(grpPosition, SWT.BORDER);
		
		Label lblAltitude = new Label(grpPosition, SWT.NONE);
		lblAltitude.setText("Altitude");
		
		textAltitude = new Text(grpPosition, SWT.BORDER);
		new Label(grpGroundStation, SWT.NONE);
		
		Group grpMask = new Group(grpGroundStation, SWT.NONE);
		grpMask.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		grpMask.setLayout(new GridLayout(1, false));
		grpMask.setText("Mask");
		
		Label lblPoints = new Label(grpMask, SWT.NONE);
		lblPoints.setText("Points");
		
		tableMaskPoints = new Table(grpMask, SWT.BORDER | SWT.FULL_SELECTION);
		GridData gridData_2 = new GridData(SWT.CENTER, SWT.FILL, true, true, 1, 1);
		gridData_2.heightHint = 150;
		tableMaskPoints.setLayoutData(gridData_2);
		tableMaskPoints.setHeaderVisible(true);
		tableMaskPoints.setLinesVisible(true);
		
		TableColumn tblclmnAzimuth = new TableColumn(tableMaskPoints, SWT.NONE);
		tblclmnAzimuth.setWidth(110);
		tblclmnAzimuth.setText("Azimuth");
		
		TableColumn tblclmnElevation = new TableColumn(tableMaskPoints, SWT.NONE);
		tblclmnElevation.setWidth(110);
		tblclmnElevation.setText("Elevation");
		
		Composite compositeMask = new Composite(grpMask, SWT.NONE);
		compositeMask.setLayout(new RowLayout(SWT.HORIZONTAL));
		compositeMask.setLayoutData(new GridData(SWT.CENTER, SWT.FILL, false, false, 1, 1));
		
		Button btnAdd = new Button(compositeMask, SWT.NONE);
		btnAdd.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAdd.setToolTipText("Add");
		btnAdd.setLayoutData(new RowData(80, SWT.DEFAULT));
		
		Button btnRemove = new Button(compositeMask, SWT.NONE);
		btnRemove.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemove.setToolTipText("Remove");
		btnRemove.setLayoutData(new RowData(80, SWT.DEFAULT));
		
		Composite compositeImport = new Composite(grpMask, SWT.NONE);
		compositeImport.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 1, 1));
		compositeImport.setLayout(new GridLayout(4, false));
		
		Label lblImport = new Label(compositeImport, SWT.NONE);
		lblImport.setText("Import");
		
		textImport = new Text(compositeImport, SWT.BORDER);
		GridData gridData = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gridData.widthHint = 250;
		textImport.setLayoutData(gridData);
		
		Button btnSelect = new Button(compositeImport, SWT.NONE);
		btnSelect.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/search_32_32.png"));
		btnSelect.setToolTipText("Select");
		GridData gd_btnSelect = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnSelect.widthHint = 80;
		btnSelect.setLayoutData(gd_btnSelect);
		
		Button btnImport = new Button(compositeImport, SWT.NONE);
		btnImport.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/import_32_32.png"));
		btnImport.setToolTipText("Import");
		GridData gd_btnImport = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnImport.widthHint = 80;
		btnImport.setLayoutData(gd_btnImport);
		btnImport.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});
		
		Composite compositeGenerate = new Composite(grpMask, SWT.NONE);
		compositeGenerate.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		compositeGenerate.setLayout(new GridLayout(3, false));
		
		Label lblGenerate = new Label(compositeGenerate, SWT.NONE);
		lblGenerate.setText("Minimum elevation");
		
		text = new Text(compositeGenerate, SWT.BORDER);
		text.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Button btnGenerate = new Button(compositeGenerate, SWT.NONE);
		btnGenerate.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/settings_32_32.png"));
		btnGenerate.setToolTipText("Generate");
		new Label(grpGroundStation, SWT.NONE);
		lblName.setText("Name");
		lblNewLabel.setText("Acronym");
		lblDescription.setText("Description");
		
		Group grpProtocols = new Group(grpGroundStation, SWT.NONE);
		grpProtocols.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		grpProtocols.setText("Protocols");
		grpProtocols.setLayout(new GridLayout(1, false));
		
		Group grpPhysicalLayer = new Group(grpProtocols, SWT.NONE);
		grpPhysicalLayer.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		grpPhysicalLayer.setText("Physical Layer");
		grpPhysicalLayer.setLayout(new GridLayout(5, false));
		
		Button btnTcpip = new Button(grpPhysicalLayer, SWT.RADIO);
		btnTcpip.setSelection(true);
		btnTcpip.setText("TCP/IP");
		
		Label lblAddress = new Label(grpPhysicalLayer, SWT.NONE);
		lblAddress.setText("Address");
		
		textIpAddress = new Text(grpPhysicalLayer, SWT.BORDER);
		GridData gd_textIpAddress = new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1);
		gd_textIpAddress.widthHint = 125;
		textIpAddress.setLayoutData(gd_textIpAddress);
		
		Label lblPort = new Label(grpPhysicalLayer, SWT.NONE);
		lblPort.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblPort.setText("Port");
		
		textPort = new Text(grpPhysicalLayer, SWT.BORDER);
		textPort.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		
		Button btnRs = new Button(grpPhysicalLayer, SWT.RADIO);
		btnRs.setText("RS 232");
		
		Label lblComPort = new Label(grpPhysicalLayer, SWT.NONE);
		lblComPort.setText("COM Port");
		
		Combo comboRs232 = new Combo(grpPhysicalLayer, SWT.NONE);
		comboRs232.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		
		Label lbln = new Label(grpPhysicalLayer, SWT.NONE);
		lbln.setText("8N1");
		new Label(grpPhysicalLayer, SWT.NONE);
		
		Button btnUsb = new Button(grpPhysicalLayer, SWT.RADIO);
		btnUsb.setText("USB");
		
		Label lblComPort_1 = new Label(grpPhysicalLayer, SWT.NONE);
		lblComPort_1.setText("COM Port");
		
		Combo comboUsb = new Combo(grpPhysicalLayer, SWT.NONE);
		comboUsb.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		new Label(grpPhysicalLayer, SWT.NONE);
		new Label(grpPhysicalLayer, SWT.NONE);
		new Label(grpGroundStation, SWT.NONE);
		
		Composite compButtons = new Composite(grpGroundStation, SWT.NONE);
		compButtons.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 2, 1));
		compButtons.setBackground(SWTResourceManager.getColor(SWT.COLOR_WIDGET_BACKGROUND));
		GridLayout gl_compButtons = new GridLayout(2, false);
		gl_compButtons.verticalSpacing = 3;
		gl_compButtons.marginWidth = 3;
		gl_compButtons.marginHeight = 3;
		gl_compButtons.horizontalSpacing = 3;
		compButtons.setLayout(gl_compButtons);
		
		Button btnUpdateGS = new Button(compButtons, SWT.NONE);
		btnUpdateGS.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/save_32_32.png"));
		btnUpdateGS.setToolTipText("Save");
		GridData gd_btnUpdateGS = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_btnUpdateGS.widthHint = 80;
		btnUpdateGS.setLayoutData(gd_btnUpdateGS);
		
		Button btnCancelGS = new Button(compButtons, SWT.NONE);
		btnCancelGS.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		btnCancelGS.setToolTipText("Cancel");
		GridData gd_btnCancelGS = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_btnCancelGS.widthHint = 80;
		btnCancelGS.setLayoutData(gd_btnCancelGS);
		new Label(compRight, SWT.NONE);
		
		
//		Composite compositeGSButton = new Composite(grpGroundStation, SWT.NONE);
//		compositeGSButton.setLayout(new GridLayout(2, false));
//		compositeGSButton.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
//		
//		Button btnAddGS = new Button(compositeGSButton, SWT.NONE);
//		btnAddGS.setToolTipText("Add or Update");
//		btnAddGS.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/ok_32_32.png"));
//		
//		Button btnCloseGS = new Button(compositeGSButton, SWT.NONE);
//		btnCloseGS.setToolTipText("Close");
//		btnCloseGS.setImage(SWTResourceManager.getImage(ToolsConfigureMissionPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
//		sashForm.setWeights(new int[] {400, 778});
//		btnCloseGS.addSelectionListener(new SelectionAdapter() {
//			private static final long serialVersionUID = 1L;
//
//			@Override
//			public void widgetSelected(SelectionEvent e) {
//				// Hide the group
//				hideGroundStationsGroup();
//			}
//		});
		
		// Scroll composite
        sc.setContent(compToolsContent);
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
    public void backButton() {
		// Back to Tools main page
		SingletonViews.getInstance().changeView(Constants.TOOLS_MAIN_VIEW_NAME);
    }

	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
	
	public void start() {
		super.start();
		
		// Read mission data; satellites, subsystems, layers, ground stations
        readData();
        
        // clean the tree and update the content
        updateTree();
	}
	
	/**
	 * Read all mission data; mission satellites, subsystems and layers
	 */
	private void readData() {
		// Read mission satellites
		readMissionSatellites();
		
		// Read mission layers
		readMissionLayers();
		
		// Read Ground Stations
		readGroundStations();
	}
	
	private void readMissionSatellites() {
		GetSatellitesMessage satelliteMsg = null;

//		try {
//			satelliteMsg = new GetSatellitesMessage(this.missionName);
//
//			ReturnData returnData = satelliteMsg.request();
//
//			if (returnData.getErrorCode() == 0) {
//				ListSatellites  tmpList = satelliteMsg.getResponse(); 
//				
//				if (this.satellitesList == null) {
//					this.satellitesList = new ArrayList<Satellite>();
//				}
//				this.satellitesList.clear();
//				this.satellitesList.addAll( tmpList.getListSatellites() );
//			}
//			else
//			{
//				showError("Unable to read mission satellites. Message:" + returnData.getErrorMessage());
//			}
//		} catch (Exception e) {
//			showError("Exception: " + e.getMessage());
//			
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
	}
	
	// Read mission layers
	// Read Default layers for all missions
	private void readMissionLayers() {
//		GetMissionLayersMessage layersMsg = null;
//
//		try {
//			layersMsg = new GetMissionLayersMessage(this.missionName);
//
//			ReturnData returnData = layersMsg.request();
//
//			if (returnData.getErrorCode() == 0) {
//				ListLayers  tmpList = layersMsg.getResponse(); 
//				
//				if (this.layersList == null) {
//					this.layersList = new ArrayList<Layer>();
//				}
//				this.layersList.clear();
//				this.layersList.addAll( tmpList.getListLayers() );
//			}
//			else
//			{
//				showError("Unable to read mission satellites. Message:" + returnData.getErrorMessage());
//			}
//		} catch (Exception e) {
//			showError("Exception: " + e.getMessage());
//			
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//		
//		GetDefaultMissionLayersMessage  defaultMsg = null;
//		
//		try {
//			defaultMsg = new GetDefaultMissionLayersMessage();
//
//			ReturnData returnData = defaultMsg.request();
//
//			if (returnData.getErrorCode() == 0) {
//				this.defaultListLayers = defaultMsg.getResponse();
//				
//				// Add the list of default layers
//				if (comboLayerProtocol != null) {
//					for(Layer current: this.defaultListLayers.getListLayers()) {						
//						comboLayerProtocol.add(current.getName());
//					}
//				}
//			}
//		} catch (Exception e) {
//			showError("Exception: " + e.getMessage());
//			
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
	}
	
	private void readGroundStations() {
	}
	
	private void updateTree() {
//		// Satellites and Subsystems
//		// ----------------------------------------------------
//		// Clean previous satellites
//		trtmSatellites.removeAll();
//
//		if (this.satellitesList != null) {
//			System.out.println("No Satellites: " + this.satellitesList.size());
//			
//			// Add the satellites
//			for (Satellite currentSatellite : this.satellitesList) {
//				TreeItem newSatellite = new TreeItem(trtmSatellites, SWT.NONE);
//				
//				newSatellite.setText(currentSatellite.getName());
//				
//				for (Subsystem currentSubsystem : currentSatellite.getListSubsystems()) {
//					TreeItem trtmSub = new TreeItem(newSatellite, SWT.NONE);
//					
//					trtmSub.setText(currentSubsystem.getName());
//				}
//			}			
//		}
//		
//		// Layers
//		// -------------------------------------------		
//		// Clean previous layers
//		trtmLayers.removeAll();
//		
//		if (this.layersList != null) {			
//			System.out.println("No layers: " + this.layersList.size());
//			
//			// Add new layers
//			for (Layer currentLayer : this.layersList) {
//				TreeItem itemLayer = new TreeItem(trtmLayers, SWT.NONE);
//				
//				itemLayer.setText(currentLayer.getName());
//			}
//		}
//		
//		// Ground Stations
//		// -------------------------------------------
	}
	
	private void showSatelliteGroup() {
		grpSatellite.setParent(compRight);		
		grpSatellite.setVisible(true);
		compRight.layout();
	}
	
	private void hideSatelliteGroup() {
		grpSatellite.setParent(compRightHidden);
		grpSatellite.setVisible(false);
		compRight.layout();
	}
	
	private void showSubsystemGroup() {
		grpSubsystem.setParent(compRight);		
		grpSubsystem.setVisible(true);
		compRight.layout();
	}
	
	private void hideSubsystemGroup() {
		grpSubsystem.setParent(compRightHidden);
		grpSubsystem.setVisible(false);
		compRight.layout();
	}
	
    private void showGroundStationsGroup() {
    	grpGroundStation.setParent(compRight);		
		grpGroundStation.setVisible(true);
		compRight.layout();
	}
	
	private void hideGroundStationsGroup() {
		grpGroundStation.setParent(compRightHidden);
		grpGroundStation.setVisible(false);
		compRight.layout();
	}
	
	protected void showLayerGroup() {
		// Show the list of layers 
//		for(Layer currentLayer: layersList) {
//			listOrderLayers.add(currentLayer.getName());
//		}

		grpLayer.setParent(compRight);
		grpLayer.setVisible(true);
		compRight.layout();
	}

	protected void hideLayerGroup() {
		// Clean list of layers
		listOrderLayers.removeAll();
		
		grpLayer.setParent(compRightHidden);
		grpLayer.setVisible(false);
		compRight.layout();
	}
	
	protected void showAddLayerGroup() {
		groupAddLayer.setParent(compRight);
		groupAddLayer.setVisible(true);
		compRight.layout();
	}
	
	protected void hideAddLayerGroup() {
		groupAddLayer.setParent(compRightHidden);
		groupAddLayer.setVisible(false);
		compRight.layout();
	}
	
//	private void addSatellite(Satellite inSatellite) {
//		AddSatelliteMessage satelliteMsg = null;
//
//		try {
//			satelliteMsg = new AddSatelliteMessage(missionName, inSatellite);
//
//			ReturnData returnData = satelliteMsg.request();
//
//			if (returnData.getErrorCode() == 0) {
//				// Add to the list
//				satellitesList.add(inSatellite);
//				
//				updateTree();
//			} else {
//				showError("Unable to add satellite. Error: " + returnData.getErrorMessage());
//			}				
//		} catch (Exception e) {
//			showError("Exception: " + e.getMessage());
//			
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//	}

	private void removeSatellite(String inSatelliteName) {
		// Look for the Satellite
		// Remove a Satellite
		boolean found = false;
		
		System.out.println("Satellite: " + inSatelliteName);
		
//		for(Satellite current: satellitesList) {
//			if (inSatelliteName.equals(current.getName()) == true) {
//				MessageBox messageBox = new MessageBox(getShell(), SWT.APPLICATION_MODAL | SWT.ICON_QUESTION | SWT.YES | SWT.NO);
//		        
//		        messageBox.setMessage("Remove satellite " + current.getName() + "?");
//		        messageBox.setText("Remove Satellite");
//		        
//		        messageBox.open(new DialogCallback() {
//					private static final long serialVersionUID = 1L;
//
//					@Override
//		            public void dialogClosed(int returnCode) {
//		                if (returnCode == SWT.YES) {                
//		                	// Remove Satellite from the DB
//							RemoveSatelliteMessage satelliteMsg = null;
//
//							try {
//								satelliteMsg = new RemoveSatelliteMessage(missionName, inSatelliteName);
//
//								ReturnData returnData = satelliteMsg.request();
//
//								if (returnData.getErrorCode() == 0) {
//									// Remove from the list
//									satellitesList.remove(current);
//									
//									updateTree();
//								} else {
//									showError("Unable to remove satellite. Error: " + returnData.getErrorMessage());
//								}				
//							} catch (Exception e) {
//								showError("Exception: " + e.getMessage());
//								
//								// TODO Auto-generated catch block
//								e.printStackTrace();
//							}
//		                }
//		            }
//		        });
//				
//				found = true;
//				break;
//			}
//		}
//		
		if (found == false) {
			showError("Please, select a Satellite");
		}
	}
	
//	private void addSubsystem(Subsystem inSubsystem) {
//		AddSubsystemMessage subsystemMsg = null;
//
//		try {
//			subsystemMsg = new AddSubsystemMessage(inSubsystem.getSatelliteName(), inSubsystem);
//
//			ReturnData returnData = subsystemMsg.request();
//
//			if (returnData.getErrorCode() == 0) {
//				// Look for the Satellite and Subsystem
//				for(Satellite current: satellitesList) {
//					if (current.getName().equals(inSubsystem.getSatelliteName()) == true) {
//						current.getListSubsystems().add(inSubsystem);
//						
//						updateTree();
//						break;
//					}
//				}
//			} else {
//				showError("Unable to add Subsystem. Error: " + returnData.getErrorMessage());
//			}				
//		} catch (Exception e) {
//			showError("Exception: " + e.getMessage());
//			
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//	}
	
	private void removeSubsystem(String inSubsystemName) {
		boolean found = false;
		
//		// Look for the Satellite and Subsystem
//		for(Satellite current: satellitesList) {
//			for(Subsystem currentSubsystem: current.getListSubsystems()) {							
//				if (inSubsystemName.equals(currentSubsystem.getName()) == true) {
//					MessageBox messageBox = new MessageBox(getShell(), SWT.APPLICATION_MODAL | SWT.ICON_QUESTION | SWT.YES | SWT.NO);
//			        
//			        messageBox.setMessage("Remove subsystem " + currentSubsystem.getName() + "?");
//			        messageBox.setText("Remove Subsystem");
//			        
//			        messageBox.open(new DialogCallback() {
//						private static final long serialVersionUID = 1L;
//
//						@Override
//			            public void dialogClosed(int returnCode) {
//			                if (returnCode == SWT.YES) {                    
//			                	// Remove Subsystem from the DB
//								RemoveSubsystemMessage subsystemMsg = null;
//
//								try {
//									subsystemMsg = new RemoveSubsystemMessage(current.getName(), inSubsystemName);
//
//									ReturnData returnData = subsystemMsg.request();
//
//									if (returnData.getErrorCode() == 0) {
//										// Remove from the list
//										List<Subsystem> tmpList = current.getListSubsystems();
//										
//										tmpList.remove(currentSubsystem);
//										
//										current.setListSubsystems(tmpList);
//									
//										updateTree();
//									} else {
//										showError("Unable to remove Subsystem. Error: " + returnData.getErrorMessage());
//									}				
//								} catch (Exception e) {
//									showError("Exception: " + e.getMessage());
//									
//									// TODO Auto-generated catch block
//									e.printStackTrace();
//								}
//			                }
//			            }
//			        });
//					
//					found = true;
//					break;
//				}						
//			}
//		}
//		
//		if (found == false) {
//			showError("Please, select a Subsystem");
//		}
	}
	
//	protected void addLayer(Layer inLayer) {
//		AddMissionLayerMessage layerMsg = null;
//
//		try {
//			layerMsg = new AddMissionLayerMessage(this.missionName, inLayer);
//
//			ReturnData returnData = layerMsg.request();
//
//			if (returnData.getErrorCode() == 0) {
//				this.layersList.add(inLayer);
//				
//				updateTree();
//			} else {
//				showError("Unable to add Layer. Error: " + returnData.getErrorMessage());
//			}				
//		} catch (Exception e) {
//			showError("Exception: " + e.getMessage());
//			
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//	}

	protected void removeLayer(String inLayerName) {
		// Look for the Layer
		boolean found = false;

		System.out.println("Layer: " + inLayerName);

//		for (Layer current : layersList) {
//			if (inLayerName.equals(current.getName()) == true) {
//				MessageBox messageBox = new MessageBox(getShell(), SWT.APPLICATION_MODAL | SWT.ICON_QUESTION | SWT.YES | SWT.NO);
//
//				messageBox.setMessage("Remove layer " + current.getName() + "?");
//				messageBox.setText("Remove Layer");
//
//				messageBox.open(new DialogCallback() {
//					private static final long serialVersionUID = 1L;
//
//					@Override
//					public void dialogClosed(int returnCode) {
//						if (returnCode == SWT.YES) {
//							// Remove Satellite from the DB
//							RemoveLayerMessage layerMsg = null;
//
//							try {
//								layerMsg = new RemoveLayerMessage(missionName, inLayerName);
//
//								ReturnData returnData = layerMsg.request();
//
//								if (returnData.getErrorCode() == 0) {
//									// Remove from the list
//									layersList.remove(current);
//									
//									listOrderLayers.remove(inLayerName);
//
//									updateTree();
//								} else {
//									showError("Unable to remove Layer. Error: " + returnData.getErrorMessage());
//								}
//							} catch (Exception e) {
//								showError("Exception: " + e.getMessage());
//
//								// TODO Auto-generated catch block
//								e.printStackTrace();
//							}
//						}
//					}
//				});
//
//				found = true;
//				break;
//			}
//		}
//
//		if (found == false) {
//			showError("Please, select a Layer");
//		}
	}
}
