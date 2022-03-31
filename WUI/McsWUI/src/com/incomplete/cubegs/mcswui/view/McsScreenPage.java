package com.incomplete.cubegs.mcswui.view;

import org.eclipse.swt.widgets.Composite;

import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.custom.SashForm;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.List;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;


public class McsScreenPage extends McsBasePage {
	private static final long serialVersionUID = 1L;
	
	// They have to be local otherwise WindowsBuiler does not work
    protected Composite compHeader = null; 
    protected Composite compContent = null;
    protected Composite compFooter = null;
    
    protected ScrolledComposite sc = null;
    protected Composite compMcsContent = null;
    protected ToolBar toolBar = null;

	/**
	 * Create the composite.
	 * 
	 * @param parent
	 * @param style
	 */
	public McsScreenPage(String newViewName, Composite parent, int style) {
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
		
		Label lblWindows = new Label(compLeft, SWT.NONE);
		lblWindows.setText("Windows");

		List list_2 = new List(compLeft, SWT.BORDER);
		list_2.setItems(new String[] { "Comms Tab", "Power Tab", "RF Tab", "OBC Tab" });
		GridData gd_list_2 = new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1);
		gd_list_2.heightHint = 439;
		list_2.setLayoutData(gd_list_2);

		Composite compLeftButtons = new Composite(compLeft, SWT.NONE);
		compLeftButtons.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		compLeftButtons.setLayout(new GridLayout(3, false));

		Button btnEdit = new Button(compLeftButtons, SWT.NONE);
		btnEdit.setImage(SWTResourceManager.getImage(McsScreenPage.class, "/com/incomplete/cubegs/resources/edit_32_32.png"));
		btnEdit.setToolTipText("Edit");
		btnEdit.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Read definition of selected Window from database
				
				// Show data in the central panel
			}
		});

		Button btnAdd = new Button(compLeftButtons, SWT.NONE);
		btnAdd.setImage(SWTResourceManager.getImage(McsScreenPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAdd.setToolTipText("Add");
		btnAdd.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});

		Button btnRemove = new Button(compLeftButtons, SWT.NONE);
		btnRemove.setImage(SWTResourceManager.getImage(McsScreenPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemove.setToolTipText("Remove");
		btnRemove.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});

		Composite compRight = new Composite(sashForm, SWT.NONE);
		compRight.setLayout(new GridLayout(1, false));

		Composite compEditDef = new Composite(compRight, SWT.NONE);
		compEditDef.setLayout(new GridLayout(2, false));
		compEditDef.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));

		Button btnUpdate = new Button(compEditDef, SWT.NONE);
		btnUpdate.setImage(SWTResourceManager.getImage(McsScreenPage.class, "/com/incomplete/cubegs/resources/save_32_32.png"));
		btnUpdate.setToolTipText("Update");
		btnUpdate.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});

		Button btnClose = new Button(compEditDef, SWT.NONE);
		btnClose.setImage(SWTResourceManager.getImage(McsScreenPage.class, "/com/incomplete/cubegs/resources/cancel_32_32.png"));
		btnClose.setToolTipText("Close");
		btnClose.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
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
