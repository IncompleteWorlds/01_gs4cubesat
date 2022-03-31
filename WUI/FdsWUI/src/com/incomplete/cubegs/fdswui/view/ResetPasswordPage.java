package com.incomplete.cubegs.fdswui.view;

//import org.eclipse.jface.dialogs.Dialog;
//import org.eclipse.jface.dialogs.IDialogConstants;
import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.wb.swt.SWTResourceManager;

import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;



public class ResetPasswordPage extends FdsBasePage  {
    private static final long serialVersionUID = 1L;

    // They have to be local otherwise WindowsBuiler does not work
    protected Composite compHeader = null; 
    protected Composite compContent = null;
    protected Composite compFooter = null;
    private Text text;

    
    public ResetPasswordPage(String newViewName, Composite parent, int style) {
        super(newViewName, parent, style, true);

        
        setFont(SWTResourceManager.getFont("Verdana", 11, SWT.NORMAL));
        setBackground(SWTResourceManager.getColor(255, 255, 255));
        setLayout(new GridLayout(1, false));
        
        // Header
        compHeader = getHeaderComposite(this, "Reset Password");

        // Central Content
        compContent = new Composite(this, SWT.NONE);
        compContent.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, true, true, 1, 1));
        compContent.setLayout(new GridLayout(1, false));
        
        Label lblPleaseEnterYour = new Label(compContent, SWT.WRAP);
        lblPleaseEnterYour.setFont(SWTResourceManager.getFont("Liberation Serif", 14, SWT.NORMAL));
        lblPleaseEnterYour.setText("Please, enter your email address or user id below.");
        
        Label lblNewLabel = new Label(compContent, SWT.NONE);
        lblNewLabel.setFont(SWTResourceManager.getFont("Liberation Serif", 14, SWT.NORMAL));
        lblNewLabel.setText("A message containting a link for resetting your password will be sent to your address.");
        
        Label lblNewLabel_1 = new Label(compContent, SWT.NONE);
        lblNewLabel_1.setFont(SWTResourceManager.getFont("Liberation Mono", 12, SWT.NORMAL));
        lblNewLabel_1.setText("");
        
        Label lblEnterYourEmail = new Label(compContent, SWT.WRAP);
        lblEnterYourEmail.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
        lblEnterYourEmail.setSize(430, 18);
        lblEnterYourEmail.setFont(SWTResourceManager.getFont("Liberation Serif", 14, SWT.NORMAL));
        lblEnterYourEmail.setText("Enter your email address or user identifer:");
        
        text = new Text(compContent, SWT.BORDER);
        GridData gd_text = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
        gd_text.widthHint = 400;
        text.setLayoutData(gd_text);
        text.setSize(1320, 27);
        
        Button btnSubmit = new Button(compContent, SWT.NONE);
        btnSubmit.setFont(SWTResourceManager.getFont("Liberation Serif", 14, SWT.NORMAL));
        GridData gd_btnSubmit = new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1);
        gd_btnSubmit.widthHint = 100;
        btnSubmit.setLayoutData(gd_btnSubmit);
        btnSubmit.setText("Submit");
        
        // Footer
        compFooter = getFooterComposite(this);
    }

    @Override
    protected void checkSubclass() {
        // Disable the check that prevents subclassing of SWT components
    }  
}
