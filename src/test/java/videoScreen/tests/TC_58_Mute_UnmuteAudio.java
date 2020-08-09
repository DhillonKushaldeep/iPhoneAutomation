/**
 * 
 */
package videoScreen.tests;

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
 * @author kushaldeepdhillon
 * 
 *The audio of the customer should be muted.
 *The audio should be back up when the customer releases the mute.
 *
 */
public class TC_58_Mute_UnmuteAudio extends BaseTest{

	@Test
	public void Mute_UnmuteAudio() throws InterruptedException {
		
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
	    
	   // MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
	    MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
	    //el1.click();
	     el2.click();
	    
	    Connected_VideoScreen connected_VideoScreen = new Connected_VideoScreen(driver);
	    connected_VideoScreen.verifyAudioMuteON_isPresent();
	    System.out.println("Audio Mute is ON and is displayed");
	    connected_VideoScreen.click_AudioMuteON();
	    
	    connected_VideoScreen.verifyAudioMuteOFF_isPresent();
	    System.out.println("Audio Mute is OFF and is displayed");
	    connected_VideoScreen.click_AudioMuteOFF();
	    Thread.sleep(1000);
	    connected_VideoScreen.click_CallEnd();
	    Thread.sleep(1000);
	    
	    CallSurveyWindow callSurveyWindow = new CallSurveyWindow(driver);
	    callSurveyWindow.verifyCallEndedIconDisplayed();
	    callSurveyWindow.click_Skip();
	    System.out.println("Call Survey Window is displayed and press on Skip button");
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
