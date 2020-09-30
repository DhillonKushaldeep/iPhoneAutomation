/**
 * 
 */
package OPI_Interpretation.tests;

import org.openqa.selenium.WebElement;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HoldScreen_Audio;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileBy;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_48_CancelCallBeforeConnecting extends BaseTest{

	@Test
	public void CancelCallBeforeConnecting() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();                      //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                     //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		LanguageScreen languageScreen = new LanguageScreen(driver);
	    Thread.sleep(2000);
	    languageScreen.verify_TopLanguages();
	    Thread.sleep(2000);
	    languageScreen.click_SpanishLanguage();   
	    
	    WebElement el = driver.findElement(MobileBy.AccessibilityId("selectedAudioLanguage")); //clicking on the AUDIO TILE
	    el.click();
	    
	 
	    //verifying all the placeholder values on the screen: Cancel Call, Connecting label
	    HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
	    holdScreen_Audio.verifyConnectingToIntLabelDisplayed();
	    System.out.println("Connecting to interpreter is displayed");
	    holdScreen_Audio.click_AudioCancelCall();
	    System.out.println("Audio Cancel Call Button is displayed");
	    
	    
	  //To RESET the DEVICE
	    Thread.sleep(2000);
	    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
