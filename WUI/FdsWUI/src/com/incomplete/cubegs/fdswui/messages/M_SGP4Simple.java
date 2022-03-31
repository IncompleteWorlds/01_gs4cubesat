package com.incomplete.cubegs.fdswui.messages;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.TimeZone;

import com.incomplete.cubegs.common.Constants;
import com.incomplete.cubegs.common.EnumOperationCode;
import com.incomplete.cubegs.common.ServerMessage;
import com.incomplete.cubegs.common.avro.messages.MsgPropagateSGP4;
import com.incomplete.cubegs.common.avro.messages.Sgp4Output;
import com.incomplete.cubegs.common.avro.messages.Tle;





/*
    "user_id"            : "xxx_yyy_1112",

    "mission_id"         : "mis1",
    "satellite_id"       : "sat1",

    "add_to_database"    : "false",

    "epoch_format"       : "UTCGregorian",

    "start_time"         : "15 Jun 2020 12:00:00.000",
    "stop_time"          : "16 Jun 2020 12:00:00.000",

    "step_size"          : 30,

    "initial_position"   : [  0.0, 1.0, 2.0 ],
    "initial_velocity"   : [  0.0, 1.0, 2.0 ],

    "input" : {
        "tle"           : {
            "line1"     : "1 25682U 99020A   20153.55123203 -.00000529  00000-0 -10763-3 0  9993",
            "line2"     : "2 25682  98.0820 216.6954 0000943  88.9800 271.1505 14.57169631123925"
        }
    },

    "output" : {
        "reference_frame" : "EarthMJ2000Eq",
        "output_format"   : "CCSDS-OEM", 
    }
 */
public class M_SGP4Simple extends ServerMessage {

    private MsgPropagateSGP4  avroMessage;
    
    public M_SGP4Simple(
            String inUserId, String inMissionId, String inSatelliteId,
            int inStepInSecs, int inWhichTle, String inTleLine1, String inTleLine2, String inTleAll,
            GregorianCalendar inStartCalendar, GregorianCalendar inEndCalendar, 
            String inEpochFormat, 
            String inEphemFormat, 
            String inPosX, String inPosY, String inPosZ, 
            String inVelX, String inVelY, String inVelZ) {
        super( EnumOperationCode.msg_propagate_sgp4.toString() );

        this.avroMessage = new MsgPropagateSGP4();

        // Copy this header to the internal Avro message
        // This is a bit inefficient
        this.avroMessage.setHeader(this.getHeader());
        
        this.setUserId(inUserId);
        
        this.avroMessage.setMissionId(inMissionId);
        this.avroMessage.setSatelliteId(inSatelliteId);
        this.avroMessage.setStepSize(inStepInSecs);
                    
        TimeZone tz = TimeZone.getTimeZone("UTC");
        SimpleDateFormat df = new SimpleDateFormat(Constants.ISO_8601_DATE_FORMAT);
        df.setTimeZone(tz);
            
        this.avroMessage.setStartTime( df.format(inStartCalendar.getTime() ) );
        this.avroMessage.setStopTime( df.format(inEndCalendar.getTime()) );
        
        // Fix value
        this.avroMessage.setEpochFormat(Constants.DEFAULT_EPOCH_FORMAT);
        
        Sgp4Output tmpOutput = new Sgp4Output(Constants.DEFAULT_REFERENCE_FRAME, inEpochFormat, inEphemFormat);
        this.avroMessage.setOutput(tmpOutput);

        ArrayList<Double>  initialPosition = new ArrayList<Double>(3);
        initialPosition.add(0, Double.parseDouble(inPosX) );
        initialPosition.add(1, Double.parseDouble(inPosY) );
        initialPosition.add(2, Double.parseDouble(inPosZ) );
         
        this.avroMessage.setInitialPosition(initialPosition);
        
        ArrayList<Double>  initialVelocity = new ArrayList<Double>(3);
        initialVelocity.add(0, Double.parseDouble(inVelX) );
        initialVelocity.add(1, Double.parseDouble(inVelY) );
        initialVelocity.add(2, Double.parseDouble(inVelZ) );
        
        this.avroMessage.setInitialVelocity(initialVelocity);
        
        Tle tmpInput = new Tle();
                        
        if (inWhichTle == 1) {
            tmpInput.setLine1(inTleLine1);
            tmpInput.setLine2(inTleLine2);
        } else if (inWhichTle == 2) {
            // Unix and Windows
            String[] arrayLines = inTleAll.split("\\r?\\n");
            
            if (arrayLines.length >= 2) {
                tmpInput.setLine1(arrayLines[0]);
                tmpInput.setLine2(arrayLines[1]);
            }
        }

        this.avroMessage.setSgp4Input(tmpInput);
    }
    
    @Override
    public String encode() {
        try {
            return ServerMessage.encodeMessage(MsgPropagateSGP4.class, this.avroMessage, this.avroMessage.getSchema());
        } catch(Exception e) {
            System.err.println(this.avroMessage.getSchema().toString(true));
            System.err.println("Input message: " + this.avroMessage.toString());

            e.printStackTrace();
            return new String();
        }
    }
    
    @Override
    public void decode(String inMsgBuffer) {
        if (inMsgBuffer.isEmpty() == false) {
            try {
                this.avroMessage = ServerMessage.decodeMessage(MsgPropagateSGP4.class, inMsgBuffer, this.avroMessage.getSchema());
            } catch(Exception e) {
                System.err.println(this.avroMessage.getSchema().toString(true));
                System.err.println("Input message: " + inMsgBuffer);
                
                e.printStackTrace();
            }            
        }
    }
    
    @SuppressWarnings("unchecked")
    @Override
    public MsgPropagateSGP4 get() {
        return this.avroMessage;
    }
}
