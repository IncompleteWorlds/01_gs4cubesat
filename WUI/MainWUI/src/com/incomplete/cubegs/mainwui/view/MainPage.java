package com.incomplete.cubegs.mainwui.view;


import javax.servlet.ServletContext;

import org.eclipse.rap.rwt.RWT;
import org.eclipse.rap.rwt.client.service.UrlLauncher;
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



public class MainPage extends BaseClassPage  {
	private static final long serialVersionUID = 1L;

	// They have to be local otherwise WindowsBuiler does not work
	protected Composite compHeader = null; 
	protected Composite compContent = null;
	protected Composite compFooter = null;

	/**
	 * Create the composite.
	 * @param parent
	 * @param style
	 */
	public MainPage(String newViewName, Composite parent, int style) {
		super(newViewName, parent, style, true);

		
		setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
		setBackground(SWTResourceManager.getColor(255, 255, 255));
		setLayout(new GridLayout(1, false));
		
		// Header
		compHeader = getHeaderComposite(this, "Main");

		// Central Content
	    compContent = new Composite(this, SWT.NONE);
		GridLayout gl_compContent = new GridLayout(3, false);
		gl_compContent.verticalSpacing = 50;
		gl_compContent.horizontalSpacing = 50;
		gl_compContent.marginTop = 30;
		gl_compContent.marginRight = 30;
		gl_compContent.marginLeft = 30;
		gl_compContent.marginBottom = 30;
		compContent.setLayout(gl_compContent);
		compContent.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, true, 1, 1));
		compContent.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Button btnMCS = new Button(compContent, SWT.FLAT);
		btnMCS.setToolTipText("MCS");
		btnMCS.setImage(SWTResourceManager.getImage(MainPage.class, "/com/incomplete/cubegs/resources/mcs_128_128.png"));
		btnMCS.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				openURL(Constants.MCS_WUI_CONTEXT, Constants.MCS_WUI_PATH);
			}
		});
		btnMCS.setForeground(SWTResourceManager.getColor(0, 0, 0));
		btnMCS.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Button btnFDS = new Button(compContent, SWT.FLAT);
		btnFDS.setToolTipText("FDS");
		btnFDS.setImage(SWTResourceManager.getImage(MainPage.class, "/com/incomplete/cubegs/resources/fds_128_128.png"));
		btnFDS.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				openURL(Constants.FDS_WUI_CONTEXT, Constants.FDS_WUI_PATH);
			}
		});
		btnFDS.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Button btnMPS = new Button(compContent, SWT.FLAT);
		btnMPS.setEnabled(false);
		btnMPS.setToolTipText("MPS");
		btnMPS.setImage(SWTResourceManager.getImage(MainPage.class, "/com/incomplete/cubegs/resources/mps_128_128.png"));
		btnMPS.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Button btnGS = new Button(compContent, SWT.FLAT);
		btnGS.setEnabled(false);
		btnGS.setToolTipText("Ground Stations");
		btnGS.setImage(SWTResourceManager.getImage(MainPage.class, "/com/incomplete/cubegs/resources/ground_station_128_128.png"));
		btnGS.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {
				openURL(Constants.GS_WUI_CONTEXT, Constants.GS_WUI_PATH);
			}
		});
		btnGS.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Button btnMC = new Button(compContent, SWT.FLAT);
		btnMC.setEnabled(false);
		btnMC.setFont(SWTResourceManager.getFont("Liberation Sans", 15, SWT.BOLD));
		GridData gd_btnMC = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_btnMC.heightHint = 128;
		gd_btnMC.widthHint = 128;
		btnMC.setLayoutData(gd_btnMC);
		btnMC.setText("M && C");
		btnMC.setToolTipText("M && C");
		btnMC.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		Button btnTools = new Button(compContent, SWT.FLAT);
		btnTools.setToolTipText("Tools");
		btnTools.setImage(SWTResourceManager.getImage(MainPage.class, "/com/incomplete/cubegs/resources/tools_128_128.png"));
		btnTools.addSelectionListener(new SelectionAdapter() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void widgetSelected(SelectionEvent e) {											
				openURL(Constants.TOOLS_WUI_CONTEXT, Constants.TOOLS_WUI_PATH);
			}
		});
		btnTools.setBackground(SWTResourceManager.getColor(255, 255, 255));
		
		// Footer
		compFooter = getFooterComposite(this);
	}

	@Override
	protected void checkSubclass() {
		// Disable the check that prevents subclassing of SWT components
	}
	
	private void openURL(String inContext, String inPath) {
		if (inContext != null && inPath != null) {
			// Set common parameters
			ServletContext servletCtx = RWT.getUISession().getHttpSession().getServletContext();
			
			// Get current user
			Object tmpObject = servletCtx.getAttribute(Constants.USER_NAME);
			                
			if (tmpObject != null) {
				ServletContext servletToolsCtx = RWT.getUISession().getHttpSession().getServletContext().getContext(inContext);
				
				if (servletToolsCtx != null) {
					servletToolsCtx.setAttribute(Constants.USER_NAME,    servletCtx.getAttribute(Constants.USER_NAME));
					servletToolsCtx.setAttribute(Constants.USER_ID,      servletCtx.getAttribute(Constants.USER_ID));
					servletToolsCtx.setAttribute(Constants.ROLE_ID,      servletCtx.getAttribute(Constants.ROLE_ID));
					servletToolsCtx.setAttribute(Constants.MISSION_NAME, servletCtx.getAttribute(Constants.MISSION_NAME));
				}
			}
			
			String tmpURL = inContext + inPath;
			//String tmpURL = inPath;
			
			UrlLauncher launcher = RWT.getClient().getService( UrlLauncher.class );
			
			launcher.openURL(tmpURL);			
		}
	}
}
