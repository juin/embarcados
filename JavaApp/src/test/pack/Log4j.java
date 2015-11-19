package test.pack;


import org.apache.log4j.Logger;

public class Log4j {
	
	private static final Logger Log = Logger.getLogger(Log4j.class);
			
	
	public static void main(String[] args){
		Log.debug("outro");
	}
}
