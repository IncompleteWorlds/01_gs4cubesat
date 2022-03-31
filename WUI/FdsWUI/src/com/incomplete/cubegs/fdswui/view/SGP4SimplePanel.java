package com.incomplete.cubegs.fdswui.view;

import java.util.GregorianCalendar;

import org.eclipse.rap.rwt.RWT;
import org.eclipse.rap.rwt.service.UISession;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.DateTime;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;

import com.incomplete.cubegs.common.BaseClassPage;
import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.EnumOperationCode;
import com.incomplete.cubegs.common.ReturnData;
import com.incomplete.cubegs.fdswui.ModuleManager;
import com.incomplete.cubegs.fdswui.messages.M_SGP4Simple;
import com.incomplete.cubegs.fdswui.messages.M_SGP4SimpleResponse;



public class SGP4SimplePanel extends Composite {
    private static final long serialVersionUID = 1L;
    
    private Text stepSecs = null;
    private Text tleLine1 = null;
    private Text tleLine2 = null;
    private Text tleAll = null;
    private Text ephemOutputText = null;

    private DateTime endDate = null;
    private DateTime endTime = null;
    
    private DateTime startDate = null;
    private DateTime startTime = null;
    
    private Combo comboEpochFormat = null;
    private Combo comboEphemFormat = null;

    private Button btnRadioGetTLE;
    private Button btnRadioManual;
    private Button btnSGP4;
    private Button btnDownloadSGP4;

    private int stepInSecs = 0;

    private int whichTle = 1;
    private GregorianCalendar endCalendar = null;
    private GregorianCalendar startCalendar = null;
    
    BaseClassPage parentPage =  null;
    private Text posX;
    private Text posY;
    private Text posZ;
    private Text velX;
    private Text velY;
    private Text velZ;
    private Text satelliteId;
    
    /**
     * Create the composite.
     * @param inCompCentral 
     * @param parent
     * @param style
     */
    public SGP4SimplePanel(Composite inCompCentral, BaseClassPage inParentPage, int style) {
        super(inCompCentral, style);
        
        parentPage = inParentPage;

        Composite compSC_SGP4 = new Composite(inCompCentral, SWT.NONE);
        GridLayout gl_compSC_SGP4 = new GridLayout(6, false);
        compSC_SGP4.setLayout(gl_compSC_SGP4);
        
        Label lblNewLabel_1 = new Label(compSC_SGP4, SWT.NONE);
        lblNewLabel_1.setText("Start time");
        
        startDate = new DateTime(compSC_SGP4, SWT.BORDER);
        
        startTime = new DateTime(compSC_SGP4, SWT.BORDER | SWT.TIME | SWT.LONG);
        
        Label lblNewLabel_2 = new Label(compSC_SGP4, SWT.NONE);
        lblNewLabel_2.setText("End time");
        
        endDate = new DateTime(compSC_SGP4, SWT.BORDER);
        
        endTime = new DateTime(compSC_SGP4, SWT.BORDER | SWT.TIME | SWT.LONG);
        
        Label lblNewLabel_3 = new Label(compSC_SGP4, SWT.NONE);
        lblNewLabel_3.setSize(68, 17);
        lblNewLabel_3.setText("Step (secs)");
        
        stepSecs = new Text(compSC_SGP4, SWT.BORDER);
        stepSecs.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        
        Label lblNewLabel = new Label(compSC_SGP4, SWT.NONE);
        lblNewLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
        lblNewLabel.setText("Initial position");
        
        Composite composite_1 = new Composite(compSC_SGP4, SWT.NONE);
        composite_1.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 3, 1));
        GridLayout gl_composite_1 = new GridLayout(3, false);
        gl_composite_1.marginHeight = 0;
        gl_composite_1.marginWidth = 0;
        composite_1.setLayout(gl_composite_1);
        
        posX = new Text(composite_1, SWT.BORDER);
        GridData gd_posX = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
        gd_posX.widthHint = 100;
        posX.setLayoutData(gd_posX);
        
        posY = new Text(composite_1, SWT.BORDER);
        GridData gd_posY = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
        gd_posY.widthHint = 100;
        posY.setLayoutData(gd_posY);
        
        posZ = new Text(composite_1, SWT.BORDER);
        GridData gd_posZ = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
        gd_posZ.widthHint = 100;
        posZ.setLayoutData(gd_posZ);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        
        Label lblNewLabel_9 = new Label(compSC_SGP4, SWT.NONE);
        lblNewLabel_9.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
        lblNewLabel_9.setText("Initial velocity");
        
        Composite composite_2 = new Composite(compSC_SGP4, SWT.NONE);
        composite_2.setLayoutData(new GridData(SWT.FILL, SWT.FILL, false, false, 3, 1));
        GridLayout gl_composite_2 = new GridLayout(3, false);
        gl_composite_2.marginHeight = 0;
        gl_composite_2.marginWidth = 0;
        composite_2.setLayout(gl_composite_2);
        
        velX = new Text(composite_2, SWT.BORDER);
        GridData gd_velX = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
        gd_velX.widthHint = 100;
        velX.setLayoutData(gd_velX);
        
        velY = new Text(composite_2, SWT.BORDER);
        GridData gd_velY = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
        gd_velY.widthHint = 100;
        velY.setLayoutData(gd_velY);
        
        velZ = new Text(composite_2, SWT.BORDER);
        GridData gd_velZ = new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1);
        gd_velZ.widthHint = 100;
        velZ.setLayoutData(gd_velZ);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        
    
        Group grpTle = new Group(compSC_SGP4, SWT.NONE);
        grpTle.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 6, 1));
        grpTle.setText("TLE");
        grpTle.setLayout(new GridLayout(2, false));
        
        btnRadioGetTLE = new Button(grpTle, SWT.RADIO);
        btnRadioGetTLE.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, false, false, 2, 1));
        btnRadioGetTLE.setText("Retrieve last TLE from Celestrack");
        new Label(grpTle, SWT.NONE);
        
        satelliteId = new Text(grpTle, SWT.BORDER);
        satelliteId.setEnabled(false);
        satelliteId.setEditable(false);
        GridData gd_satelliteId = new GridData(SWT.LEFT, SWT.CENTER, true, false, 1, 1);
        gd_satelliteId.widthHint = 150;
        satelliteId.setLayoutData(gd_satelliteId);
        
        UISession uiSession = RWT.getUISession();
        
        satelliteId.setText( (String) uiSession.getAttribute(Constants.SATELLITE_NAME) );
        
        btnRadioManual = new Button(grpTle, SWT.RADIO);
        btnRadioManual.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, false, false, 2, 1));
        btnRadioManual.setText("Manual");
        btnRadioManual.setSelection(true);
        
        Label lblNewLabel_4 = new Label(grpTle, SWT.NONE);
        GridData gd_lblNewLabel_4 = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
        gd_lblNewLabel_4.widthHint = 60;
        lblNewLabel_4.setLayoutData(gd_lblNewLabel_4);
        lblNewLabel_4.setText("Line 1");
        
        tleLine1 = new Text(grpTle, SWT.BORDER);
        tleLine1.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
        
        Label lblNewLabel_5 = new Label(grpTle, SWT.NONE);
        lblNewLabel_5.setText("Line 2");
        
        tleLine2 = new Text(grpTle, SWT.BORDER);
        tleLine2.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
        
        Label lblNewLabel_8 = new Label(grpTle, SWT.NONE);
        lblNewLabel_8.setText("All");
        
        
        tleAll = new Text(grpTle, SWT.BORDER | SWT.MULTI);
        GridData gd_tleAll = new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1);
        gd_tleAll.heightHint = 60;
        tleAll.setLayoutData(gd_tleAll);
        
        Label lblNewLabel_6 = new Label(compSC_SGP4, SWT.NONE);
        lblNewLabel_6.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, false, false, 2, 1));
        lblNewLabel_6.setText("Output epoch format");
        
        comboEpochFormat = new Combo(compSC_SGP4, SWT.READ_ONLY);
        comboEpochFormat.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
        comboEpochFormat.setItems(new String[] {"UTC", "MJD 2000"});
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        
        Label lblNewLabel_7 = new Label(compSC_SGP4, SWT.NONE);
        lblNewLabel_7.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, false, false, 2, 1));
        lblNewLabel_7.setText("Ephemeris output format");
        
        comboEphemFormat = new Combo(compSC_SGP4, SWT.READ_ONLY);
        comboEphemFormat.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
        comboEphemFormat.setItems(new String[] {"JSON", "CCSDS-OEM", "CSV"});
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        
        btnSGP4 = new Button(compSC_SGP4, SWT.NONE);
        btnSGP4.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
        btnSGP4.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            @Override
            public void widgetSelected(SelectionEvent e) {
                doSgp4();
            }
        });
        btnSGP4.setText("Run");
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        
        ScrolledComposite scEphemOutput = new ScrolledComposite(compSC_SGP4, SWT.BORDER | SWT.H_SCROLL | SWT.V_SCROLL);
        scEphemOutput.setMinHeight(200);
        
        GridData gd_scEphemOutput = new GridData(SWT.FILL, SWT.FILL, false, false, 6, 1);
        gd_scEphemOutput.heightHint = 250;
        scEphemOutput.setLayoutData(gd_scEphemOutput);
        scEphemOutput.setExpandHorizontal(true);
        scEphemOutput.setExpandVertical(true);
        
        Composite composite = new Composite(scEphemOutput, SWT.NONE);
        composite.setLayout(new FillLayout(SWT.HORIZONTAL));
        
        ephemOutputText = new Text(composite, SWT.BORDER | SWT.READ_ONLY | SWT.WRAP | SWT.MULTI);
        ephemOutputText.setEditable(false);
        scEphemOutput.setContent(composite);
        scEphemOutput.setMinSize(composite.computeSize(SWT.DEFAULT, SWT.DEFAULT));
        
        btnDownloadSGP4 = new Button(compSC_SGP4, SWT.NONE);
        btnDownloadSGP4.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
        btnDownloadSGP4.addSelectionListener(new SelectionAdapter() {
            private static final long serialVersionUID = 1L;

            @Override
            public void widgetSelected(SelectionEvent e) {
                doDownload();
            }
        });
        btnDownloadSGP4.setText("Download");
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        new Label(compSC_SGP4, SWT.NONE);
        
        compSC_SGP4.pack();
    }

    

    @Override
    protected void checkSubclass() {
        // Disable the check that prevents subclassing of SWT components
    }
    
    private void doSgp4() {
        try {   
            ReturnData rc = checkFields();
            
            if (rc.getErrorCode() != 0) {
                parentPage.showError(rc.getErrorMessage());    
                return;
            }
            
            // Get JSON message
            int idx = comboEpochFormat.getSelectionIndex();
            String epochFormat = comboEpochFormat.getItem(idx);
            
            // UTCGregorian UTCModJulian,
            if (epochFormat.equals("UTC") == true) {
                epochFormat = "UTCGregorian";
            } else {
                if (epochFormat.equals("MJD 2000") == true) {
                    epochFormat = "UTCModJulian";    
                }
            }
            
            idx = comboEphemFormat.getSelectionIndex();
            String ephemFormat = comboEphemFormat.getItem(idx);
            
            UISession uiSession = RWT.getUISession();
            
            String userId = Integer.toString( (int) uiSession.getAttribute(Constants.USER_ID) );
            String missionId = (String) uiSession.getAttribute(Constants.MISSION_NAME);
            String satelliteId = (String) uiSession.getAttribute(Constants.SATELLITE_NAME);
            
            // Connect to Celestrack to retrieve the latest TLE 
            if (whichTle == 3) {
                // Retrieve latest TLE from Internet
                String tmpTle = "";
                rc = retrieveTle(satelliteId, tmpTle);
                
                if (rc.getErrorCode() != 0) {
                    parentPage.showError(rc.getErrorMessage());    
                    return;
                }
                
                tleAll.setText(tmpTle);
            }
            
            M_SGP4Simple request = new M_SGP4Simple(userId, missionId, satelliteId,
                                                stepInSecs, 
                                                whichTle, tleLine1.getText(), tleLine2.getText(), tleAll.getText(), 
                                                startCalendar,
                                                endCalendar,
                                                epochFormat,
                                                ephemFormat,
                                                posX.getText(), posY.getText(), posZ.getText(),
                                                velX.getText(), velY.getText(), velZ.getText());
            
            M_SGP4SimpleResponse response = new M_SGP4SimpleResponse();
            
            ephemOutputText.setText("");
            
            // Call the module and wait for answer
            rc = ModuleManager.run(EnumOperationCode.msg_propagate_sgp4, request, response);
            
            if (rc.getErrorCode() != 0) {
                parentPage.showError(rc.getErrorMessage());
                return;
            }
            
            // Show the data
            ephemOutputText.setText( response.getEphemerisText() );
        } catch(Exception e) {
            parentPage.showError("Exception: " + e.toString() );
            return;
        }
    }


    private ReturnData retrieveTle(String inSatelliteId, String outTle) {
        ReturnData rc = new ReturnData();
        
        return rc;
    }

    private void doDownload() {
        if (ephemOutputText.getText().isBlank() == false) {                
            // Take the of the output and save it locally
            
            // TODO
        }        
    }

    private ReturnData checkFields() {
        ReturnData rc = new ReturnData();

        if (stepSecs.getText().isBlank() == true) {
            rc.set(-1, "Steps is empty or invalid");
            return rc;
        }
        try {
            stepInSecs = Integer.parseInt( stepSecs.getText() );
        } catch(Exception e) {
            rc.set(-1, "Steps is empty or invalid");
            return rc;   
        }
        
        // Check position
        if (posX.getText().isBlank() == true ||
            posY.getText().isBlank() == true ||
            posZ.getText().isBlank() == true) {
            rc.set(-1, "Incorrect Initial position");
            return rc;    
        }

        // Check velocity
        if (velX.getText().isBlank() == true ||
            velY.getText().isBlank() == true ||
            velZ.getText().isBlank() == true) {
            rc.set(-1, "Incorrect Initial velocity");
            return rc;    
        }
        
        // If Set TLE Manually is selected, check the fields
        whichTle = 0;
        if (btnRadioManual.getSelection() == true) {
            if (tleLine1.getText().isBlank() == true) {
                if (tleAll.getText().isBlank() == true) {
                    rc.set(-1,  "Empty TLE. Please enter the two lines elements");
                    return rc;
                } else {                        
                    whichTle = 2;   
                }
            } else {
                if (tleLine2.getText().isBlank() == true) {
                    rc.set(-1,  "Empty TLE. Please enter the two lines elements");
                    return rc;
                } else {
                    whichTle = 1;
                }
            }        
        }
        
        // Download from Internet
        if (btnRadioGetTLE.getSelection() == true) {
            whichTle = 3;
        }

        endCalendar = new GregorianCalendar(endDate.getYear(), endDate.getMonth(), endDate.getDay(),
                                                           endTime.getHours(), endTime.getMinutes(), endTime.getSeconds());

        startCalendar = new GregorianCalendar(startDate.getYear(), startDate.getMonth(), startDate.getDay(),
                                                                startTime.getHours(), startTime.getMinutes(), startTime.getSeconds());
  
        if (endCalendar.before(startCalendar) == true) {
            rc.set(-1,  "End Date/Time is set before Start Date/Time");
            return rc;
        }
        
        // check Comboboxes
        int idx = comboEpochFormat.getSelectionIndex();
        if (idx == -1) {
            rc.set(-1, "Please, select an Epoch format");
            return rc;  
        }
        
        idx = comboEphemFormat.getSelectionIndex();
        if (idx == -1) {
            rc.set(-1, "Please, select an Ephemeris format");
            return rc;  
        }

        return rc;
    }
}
