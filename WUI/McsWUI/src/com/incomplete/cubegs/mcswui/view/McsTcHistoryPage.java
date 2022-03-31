package com.incomplete.cubegs.mcswui.view;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.ToolBar;
import org.eclipse.wb.swt.SWTResourceManager;

public class McsTcHistoryPage extends McsBasePage {
    private static final long serialVersionUID = 1L;
    
    // They have to be local otherwise WindowsBuiler does not work
    protected Composite compHeader = null; 
    protected Composite compContent = null;
    protected Composite compFooter = null;
    
    protected ScrolledComposite sc = null;
    protected Composite compMcsContent = null;
    protected ToolBar toolBar = null;
    
    
	private Table table;

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public McsTcHistoryPage(String newViewName, Composite parent, int style) {
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
		
		Label lblListOfSent = new Label(compMcsContent, SWT.NONE);
		lblListOfSent.setText("List of sent TCs");
		
		table = new Table(compMcsContent, SWT.BORDER | SWT.FULL_SELECTION);
		GridData gd_table = new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1);
		gd_table.heightHint = 261;
		gd_table.widthHint = 626;
		table.setLayoutData(gd_table);
		table.setHeaderVisible(true);
		table.setLinesVisible(true);
		
		TableColumn tblclmnDate = new TableColumn(table, SWT.NONE);
		tblclmnDate.setWidth(100);
		tblclmnDate.setText("Date");
		
		TableColumn tblclmnTime = new TableColumn(table, SWT.NONE);
		tblclmnTime.setWidth(100);
		tblclmnTime.setText("Time");
		
		TableColumn tblclmnTc = new TableColumn(table, SWT.NONE);
		tblclmnTc.setWidth(100);
		tblclmnTc.setText("TC");
		
		TableColumn tblclmnParameters = new TableColumn(table, SWT.NONE);
		tblclmnParameters.setWidth(297);
		tblclmnParameters.setText("Parameters");
		
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
