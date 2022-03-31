package com.incomplete.cubegs.mcswui.view;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.custom.SashForm;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.TreeItem;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.List;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

public class McsFramesPage extends McsBasePage {
    private static final long serialVersionUID = 1L;
    
    // They have to be local otherwise WindowsBuiler does not work
    protected Composite compHeader = null; 
    protected Composite compContent = null;
    protected Composite compFooter = null;
    
    protected ScrolledComposite sc = null;
    protected Composite compMcsContent = null;
    protected ToolBar toolBar = null;
    
	
	private Text textName;
	private Text text;
	private Text text_1;
	private Table table;
	private Text text_2;

	/**
	 * Create the composite.
	 * 
	 * @param parent
	 * @param style
	 */
	public McsFramesPage(String newViewName, Composite parent, int style) {
        super(newViewName, parent, style);
        
        setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
        setBackground(SWTResourceManager.getColor(255, 255, 255));
        setLayout(new GridLayout(1, false));
        
        // Header
        compHeader = getHeaderComposite(this, "");

        // Central Content
        compContent = new Composite(this, SWT.NONE);
        compContent.setLayout(new GridLayout(1, false));
        GridData gd_compContent = new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1);
        gd_compContent.heightHint = 711;
        compContent.setLayoutData(gd_compContent);
        compContent.setBackground(SWTResourceManager.getColor(255, 255, 255));      
        
        // Create the MCS Toolbar
        toolBar = getMcsToolBar(compContent);
        
        Label viewName = new Label(compContent, SWT.NONE);
        viewName.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1));
        viewName.setText(newViewName);

        // Add Scroll
        sc = new ScrolledComposite(compContent, SWT.H_SCROLL | SWT.V_SCROLL);       
        GridData gd_sc = new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1);
        gd_sc.heightHint = 698;
        sc.setLayoutData(gd_sc);
        
        compMcsContent = new Composite(sc, SWT.NONE);
        compMcsContent.setLayout(new GridLayout(1, false));
        compMcsContent.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, true, 1, 1));

        // Main content
		SashForm sashForm = new SashForm(compMcsContent, SWT.BORDER);
		GridData gd_sashForm = new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1);
		gd_sashForm.widthHint = 964;
		gd_sashForm.heightHint = 459;
		sashForm.setLayoutData(gd_sashForm);
		sashForm.setLocation(0, 0);

		Composite compLeft = new Composite(sashForm, SWT.NONE);
		compLeft.setLayout(new GridLayout(1, false));
		
		Label lblFrames = new Label(compLeft, SWT.NONE);
		lblFrames.setText("Frames");

		Tree tree = new Tree(compLeft, SWT.BORDER);
		tree.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Get the selected item
				
				// Read the item data from the database
				
				// Show the data in the central panel
			}
		});
		GridData gd_tree = new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1);
		gd_tree.heightHint = 540;
		tree.setLayoutData(gd_tree);
		tree.setBounds(0, 0, 85, 85);

		TreeItem trtmSatellite = new TreeItem(tree, SWT.NONE);
		trtmSatellite.setText("Satellite 1");

		TreeItem trtmHkTm = new TreeItem(trtmSatellite, SWT.NONE);
		trtmHkTm.setText("HK TM");

		TreeItem trtmFrame = new TreeItem(trtmHkTm, SWT.NONE);
		trtmFrame.setText("Frame 1");

		TreeItem trtmFrame_1 = new TreeItem(trtmHkTm, SWT.NONE);
		trtmFrame_1.setText("Frame 2");
		trtmHkTm.setExpanded(true);
		trtmSatellite.setExpanded(true);

		TreeItem trtmPayloadTm = new TreeItem(trtmSatellite, SWT.NONE);
		trtmPayloadTm.setText("Payload TM");

		TreeItem trtmPFrame = new TreeItem(trtmPayloadTm, SWT.NONE);
		trtmPFrame.setText("P Frame 1");
		trtmPayloadTm.setExpanded(true);

		TreeItem trtmTc = new TreeItem(trtmSatellite, SWT.NONE);
		trtmTc.setText("TC");

		TreeItem trtmTc_1 = new TreeItem(trtmTc, SWT.NONE);
		trtmTc_1.setText("TC 1");
		trtmTc_1.setExpanded(true);

		TreeItem trtmTc_2 = new TreeItem(trtmTc, SWT.NONE);
		trtmTc_2.setText("TC 2");
		trtmTc.setExpanded(true);

		TreeItem trtmSatellite_1 = new TreeItem(tree, SWT.NONE);
		trtmSatellite_1.setText("Satellite 2");

		TreeItem treeItem = new TreeItem(trtmSatellite_1, 0);
		treeItem.setText("HK TM");

		TreeItem treeItem_1 = new TreeItem(trtmSatellite_1, 0);
		treeItem_1.setText("Payload TM");
		treeItem_1.setExpanded(true);

		TreeItem treeItem_2 = new TreeItem(trtmSatellite_1, 0);
		treeItem_2.setText("TC");

		TreeItem trtmTc_3 = new TreeItem(treeItem_2, SWT.NONE);
		trtmTc_3.setText("TC 3");
		treeItem_2.setExpanded(true);
		trtmSatellite_1.setExpanded(true);

		Composite compLeftButtons = new Composite(compLeft, SWT.NONE);
		compLeftButtons.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		compLeftButtons.setLayout(new GridLayout(2, false));

		Button btnAdd = new Button(compLeftButtons, SWT.NONE);
		btnAdd.setImage(SWTResourceManager.getImage(McsFramesPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAdd.setToolTipText("Add");
		btnAdd.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Add  a new frame
				// Ask for a name. Open small dialog
				// Store in the database
				// Add to the tree
				// Refresh the tree
			}
		});

		Button btnRemove = new Button(compLeftButtons, SWT.NONE);
		btnRemove.setImage(SWTResourceManager.getImage(McsFramesPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemove.setToolTipText("Remove");
		btnRemove.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Remove selected frame
				// If a frame is selected
				//   Ask for a confirmation
				//   If yes, remove the selected frame from the DB
			}
		});

		Composite compRight = new Composite(sashForm, SWT.NONE);
		compRight.setLayout(new GridLayout(2, false));
		new Label(compRight, SWT.NONE);
		new Label(compRight, SWT.NONE);

		Label lblName = new Label(compRight, SWT.NONE);
		lblName.setText("Name");

		textName = new Text(compRight, SWT.BORDER);
		GridData gd_textName = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_textName.widthHint = 150;
		textName.setLayoutData(gd_textName);

		Label lblDescription = new Label(compRight, SWT.NONE);
		lblDescription.setText("Description");

		text = new Text(compRight, SWT.BORDER | SWT.MULTI);
		GridData gd_text = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_text.widthHint = 365;
		gd_text.heightHint = 55;
		text.setLayoutData(gd_text);

		Group grpEndiniaty = new Group(compRight, SWT.NONE);
		grpEndiniaty.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 2, 1));
		grpEndiniaty.setLayout(new GridLayout(4, false));
		grpEndiniaty.setText("Endianity");

		Label lblBits = new Label(grpEndiniaty, SWT.NONE);
		lblBits.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblBits.setText("Bits");

		Combo combo = new Combo(grpEndiniaty, SWT.NONE);
		combo.setItems(new String[] { "LSB First", "MSB First" });
		GridData gd_combo = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_combo.widthHint = 100;
		combo.setLayoutData(gd_combo);

		Label lblBytes = new Label(grpEndiniaty, SWT.NONE);
		lblBytes.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblBytes.setText("Bytes");

		Combo combo_1 = new Combo(grpEndiniaty, SWT.NONE);
		combo_1.setItems(new String[] { "Little Endian", "Big Endian" });
		GridData gd_combo_1 = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_combo_1.widthHint = 100;
		combo_1.setLayoutData(gd_combo_1);

		Composite composite_1 = new Composite(compRight, SWT.NONE);
		composite_1.setLayoutData(new GridData(SWT.CENTER, SWT.FILL, true, false, 2, 1));
		composite_1.setLayout(new GridLayout(4, false));

		Label lblSubsystem = new Label(composite_1, SWT.NONE);
		lblSubsystem.setText("Subsystem");

		Label lblPoints = new Label(composite_1, SWT.NONE);
		lblPoints.setText("Points");
		new Label(composite_1, SWT.NONE);
		new Label(composite_1, SWT.NONE);

		List list = new List(composite_1, SWT.BORDER);
		GridData gd_list = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_list.widthHint = 125;
		gd_list.heightHint = 269;
		list.setLayoutData(gd_list);

		List list_1 = new List(composite_1, SWT.BORDER);
		GridData gd_list_1 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_list_1.widthHint = 125;
		gd_list_1.heightHint = 262;
		list_1.setLayoutData(gd_list_1);

		Composite composite = new Composite(composite_1, SWT.NONE);
		composite.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		composite.setLayout(new GridLayout(1, false));

		Button button_1 = new Button(composite, SWT.NONE);
		button_1.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Copy selected TM Point to the frame
				
				// Update table below.
				// Add to table / label
				// Refresh table
				
				// Update Current Frame label
			}
		});
		button_1.setText(">");

		Button button = new Button(composite, SWT.NONE);
		button.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Remove selected TM Point to the table
				
				// Update table below.
				// Remove from table / label
				// Refresh table
				
				// Update Current Frame label
			}
		});
		button.setText("<");

		table = new Table(composite_1, SWT.BORDER | SWT.FULL_SELECTION);
		table.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 1, 1));
		table.setHeaderVisible(true);
		table.setLinesVisible(true);

		TableColumn tblclmnName = new TableColumn(table, SWT.NONE);
		tblclmnName.setWidth(100);
		tblclmnName.setText("Name");

		TableColumn tblclmnType = new TableColumn(table, SWT.NONE);
		tblclmnType.setWidth(100);
		tblclmnType.setText("Type");

		TableColumn tblclmnLength = new TableColumn(table, SWT.NONE);
		tblclmnLength.setWidth(100);
		tblclmnLength.setText("Length");

		Composite composite_2 = new Composite(compRight, SWT.NONE);
		composite_2.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 2, 1));
		composite_2.setLayout(new GridLayout(5, false));

		Label lblCurrentFrameLength = new Label(composite_2, SWT.NONE);
		lblCurrentFrameLength.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblCurrentFrameLength.setText("Current Frame: Length");

		text_1 = new Text(composite_2, SWT.BORDER);
		text_1.setEditable(false);

		Label lblBytesBits = new Label(composite_2, SWT.NONE);
		lblBytesBits.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblBytesBits.setText("bytes");

		text_2 = new Text(composite_2, SWT.BORDER);
		text_2.setEditable(false);

		Label lblBits_1 = new Label(composite_2, SWT.NONE);
		lblBits_1.setText("bits");
		
		ScrolledComposite scrolledComposite = new ScrolledComposite(compRight, SWT.BORDER | SWT.H_SCROLL | SWT.V_SCROLL);
		scrolledComposite.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 2, 1));
		scrolledComposite.setExpandHorizontal(true);
		scrolledComposite.setExpandVertical(true);
		
		Composite composite_3 = new Composite(scrolledComposite, SWT.BORDER);
		composite_3.setLayout(new RowLayout(SWT.HORIZONTAL));
		
		Label lblPoint = new Label(composite_3, SWT.BORDER);
		lblPoint.setText("Point1 (1 bit)");
		
		Label lblPoint_1 = new Label(composite_3, SWT.BORDER);
		lblPoint_1.setText("Point 2 (3 bits)");
		scrolledComposite.setContent(composite_3);
		scrolledComposite.setMinSize(composite_3.computeSize(SWT.DEFAULT, SWT.DEFAULT));
		new Label(compRight, SWT.NONE);

		Composite compEditDef = new Composite(compRight, SWT.NONE);
		compEditDef.setLayout(new GridLayout(2, false));
		compEditDef.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));

		Button btnUpdate = new Button(compEditDef, SWT.NONE);
		btnUpdate.setImage(SWTResourceManager.getImage(McsFramesPage.class, "/com/incomplete/cubegs/resources/save_32_32.png"));
		btnUpdate.setToolTipText("Update");
		btnUpdate.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Read all the values from the panel
				
				// Get selected frame
				
				// Update the definition in the database
			}
		});

		Button btnClose = new Button(compEditDef, SWT.NONE);
		btnClose.setImage(SWTResourceManager.getImage(McsFramesPage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		btnClose.setToolTipText("Close");
		btnClose.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Ask for confirmation (discard changes)
				// If yes, clean all the panel fields
			}
		});

		sashForm.setWeights(new int[] { 226, 896 });
		
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
