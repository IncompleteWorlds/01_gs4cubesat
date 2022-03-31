package com.incomplete.cubegs.fdswui.view;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.custom.StackLayout;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.wb.swt.SWTResourceManager;





public class FdsMainPage extends FdsBasePage  {
	private static final long serialVersionUID = 1L;

	// They have to be local otherwise WindowsBuiler does not work
	protected Composite compHeader = null; 
	protected Composite compContent = null;
	protected Composite compFooter = null;
	
	protected ScrolledComposite sc = null;
	protected Composite compFdsContent = null;
	protected ToolBar toolBar = null;
	
	protected Composite compTabs = null;
	protected Composite compSubTabs = null;
	
	protected Button pressedButton = null;
	
    private Text text;
    private Text text_1;
    private Text text_2;
    private Text text_3;
    private Text text_4;
    private Text txtPoint;
    private Text text_5;
    private Text text_6;
    private Text text_7;
    private Text text_8;
    private Text text_9;
    private Text text_10;
    private Text text_11;
    private Text text_12;
    private Text text_13;
    private Text text_14;
    private Text text_15;
    private Text text_16;
    private Text text_17;
    private Text text_18;
    private Text text_19;
    private Text text_20;
    private Text text_21;
    private Text text_22;
    private Text text_23;
    private Text text_24;
    private Text text_25;
    private Text text_26;
    private Text text_27;
    private Composite compSubTaskWorkspace = null;
	private Composite compSubTaskCommon = null;
	private Composite compSubTaskVisualization= null;
	private Composite compSubTaskGSn = null;
	private Composite compSubTaskDB = null;
	private Composite compSubTaskSC = null;
	private Composite compSubTaskSetup = null;

	private StackLayout menuStackLayout = null;
	private Button btnSpacecraft;

	private Button btnPropagateSGP4;

	private Button btnPropagate;

	private Button btnDetermine;

	private Button btnGenTLE;

	private Button btnOrbitComparison;

	private Button btnGetExternData;

	private Button btnCollisionRisk;

	private Button btnExportData;

	private Button btnGenerateProducts;
	private Text stepSecs;
	private Text tleLine1;
	private Text tleLine2;
	private Text ephemOutputText;
	private Text tleAll;

	private Composite compCentral;



	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public FdsMainPage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style, true);

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

		// Add Scroll
        sc = new ScrolledComposite(compContent, SWT.H_SCROLL | SWT.V_SCROLL);       
        sc.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
		
	    compFdsContent = new Composite(sc, SWT.NONE);
		GridLayout gl_compMcsContent = new GridLayout(1, true);
		gl_compMcsContent.verticalSpacing = 0;
		compFdsContent.setLayout(gl_compMcsContent);
		compFdsContent.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, true, 1, 1));
		
	    compTabs = new Composite(compFdsContent, SWT.NONE);
	    compTabs.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		GridLayout gl_compTabs = new GridLayout(7, true);
		gl_compTabs.horizontalSpacing = 1;
		gl_compTabs.marginHeight = 1;
		gl_compTabs.marginWidth = 1;
		compTabs.setLayout(gl_compTabs);
		
		compSubTabs = new Composite(compFdsContent, SWT.NONE);
		
		// Stack of submenus
		// Top control is the visible one
		menuStackLayout = new StackLayout();
		
		compSubTabs.setLayout(menuStackLayout);
		compSubTabs.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));


		compCentral = new Composite(compFdsContent, SWT.NONE);
		compCentral.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
				
		
		compSubTaskWorkspace = new Composite(compSubTabs, SWT.NONE);
		GridLayout gl_compSubTaskWorkspace = new GridLayout(10, true);
		gl_compSubTaskWorkspace.verticalSpacing = 0;
		gl_compSubTaskWorkspace.horizontalSpacing = 0;
		gl_compSubTaskWorkspace.marginHeight = 0;
		gl_compSubTaskWorkspace.marginWidth = 0;
		compSubTaskWorkspace.setLayout(gl_compSubTaskWorkspace);
		addWorkspaceCommands();
		
		compSubTaskCommon = new Composite(compSubTabs, SWT.NONE);
		GridLayout gl_compSubTaskCommon = new GridLayout(10, true);
		gl_compSubTaskCommon.verticalSpacing = 0;
		gl_compSubTaskCommon.horizontalSpacing = 0;
		gl_compSubTaskCommon.marginHeight = 0;
		gl_compSubTaskCommon.marginWidth = 0;
		compSubTaskCommon.setLayout(gl_compSubTaskCommon);
		addCommonCommands();
		
		compSubTaskVisualization = new Composite(compSubTabs, SWT.NONE);
		GridLayout gl_compSubTaskVisualization = new GridLayout(10, true);
		gl_compSubTaskVisualization.verticalSpacing = 0;
		gl_compSubTaskVisualization.horizontalSpacing = 0;
		gl_compSubTaskVisualization.marginHeight = 0;
		gl_compSubTaskVisualization.marginWidth = 0;
		compSubTaskVisualization.setLayout(gl_compSubTaskVisualization);
		addVisualizationCommands();
	
		compSubTaskSC = new Composite(compSubTabs, SWT.NONE);
		GridLayout gl_compSubTaskSC = new GridLayout(10, true);
		gl_compSubTaskSC.marginHeight = 0;
		gl_compSubTaskSC.verticalSpacing = 0;
		gl_compSubTaskSC.horizontalSpacing = 0;
		gl_compSubTaskSC.marginWidth = 0;
		compSubTaskSC.setLayout(gl_compSubTaskSC);
		addSpacecraftCommands();
		
		compSubTaskGSn = new Composite(compSubTabs, SWT.NONE);
		GridLayout gl_compSubTaskGSn = new GridLayout(10, true);
		gl_compSubTaskGSn.verticalSpacing = 0;
		gl_compSubTaskGSn.horizontalSpacing = 0;
		gl_compSubTaskGSn.marginHeight = 0;
		gl_compSubTaskGSn.marginWidth = 0;
		compSubTaskGSn.setLayout(gl_compSubTaskGSn);
		addStationCommands();
		
		compSubTaskDB = new Composite(compSubTabs, SWT.NONE);
		GridLayout gl_compSubTaskDB = new GridLayout(10, true);
		gl_compSubTaskDB.verticalSpacing = 0;
		gl_compSubTaskDB.horizontalSpacing = 0;
		gl_compSubTaskDB.marginHeight = 0;
		gl_compSubTaskDB.marginWidth = 0;
		compSubTaskDB.setLayout(gl_compSubTaskDB);
		addDatabaseCommands();
		
		compSubTaskSetup = new Composite(compSubTabs, SWT.NONE);
		GridLayout gl_compSubTaskSetup = new GridLayout(10, true);
		gl_compSubTaskSetup.verticalSpacing = 0;
		gl_compSubTaskSetup.horizontalSpacing = 0;
		gl_compSubTaskSetup.marginHeight = 0;
		gl_compSubTaskSetup.marginWidth = 0;
		compSubTaskSetup.setLayout(gl_compSubTaskSetup);
		
		Button btnNewButton = new Button(compSubTabs, SWT.FLAT);
		btnNewButton.setEnabled(false);
		btnNewButton.setText("      ");
		addSetupCommands();

		Button btnWorkspace = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnWorkspace.setEnabled(false);
		btnWorkspace.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 1, 1));
		btnWorkspace.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnWorkspace.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
				Button tmpBtn = (Button) e.widget;
				
				// Is it selected?
				if (highlightButton(tmpBtn) == true) {
					menuStackLayout.topControl = compSubTaskWorkspace;
					compSubTabs.layout();	
				}
		    }
		});
		btnWorkspace.setAlignment(SWT.CENTER);
		btnWorkspace.setText("Workspace");
		
		Button btnCommon = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnCommon.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		btnCommon.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnCommon.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
				Button tmpBtn = (Button) e.widget;
				
				// Is it selected?
				if (highlightButton(tmpBtn) == true) {
					menuStackLayout.topControl = compSubTaskCommon;
					compSubTabs.layout();	
				}
		    }
		});
		btnCommon.setText("Common");
		
		Button btnVisualization = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnVisualization.setEnabled(false);
		btnVisualization.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		btnVisualization.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnVisualization.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
				Button tmpBtn = (Button) e.widget;
				
				// Is it selected?
				if (highlightButton(tmpBtn) == true) {
					menuStackLayout.topControl = compSubTaskVisualization;
					compSubTabs.layout();	
				}
		    }
		});
		btnVisualization.setText("Visualization");
		btnVisualization.setBounds(0, 0, 75, 31);
		
		btnSpacecraft = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnSpacecraft.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		btnSpacecraft.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnSpacecraft.setText("Spacecraft");
		btnSpacecraft.setBounds(0, 0, 100, 31);
		btnSpacecraft.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
				Button tmpBtn = (Button) e.widget;
				
				// Is it selected?
				if (highlightButton(tmpBtn) == true) {
					menuStackLayout.topControl = compSubTaskSC;
					compSubTabs.layout();	
				}
		    }
		});
		
		Button btnStation = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnStation.setEnabled(false);
		btnStation.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		btnStation.setText("G. Station");
		btnStation.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnStation.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
				Button tmpBtn = (Button) e.widget;
				
				// Is it selected?
				if (highlightButton(tmpBtn) == true) {
					menuStackLayout.topControl = compSubTaskGSn;
					compSubTabs.layout();	
				}
		    }
		});
		
		Button btnDatabase = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnDatabase.setEnabled(false);
		btnDatabase.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		btnDatabase.setText("Database");
		btnDatabase.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnDatabase.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
				Button tmpBtn = (Button) e.widget;
				
				// Is it selected?
				if (highlightButton(tmpBtn) == true) {
					menuStackLayout.topControl = compSubTaskDB;
					compSubTabs.layout();	
				}				
		    }
		});
		
		Button btnSetup = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnSetup.setEnabled(false);
		btnSetup.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		btnSetup.setText("Setup");
		btnSetup.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));		
		
		btnSetup.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
				Button tmpBtn = (Button) e.widget;
				
				// Is it selected?
				if (highlightButton(tmpBtn) == true) {
					menuStackLayout.topControl = compSubTaskSetup;
					compSubTabs.layout();	
				}				
		    }
		});
		
		
		
		
		
		
		/*
		TabFolder tabFolder = new TabFolder(compFdsContent, SWT.NONE);
		GridData gd_tabFolder = new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1);
		gd_tabFolder.widthHint = 940;
		gd_tabFolder.heightHint = 497;
		tabFolder.setLayoutData(gd_tabFolder);
		
		TabItem tbtmPower = new TabItem(tabFolder, SWT.NONE);
		tbtmPower.setText("Power");
		
		Composite compPower = new Composite(tabFolder, SWT.NONE);
		tbtmPower.setControl(compPower);
		compPower.setLayout(new GridLayout(6, false));
		
		
		Label lblNewLabel = new Label(compPower, SWT.NONE);
		GridData gd_lblNewLabel = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_lblNewLabel.widthHint = 100;
		lblNewLabel.setLayoutData(gd_lblNewLabel);
		lblNewLabel.setText("Point 1");
		
		text = new Text(compPower, SWT.BORDER);
		text.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text.setText("9.99");
		GridData gd_text = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_text.widthHint = 100;
		text.setLayoutData(gd_text);
		
		Label lblNewLabel_3 = new Label(compPower, SWT.NONE);
		GridData gd_lblNewLabel_3 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_lblNewLabel_3.widthHint = 100;
		lblNewLabel_3.setLayoutData(gd_lblNewLabel_3);
		lblNewLabel_3.setText("Point 10");
		
		text_2 = new Text(compPower, SWT.BORDER);
		text_2.setForeground(SWTResourceManager.getColor(255, 0, 0));
		text_2.setText("0.1234");
		text_2.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label lblPoint = new Label(compPower, SWT.NONE);
		GridData gd_lblPoint = new GridData(SWT.LEFT, SWT.TOP, false, false, 1, 1);
		gd_lblPoint.widthHint = 100;
		lblPoint.setLayoutData(gd_lblPoint);
		lblPoint.setText("Point 20");
		
		text_5 = new Text(compPower, SWT.BORDER);
		text_5.setForeground(SWTResourceManager.getColor(51, 204, 0));
		text_5.setText("99.999");
		GridData gd_text_5 = new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1);
		gd_text_5.widthHint = 100;
		text_5.setLayoutData(gd_text_5);
		
		Label lblNewLabel_1 = new Label(compPower, SWT.NONE);
		lblNewLabel_1.setText("Point 2");
		
		text_1 = new Text(compPower, SWT.BORDER);
		text_1.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_1.setText("0.9999");
		text_1.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label lblNewLabel_4 = new Label(compPower, SWT.NONE);
		lblNewLabel_4.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, false, false, 1, 1));
		lblNewLabel_4.setText("Point 11");
		
		text_3 = new Text(compPower, SWT.BORDER);
		text_3.setForeground(SWTResourceManager.getColor(255, 0, 0));
		text_3.setText("0.1213");
		text_3.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		new Label(compPower, SWT.NONE);
		new Label(compPower, SWT.NONE);
		
		Label lblNewLabel_2 = new Label(compPower, SWT.NONE);
		lblNewLabel_2.setText("Point 3");
		
		text_4 = new Text(compPower, SWT.BORDER);
		text_4.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_4.setText("99.999");
		text_4.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, false, false, 1, 1));
		new Label(compPower, SWT.NONE);
		new Label(compPower, SWT.NONE);
		new Label(compPower, SWT.NONE);
		new Label(compPower, SWT.NONE);
		
		Label lblPoint_1 = new Label(compPower, SWT.NONE);
		lblPoint_1.setText("Point 4");
		
		txtPoint = new Text(compPower, SWT.BORDER);
		txtPoint.setForeground(SWTResourceManager.getColor(0, 153, 0));
		txtPoint.setText("0.00001");
		txtPoint.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1));
		new Label(compPower, SWT.NONE);
		new Label(compPower, SWT.NONE);
		new Label(compPower, SWT.NONE);
		new Label(compPower, SWT.NONE);
		
		TabItem tabComms = new TabItem(tabFolder, SWT.NONE);
		tabComms.setText("Comms");
		
		Composite compComms = new Composite(tabFolder, SWT.NONE);
		tabComms.setControl(compComms);
		compComms.setLayout(new GridLayout(6, false));
		
		Label label = new Label(compComms, SWT.NONE);
		GridData gd_label = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_label.widthHint = 100;
		label.setLayoutData(gd_label);
		label.setText("Point 1");
		
		text_6 = new Text(compComms, SWT.BORDER);
		text_6.setText("9.99");
		text_6.setForeground(SWTResourceManager.getColor(0, 153, 0));
		GridData gd_text_6 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_text_6.widthHint = 100;
		text_6.setLayoutData(gd_text_6);
		
		Label label_1 = new Label(compComms, SWT.NONE);
		GridData gd_label_1 = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_label_1.widthHint = 100;
		label_1.setLayoutData(gd_label_1);
		label_1.setText("Point 10");
		
		text_7 = new Text(compComms, SWT.BORDER);
		text_7.setText("0.1234");
		text_7.setForeground(SWTResourceManager.getColor(255, 0, 0));
		text_7.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label label_2 = new Label(compComms, SWT.NONE);
		GridData gd_label_2 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_label_2.widthHint = 100;
		label_2.setLayoutData(gd_label_2);
		label_2.setText("Point 20");
		
		text_8 = new Text(compComms, SWT.BORDER);
		text_8.setText("99.999");
		text_8.setForeground(SWTResourceManager.getColor(51, 204, 0));
		GridData gd_text_8 = new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1);
		gd_text_8.widthHint = 100;
		text_8.setLayoutData(gd_text_8);
		
		Label label_3 = new Label(compComms, SWT.NONE);
		label_3.setText("Point 2");
		
		text_9 = new Text(compComms, SWT.BORDER);
		text_9.setText("0.9999");
		text_9.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_9.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label label_4 = new Label(compComms, SWT.NONE);
		label_4.setText("Point 11");
		
		text_10 = new Text(compComms, SWT.BORDER);
		text_10.setText("0.1213");
		text_10.setForeground(SWTResourceManager.getColor(255, 0, 0));
		text_10.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		new Label(compComms, SWT.NONE);
		new Label(compComms, SWT.NONE);
		
		Label label_5 = new Label(compComms, SWT.NONE);
		label_5.setText("Point 3");
		
		text_11 = new Text(compComms, SWT.BORDER);
		text_11.setText("99.999");
		text_11.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_11.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, false, false, 1, 1));
		new Label(compComms, SWT.NONE);
		new Label(compComms, SWT.NONE);
		new Label(compComms, SWT.NONE);
		new Label(compComms, SWT.NONE);
		
		Label label_6 = new Label(compComms, SWT.NONE);
		label_6.setText("Point 4");
		
		text_12 = new Text(compComms, SWT.BORDER);
		text_12.setText("0.00001");
		text_12.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_12.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1));
		new Label(compComms, SWT.NONE);
		new Label(compComms, SWT.NONE);
		new Label(compComms, SWT.NONE);
		new Label(compComms, SWT.NONE);
		
		TabItem tabOBC = new TabItem(tabFolder, SWT.NONE);
		tabOBC.setText("OBC");
		
		Composite compOBC = new Composite(tabFolder, SWT.NONE);
		tabOBC.setControl(compOBC);
		compOBC.setLayout(new GridLayout(6, false));
		
		Label label_7 = new Label(compOBC, SWT.NONE);
		GridData gd_label_7 = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_label_7.widthHint = 100;
		label_7.setLayoutData(gd_label_7);
		label_7.setText("Point 1");
		
		text_13 = new Text(compOBC, SWT.BORDER);
		text_13.setText("9.99");
		text_13.setForeground(SWTResourceManager.getColor(0, 153, 0));
		GridData gd_text_13 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_text_13.widthHint = 100;
		text_13.setLayoutData(gd_text_13);
		
		Label label_8 = new Label(compOBC, SWT.NONE);
		GridData gd_label_8 = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_label_8.widthHint = 100;
		label_8.setLayoutData(gd_label_8);
		label_8.setText("Point 10");
		
		text_14 = new Text(compOBC, SWT.BORDER);
		text_14.setText("0.1234");
		text_14.setForeground(SWTResourceManager.getColor(255, 0, 0));
		text_14.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label label_9 = new Label(compOBC, SWT.NONE);
		GridData gd_label_9 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_label_9.widthHint = 100;
		label_9.setLayoutData(gd_label_9);
		label_9.setText("Point 20");
		
		text_15 = new Text(compOBC, SWT.BORDER);
		text_15.setText("99.999");
		text_15.setForeground(SWTResourceManager.getColor(51, 204, 0));
		GridData gd_text_15 = new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1);
		gd_text_15.widthHint = 100;
		text_15.setLayoutData(gd_text_15);
		
		Label label_10 = new Label(compOBC, SWT.NONE);
		label_10.setText("Point 2");
		
		text_16 = new Text(compOBC, SWT.BORDER);
		text_16.setText("0.9999");
		text_16.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_16.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label label_11 = new Label(compOBC, SWT.NONE);
		label_11.setText("Point 11");
		
		text_17 = new Text(compOBC, SWT.BORDER);
		text_17.setText("0.1213");
		text_17.setForeground(SWTResourceManager.getColor(255, 0, 0));
		text_17.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		
		Label label_12 = new Label(compOBC, SWT.NONE);
		label_12.setText("Point 3");
		
		text_18 = new Text(compOBC, SWT.BORDER);
		text_18.setText("99.999");
		text_18.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_18.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, false, false, 1, 1));
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		
		Label label_13 = new Label(compOBC, SWT.NONE);
		label_13.setText("Point 4");
		
		text_19 = new Text(compOBC, SWT.BORDER);
		text_19.setText("0.00001");
		text_19.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_19.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1));
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		
		Label lblPoint_2 = new Label(compOBC, SWT.NONE);
		lblPoint_2.setText("Point 5");
		
		text_27 = new Text(compOBC, SWT.BORDER);
		text_27.setText("0.00001");
		text_27.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_27.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		new Label(compOBC, SWT.NONE);
		
		TabItem tabPanels = new TabItem(tabFolder, SWT.NONE);
		tabPanels.setText("Panels");
		
		Composite compPanels = new Composite(tabFolder, SWT.NONE);
		tabPanels.setControl(compPanels);
		compPanels.setLayout(new GridLayout(6, false));
		
		Label label_14 = new Label(compPanels, SWT.NONE);
		GridData gd_label_14 = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_label_14.widthHint = 100;
		label_14.setLayoutData(gd_label_14);
		label_14.setText("Point 1");
		
		text_20 = new Text(compPanels, SWT.BORDER);
		text_20.setText("9.99");
		text_20.setForeground(SWTResourceManager.getColor(0, 153, 0));
		GridData gd_text_20 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_text_20.widthHint = 100;
		text_20.setLayoutData(gd_text_20);
		
		Label label_15 = new Label(compPanels, SWT.NONE);
		GridData gd_label_15 = new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1);
		gd_label_15.widthHint = 100;
		label_15.setLayoutData(gd_label_15);
		label_15.setText("Point 10");
		
		text_21 = new Text(compPanels, SWT.BORDER);
		text_21.setText("0.1234");
		text_21.setForeground(SWTResourceManager.getColor(255, 0, 0));
		text_21.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label label_16 = new Label(compPanels, SWT.NONE);
		GridData gd_label_16 = new GridData(SWT.RIGHT, SWT.TOP, false, false, 1, 1);
		gd_label_16.widthHint = 100;
		label_16.setLayoutData(gd_label_16);
		label_16.setText("Point 20");
		
		text_22 = new Text(compPanels, SWT.BORDER);
		text_22.setText("99.999");
		text_22.setForeground(SWTResourceManager.getColor(51, 204, 0));
		GridData gd_text_22 = new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1);
		gd_text_22.widthHint = 100;
		text_22.setLayoutData(gd_text_22);
		
		Label label_17 = new Label(compPanels, SWT.NONE);
		label_17.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		label_17.setText("Point 2");
		
		text_23 = new Text(compPanels, SWT.BORDER);
		text_23.setText("0.9999");
		text_23.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_23.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		
		Label label_18 = new Label(compPanels, SWT.NONE);
		label_18.setLayoutData(new GridData(SWT.RIGHT, SWT.TOP, false, false, 1, 1));
		label_18.setText("Point 11");
		
		text_24 = new Text(compPanels, SWT.BORDER);
		text_24.setText("0.1213");
		text_24.setForeground(SWTResourceManager.getColor(255, 0, 0));
		text_24.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		new Label(compPanels, SWT.NONE);
		new Label(compPanels, SWT.NONE);
		
		Label label_19 = new Label(compPanels, SWT.NONE);
		label_19.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		label_19.setText("Point 3");
		
		text_25 = new Text(compPanels, SWT.BORDER);
		text_25.setText("99.999");
		text_25.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_25.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, false, false, 1, 1));
		new Label(compPanels, SWT.NONE);
		new Label(compPanels, SWT.NONE);
		new Label(compPanels, SWT.NONE);
		new Label(compPanels, SWT.NONE);
		
		Label label_20 = new Label(compPanels, SWT.NONE);
		label_20.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		label_20.setText("Point 4");
		
		text_26 = new Text(compPanels, SWT.BORDER);
		text_26.setText("0.00001");
		text_26.setForeground(SWTResourceManager.getColor(0, 153, 0));
		text_26.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1));
		
		new Label(compPanels, SWT.NONE);
		new Label(compPanels, SWT.NONE);
		new Label(compPanels, SWT.NONE);
		new Label(compPanels, SWT.NONE);
		*/
		

		
		
        // Scroll composite
        sc.setContent(compFdsContent);
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

    protected void addCommonCommands() {
    	if (compSubTaskCommon != null) {
	    	btnGetExternData = new Button(compSubTaskCommon, SWT.FLAT | SWT.TOGGLE);
			GridData gd_externData = new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1);
			btnGetExternData.setLayoutData(gd_externData);
			btnGetExternData.setText("Get External Data");
			btnGetExternData.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			btnGetExternData.setAlignment(SWT.CENTER);
			
			btnCollisionRisk = new Button(compSubTaskCommon, SWT.FLAT | SWT.TOGGLE);
			GridData gd_collisionRisk = new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1);
			btnCollisionRisk.setLayoutData(gd_collisionRisk);
			btnCollisionRisk.setText("Collision Risk");
			btnCollisionRisk.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			btnCollisionRisk.setAlignment(SWT.CENTER);
			
			btnExportData = new Button(compSubTaskCommon, SWT.FLAT | SWT.TOGGLE);
			GridData gd_exportData = new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1);
			btnExportData.setLayoutData(gd_exportData);
			btnExportData.setText("Export Data");
			btnExportData.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			btnExportData.setAlignment(SWT.CENTER);
			
			btnGenerateProducts = new Button(compSubTaskCommon, SWT.FLAT | SWT.TOGGLE);
			GridData gd_generateProducts = new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1);
			btnGenerateProducts.setLayoutData(gd_generateProducts);
			btnGenerateProducts.setText("Generate Data");
			btnGenerateProducts.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			btnGenerateProducts.setAlignment(SWT.CENTER);
			
			compSubTabs.pack();
    	}
	}

	protected void addVisualizationCommands() {
		if (compSubTaskVisualization != null) {
	    	Button btn2D = new Button(compSubTaskVisualization , SWT.FLAT | SWT.TOGGLE);
			GridData gd_externData = new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1);
			gd_externData.widthHint = 100;
			btn2D.setLayoutData(gd_externData);
			btn2D.setText("2D");
			btn2D.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			btn2D.setAlignment(SWT.CENTER);
			
			compSubTaskVisualization.pack();
    	}
	}

	protected void addSpacecraftCommands() {
	    // Test
	    final FdsMainPage parentPage = (FdsMainPage) this;
	    
	    //SGP4SimplePanel centralPanel = new SGP4SimplePanel(this.compCentral, parentPage, SWT.NONE);
        //compCentral.pack();
        
		if (compSubTaskSC != null) {
            btnPropagate = new Button(compSubTaskSC, SWT.FLAT | SWT.TOGGLE);
            //gd_btnCreateWsp.widthHint = 100;
            btnPropagate.setLayoutData(new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1));
            btnPropagate.setText("Orb Propagation");
            btnPropagate.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
            btnPropagate.setAlignment(SWT.CENTER);
            btnPropagate.addSelectionListener(new SelectionAdapter() {
                private static final long serialVersionUID = 1L;

                @Override
		    	public void widgetSelected(SelectionEvent e) {
		    	}
		    });
            
            btnDetermine = new Button(compSubTaskSC, SWT.FLAT | SWT.TOGGLE);
            //gd_btnCreateWsp.widthHint = 100;
            btnDetermine.setLayoutData(new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1));
            btnDetermine.setText("Orb Determination");
            btnDetermine.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
            btnDetermine.setAlignment(SWT.CENTER);
            btnDetermine.addSelectionListener(new SelectionAdapter() {
                private static final long serialVersionUID = 1L;

                @Override
		    	public void widgetSelected(SelectionEvent e) {
		    	}
		    });
            
            btnGenTLE = new Button(compSubTaskSC, SWT.FLAT | SWT.TOGGLE);
            //gd_btnCreateWsp.widthHint = 100;
            btnGenTLE.setLayoutData(new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1));
            btnGenTLE.setText("Gen TLE");
            btnGenTLE.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
            btnGenTLE.setAlignment(SWT.CENTER);
            btnGenTLE.addSelectionListener(new SelectionAdapter() {
                private static final long serialVersionUID = 1L;

                @Override
		    	public void widgetSelected(SelectionEvent e) {
		    	}
		    });
            
            btnPropagateSGP4 = new Button(compSubTaskSC, SWT.FLAT | SWT.TOGGLE);
            //gd_btnCreateWsp.widthHint = 100;
            btnPropagateSGP4.setLayoutData(new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1));
            btnPropagateSGP4.setText("SGP4 Propagation");
            btnPropagateSGP4.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
            btnPropagateSGP4.setAlignment(SWT.CENTER);
            
            btnPropagateSGP4.addSelectionListener(new SelectionAdapter() {
                private static final long serialVersionUID = 1L;

                @Override
            	public void widgetSelected(SelectionEvent e) {
            		Button tmpBtn = (Button) e.widget;
    				
    				// Is it selected?
    				if (highlightButton(tmpBtn) == true) {
    				    SGP4SimplePanel centralPanel = new SGP4SimplePanel(compCentral, parentPage, SWT.NONE);
    					
    					compCentral.pack();
    				}
            	}
            });
            
            btnOrbitComparison = new Button(compSubTaskSC, SWT.FLAT | SWT.TOGGLE);
            //gd_btnCreateWsp.widthHint = 100;
            btnOrbitComparison.setLayoutData(new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1));
            btnOrbitComparison.setText("Orb Comparison");
            btnOrbitComparison.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
            btnOrbitComparison.setAlignment(SWT.CENTER);
            btnOrbitComparison.addSelectionListener(new SelectionAdapter() {
                private static final long serialVersionUID = 1L;

                @Override
            	public void widgetSelected(SelectionEvent e) {
            	}
            });
            
            compSubTaskSC.pack();		
        }
	}

	protected void addStationCommands() {
		
	}

	protected void addDatabaseCommands() {
		
	}

	protected void addSetupCommands() {
		
	}

	protected void addWorkspaceCommands() {
		if (compSubTaskWorkspace != null) {
	    	Button btnCreateWsp = new Button(compSubTaskWorkspace, SWT.FLAT | SWT.TOGGLE);
			GridData gd_btnCreateWsp = new GridData(SWT.FILL, SWT.TOP, false, false, 1, 1);
			//gd_btnCreateWsp.widthHint = 100;
			btnCreateWsp.setLayoutData(gd_btnCreateWsp);
			btnCreateWsp.setText("Create");
			btnCreateWsp.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			btnCreateWsp.setAlignment(SWT.CENTER);
			
			Button btnLoadWsp = new Button(compSubTaskWorkspace, SWT.FLAT | SWT.TOGGLE);
			GridData gd_btnLoadWsp = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
			//gd_btnLoadWsp.widthHint = 100;
			btnLoadWsp.setLayoutData(gd_btnLoadWsp);
			btnLoadWsp.setText("Load");
			btnLoadWsp.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			
			Button btnSaveWsp = new Button(compSubTaskWorkspace, SWT.FLAT | SWT.TOGGLE);
			GridData gd_btnSaveWsp = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
			//gd_btnSaveWsp.widthHint = 100;
			btnSaveWsp.setLayoutData(gd_btnSaveWsp);
			btnSaveWsp.setText("Save");
			btnSaveWsp.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			
			Button btnSaveAsWsp = new Button(compSubTaskWorkspace, SWT.FLAT | SWT.TOGGLE);
			GridData gd_btnSaveAsWsp = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
			//gd_btnSaveAsWsp.widthHint = 100;
			btnSaveAsWsp.setLayoutData(gd_btnSaveAsWsp);
			btnSaveAsWsp.setText("Save As");
			btnSaveAsWsp.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			
			Button btnCloseWsp = new Button(compSubTaskWorkspace, SWT.FLAT | SWT.TOGGLE);
			btnCloseWsp.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
			GridData gd_btnCloseWsp = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
			//gd_btnCloseWsp.widthHint = 100;
			btnSaveAsWsp.setLayoutData(gd_btnCloseWsp);
			btnCloseWsp.setText("Close");
			btnCloseWsp.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
			
			compSubTaskWorkspace.pack();
		}
	}
		
	protected boolean highlightButton(Button tmpBtn) {
		 
        if (tmpBtn != pressedButton) {		        	
        	// Reset the background
        	if (pressedButton != null) {
        		pressedButton.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
        		pressedButton.setSelection(false);
        	}
        	
        	if (tmpBtn.getSelection() == true) {
        		tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_GREEN));

        		pressedButton = tmpBtn;
        	} 
        }
        
        return tmpBtn.getSelection();
	}
	
	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
}
