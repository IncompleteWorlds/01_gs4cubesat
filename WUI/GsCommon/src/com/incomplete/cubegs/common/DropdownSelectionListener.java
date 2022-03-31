package com.incomplete.cubegs.common;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.ToolItem;

public class DropdownSelectionListener extends SelectionAdapter {
	private static final long serialVersionUID = 1L;

	//private ToolItem dropdown = null;

	private Menu menu = null;

	public DropdownSelectionListener(ToolItem dropdown) {
		menu = new Menu(dropdown.getParent().getShell(), SWT.POP_UP);
	}

	public Menu getMenu() {
	    return this.menu;
	}

	public void widgetSelected(SelectionEvent event) {
		if (event.detail == SWT.ARROW) {
			ToolItem item = (ToolItem) event.widget;
//			Rectangle rect = item.getBounds();
//			Point pt = item.getParent().toDisplay(new Point(rect.x, rect.y));
//			menu.setLocation(pt.x, pt.y + rect.height);
//			menu.setVisible(true);
			
			
			Point point = item.getParent().toDisplay(event.x, event.y);
			
			menu.setOrientation(item.getParent().getOrientation());
			menu.setLocation(point);
			menu.setVisible(true);			
		} 
	}
}
