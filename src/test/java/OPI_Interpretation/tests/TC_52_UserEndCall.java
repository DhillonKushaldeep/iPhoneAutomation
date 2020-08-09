/**
 * 
 */
package OPI_Interpretation.tests;

import java.util.concurrent.TimeUnit;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HoldScreen_Audio;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_52_UserEndCall extends BaseTest{

	@Test
	public void UserEndCall() throws InterruptedException {
		
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
	    
	    languageScreen.click_AudioFrenchLanguage();     
	    languageScreen.click_AudioLanguageTileSplit();
	    
	 
	    //verifying all the placeholder values on the screen: Speaker, Mute Button, Call Hangup, Connected label
	    HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
	    holdScreen_Audio.verifyConnectedLabelDisplayed();
	    System.out.println("Connected is displayed");
	    TimeUnit.SECONDS.sleep(2);
	    
	    
	    holdScreen_Audio.click_AudioCallHangup();
	    System.out.println("Audio Call Hangup Button is displayed");
	    TimeUnit.SECONDS.sleep(2);
	    
	    LanguageScreen languageScreen1 = new LanguageScreen(driver);
	    languageScreen1.verify_AllLanguages();
	    languageScreen1.verify_TopLanguages();
	    System.out.println("All Languages and Top Languages are displayed at the Top in the header");
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
