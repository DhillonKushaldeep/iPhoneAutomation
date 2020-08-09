/**
 * 
 */
package audio_VideoAuthorization.tests;

import static org.testng.Assert.assertEquals;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HoldScreen_Video;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_73_CallRouting_Audio_NotAvailable extends BaseTest{

	@Test
	public void CallRouting_Audio_NotAvailable() throws InterruptedException {
			
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
			 holdScreen_Video.verifyLoadingSpinnerDisplayed();
			 holdScreen_Video.verifyConnectingtoYourInterpreterdDisplayed();
			 
			 // Sorry, we are currently unable to connect to your Portuguese video interpreter at this time.
			 
			 MobileElement element = (MobileElement) driver.findElementByAccessibilityId("Sorry, we are currently unable to connect to your Portuguese video interpreter at this time.");
				
			String message = element.getText();
			String SucessMessage = "Sorry, we are currently unable to connect to your Portuguese video interpreter at this time.";	                   
								 
			assertEquals(message, SucessMessage);					
			Thread.sleep(5000);	
				
				
			 holdScreen_Video.click_CancelCall();
			 
		    
		     ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
			 resetDevice.resetDeviceApp();
			 Thread.sleep(2000);

	}

}
