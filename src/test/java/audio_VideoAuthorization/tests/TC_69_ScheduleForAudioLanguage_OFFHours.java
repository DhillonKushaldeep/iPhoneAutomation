/**
 * 
 */
package audio_VideoAuthorization.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.HoldScreen_Audio;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_69_ScheduleForAudioLanguage_OFFHours extends BaseTest{

	@Test
	public void ScheduleForAudioLanguage_OFFHours() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();       //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		
		LanguageScreen languageScreen = new LanguageScreen(driver);     // click on Acholi
		languageScreen.click_AllLanguages();
		languageScreen.click_AcholiLanguage();   
		
		 Thread.sleep(2000);
		 MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioOnlyLanguage"));
		 el1.click();
		
		 HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
		 holdScreen_Audio.verifyConnectingtoYourInterpreterdDisplayed();
		 System.out.println("Connecting to Your Interpreter is displayed");
		 Thread.sleep(1000);
		 
		 holdScreen_Audio.click_AudioCancelCall();
		 System.out.println("Audio Cancel Call Button is clicked");
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
