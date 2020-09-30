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
 * @author KushaldeepDhillon
 *
 */
public class TC_72_VerifyCallRouting extends BaseTest{

	@Test
	public void VerifyCallRouting() throws InterruptedException {
			
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
			
			 HoldScreen_Video holdScreen_Video = new HoldScreen_Video(driver);
			 holdScreen_Video.verifyLoadingSpinnerDisplayed();
			 holdScreen_Video.verifyConnectingtoYourInterpreterdDisplayed();
			 
			 //  Connecting to your Portuguese Interpreter
			 MobileElement element =  (MobileElement) driver.findElementByAccessibilityId("labelConnecting");      //Connecting to Your
			 MobileElement element1 = (MobileElement) driver.findElementByAccessibilityId("labelWaiting");        //	Portuguese
			 MobileElement element2 = (MobileElement) driver.findElementByAccessibilityId("labelInterpreter");    //Interpreter
				
			 String message = element.getText();
			 String message1 = element1.getText();
			 String message2 = element2.getText();
			 
			 String SucessMessage  = "Connecting to Your";	 
			 String SucessMessage1 = "Portuguese";
			 String SucessMessage2 = "Interpreter";
								 
			 assertEquals(message,  SucessMessage);	
			 assertEquals(message1, SucessMessage1);
			 assertEquals(message2, SucessMessage2);
			 Thread.sleep(5000);	
				
			 holdScreen_Video.click_CancelCall();
			 
			//To RESET the DEVICE
		    Thread.sleep(2000);
		    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
		    
		    
			ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
			resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
			resetDevice.resetDeviceApp();
			Thread.sleep(2000);

	}

}
