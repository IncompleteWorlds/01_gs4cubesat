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
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Combo;



public class McsOfflinePlotPage extends McsBasePage  {
	private static final long serialVersionUID = 1L;

	// They have to be local otherwise WindowsBuiler does not work
	protected Composite compHeader = null; 
	protected Composite compContent = null;
	protected Composite compFooter = null;

	protected ToolBar toolBar = null;

    private Composite compPlot1 = null;
    private Composite compPlot2 = null;
    private Composite compPlot3 = null;
    private Composite compPlot4 = null;
    
    protected ScrolledComposite sc = null;
    protected Composite compMcsContent;
    private Text text;

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public McsOfflinePlotPage(String newViewName, Composite parent, int style) {
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
		
		compPlot1 = createPlot(compMcsContent);
		
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
    
    /**
     * Create a Plot
     * @param parentComposite
     * @return
     */
    protected Composite createPlot(Composite parentComposite) {
        
        Composite output = new Composite (parentComposite, SWT.BORDER);
        GridData gd_output = new GridData(SWT.LEFT, SWT.TOP, true, true, 1, 1);
        gd_output.widthHint = 642;
        output.setLayoutData(gd_output);
        output.setLayout(new GridLayout(4, false));       
        
        Label lblTitle = new Label(output, SWT.NONE);
        lblTitle.setText("Plot ");
        new Label(output, SWT.NONE);
        new Label(output, SWT.NONE);
        
        Composite composite_1 = new Composite(output, SWT.NONE);
        composite_1.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
        GridLayout gl_composite_1 = new GridLayout(2, false);
        gl_composite_1.marginWidth = 0;
        gl_composite_1.marginHeight = 0;
        composite_1.setLayout(gl_composite_1);
        
        Label label = new Label(composite_1, SWT.NONE);
        label.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
        label.setText("File name");
        
        text = new Text(composite_1, SWT.BORDER);
        text.setEditable(false);
        GridData gd_text = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_text.widthHint = 150;
        text.setLayoutData(gd_text);
        
        Label lblSubsystem = new Label(output, SWT.NONE);
        lblSubsystem.setBounds(0, 0, 76, 18);
        lblSubsystem.setText("Subsystem");
        
        Combo comboSubsystem = new Combo(output, SWT.NONE);
        GridData gd_comboSubsystem = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_comboSubsystem.widthHint = 150;
        comboSubsystem.setLayoutData(gd_comboSubsystem);
        comboSubsystem.setItems(new String[] {"Power", "Comms", "OBC", "Panels", "Thermal"});
        comboSubsystem.setSize(323, 30);
        
        Label lblHkTmPoint = new Label(output, SWT.NONE);
        lblHkTmPoint.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
        lblHkTmPoint.setText("HK TM Point");
        
        Combo comboHkTm = new Combo(output, SWT.NONE);
        comboHkTm.setItems(new String[] {"Point 1", "Point 2", "Point 3", "Point 4", "Point 5", "Point 6"});
        GridData gd_comboHkTm = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
        gd_comboHkTm.widthHint = 150;
        comboHkTm.setLayoutData(gd_comboHkTm);
        
        Label lblNewLabel = new Label(output, SWT.NONE);
        lblNewLabel.setImage(SWTResourceManager.getImage(McsOfflinePlotPage.class, "/com/incomplete/cubegs/resources/hk_tm_plot.png"));
        lblNewLabel.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 4, 1));
        new Label(output, SWT.NONE);
        new Label(output, SWT.NONE);
        new Label(output, SWT.NONE);
        
        Composite composite = new Composite(output, SWT.NONE);
        composite.setLayoutData(new GridData(SWT.RIGHT, SWT.FILL, false, false, 1, 1));
        composite.setLayout(new GridLayout(2, false));
        
        Button btnAdd = new Button(composite, SWT.NONE);
        btnAdd.setToolTipText("Add");
        btnAdd.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
                compPlot2 = createPlot(parentComposite);
                
                parentComposite.pack();
            }
        });
        btnAdd.setImage(SWTResourceManager.getImage(McsOfflinePlotPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
        
        Button btnRemove = new Button(composite, SWT.NONE);
        btnRemove.setToolTipText("Remove");
        btnRemove.setImage(SWTResourceManager.getImage(McsOfflinePlotPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
        btnRemove.addSelectionListener(new SelectionAdapter() {
            /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
            public void widgetSelected(SelectionEvent e) {
                compPlot2 = null;
                
                parentComposite.pack();
            }
        });
        
        return output;
    }
}
