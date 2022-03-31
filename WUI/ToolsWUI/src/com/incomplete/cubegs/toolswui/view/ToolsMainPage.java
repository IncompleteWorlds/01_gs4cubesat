package com.incomplete.cubegs.toolswui.view;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.SWT;
import org.eclipse.wb.swt.SWTResourceManager;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

import com.incomplete.cubegs.common.BaseClassPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.SingletonViews;
import org.eclipse.swt.widgets.Label;



public class ToolsMainPage extends BaseClassPage  {
	private static final long serialVersionUID = 1L;

	// They have to be local otherwise WindowsBuiler does not work
	private Composite compHeader = null; 
	private Composite compContent = null;
	private Composite compFooter = null;
	

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public ToolsMainPage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style, true);

		setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
		setBackground(SWTResourceManager.getColor(255, 255, 255));
		setLayout(new GridLayout(1, false));
		
		// Header
		compHeader = getHeaderComposite(this, "Tools");

		// Central Content
	    compContent = new Composite(this, SWT.NONE);
		GridLayout gl_compContent = new GridLayout(5, false);
		gl_compContent.verticalSpacing = 50;
		gl_compContent.horizontalSpacing = 50;
		gl_compContent.marginTop = 30;
		gl_compContent.marginRight = 30;
		gl_compContent.marginLeft = 30;
		gl_compContent.marginBottom = 30;
		compContent.setLayout(gl_compContent);
		compContent.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, true, 1, 1));
		compContent.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Button btnConfiguration = new Button(compContent, SWT.FLAT);
		btnConfiguration.setToolTipText("Configure Parameters");
		btnConfiguration.setImage(SWTResourceManager.getImage(ToolsMainPage.class, "/com/incomplete/cubegs/resources/tools_settings_128_128.png"));
		btnConfiguration.setForeground(SWTResourceManager.getColor(0, 0, 0));
		btnConfiguration.setBackground(SWTResourceManager.getColor(255, 255, 255));
		btnConfiguration.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				SingletonViews.getInstance().changeView(Constants.TOOLS_CONFIG_VIEW_NAME);
			}
		});
		
		
		Button btnEditMission = new Button(compContent, SWT.FLAT);
		btnEditMission.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				SingletonViews.getInstance().changeView(Constants.TOOLS_EDIT_MISSION_VIEW_NAME);
			}
		});
		btnEditMission.setToolTipText("Edit Mission");
		btnEditMission.setImage(SWTResourceManager.getImage(ToolsMainPage.class, "/com/incomplete/cubegs/resources/mission.png"));
		btnEditMission.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Button btnConfMission = new Button(compContent, SWT.NONE);
		btnConfMission.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;
			
			@Override
			public void widgetSelected(SelectionEvent e) {
				SingletonViews.getInstance().changeView(Constants.TOOLS_CONFIGURE_MISSION_VIEW_NAME);
			}
		});
		btnConfMission.setToolTipText("Configure Mission");
		btnConfMission.setImage(SWTResourceManager.getImage(ToolsMainPage.class, "/com/incomplete/cubegs/resources/tools_sub_mission.png"));
		
		Button btnRemoveMission = new Button(compContent, SWT.NONE);
		btnRemoveMission.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});
		btnRemoveMission.setImage(SWTResourceManager.getImage(ToolsMainPage.class, "/com/incomplete/cubegs/resources/remove-mission.png"));
		btnRemoveMission.setToolTipText("Remove Mission");
		
		Button btnUser = new Button(compContent, SWT.FLAT);
		btnUser.addSelectionListener(new SelectionAdapter() {
			private static final long serialVersionUID = 1L;

			@Override
		    public void widgetSelected(SelectionEvent e) {
		        SingletonViews.getInstance().changeView(Constants.TOOLS_OPERATOR_VIEW_NAME);
		    }
		});
		btnUser.setToolTipText("Operators Management");
		btnUser.setImage(SWTResourceManager.getImage(ToolsMainPage.class, "/com/incomplete/cubegs/resources/users_128_128.png"));
		btnUser.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		// Footer
		compFooter = getFooterComposite(this);
	}
	
	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
}
