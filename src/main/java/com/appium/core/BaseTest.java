package com.appium.core;

import io.appium.java_client.AppiumDriver;
import io.appium.java_client.MobileElement;
import io.appium.java_client.android.AndroidDriver;
import io.appium.java_client.ios.IOSDriver;
import io.appium.java_client.remote.MobileCapabilityType;

import java.io.File;
import java.lang.reflect.Method;
import java.net.URL;
import java.util.concurrent.TimeUnit;

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
    public void setupReport(){
        extent = new ExtentReports("target/surefire-reports/ExtentReport.html", true);
    }
    
        
    @BeforeMethod
    public void setupMethod(Method method){
        test = extent.startTest(method.getName(), this.getClass().getName());
        test.assignAuthor("Kushaldeep Dhillon");
        test.assignCategory(this.getClass().getSimpleName());
        System.out.println("Test");        
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
			throw new Exception("Please provide valied driver option either Android or iOS ");

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
	
	    
    @AfterMethod
    public void tearDownMethod(ITestResult result){
        
        if (result.getStatus() == ITestResult.FAILURE) {
            test.log(LogStatus.FAIL, result.getThrowable() );
        }
        
        if (result.getStatus() == ITestResult.SUCCESS) {
            test.log(LogStatus.PASS, "Test method " + result.getName() + " execution successfully" );
        }
        extent.endTest(test);
    }
    
    @AfterSuite
    public void tearDownSuite(){
        extent.flush();
        extent.close();
    }

}
