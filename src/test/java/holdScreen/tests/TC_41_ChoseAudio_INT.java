/**
 * 
 */
package holdScreen.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HoldScreen_Audio;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_41_ChoseAudio_INT extends BaseTest{

	@Test
	public void ChoseAudio_INT() throws InterruptedException {
		
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
	    languageScreen.click_AudioLanguageTileSplit();
	    
	   // MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
	    //MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
	    //el1.click();
	   // el2.click();
	    
	    //verifying all the placeholder values on the screen: Speaker, Mute Button, Call Hangup, Connected label
	    HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
	    holdScreen_Audio.verifyConnectedLabelDisplayed();
	    System.out.println("Connected is displayed");
	    holdScreen_Audio.verifyAudioCallSpeakerButtonDisplayed();
	    System.out.println("Audio Call Speaker Button is displayed");
	    holdScreen_Audio.verifyAudioCallMuteButtonOnDisplayed();
	    System.out.println("Audio Call Mute Button is displayed");
	    holdScreen_Audio.click_AudioCallHangup();
	    System.out.println("Audio Call Hangup Button is displayed");
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
