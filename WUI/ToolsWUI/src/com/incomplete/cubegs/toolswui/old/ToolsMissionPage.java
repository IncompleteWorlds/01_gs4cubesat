package com.incomplete.cubegs.toolswui.old;

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


public class ToolsMissionPage extends BaseClassPage {
	private static final long serialVersionUID = 1L;

	private static final int BUFFER_SIZE = 4096;     // 4KB
	
	// They have to be local otherwise WindowsBuiler does not work
	private Composite compHeader = null; 
	private ScrolledComposite scCompContent;
	private Composite compFooter = null;
	private Table table_1;
	
	
	public ToolsMissionPage(String newViewName, Composite parent, int style) {
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
		compHeader = getHeaderComposite(this, "Tools");
		
		// Central content
		scCompContent = new ScrolledComposite(this, SWT.H_SCROLL | SWT.V_SCROLL);
		scCompContent.setLayoutData(new GridData(SWT.FILL, SWT.TOP, true, true, 1, 1));
		
		
		Composite composite_11 = new Composite(scCompContent, SWT.NONE);
		composite_11.setLayout(new GridLayout(1, false));
		
		Label lblMissions = new Label(composite_11, SWT.NONE);
		lblMissions.setFont(SWTResourceManager.getFont("Sans", 12, SWT.NORMAL));
		lblMissions.setText("List of Missions");
		new Label(composite_11, SWT.NONE);
		
		table_1 = new Table(composite_11, SWT.BORDER | SWT.FULL_SELECTION);
		GridData gd_table_1 = new GridData(SWT.CENTER, SWT.FILL, true, true, 1, 1);
		gd_table_1.heightHint = 200;
		table_1.setLayoutData(gd_table_1);
		table_1.setLinesVisible(true);
		table_1.setHeaderVisible(true);
		
		TableColumn tableColumn_6 = new TableColumn(table_1, SWT.NONE);
		tableColumn_6.setWidth(100);
		tableColumn_6.setText("Identifier");
		
		TableColumn tableColumn_7 = new TableColumn(table_1, SWT.NONE);
		tableColumn_7.setWidth(100);
		tableColumn_7.setText("Name");
		
		TableColumn tableColumn_8 = new TableColumn(table_1, SWT.NONE);
		tableColumn_8.setWidth(250);
		tableColumn_8.setText("Description");
		
		TableColumn tableColumn_9 = new TableColumn(table_1, SWT.NONE);
		tableColumn_9.setWidth(150);
		tableColumn_9.setText("Country");
		
		TableColumn tableColumn_10 = new TableColumn(table_1, SWT.NONE);
		tableColumn_10.setWidth(150);
		tableColumn_10.setText("Owner");
		
		TableColumn tableColumn_11 = new TableColumn(table_1, SWT.NONE);
		tableColumn_11.setWidth(100);
		tableColumn_11.setText("Creation Date");
				
		Composite composite_13 = new Composite(composite_11, SWT.NONE);
		composite_13.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, true, false, 1, 1));
		GridLayout gl_composite_13 = new GridLayout(4, false);
		gl_composite_13.verticalSpacing = 3;
		gl_composite_13.marginWidth = 0;
		gl_composite_13.marginHeight = 0;
		gl_composite_13.horizontalSpacing = 3;
		composite_13.setLayout(gl_composite_13);
		
		Button btnRemove = new Button(composite_13, SWT.NONE);
		btnRemove.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				doRemove();
			}
		});
		btnRemove.setImage(SWTResourceManager.getImage(ToolsMissionPage.class, "/com/incomplete/cubegs/resources/minus_32_32.png"));
		btnRemove.setToolTipText("Remove");
		GridData gd_btnRemove = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnRemove.widthHint = 80;
		btnRemove.setLayoutData(gd_btnRemove);
		
		Button btnEdit = new Button(composite_13, SWT.NONE);
		btnEdit.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				doEdit();
			}
		});
		btnEdit.setImage(SWTResourceManager.getImage(ToolsMissionPage.class, "/com/incomplete/cubegs/resources/edit_32_32.png"));
		btnEdit.setToolTipText("Edit");
		GridData gd_btnEdit = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnEdit.widthHint = 80;
		btnEdit.setLayoutData(gd_btnEdit);
		
		Button btnAdd = new Button(composite_13, SWT.NONE);
		btnAdd.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				doAdd();
			}
		});
		btnAdd.setImage(SWTResourceManager.getImage(ToolsMissionPage.class, "/com/incomplete/cubegs/resources/add_32_32.png"));
		btnAdd.setToolTipText("Add");
		GridData gd_btnAdd = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnAdd.widthHint = 80;
		btnAdd.setLayoutData(gd_btnAdd);
		
		Button btnRefresh = new Button(composite_13, SWT.NONE);
		btnRefresh.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				doRefresh();
			}
		});
		btnRefresh.setImage(SWTResourceManager.getImage(ToolsMissionPage.class, "/com/incomplete/cubegs/resources/refresh_32_32.png"));
		btnRefresh.setToolTipText("Refresh");
		GridData gd_btnRefresh = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnRefresh.widthHint = 80;
		btnRefresh.setLayoutData(gd_btnRefresh);
		
	

		// Footer
		compFooter = getFooterComposite(this);

		scCompContent.setExpandHorizontal(true);
		scCompContent.setExpandVertical(true);

		scCompContent.setContent(composite_11);
		scCompContent.setMinSize(composite_11.computeSize(SWT.DEFAULT, SWT.DEFAULT));
	}

    protected void doRefresh() {
		// TODO Auto-generated method stub
		
	}

	protected void doAdd() {
	}

	protected void doEdit() {
		// TODO Auto-generated method stub
		
	}

	protected void doRemove() {
		// TODO Auto-generated method stub
		
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
