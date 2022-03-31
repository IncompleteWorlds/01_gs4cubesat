package com.incomplete.cubegs.common;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class TimeUtil {

	public final static String UTC_DATETIME_FORMAT="yyyy-MM-dd'T'HH:mm:ss.SSS'Z'";
	public final static String UTC_DATE_FORMAT="yyyy-MM-dd";
	
	public static String getCurrentUTCTimeAsString() {
		String output = null;
				
		SimpleDateFormat df = new SimpleDateFormat(UTC_DATETIME_FORMAT);

		Date currentDate = Calendar.getInstance().getTime();        
		
		output = df.format(currentDate);
		
		return output;
	}
	
	public static String getDateString(Date inDate) {
		String output = null;
		
		if (inDate != null) {
			SimpleDateFormat df = new SimpleDateFormat(UTC_DATE_FORMAT);
			
			output = df.format(inDate);			
		}
		
		return output;
	}
}
