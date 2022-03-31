package com.incomplete.cubegs.messages;

import org.eclipse.rap.rwt.RWT;

/**
 * 
 * @author albertofernandez
 *
 */
public class Messages {

	// Name of the file without extension
	private static final String BUNDLE_NAME = "com.incomplete.cugegs.mainwui.messages.resources.messages"; //$NON-NLS-1$

	// List of keywords
	// All of them shall be defined in the messages.properties file
	// Example of use: label.setText( Messages.get().ExampleView_Message );
	public String ExampleView_Title;
	public String ExampleView_Message;

	public static Messages get() {
		Class clazz = Messages.class;

		return (Messages) RWT.NLS.getISO8859_1Encoded(BUNDLE_NAME, clazz);
	}

	private Messages() {
		// prevent instantiation
	}

}