package com.appium.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;

import org.apache.commons.lang3.StringUtils;


public class FileReader {
	


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
