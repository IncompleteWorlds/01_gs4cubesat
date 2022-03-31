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
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;
import org.eclipse.swt.widgets.Text;



public class McsOfflineHkTmPage extends McsBasePage  {
	private static final long serialVersionUID = 1L;

	// They have to be local otherwise WindowsBuiler does not work
	protected Composite compHeader = null; 
	protected Composite compContent = null;
	protected Composite compFooter = null;
	
	protected ScrolledComposite sc = null;
	protected Composite compMcsContent = null;
	protected ToolBar toolBar = null;
	
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
    private Text textFileName;



	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public McsOfflineHkTmPage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style);

		setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
		setBackground(SWTResourceManager.getColor(255, 255, 255));
		setLayout(new GridLayout(1, false));
		
		// Header
		compHeader = getHeaderComposite(this, "");

		// Central Content
		compContent = new Composite(this, SWT.NONE);
		compContent.setLayout(new GridLayout(1, false));
		compContent.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, true, 1, 1));
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
		
		Composite compTabs = new Composite(compMcsContent, SWT.NONE);
		GridData gd_compTabs = new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1);
		gd_compTabs.widthHint = 564;
		compTabs.setLayoutData(gd_compTabs);
		compTabs.setLayout(new GridLayout(5, false));
		
		Button btnPower = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnPower.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnPower.addSelectionListener(new SelectionAdapter() {
		    /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
		        Button tmpBtn = (Button) e.widget; 
		        if (tmpBtn.getSelection() == true) {
		            tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_GREEN));
		        } else {
		            tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		        }
		    }
		});
		btnPower.setAlignment(SWT.CENTER);
		GridData gd_btnPower = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnPower.widthHint = 100;
		btnPower.setLayoutData(gd_btnPower);
		btnPower.setText("Power");
		
		Button btnComms = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnComms.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnComms.addSelectionListener(new SelectionAdapter() {
		    /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
		        Button tmpBtn = (Button) e.widget; 
                if (tmpBtn.getSelection() == true) {
                    tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_GREEN));
                } else {
                    tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
                }
		    }
		});
		GridData gd_btnComms = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnComms.widthHint = 100;
		btnComms.setLayoutData(gd_btnComms);
		btnComms.setText("Comms");
		
		Button btnOBC = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnOBC.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnOBC.addSelectionListener(new SelectionAdapter() {
		    /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
		        Button tmpBtn = (Button) e.widget; 
                if (tmpBtn.getSelection() == true) {
                    tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_GREEN));
                } else {
                    tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
                }
		    }
		});
		GridData gd_btnOBC = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnOBC.widthHint = 100;
		btnOBC.setLayoutData(gd_btnOBC);
		btnOBC.setText("OBC");
		btnOBC.setBounds(0, 0, 75, 31);
		
		Button btnPanels = new Button(compTabs, SWT.FLAT | SWT.TOGGLE);
		btnPanels.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
		btnPanels.addSelectionListener(new SelectionAdapter() {
		    /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
		        Button tmpBtn = (Button) e.widget; 
		        if (tmpBtn.getSelection() == true) {
                    tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_GREEN));
                } else {
                    tmpBtn.setBackground(SWTResourceManager.getColor(SWT.COLOR_WHITE));
                }
		    }
		});
		GridData gd_btnPanels = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnPanels.widthHint = 100;
		btnPanels.setLayoutData(gd_btnPanels);
		btnPanels.setText("Panels");
		btnPanels.setBounds(0, 0, 100, 31);
		
		Composite composite = new Composite(compTabs, SWT.NONE);
		composite.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 1, 1));
		GridLayout gl_composite = new GridLayout(2, false);
		gl_composite.marginHeight = 0;
		gl_composite.marginWidth = 0;
		composite.setLayout(gl_composite);
		
		Label lblFileName = new Label(composite, SWT.NONE);
		lblFileName.setText("File name");
		
		textFileName = new Text(composite, SWT.BORDER);
		GridData gd_textFileName = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_textFileName.widthHint = 150;
		textFileName.setLayoutData(gd_textFileName);
		textFileName.setEditable(false);
		
		TabFolder tabFolder = new TabFolder(compMcsContent, SWT.NONE);
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
