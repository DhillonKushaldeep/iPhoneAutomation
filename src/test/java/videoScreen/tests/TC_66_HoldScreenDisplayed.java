/**
 * 
 */
package videoScreen.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.Connected_VideoScreen;
import com.appium.pages.HoldScreen_Video;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_66_HoldScreenDisplayed extends BaseTest{

	@Test
	public void HoldScreenDisplayed() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();       //To give access to Camera
		} catch (Exception e) {
			
	}			
		
		
		LanguageScreen languageScreen = new LanguageScreen(driver);
		languageScreen.click_searchLanguages("Punjabi");
		languageScreen.click_PunjabiLanguage();
	    Thread.sleep(2000);
	    
	     MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
	     el2.click();
	    
	     HoldScreen_Video holdScreen_Video = new HoldScreen_Video(driver);
		 holdScreen_Video.verifyConnectingtoYourInterpreterdDisplayed();
		 System.out.println("Connecting to Your Interpreter is displayed");
		 Thread.sleep(2000);
		    
		    
		 holdScreen_Video.click_CancelVideoCall();
		 System.out.println("Video Cancel Call Button is clicked");
	     Thread.sleep(2000);
	    
	   //To RESET the DEVICE
	    Thread.sleep(2000);
	    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
