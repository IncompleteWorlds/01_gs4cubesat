package com.incomplete.cubegs.toolswui.view;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.wb.swt.SWTResourceManager;

import com.incomplete.cubegs.common.BaseClassPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.SingletonViews;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.layout.RowLayout;


public class ToolsConfigurePage extends BaseClassPage {
	private static final long serialVersionUID = 1L;
	
	// They have to be local otherwise WindowsBuiler does not work
	private Composite compHeader = null; 
	private ScrolledComposite scCompContent;
	private Composite compFooter = null;

	private Table tblGroundStations;
	private Text textName;
	private Text textDescription;
	private Text textValue;
	
	
	public ToolsConfigurePage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style, false);
		
		setFont(SWTResourceManager.getFont("Lucida Console", 13, SWT.NORMAL));
		setBackground(SWTResourceManager.getColor(255, 255, 255));
		GridLayout gridLayout = new GridLayout(1, false);
		gridLayout.marginWidth = 3;
		gridLayout.marginHeight = 3;
		gridLayout.verticalSpacing = 3;
		gridLayout.horizontalSpacing = 3;
		setLayout(gridLayout);
		
		// Header
		compHeader = getHeaderComposite(this, "Configure Parameters");
		
		// Central content
		scCompContent = new ScrolledComposite(this, SWT.H_SCROLL | SWT.V_SCROLL);
		scCompContent.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, true, 1, 1));
		
	    Composite compContent = new Composite(scCompContent, SWT.NONE);
	    
	    GridLayout gl_compContent = new GridLayout(1, false);
		gl_compContent.verticalSpacing = 3;
		gl_compContent.horizontalSpacing = 3;
		gl_compContent.marginHeight = 3;
		gl_compContent.marginWidth = 3;
		compContent.setLayout(gl_compContent);
		
		Label lblConfigurationParameters = new Label(compContent, SWT.NONE);
		lblConfigurationParameters.setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
		lblConfigurationParameters.setText("Configuration Parameters");
		
		tblGroundStations = new Table(compContent, SWT.BORDER | SWT.FULL_SELECTION);
		tblGroundStations.setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
		tblGroundStations.setBackground(SWTResourceManager.getColor(255, 255, 204));
		GridData gd_tblGroundStations = new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1);
		gd_tblGroundStations.heightHint = 300;
		tblGroundStations.setLayoutData(gd_tblGroundStations);
		tblGroundStations.setHeaderVisible(true);
		tblGroundStations.setLinesVisible(true);
		
		TableColumn tblclmnIdentifier = new TableColumn(tblGroundStations, SWT.NONE);
		tblclmnIdentifier.setWidth(100);
		tblclmnIdentifier.setText("Identifier");
		
		TableColumn tblclmnName = new TableColumn(tblGroundStations, SWT.NONE);
		tblclmnName.setWidth(100);
		tblclmnName.setText("Name");
		
		TableColumn tblclmnDescription = new TableColumn(tblGroundStations, SWT.NONE);
		tblclmnDescription.setWidth(150);
		tblclmnDescription.setText("Description");
		
		TableColumn tblclmnValue = new TableColumn(tblGroundStations, SWT.NONE);
		tblclmnValue.setWidth(100);
		tblclmnValue.setText("Value");
		
		TableColumn tblclmnGroup = new TableColumn(tblGroundStations, SWT.NONE);
		tblclmnGroup.setWidth(100);
		tblclmnGroup.setText("Group");
		
		TableColumn tblclmnType = new TableColumn(tblGroundStations, SWT.NONE);
		tblclmnType.setWidth(100);
		tblclmnType.setText("Type");
		
		Composite compButtons = new Composite(compContent, SWT.NONE);
		//compButtons.setBackground(SWTResourceManager.getColor(SWT.COLOR_TITLE_BACKGROUND));
		compButtons.setLayout(new GridLayout(1, false));
		compButtons.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 1, 1));
		
		Composite compIntButtons = new Composite(compButtons, SWT.NONE);
		//compIntButtons.setBackground(SWTResourceManager.getColor(SWT.COLOR_TITLE_BACKGROUND));
		compIntButtons.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, true, false, 1, 1));
		GridLayout gl_compIntButtons = new GridLayout(4, false);
		gl_compIntButtons.verticalSpacing = 3;
		gl_compIntButtons.horizontalSpacing = 3;
		gl_compIntButtons.marginHeight = 0;
		gl_compIntButtons.marginWidth = 0;
		compIntButtons.setLayout(gl_compIntButtons);
		
		Button btnRemove = new Button(compIntButtons, SWT.NONE);
		btnRemove.setImage(SWTResourceManager.getImage(ToolsConfigurePage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemove.setToolTipText("Remove");
		GridData gd_btnRemove = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnRemove.widthHint = 80;
		btnRemove.setLayoutData(gd_btnRemove);
		btnRemove.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});
		
		Button btnEdit = new Button(compIntButtons, SWT.NONE);
		btnEdit.setImage(SWTResourceManager.getImage(ToolsConfigurePage.class, "/com/incomplete/cubegs/resources/edit_32_32.png"));
		btnEdit.setToolTipText("Edit");
		GridData gd_btnEdit = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnEdit.widthHint = 80;
		btnEdit.setLayoutData(gd_btnEdit);
		btnEdit.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Activate GS add page
				SingletonViews.getInstance().changeView(Constants.GS_ADD_VIEW_NAME);
			}
		});
		
		Button btnAdd = new Button(compIntButtons, SWT.NONE);
		btnAdd.setImage(SWTResourceManager.getImage(ToolsConfigurePage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAdd.setToolTipText("Add");
		GridData gd_btnAdd = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnAdd.widthHint = 80;
		btnAdd.setLayoutData(gd_btnAdd);
		btnAdd.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				// Activate GS add page
				SingletonViews.getInstance().changeView(Constants.GS_ADD_VIEW_NAME);
			}
		});
		
		Button btnRefresh = new Button(compIntButtons, SWT.NONE);
		btnRefresh.setImage(SWTResourceManager.getImage(ToolsConfigurePage.class, "/com/incomplete/cubegs/resources/refresh_32_32.png"));
		btnRefresh.setToolTipText("Refresh");
		GridData gd_btnRefresh = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnRefresh.widthHint = 80;
		btnRefresh.setLayoutData(gd_btnRefresh);
		btnRefresh.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});
		new Label(compContent, SWT.NONE);
		
		Group grpParameter = new Group(compContent, SWT.BORDER | SWT.SHADOW_IN);
		grpParameter.setVisible(false);
		grpParameter.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		grpParameter.setEnabled(false);
		grpParameter.setText("Parameter");
		grpParameter.setLayout(new GridLayout(4, false));
		
		Label lblName = new Label(grpParameter, SWT.NONE);
		lblName.setText("Name");
		
		textName = new Text(grpParameter, SWT.BORDER);
		GridData gd_textName = new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1);
		gd_textName.widthHint = 100;
		textName.setLayoutData(gd_textName);
		
		Label lblValue = new Label(grpParameter, SWT.NONE);
		lblValue.setText("Value");
		
		textValue = new Text(grpParameter, SWT.BORDER);
		textValue.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		
		Label lblDescription = new Label(grpParameter, SWT.NONE);
		lblDescription.setText("Description");
		
		textDescription = new Text(grpParameter, SWT.BORDER);
		textDescription.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		new Label(grpParameter, SWT.NONE);
		new Label(grpParameter, SWT.NONE);
		
		Label lblGroup = new Label(grpParameter, SWT.NONE);
		lblGroup.setText("Group");
		
		Combo comboGroup = new Combo(grpParameter, SWT.NONE);
		GridData gd_comboGroup = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_comboGroup.widthHint = 150;
		comboGroup.setLayoutData(gd_comboGroup);
		
		Label lblType = new Label(grpParameter, SWT.NONE);
		lblType.setText("Type");
		
		Combo comboType = new Combo(grpParameter, SWT.NONE);
		GridData gd_comboType = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
		gd_comboType.widthHint = 150;
		comboType.setLayoutData(gd_comboType);
		new Label(grpParameter, SWT.NONE);
		new Label(grpParameter, SWT.NONE);
		new Label(grpParameter, SWT.NONE);
		
		Composite composite = new Composite(grpParameter, SWT.NONE);
		composite.setLayout(new RowLayout(SWT.HORIZONTAL));
		composite.setLayoutData(new GridData(SWT.RIGHT, SWT.FILL, false, false, 1, 1));
		
		Button btnUpdate = new Button(composite, SWT.NONE);
		btnUpdate.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});
		btnUpdate.setImage(SWTResourceManager.getImage(ToolsConfigurePage.class, "/com/incomplete/cubegs/resources/save_32_32.png"));
		btnUpdate.setToolTipText("Update");
		
		Button btnClose = new Button(composite, SWT.NONE);
		btnClose.setImage(SWTResourceManager.getImage(ToolsConfigurePage.class, "/com/incomplete/cubegs/resources/cancel1_32_32.png"));
		btnClose.setToolTipText("btnClose");
		btnClose.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});

		// Footer
		compFooter = getFooterComposite(this);

		// Scroll
		scCompContent.setContent(compContent);

		scCompContent.setMinSize( compContent.computeSize(SWT.DEFAULT,SWT.DEFAULT) );

		scCompContent.setExpandHorizontal(true);
		scCompContent.setExpandVertical(true);
	}

	@Override
    public void backButton() {
		// Back to GS main page
		SingletonViews.getInstance().changeView( Constants.TOOLS_MAIN_VIEW_NAME);
    }

	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
}
