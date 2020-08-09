/**
 * 
 */
package audioIndicators.tests;

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
 * The indicators should be displayed as:   a.Initializing    b.Connecting   c.Connected
   The mute button should be disabled until call becomes active
 */
public class TC_138_RestrictionNotSet extends BaseTest{  //use kushaltest

	@Test
	public void RestrictionNotSet() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();                      //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                     //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
		LanguageScreen languageScreen = new LanguageScreen(driver);
	    Thread.sleep(2000);
	    
	    languageScreen.click_SpanishLanguage();   
	    MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
		el1.click();
	 
	    //verifying all the placeholder values on the screen: Speaker, Mute Button, Call Hangup, Connected label
		
		holdScreen_Audio.LabelInitializingDisplayed();
		System.out.println("Label Initializing is displayed");
		
		holdScreen_Audio.LabelConnectingDisplayed();     //sometimes displaying of this element is so quick that it doesnt get recognized
		System.out.println("Label Connecting is displayed");
		
		holdScreen_Audio.LabelConnectedDisplayed();
		System.out.println("Label Connected is displayed");
		
	    holdScreen_Audio.verifyAudioCallMuteButtonOnDisplayed();
	    System.out.println("Audio Call Mute Button is displayed");
	    
	    holdScreen_Audio.click_AudioCallHangup();
	    System.out.println("Audio Call Hangup Button is clicked");
	    
	    CallSurveyWindow callSurveyWindow = new CallSurveyWindow(driver);
	    callSurveyWindow.click_Skip();
	    System.out.println("Call Survey Window is displayed and press on Skip button");
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
