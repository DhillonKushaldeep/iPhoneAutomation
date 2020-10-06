package com.appium.core;

import io.appium.java_client.AppiumDriver;
import io.appium.java_client.MobileElement;
import io.appium.java_client.android.AndroidDriver;
import io.appium.java_client.ios.IOSDriver;
import io.appium.java_client.remote.MobileCapabilityType;

import java.io.File;
import java.lang.reflect.Method;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.TimeUnit;

import org.apache.commons.io.FileUtils;
import org.openqa.selenium.OutputType;
import org.openqa.selenium.TakesScreenshot;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.testng.ITestResult;
import org.testng.annotations.AfterClass;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.AfterSuite;
import org.testng.annotations.BeforeClass;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.BeforeSuite;

import com.appium.utils.FileReader;
import com.relevantcodes.extentreports.Configuration;
import com.relevantcodes.extentreports.ExtentReports;
import com.relevantcodes.extentreports.ExtentTest;
import com.relevantcodes.extentreports.LogStatus;


public class BaseTest {

	protected AppiumDriver driver;
	protected int timeOut = 120;
	private int port = 0;
	public static ExtentTest test;
	public static ExtentReports extent;
	
	
		
	protected String userName;
    protected String raghuUser;
    protected String invalidUserName;
    protected String incompleteUserName;
    
    protected String Username_OutsideGeoFence;
    protected String Username_WithinGeoFence;
    protected String Username_WithinNetwork;
    protected String Username_NetworkRestriction;
    protected String Username_GeofenceRestriction;
    
    protected String Username_DisabledAuthCode;
    
    protected String Username_WithMaxChar;
    protected String Username_WithMaxAuth;    
    protected String Username_SecondAuth;
    
    protected String DeviceName_Special;
    protected String DeviceName_SecondAuth;
    protected String DeviceName_MaxChar;
    protected String password;
	

	
	@BeforeSuite
    public void setupReport() throws Exception{
		
		extent = new ExtentReports("target/surefire-reports/ExtentReport.html", true); //to get SINGLE Extent Report based on TIME
        //extent = new ExtentReports("target/surefire-reports/ExtentReport.html" + FileReader.getTimeStamp()+ ".html", true); //to get MULTIPLE Extent Reports based on TIME
        
        extent.addSystemInfo("Manager",   "Julia Berke");
        extent.addSystemInfo("Company",   "LanguageLine Solutions");
        extent.addSystemInfo("Simulator",  FileReader.readData("IDeviceName"));
    }
    
        
    @BeforeMethod
    public void setupMethod(Method method){
        test = extent.startTest(method.getName(), this.getClass().getName());
        test.assignAuthor("Kushaldeep Dhillon");
        test.assignCategory(this.getClass().getSimpleName());
        System.out.println("Test Starting on Device");        
    }
    
	@BeforeClass
	public void setUp() throws Exception {
		
		userName =                        FileReader.readData("UserName");    
        raghuUser =                       FileReader.readData("RaghuUsername");
        invalidUserName =                 FileReader.readData("InvalidUsername");
        incompleteUserName =              FileReader.readData("IncompleteUsername");           
        
        Username_DisabledAuthCode =       FileReader.readData("DisabledAuthCode");
        
        Username_SecondAuth =             FileReader.readData("UsernameSecondAuth");
        
        Username_WithMaxChar =            FileReader.readData("UsernameWithMaxChar");
        Username_WithMaxAuth =            FileReader.readData("UsernameWithMaxAuth");
                
        DeviceName_Special =              FileReader.readData("DeviceNameSpecial");        
        DeviceName_SecondAuth =           FileReader.readData("DeviceNameSecondAuth");
        DeviceName_MaxChar =              FileReader.readData("DeviceNameWithMaxChar");
        password =                        FileReader.readData("Password");
		
		
		//System.setProperty("webdriver.chrome.driver",	"C://Users//kdhillon//BitBucket//src//test//resources//webdriver/chromedriver.exe");
		// setup port
		if (port == 0)
			port = Integer.parseInt(FileReader.readData("Port"));		
		try {
			driver = iOSSetUp();
		} catch (Exception e) {
			throw new Exception(e);
		}
		//driver.navigate().to("https://www.google.com/");
		//driver.manage().timeouts().implicitlyWait(timeOut, TimeUnit.SECONDS);

	}

	@AfterSuite
	public void tearDown() throws Exception {
		driver.quit();
		Runtime run = Runtime.getRuntime();
		run.exec("killall -9 iPhone Simulator");
	}

	/**
	 * @author Get absolute path of android application apk file. Apk file is
	 *         under the app folder
	 * @param no
	 *            parameter
	 * @return absolute path.
	 * @throws Exception
	 */
	public String getAppAbsoultePath() throws Exception {
		File classpathRoot = new File(System.getProperty("user.dir"));
		File appDir = new File(classpathRoot, "/app");
		File app = new File(appDir, FileReader.readData("APKFileName") + ".apk");
		String appName = app.getAbsolutePath();
		return appName;
	}

	/**
	 * it create session of Appium for Android object
	 *
	 * @return : return appium driver object
	 * @throws Exception
	 *             : throw exception
	 */
	public AppiumDriver<MobileElement> androidSetUp() throws Exception {
		// setup port
		if (port == 0) {
			port = Integer.parseInt(FileReader.readData("Port"));
		}
		String host = FileReader.readData("Host");
		try {
			driver = new AndroidDriver<MobileElement>(new URL("http://" + host + ":" + port + "/wd/hub"), getDesiredCapabilities("Androidweb"));
		} catch (Exception e) {
			throw new Exception(e);
		}
		driver.manage().timeouts().implicitlyWait(timeOut, TimeUnit.SECONDS);
		return driver;
	}

	/**
	 * it create session of Appium for iOS Object
	 *
	 * @return : return appium driver object
	 * @throws Exception
	 *             : throw exception
	 */
	public AppiumDriver<MobileElement> iOSSetUp() throws Exception {
		String host = FileReader.readData("Host");
		String port = FileReader.readData("Port");
		try {
			driver = new IOSDriver<>(new URL("http://" + host + ":" + port + "/wd/hub"), getDesiredCapabilities("iOS"));
		} catch (Exception e) {
			throw new Exception(e);
		}
		driver.manage().timeouts().implicitlyWait(timeOut, TimeUnit.SECONDS);
		return driver;
	}

	/**
	 * @return absolute path
	 * @throws Exception
	 *             : throw exception
	 * @author Setup configuration in DesiredCapabilities which appium used to
	 *         run test
	 */
	public DesiredCapabilities getDesiredCapabilities(String driverType) throws Exception {
		DesiredCapabilities capabilities = new DesiredCapabilities();

		switch (driverType) {
		case "Android":
			capabilities.setCapability("platformName", "Android");
			capabilities.setCapability("deviceName",  FileReader.readData("ADeviceName"));
			//capabilities.setCapability("platformVersion",  FileReader.readData("APlatformVersion"));
			capabilities.setCapability("unicodeKeyboard ", "true");
			capabilities.setCapability("app", getAppAbsoultePath());
			break;
			
		case "Androidweb":
			
			capabilities.setCapability("platformName", "Android");
			//capabilities.setCapability(MobileCapabilityType.PLATFORM_VERSION, "4.4");
			capabilities.setCapability(MobileCapabilityType.DEVICE_NAME, "Android Emulator");
			capabilities.setCapability(MobileCapabilityType.BROWSER_NAME, "Chrome");
			capabilities.setCapability("unicodeKeyboard ", "true");
			
			//capabilities.setCapability("platformName", "Android");
			//capabilities.setCapability("deviceName",  FileReader.readData("ADeviceName"));
			//capabilities.setCapability("platformVersion",  FileReader.readData("APlatformVersion"));
			//capabilities.setCapability("unicodeKeyboard ", "true");
			//capabilities.setCapability("app", getAppAbsoultePath());
			break;
			
		case "iOS":
			capabilities.setCapability("platformName", "iOS");
			capabilities.setCapability("deviceName",  FileReader.readData("IDeviceName"));
			capabilities.setCapability("platformVersion",  FileReader.readData("IPlatformVersion"));
			capabilities.setCapability("automationName", "XCUITest");
			capabilities.setCapability("autoGrantPermissions", "true");
			capabilities.setCapability("app", getIOSAbsoultePath());
			break;
		default:
			throw new Exception("Please provide valid driver option either Android or iOS ");

		}
		return capabilities;
	}

	  /**
	   * @return absolute path
	   * @throws Exception : throw exception
	   * @author Get absolute path of ios application app file.path under the app folder
	   */
	  public String getIOSAbsoultePath() throws Exception {
	    File classpathRoot = new File(System.getProperty("user.dir"));
	    File appDir = new File(classpathRoot, "/app");
	    File app = new File(appDir, FileReader.readData("IApp") + ".app");
	    String appName = app.getAbsolutePath();
	    return appName;
	  }
	  
	public void relaunchApp() {
		driver.closeApp();
		driver.launchApp();
	}

	/**
	 * reset application
	 */
	public void appReset() {
		driver.resetApp();
	}
	
	//This method is to capture the screenshot and return the path of the screenshot.
			public static String getScreenhot(WebDriver driver, String screenshotName) throws Exception {
			String dateName = new SimpleDateFormat("dd-MMMM-yyyy hh-mm-ss").format(new Date());
			TakesScreenshot ts = (TakesScreenshot) driver;
			File source = ts.getScreenshotAs(OutputType.FILE);
			                //after execution, you could see a folder "FailedTestsScreenshots" under src folder
			String destination = System.getProperty("user.dir") + "/FailedTestsScreenshots/"+screenshotName + dateName+".png";
			File finalDestination = new File(destination);
			FileUtils.copyFile(source, finalDestination);
			return destination;
			}
	    
    @AfterMethod
    public void tearDownMethod(ITestResult result) throws Exception{
    	
    	if (result.getStatus() == ITestResult.SUCCESS) {
            test.log(LogStatus.PASS, "Test case Passed is:  " + result.getName() + " . It has been executed successfully" );
    	}
        
    	else if (result.getStatus() == ITestResult.FAILURE) {
        	test.log(LogStatus.FAIL, "Failed Test Case is:  " + result.getName());
            test.log(LogStatus.FAIL, "Failed Test Case showing error as:  " + result.getThrowable());
            
            //To capture SCREENSHOT path and store the path of the screenshot in the string screenshotPath
            //We do pass the path captured by this method in to the extent reports using "test.addScreenCapture" method.
           
            //String screenshotPath = ExtentReportsClass.getScreenshot(driver, result.getName());
            String screenshotPath = BaseTest.getScreenhot(driver, result.getName());
            
            //To add it in the Extent Report
            test.log(LogStatus.FAIL, test.addScreenCapture(screenshotPath));
      
        
        
        }else if
        (result.getStatus() == ITestResult.SKIP) {
            test.log(LogStatus.SKIP, "Test case Skipped is:  " + result.getName() + " TC Skipped" );
        }
        
        
        extent.endTest(test);
    }
    

	@AfterSuite
    public void tearDownSuite(){
        extent.flush();
        extent.close();
    }

}
