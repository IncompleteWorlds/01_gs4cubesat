package com.incomplete.cubegs.mcswui.view;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Label;



public class McsFilesManagerPage extends McsBasePage  {
	private static final long serialVersionUID = 1L;

	// They have to be local otherwise WindowsBuiler does not work
	protected Composite compHeader = null; 
	protected Composite compContent = null;
	protected Composite compFooter = null;

	protected ToolBar toolBar = null;

    
    protected ScrolledComposite sc = null;
    protected Composite compMcsContent;

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public McsFilesManagerPage(String newViewName, Composite parent, int style) {
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
		
		// Central component
		Button btnAdd = new Button(compMcsContent, SWT.NONE);
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
        btnAdd.setImage(SWTResourceManager.getImage(McsFilesManagerPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
        
        Button btnRemove = new Button(compMcsContent, SWT.NONE);
        btnRemove.setToolTipText("Remove");
        btnRemove.setImage(SWTResourceManager.getImage(McsFilesManagerPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
        btnRemove.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
               
            }
        });
		
		
		
		
        // Scroll composite
        sc.setContent(compMcsContent);
        sc.setExpandHorizontal(true);
        sc.setExpandVertical(true);

        // Resize the scroll
        sc.addListener( SWT.Resize , event -> { 
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
