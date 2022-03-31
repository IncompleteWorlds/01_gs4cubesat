package com.incomplete.cubegs.mcswui.view;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.custom.SashForm;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.TreeItem;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;


public class McsSC_DBPage extends McsBasePage {
    private static final long serialVersionUID = 1L;
    
    // They have to be local otherwise WindowsBuiler does not work
    protected Composite compHeader = null; 
    protected Composite compContent = null;
    protected Composite compFooter = null;
    
    protected ScrolledComposite sc = null;
    protected Composite compMcsContent = null;
    protected ToolBar toolBar = null;

	
	private Text textName;
	private Text textDescription;
	private Table table;
	private Text textLoError;
	private Text textLoWarning;
	private Text textUpWarning;
	private Text textUpError;
	private Text text;
	private Text text_1;

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public McsSC_DBPage(String newViewName, Composite parent, int style) {
        super(newViewName, parent, style);

        setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
        setBackground(SWTResourceManager.getColor(255, 255, 255));
        setLayout(new GridLayout(1, false));
        
        // Header
        compHeader = getHeaderComposite(this,"");

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
        sc.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
        
        compMcsContent = new Composite(sc, SWT.NONE);
        compMcsContent.setLayout(new GridLayout(1, false));
        compMcsContent.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, true, 1, 1));
		
		SashForm sashForm = new SashForm(compMcsContent, SWT.BORDER);
		GridData gd_sashForm = new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1);
		gd_sashForm.widthHint = 964;
		gd_sashForm.heightHint = 459;
		sashForm.setLayoutData(gd_sashForm);
		sashForm.setLocation(0, 0);
		
		Composite compLeft = new Composite(sashForm, SWT.NONE);
		compLeft.setLayout(new GridLayout(1, false));
		
		Tree tree = new Tree(compLeft, SWT.BORDER);
		GridData gd_tree = new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1);
		gd_tree.heightHint = 635;
		gd_tree.widthHint = 363;
		tree.setLayoutData(gd_tree);
		tree.setBounds(0, 0, 85, 85);
		
		TreeItem trtmSatellite = new TreeItem(tree, SWT.NONE);
		trtmSatellite.setText("Satellite 1");
		
		TreeItem trtmPowerSub = new TreeItem(trtmSatellite, SWT.NONE);
		trtmPowerSub.setText("Power Sub");
		
		TreeItem trtmPowerSubHtTm = new TreeItem(trtmPowerSub, SWT.NONE);
		trtmPowerSubHtTm.setText("HK TM");
		
		TreeItem trtmPowerSubPayTm = new TreeItem(trtmPowerSub, SWT.NONE);
		trtmPowerSubPayTm.setText("Payload TM");
		
		TreeItem trtmPowerSubTc = new TreeItem(trtmPowerSub, SWT.NONE);
		trtmPowerSubTc.setText("TC");
		
		TreeItem trtmRfSub = new TreeItem(trtmSatellite, SWT.NONE);
		trtmRfSub.setText("RF Sub");
		
		TreeItem trtmRFHkTm = new TreeItem(trtmRfSub, 0);
		trtmRFHkTm.setText("HK TM");
		
		TreeItem trtmRFPayTM = new TreeItem(trtmRfSub, 0);
		trtmRFPayTM.setText("Payload TM");
		
		TreeItem trtmRFTC = new TreeItem(trtmRfSub, 0);
		trtmRFTC.setText("TC");
		trtmRfSub.setExpanded(true);
		trtmSatellite.setExpanded(true);
		
		TreeItem trtmObc = new TreeItem(trtmSatellite, SWT.NONE);
		trtmObc.setText("OBC");
		
		TreeItem treeItem_3 = new TreeItem(trtmObc, 0);
		treeItem_3.setText("HK TM");
		
		TreeItem treeItem_4 = new TreeItem(trtmObc, 0);
		treeItem_4.setText("Payload TM");
		
		TreeItem treeItem_5 = new TreeItem(trtmObc, 0);
		treeItem_5.setText("TC");
		trtmObc.setExpanded(true);
		
		TreeItem trtmSatellite_1 = new TreeItem(tree, SWT.NONE);
		trtmSatellite_1.setText("Satellite 2");
		
		TreeItem treeItem = new TreeItem(trtmSatellite_1, 0);
		treeItem.setText("Power Sub");
		
		TreeItem treeItem_6 = new TreeItem(treeItem, 0);
		treeItem_6.setText("HK TM");
		
		TreeItem treeItem_7 = new TreeItem(treeItem, 0);
		treeItem_7.setText("Payload TM");
		
		TreeItem treeItem_8 = new TreeItem(treeItem, 0);
		treeItem_8.setText("TC");
		treeItem.setExpanded(true);
		
		TreeItem treeItem_1 = new TreeItem(trtmSatellite_1, 0);
		treeItem_1.setText("RF Sub");
		treeItem_1.setExpanded(true);
		
		TreeItem treeItem_2 = new TreeItem(trtmSatellite_1, 0);
		treeItem_2.setText("OBC");
		
		TreeItem treeItem_9 = new TreeItem(treeItem_2, 0);
		treeItem_9.setText("HK TM");
		
		TreeItem treeItem_10 = new TreeItem(treeItem_2, 0);
		treeItem_10.setText("Payload TM");
		
		TreeItem treeItem_11 = new TreeItem(treeItem_2, 0);
		treeItem_11.setText("TC");
		treeItem_2.setExpanded(true);
		trtmSatellite_1.setExpanded(true);
		
		Composite compLeftButtons = new Composite(compLeft, SWT.NONE);
		compLeftButtons.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		compLeftButtons.setLayout(new GridLayout(4, false));
		
		Button btnRefresh = new Button(compLeftButtons, SWT.NONE);
		btnRefresh.setImage(SWTResourceManager.getImage(McsSC_DBPage.class, "/com/incomplete/cubegs/resources/refresh_32_32.png"));
		btnRefresh.setToolTipText("Refresh");
		btnRefresh.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Read the list of TC and TM points from the DB
				
				// Update the tree
				
				// Show them (in the tree)
			}
		});
		
		Button btnAdd = new Button(compLeftButtons, SWT.NONE);
		btnAdd.setImage(SWTResourceManager.getImage(McsSC_DBPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAdd.setToolTipText("Add");
		btnAdd.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Add a new TC or TM
				
			}
		});
		
		Button btnRemove = new Button(compLeftButtons, SWT.NONE);
		btnRemove.setImage(SWTResourceManager.getImage(McsSC_DBPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemove.setToolTipText("Remove");
		btnRemove.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Check a Tree Item is selected
				// If an item is selected
				//    Ask for a confirmation
				//    If yes, remove TC or TM point
				//        update the Tree
				
			}
		});
		
		Button btnEdit = new Button(compLeftButtons, SWT.NONE);
		btnEdit.setImage(SWTResourceManager.getImage(McsSC_DBPage.class, "/com/incomplete/cubegs/resources/edit_32_32.png"));
		btnEdit.setToolTipText("Edit");
		btnEdit.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Edit a TC or TM Point
				
				// Check an Item is selected
				// If selected, show the data
				
			}
		});
		new Label(compLeftButtons, SWT.NONE);
		new Label(compLeftButtons, SWT.NONE);
		
		Button btnImport = new Button(compLeftButtons, SWT.NONE);
		btnImport.setImage(SWTResourceManager.getImage(McsSC_DBPage.class, "/com/incomplete/cubegs/resources/import_32_32.png"));
		btnImport.setToolTipText("Import");
		btnImport.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Select file. Open dialog
				
				// Import S/C database
				// Load from an XML, XTCE o JSON file
				
			}
		});
		
		Button btnExport = new Button(compLeftButtons, SWT.NONE);
		btnExport.setImage(SWTResourceManager.getImage(McsSC_DBPage.class, "/com/incomplete/cubegs/resources/export_32_32.png"));
		btnExport.setToolTipText("Export");
		btnExport.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Select file. Open dialog
				
				// Export S/C database
				// Save to an XML, XTCE o JSON file
				
			}
		});
		
		Composite compRight = new Composite(sashForm, SWT.NONE);
		compRight.setLayout(new GridLayout(6, false));
		
		Label lblName = new Label(compRight, SWT.NONE);
		lblName.setText("Name");
		
		textName = new Text(compRight, SWT.BORDER);
		GridData gd_textName = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_textName.widthHint = 150;
		textName.setLayoutData(gd_textName);
		new Label(compRight, SWT.NONE);
		
		Label lblDescription = new Label(compRight, SWT.NONE);
		lblDescription.setText("Description");
		
		textDescription = new Text(compRight, SWT.BORDER | SWT.MULTI);
		GridData gd_textDescription = new GridData(SWT.FILL, SWT.CENTER, true, false, 2, 1);
		gd_textDescription.heightHint = 63;
		textDescription.setLayoutData(gd_textDescription);
		
		Label lblType = new Label(compRight, SWT.NONE);
		lblType.setText("Type");
		
		Combo comboType = new Combo(compRight, SWT.NONE);
		comboType.setItems(new String[] {"None", "String", "Integer", "Boolean", "Float"});
		GridData gd_comboType = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_comboType.widthHint = 100;
		comboType.setLayoutData(gd_comboType);
		
		Label lblRadix = new Label(compRight, SWT.NONE);
		lblRadix.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblRadix.setText("Radix");
		
		Combo comboRadix = new Combo(compRight, SWT.NONE);
		comboRadix.setItems(new String[] {"None", "Decimal", "Hexadecimal"});
		GridData gd_comboRadix = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_comboRadix.widthHint = 100;
		comboRadix.setLayoutData(gd_comboRadix);
		
		Label lblUnits = new Label(compRight, SWT.NONE);
		lblUnits.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblUnits.setText("Units");
		
		Combo comboUnits = new Combo(compRight, SWT.NONE);
		comboUnits.setItems(new String[] {"None", "Meters", "Kilometers", "Volts", "Ampers", "Watts"});
		GridData gd_comboUnits = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_comboUnits.widthHint = 100;
		comboUnits.setLayoutData(gd_comboUnits);
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		
		Group grpCalibrationCoeficients = new Group(compRight, SWT.NONE);
		grpCalibrationCoeficients.setLayout(new GridLayout(4, false));
		grpCalibrationCoeficients.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 6, 1));
		grpCalibrationCoeficients.setText("Calibration Coeficients");
		
		table = new Table(grpCalibrationCoeficients, SWT.BORDER | SWT.FULL_SELECTION);
		GridData gd_table = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_table.heightHint = 125;
		table.setLayoutData(gd_table);
		table.setBounds(0, 0, 85, 45);
		table.setHeaderVisible(true);
		table.setLinesVisible(true);
		
		TableColumn tblclmnName = new TableColumn(table, SWT.NONE);
		tblclmnName.setWidth(100);
		tblclmnName.setText("Name");
		
		TableColumn tblclmnValue = new TableColumn(table, SWT.NONE);
		tblclmnValue.setWidth(100);
		tblclmnValue.setText("Value");
		new Label(grpCalibrationCoeficients, SWT.NONE);
		
		Label lblCalibType = new Label(grpCalibrationCoeficients, SWT.NONE);
		lblCalibType.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, false, false, 1, 1));
		lblCalibType.setText("Calib. Type");
		
		Combo comboCalType = new Combo(grpCalibrationCoeficients, SWT.NONE);
		comboCalType.setItems(new String[] {"None", "Constant", "Linear", "Polynomal"});
		comboCalType.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, false, 1, 1));
		
		Composite compTableButton = new Composite(grpCalibrationCoeficients, SWT.NONE);
		compTableButton.setLayout(new GridLayout(2, false));
		compTableButton.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		compTableButton.setSize(64, 64);
		
		Button btnAdd_1 = new Button(compTableButton, SWT.NONE);
		btnAdd_1.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Add a Calibration coefficient to the list
			}
		});
		btnAdd_1.setText("Add");
		
		Button btnRemove_1 = new Button(compTableButton, SWT.NONE);
		btnRemove_1.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Check if a coefficient is selected
				// If selected, remove it
				//    Refresh the list
			}
		});
		btnRemove_1.setText("Remove");
		new Label(grpCalibrationCoeficients, SWT.NONE);
		new Label(grpCalibrationCoeficients, SWT.NONE);
		new Label(grpCalibrationCoeficients, SWT.NONE);
		
		Group grpLimits = new Group(compRight, SWT.NONE);
		grpLimits.setLayout(new GridLayout(9, false));
		grpLimits.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 6, 1));
		grpLimits.setText("Limits");
		new Label(grpLimits, SWT.NONE);
		
		Label lblLower = new Label(grpLimits, SWT.NONE);
		lblLower.setText("Lower");
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		
		Label lblUpper = new Label(grpLimits, SWT.NONE);
		lblUpper.setText("Upper");
		new Label(grpLimits, SWT.NONE);
		
		Label lblError = new Label(grpLimits, SWT.NONE);
		lblError.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		lblError.setText("Error");
		new Label(grpLimits, SWT.NONE);
		
		Label lblWarning = new Label(grpLimits, SWT.NONE);
		lblWarning.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		lblWarning.setText("Warning");
		new Label(grpLimits, SWT.NONE);
		
		Label lblNominal = new Label(grpLimits, SWT.NONE);
		lblNominal.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		lblNominal.setText("Nominal");
		new Label(grpLimits, SWT.NONE);
		
		Label lblWarning_1 = new Label(grpLimits, SWT.NONE);
		lblWarning_1.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		lblWarning_1.setText("Warning");
		new Label(grpLimits, SWT.NONE);
		
		Label lblError_1 = new Label(grpLimits, SWT.NONE);
		lblError_1.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		lblError_1.setText("Error");
		
		Label label = new Label(grpLimits, SWT.NONE);
		label.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		label.setText("[");
		new Label(grpLimits, SWT.NONE);
		
		Label label_1 = new Label(grpLimits, SWT.NONE);
		label_1.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		label_1.setText("[");
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		
		Label label_2 = new Label(grpLimits, SWT.NONE);
		label_2.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		label_2.setText("]");
		new Label(grpLimits, SWT.NONE);
		
		Label label_3 = new Label(grpLimits, SWT.NONE);
		label_3.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		label_3.setText("]");
		
		textLoError = new Text(grpLimits, SWT.BORDER);
		textLoError.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		new Label(grpLimits, SWT.NONE);
		
		textLoWarning = new Text(grpLimits, SWT.BORDER);
		textLoWarning.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		
		textUpWarning = new Text(grpLimits, SWT.BORDER);
		textUpWarning.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		new Label(grpLimits, SWT.NONE);
		
		textUpError = new Text(grpLimits, SWT.BORDER);
		textUpError.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		new Label(grpLimits, SWT.NONE);
		
		Label lblColor = new Label(grpLimits, SWT.NONE);
		lblColor.setText("Color");
		
		Combo comboNominalColor = new Combo(grpLimits, SWT.NONE);
		comboNominalColor.setItems(new String[] {"Black", "Green", "Yellow", "Red"});
		comboNominalColor.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		new Label(grpLimits, SWT.NONE);
		
		Combo comboWarningColor = new Combo(grpLimits, SWT.NONE);
		comboWarningColor.setItems(new String[] {"Black", "Green", "Yellow", "Red"});
		comboWarningColor.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		new Label(grpLimits, SWT.NONE);
		
		Combo comboErrorColor = new Combo(grpLimits, SWT.NONE);
		comboErrorColor.setItems(new String[] {"Black", "Green", "Yellow", "Red"});
		comboErrorColor.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1));
		
		Label lblActionWarning = new Label(grpLimits, SWT.NONE);
		lblActionWarning.setText("Action Warning");
		new Label(grpLimits, SWT.NONE);
		
		Combo comboActWarning = new Combo(grpLimits, SWT.NONE);
		comboActWarning.setItems(new String[] {"None", "Log", "Email"});
		comboActWarning.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		new Label(grpLimits, SWT.NONE);
		
		Label lblEmail = new Label(grpLimits, SWT.NONE);
		lblEmail.setText("Email");
		
		text = new Text(grpLimits, SWT.BORDER);
		text.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 3, 1));
		new Label(grpLimits, SWT.NONE);
		
		Label lblActionError = new Label(grpLimits, SWT.NONE);
		lblActionError.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, false, false, 2, 1));
		lblActionError.setText("Action Error");
		
		Combo combo = new Combo(grpLimits, SWT.NONE);
		combo.setItems(new String[] {"None", "Log", "Email"});
		combo.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		new Label(grpLimits, SWT.NONE);
		
		Label lblEmail_1 = new Label(grpLimits, SWT.NONE);
		lblEmail_1.setText("Email");
		
		text_1 = new Text(grpLimits, SWT.BORDER);
		text_1.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 3, 1));
		new Label(grpLimits, SWT.NONE);
		
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);
		
		Composite compEditDef = new Composite(compRight, SWT.NONE);
		compEditDef.setLayout(new GridLayout(2, false));
		compEditDef.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		
		Button btnUpdate = new Button(compEditDef, SWT.NONE);
		btnUpdate.setImage(SWTResourceManager.getImage(McsSC_DBPage.class, "/com/incomplete/cubegs/resources/save_32_32.png"));
		btnUpdate.setToolTipText("Update");
		btnUpdate.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Read all the values of the panel and update the TC or TM
			}
		});
		
		Button btnClose = new Button(compEditDef, SWT.NONE);
		btnClose.setImage(SWTResourceManager.getImage(McsSC_DBPage.class, "/com/incomplete/cubegs/resources/cancel_32_32.png"));
		btnClose.setToolTipText("Close");
		btnClose.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Ask for confirmation
				// If yes, discard all the changes
				//    Clean the fields
			}
		});
		
		sashForm.setWeights(new int[] {285, 665});
		
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
}
