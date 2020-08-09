/**
 * 
 */
package audio_VideoAuthorization.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HoldScreen_Audio;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_70_DisplayOfAudio extends BaseTest{

	@Test
	public void DisplayOfAudio() throws InterruptedException {
			
			LoginPage loginPage = new LoginPage(driver);
			loginPage.loginInApp("kushaltest", "test");	
			driver.switchTo().alert().accept();        //To give access to MicroPhone
	        Thread.sleep(2000);
			
			try {
				
			driver.switchTo().alert().accept();       //To give access to Camera
			} catch (Exception e) {
				
			
			}			
			
			
			LanguageScreen languageScreen = new LanguageScreen(driver);     // click on French 
			languageScreen.click_searchLanguages("French");
			languageScreen.clickFrenchLanguage();
			
			 Thread.sleep(2000);
			    
			 MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
			 //MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
			 el1.click();
			 //el2.click();
			
			 HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
			 holdScreen_Audio.verifyAudioCallSpeakerButtonDisplayed();
			 holdScreen_Audio.verifyConnectedLabelDisplayed();
			 holdScreen_Audio.click_AudioCallHangup();
			 
			 //Call does not get connected to the Interpreter in this span of time, so no need of this code for Call Survey Window
			 
			/* 
			 CallSurveyWindow callSurveyWindow = new CallSurveyWindow(driver);
			 callSurveyWindow.verifyCallEndedIconDisplayed();
			 callSurveyWindow.click_Skip();
			 System.out.println("Call Survey Window is displayed and press on Skip button");*/
			 
			    
		     ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
			 resetDevice.resetDeviceApp();
			 Thread.sleep(2000);

	}

}
