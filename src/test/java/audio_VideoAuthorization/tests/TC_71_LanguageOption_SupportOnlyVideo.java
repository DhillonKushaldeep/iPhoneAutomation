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
			    
			 //MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
			 //MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
			 //el1.click();
			 //el2.click();
			
			 HoldScreen_Video holdScreen_Video = new HoldScreen_Video(driver);
			 holdScreen_Video.verifyConnectingtoYourInterpreterdDisplayed();
			 holdScreen_Video.click_CancelCall();
			 
			 
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
