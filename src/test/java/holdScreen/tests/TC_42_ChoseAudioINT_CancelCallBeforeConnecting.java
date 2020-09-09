/**
 * 
 */
package holdScreen.tests;

import org.openqa.selenium.WebElement;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HoldScreen_Audio;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileBy;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_42_ChoseAudioINT_CancelCallBeforeConnecting extends BaseTest{

	@Test
	public void ChoseAudioINT_CancelCallBeforeConnecting() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();                      //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                     //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		LanguageScreen languageScreen = new LanguageScreen(driver);
		languageScreen.verify_TopLanguages();
	    Thread.sleep(2000);
	    languageScreen.click_SpanishLanguage();   
	    
	    WebElement el = driver.findElement(MobileBy.AccessibilityId("selectedAudioLanguage")); //clicking on the AUDIO TILE
	    el.click();
	    
	    HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
	    Thread.sleep(2000);
	    holdScreen_Audio.click_AudioCancelCall();
	    System.out.println("Cancel Call Button is displayed and is clicked to end the call");
	    
	    
	    //To RESET the DEVICE
	    Thread.sleep(2000);
	    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);


	}

}
