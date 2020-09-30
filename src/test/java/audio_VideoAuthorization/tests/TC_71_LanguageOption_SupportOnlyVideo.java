/**
 * 
 */
package audio_VideoAuthorization.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.locator.HoldScreen_VideoUI;
import com.appium.pages.HoldScreen_Audio;
import com.appium.pages.HoldScreen_Video;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_71_LanguageOption_SupportOnlyVideo extends BaseTest{

	@Test
	public void LanguageOption_SupportOnlyVideo() throws InterruptedException {
			
			LoginPage loginPage = new LoginPage(driver);
			loginPage.loginInApp("kushaltest", "test");	
			driver.switchTo().alert().accept();        //To give access to MicroPhone
	        Thread.sleep(2000);
			
			try {
				
			driver.switchTo().alert().accept();       //To give access to Camera
			} catch (Exception e) {
				
			
			}			
			
			
			LanguageScreen languageScreen = new LanguageScreen(driver);     // click on Portuguese 
			languageScreen.click_searchLanguages("Portuguese");
			languageScreen.click_PortugueseLanguage();
			
			 Thread.sleep(2000);
			 
			 MobileElement viewVideoAvailability = (MobileElement) driver.findElement(By.id("selectedVideoOnlyLanguage"));
			 viewVideoAvailability.click();
			 Thread.sleep(2000);
			
			 HoldScreen_Video holdScreen_Video = new HoldScreen_Video(driver);
			 holdScreen_Video.verifyConnectingtoYourInterpreterdDisplayed();
			 holdScreen_Video.click_CancelCall();
			 
			//To RESET the DEVICE
		    Thread.sleep(2000);
		    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
		    
		    
			ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
			resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
			resetDevice.resetDeviceApp();
			Thread.sleep(2000);
	}

}
