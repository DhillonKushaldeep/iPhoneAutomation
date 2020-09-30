/**
 * 
 */
package callHistorySettings.tests;

import java.util.Collections;
import java.util.List;

import org.junit.Assert;
import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.HelpAndSettingsLink;
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
public class TC_102_Sorting_ByDuration extends BaseTest{

	@Test
	public void Sorting_ByDuration() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();                      //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                      //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		
		HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
		LanguageScreen languageScreen = new LanguageScreen(driver);
		Thread.sleep(2000);
		
		//add code to click on some languages for calling because only then we will verify the call history
		
		languageScreen.click_SpanishLanguage();                                                 //click SPANISH 
		MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
		el1.click();
		Thread.sleep(4000);
		// holdScreen_Audio.click_AudioCallHangup();  
		 
	    holdScreen_Audio.click_AudioCancelCall();
		System.out.println("Audio Call Hangup Button is clicked to END the SPANISH Call");
		//callSurveyWindow.click_Skip();      //To Skip the Survey Window
		
		languageScreen.click_Vietnamese();                                             //click VIETNAMESE
		MobileElement el3 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
		el3.click();
		Thread.sleep(1000);
		// holdScreen_Audio.click_AudioCallHangup();  
		 
	    holdScreen_Audio.click_AudioCancelCall();
		Thread.sleep(2000);
		System.out.println("Audio Call Hangup Button is clicked to END the VIETNAMESE Call");
		//callSurveyWindow.click_Skip();      //To Skip the Survey Window
		
		languageScreen.clickCantonese();                                                     //click CANTONESE
		MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
		el2.click();
		Thread.sleep(4000);
		// holdScreen_Audio.click_AudioCallHangup();  
		 
	    holdScreen_Audio.click_AudioCancelCall();
		System.out.println("Audio Call Hangup Button is clicked to END the CANTONESE Call");
		Thread.sleep(2000);
		//callSurveyWindow.click_Skip();      //To Skip the Survey Window
		
		
	
		languageScreen.click_GearIconAtTOP(); 
		
		HelpAndSettingsLink helpAndSettingsLink = new HelpAndSettingsLink(driver);
		Thread.sleep(2000);
		//helpAndSettingsLink.clickCallHistory();  ///not able to click here
		Thread.sleep(2000);
		
		
		
		List<String> history2 = helpAndSettingsLink.captureDurationLog();		//DURATION
		List<String> beforeSorted2 = history2;  
		Thread.sleep(2000); 	
	
		Collections.sort(history2,  Collections.reverseOrder());
		Assert.assertEquals(history2, beforeSorted2);
		System.out.println(history2);
		System.out.println(beforeSorted2);
		
		
		
		helpAndSettingsLink.clickCallHistoryBackButton();  //click back at TOP 
		
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
