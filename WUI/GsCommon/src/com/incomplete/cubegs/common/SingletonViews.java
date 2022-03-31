package com.incomplete.cubegs.common;

import java.util.HashMap;

import org.eclipse.rap.rwt.SingletonUtil;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.StackLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Composite;

public class SingletonViews {
	
	private StackLayout containerLayout = null;
	private Composite container = null;
	
	private HashMap<String, BaseClassPage> viewsList = null;
	private BaseClassPage currentPage = null;

	
	private SingletonViews() {
	}
	
	public static SingletonViews getInstance() {
		return SingletonUtil.getSessionInstance( SingletonViews.class );
	}
	
	public void registerView(String viewName, BaseClassPage viewPage) {
		if (viewName != null && viewPage != null) {
			if (this.viewsList == null) {
				this.viewsList = new HashMap<String, BaseClassPage>();
			}
			
			this.viewsList.put(viewName, viewPage);
		}
	}
	
	public void changeView(String viewName) {
		if (viewName != null) {
			if (this.viewsList.containsKey(viewName) == true) {
				// Execute stop() operation in current view
				if (currentPage != null) {
					currentPage.stop();
				}
				
				// Change the view
				currentPage = this.viewsList.get(viewName);
				
				if (currentPage != null) {
					currentPage.start();
					
					containerLayout.topControl = currentPage;
					
					container.layout();
					container.pack();
				}
			}
		}
	}
	
	public void initialize(Composite newParent) {
        container = new Composite( newParent, SWT.NONE );
		
    	container.setLayoutData( new GridData( SWT.FILL, SWT.FILL, true, true ) );
    	
    	containerLayout = new StackLayout();
    	container.setLayout( containerLayout );
	}
	
	public Composite getContainer() {
		return this.container;
	}
}

