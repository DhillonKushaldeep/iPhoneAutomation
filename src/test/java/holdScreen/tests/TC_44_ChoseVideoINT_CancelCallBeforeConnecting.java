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
public class TC_44_ChoseVideoINT_CancelCallBeforeConnecting extends BaseTest{

	@Test
	public void ChoseVideoINT_CancelCallBeforeConnecting() throws InterruptedException {
		
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
	    
	    //verifying all the placeholder values on the screen: Speaker, Mute Button, Call Hangup, Connected label
	    HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
	    holdScreen_Audio.click_AudioCallHangup();
	    System.out.println("The interpreter request call should be disconnected.");
	    Thread.sleep(2000);
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);


	}

}
