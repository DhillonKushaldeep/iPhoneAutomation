/**
 * 
 */
package audio_VideoAuthorization.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.Connected_VideoScreen;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_68_ScheduleForVideoLanguage_OFFHours extends BaseTest{

	@Test
	public void ScheduleForVideoLanguage_OFFHours() throws InterruptedException {
	
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();       //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		
		LanguageScreen languageScreen = new LanguageScreen(driver);     // click on American Sign Language
	    languageScreen.click_AmericanSignLanguage();
	    
	    MobileElement viewVideoAvailability = (MobileElement) driver.findElement(By.id("View Video Availability"));////XCUIElementTypeStaticText[@name="View Video Availability"]
	    viewVideoAvailability.click();
	    Thread.sleep(2000);
	   
	  //******************************************************* When we Click on ASL, next page opens up on top of it with its schedule     **************************//
	    LanguageScreen languageScreen1 = new LanguageScreen(driver);
	    languageScreen1.viewAmericanSignLanguageSchedule();
	    
	  //******************************************************* When we Click on ASL, next page opens up on top of it with its schedule     **************************//
	    
	    //To RESET the DEVICE
	    Thread.sleep(2000);
	    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);
	}

}
