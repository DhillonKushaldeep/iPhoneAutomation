package com.appium.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;

import org.apache.commons.lang3.StringUtils;


public class FileReader {
	
/*static String path = getFilePath();
    
    public static String readConfig(String key) throws Exception {
        String value = "";        
        try {
            Properties prop = new Properties();
            File f = new File(path + "/Authentication.properties");
            if (f.exists()) {
                prop.load(new FileInputStream(f));
                value = prop.getProperty(key);
                System.out.println("value "+value);
            }
            else{
                throw new Exception("File not found");
            }
        } catch (FileNotFoundException ex) {
            System.out.println("Failed to read from application.properties file.");
            throw ex;
        }
        if(value == null)
            throw new Exception("Key not found in properties file");
        return value;
    }

    public static String getFilePath() {
        String filepath = "";
        File file = new File("");
        String absolutePathOfFirstFile = file.getAbsolutePath();
        filepath = absolutePathOfFirstFile.replaceAll("\\\\+", "/");
        return filepath;
    }
	
	
}*/

	private static final String configFile = "Config.properties";

	//
	// * It load the configuration file and read data
	// * 
	// * @param by
	// *            String properties file key
	// * @return the found value from properties file.
	// *//
	public static String readData(String key) throws Exception {
		if (StringUtils.isEmpty(key)) {
			throw new Exception("key name is null");
		}
		String value = "";
		try {

			Properties properties = new Properties();
			File file = new File(configFile);
			if (file.exists()) {
				properties.load(new FileInputStream(file));
				value = properties.getProperty(key);
			}
		} catch (Exception e) {
			System.out.println("File not found");
		}
		return value;
	}

}
