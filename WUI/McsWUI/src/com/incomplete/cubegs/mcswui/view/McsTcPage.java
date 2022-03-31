package com.incomplete.cubegs.mcswui.view;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.custom.SashForm;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.Combo;



public class McsTcPage extends McsBasePage  {
	private static final long serialVersionUID = 1L;

	// They have to be local otherwise WindowsBuiler does not work
	protected Composite compHeader = null; 
	protected Composite compContent = null;
	protected Composite compFooter = null;
	
	protected ScrolledComposite sc = null;
	protected Composite compMcsContent = null;
	protected ToolBar toolBar = null;
	private Table tableQueue;
	private Table tableTCParameters;



	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public McsTcPage(String newViewName, Composite parent, int style) {
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
        sc.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
		
	    compMcsContent = new Composite(sc, SWT.NONE);
		compMcsContent.setLayout(new GridLayout(1, false));
		compMcsContent.setLayoutData(new GridData(SWT.LEFT, SWT.TOP, true, true, 1, 1));
		
		SashForm sashForm = new SashForm(compMcsContent, SWT.BORDER);
		sashForm.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
		
		Composite compTcDef = new Composite(sashForm, SWT.NONE);
		compTcDef.setLayout(new GridLayout(1, false));
		
		Composite compSubsystem = new Composite(compTcDef, SWT.NONE);
		compSubsystem.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1));
		compSubsystem.setLayout(new GridLayout(4, false));
		
		Label lblNewLabel = new Label(compSubsystem, SWT.NONE);
		lblNewLabel.setText("Subsystem");
		
		Combo comboSubsystem = new Combo(compSubsystem, SWT.NONE);
		comboSubsystem.setItems(new String[] {"Power", "Comms", "Thermal", "OBC", "Panels"});
		GridData gd_comboSubsystem = new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1);
		gd_comboSubsystem.widthHint = 150;
		comboSubsystem.setLayoutData(gd_comboSubsystem);
		
		Label lblTcPoint = new Label(compSubsystem, SWT.NONE);
		lblTcPoint.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		lblTcPoint.setText("TC");
		
		Combo combo = new Combo(compSubsystem, SWT.NONE);
		combo.setItems(new String[] {"TC 1", "TC 2", "TC 3", "TC 4", "TC 5"});
		GridData gd_combo = new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1);
		gd_combo.widthHint = 150;
		combo.setLayoutData(gd_combo);
		
		Label lblParameters = new Label(compSubsystem, SWT.NONE);
		lblParameters.setText("Parameters");
		new Label(compSubsystem, SWT.NONE);
		new Label(compSubsystem, SWT.NONE);
		new Label(compSubsystem, SWT.NONE);
		
		tableTCParameters = new Table(compTcDef, SWT.BORDER | SWT.FULL_SELECTION);
		GridData gd_tableTCParameters = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
		gd_tableTCParameters.widthHint = 300;
		gd_tableTCParameters.heightHint = 400;
		tableTCParameters.setLayoutData(gd_tableTCParameters);
		tableTCParameters.setHeaderVisible(true);
		tableTCParameters.setLinesVisible(true);
		
		TableColumn tblclmnName_1 = new TableColumn(tableTCParameters, SWT.NONE);
		tblclmnName_1.setWidth(100);
		tblclmnName_1.setText("Name");
		
		TableColumn tblclmnValue = new TableColumn(tableTCParameters, SWT.NONE);
		tblclmnValue.setWidth(100);
		tblclmnValue.setText("Value");
		
		Composite compBtnTc = new Composite(compTcDef, SWT.NONE);
		compBtnTc.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		compBtnTc.setLayout(new GridLayout(4, false));
		
		Button btnEnqueue = new Button(compBtnTc, SWT.NONE);
		btnEnqueue.setToolTipText("Enqueue");
		btnEnqueue.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/enqueue_32_32.png"));
		
		Button btnUploadNow = new Button(compBtnTc, SWT.NONE);
		btnUploadNow.setToolTipText("Upload now");
		btnUploadNow.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/upload_32_32.png"));
		
		Button btnAdd = new Button(compBtnTc, SWT.NONE);
		btnAdd.setToolTipText("Add");
		btnAdd.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		
		Button btnRemove_1 = new Button(compBtnTc, SWT.NONE);
		btnRemove_1.setToolTipText("Remove");
		btnRemove_1.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		
		Composite compQueue = new Composite(sashForm, SWT.NONE);
		GridLayout gl_compQueue = new GridLayout(1, false);
		compQueue.setLayout(gl_compQueue);
		
		Label lblTcQueue = new Label(compQueue, SWT.NONE);
		lblTcQueue.setText("TC Queue");
		
		tableQueue = new Table(compQueue, SWT.BORDER | SWT.FULL_SELECTION | SWT.MULTI);
		GridData gd_tableQueue = new GridData(SWT.CENTER, SWT.FILL, false, false, 1, 1);
		gd_tableQueue.widthHint = 450;
		gd_tableQueue.heightHint = 400;
		tableQueue.setLayoutData(gd_tableQueue);
		tableQueue.setHeaderVisible(true);
		tableQueue.setLinesVisible(true);
		
		TableColumn tblclmnName = new TableColumn(tableQueue, SWT.NONE);
		tblclmnName.setWidth(100);
		tblclmnName.setText("TC");
		
		TableColumn tblclmnNewColumn = new TableColumn(tableQueue, SWT.NONE);
		tblclmnNewColumn.setWidth(100);
		tblclmnNewColumn.setText("Result");
		
		Composite compBtnQueue = new Composite(compQueue, SWT.NONE);
		compBtnQueue.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		GridLayout gl_compBtnQueue = new GridLayout(7, false);
		gl_compBtnQueue.marginHeight = 0;
		gl_compBtnQueue.marginWidth = 0;
		compBtnQueue.setLayout(gl_compBtnQueue);
		
		Button btnExport = new Button(compBtnQueue, SWT.NONE);
		btnExport.setToolTipText("Export");
		btnExport.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/export_32_32.png"));
		
		Button btnImport = new Button(compBtnQueue, SWT.NONE);
		btnImport.setToolTipText("Import");
		btnImport.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/import_32_32.png"));
		
		Button btnUploadAll = new Button(compBtnQueue, SWT.NONE);
		btnUploadAll.setToolTipText("Upload all");
		btnUploadAll.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/upload_all_32_32.png"));
		
		Button btnUpload = new Button(compBtnQueue, SWT.NONE);
		btnUpload.setToolTipText("Upload");
		btnUpload.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/upload_32_32.png"));
		btnUpload.setBounds(0, 0, 99, 30);
		
		Button btnRemove = new Button(compBtnQueue, SWT.NONE);
		btnRemove.setToolTipText("Remove");
		btnRemove.setImage(SWTResourceManager.getImage(McsTcPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		new Label(compBtnQueue, SWT.NONE);
		new Label(compBtnQueue, SWT.NONE);
		sashForm.setWeights(new int[] {50, 50});
		
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
