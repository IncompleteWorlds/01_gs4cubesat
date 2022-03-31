TODO LIST
--------------------------------------

- Menu settings. Logout button
- Improve drop down menu. Maybe, not to use ToolBars
- Add User. Check no duplicates
- Create a Mission DB per user. DB will be created with the user creates a new mission



Icons from: http://www.clker.com

Get current shell
--------------------------------------
Display.getCurrent().getActiveShell()



//            Thread t = new Thread(new Runnable() {
//                @Override
//                public void run() {
//                    // TODO Auto-generated method stub
//                    
//                }
//            });
//            t.start();
//            t.joint();


SWTResourceManager
-----------------------------------------

- Remove a third parameter
- Add two casts to (Image)

//return new Image(display, data, data.getTransparencyMask());
return new Image(display, data);
                
GC gc = new GC((Drawable) result);


WindowsBuilder
--------------------------------------------

$ export SWT_GTK3=0
$ eclipse &





Show a Dialog box
--------------------------------------
// Show error
this.getDisplay().syncExec(new Runnable() {
    public void run() {
        //MessageDialog.openError(getShell(), "Error", returnData.getErrorMessage());
        
        MessageBox msg = new MessageBox(getShell(), SWT.APPLICATION_MODAL);
        msg.setText("Error");
        msg.setMessage(returnData.getErrorMessage());
        
        // TODO: Can I remove the callback?
        msg.open(new DialogCallback() {
            @Override
            public void dialogClosed(int returnCode) {
                // Do nothing
            }
        });
    }
} );


         application.addResource( "qpid.properties", new ResourceLoader() {
            @Override
            public InputStream getResourceAsStream( String resourceName ) throws IOException {
                return this.getClass().getClassLoader().getResourceAsStream( "resources/qpid.properties" );
            }
          } );


RAP 
---------------------------------------------
ExitConfirmation service = RWT.getClient().getService( ExitConfirmation.class );
service.setMessage( "Do you really wanna leave the party?" );



Register a style:
application.addStyleSheet( "my.application.aquablue", "theme/aquablue.css" );


Parameters in the URl:
StartupParameters service = RWT.getClient().getService( StartupParameters.class );
String foo = service.getParameter( "foo" );



Handle close tab or window:

RWT.getUISession().addUISessionListener( new UISessionListener() {
  public void beforeDestroy( UISessionEvent event ) {
    // Perform cleanup        
  }
} );

*/




/*
 * 
 * String url = "edit#person/" + persons.indexOf( person );
cell.setText(  
"<a href=\"" 
+ url 
+ "\" target=\"_blank\">edit</a>" 
);

 In the other EntryPoint, we add deep-link support like this:

BrowserNavigation bn 
= RWT.getClient().getService( BrowserNavigation.class );
bn.addBrowserNavigationListener( new BrowserNavigationListener() {
@Override
public void navigated( BrowserNavigationEvent event ) {
String state = event.getState();
if( state.startsWith( "person/" ) ) {
int index = Integer.parseInt( state.substring( 7 ) );
editPerson( persons.get( index ) );
}
}
} );


Deployment
-----------------------------------

1 - Create a Web Project; MainWUI
    Tomcat 8.5, servlet engine 2.4
2 - Create a Java Project for the other parts of the WUI
3 - In the Deployment Configuration, add the other projects. They will be added as a JAR
    GsCommon, McsWUI, ToolsWUI, etc.

4 - MainWUI. Add resources folder to the deployment. Target folder
    WEB-INF/resources
    
5 - Export the MainWUI protect as a WAR file
6 - Select Tomcat webapp folder

NOTE: Native jzmq library is in /usr/lib/x86_64-linux-gnu/jni/
NOTE: Add as native to Build Path -> Libraries. Select and Edit


Error: jzmq cannot be loaded twice. 
Solution: Copy the jzmq.jar in tomcat/lib
Remove jzmq.jar from all projects as it is not directly referenced

The URL is

http://localhost:8080/MainWUI/cubegs 

MainWUI is the name of the WAR file

When deploying on Tomcat, there is no need to create GsCommon.jar


KrakenD API Gateway
Start krakend
$ cd Project/10_KrakenD
$ ./start_kraken.sh

It will start the API Gateway. It is listening on port 8888 (check shell script)






ScrollComposite
// ----------------------------------------------------------------------------

/*******************************************************************************
 * Copyright (c) 2000, 2004 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
//package org.eclipse.swt.snippets;
/*
 * Create a ScrolledComposite with wrapping content.
 *
 * For a list of all SWT example snippets see
 * http://www.eclipse.org/swt/snippets/
 * 
 * @since 3.0
 */
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.ControlAdapter;
import org.eclipse.swt.events.ControlEvent;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.RowLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Shell;

public class ScrolledCompositeCreate {

  public static void main(String[] args) {
    Display display = new Display();
    Image image1 = display.getSystemImage(SWT.ICON_WORKING);
    Image image2 = display.getSystemImage(SWT.ICON_QUESTION);
    Image image3 = display.getSystemImage(SWT.ICON_ERROR);

    Shell shell = new Shell(display);
    shell.setLayout(new FillLayout());

    final ScrolledComposite scrollComposite = new ScrolledComposite(shell, SWT.V_SCROLL
        | SWT.BORDER);

    final Composite parent = new Composite(scrollComposite, SWT.NONE);
    for (int i = 0; i <= 50; i++) {
      Label label = new Label(parent, SWT.NONE);
      if (i % 3 == 0)
        label.setImage(image1);
      if (i % 3 == 1)
        label.setImage(image2);
      if (i % 3 == 2)
        label.setImage(image3);
    }
    RowLayout layout = new RowLayout(SWT.HORIZONTAL);
    layout.wrap = true;
    parent.setLayout(layout);

    scrollComposite.setContent(parent);
    scrollComposite.setExpandVertical(true);
    scrollComposite.setExpandHorizontal(true);
    scrollComposite.addControlListener(new ControlAdapter() {
      public void controlResized(ControlEvent e) {
        Rectangle r = scrollComposite.getClientArea();
        scrollComposite.setMinSize(parent.computeSize(r.width, SWT.DEFAULT));
      }
    });

    shell.open();
    while (!shell.isDisposed()) {
      if (!display.readAndDispatch()) {
        display.sleep();
      }
    }
    display.dispose();
  }
}




// Changes wrt how to deploy the systems
//------------------------------------------------------
public HttpManager() throws Exception {
        // This is required for Tomcat
        InputStream is = this.getClass().getClassLoader().getResourceAsStream("../resources/url.properties");

        properties.load( is );
        
        // This is required for Jetty (inside Eclipse)
        //properties.load( new FileInputStream("resources/url.properties") ); 
        
        System.out.println("INFO: Loaded URL properties");
    }

