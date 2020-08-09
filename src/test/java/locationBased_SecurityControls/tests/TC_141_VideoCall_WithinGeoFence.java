/**
 * 
 */
package locationBased_SecurityControls.tests;

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
 * 1.The "Authorizing Call" message should be displayed.        2.The call should be successfully initiated.             3.The interpreter should receive the call. 
 * 
 */
public class TC_141_VideoCall_WithinGeoFence extends BaseTest{  //Kushaltest

	@Test
	public void VideoCall_WithinGeoFence() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();                      //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                     //To give access to Camera
		} catch (Exception e) {
			
		
		}	
		
		

		LanguageScreen languageScreen = new LanguageScreen(driver);
		Thread.sleep(3000);
		driver.switchTo().alert().accept();                      //To give access to LOCATION
        Thread.sleep(1000);
		languageScreen.click_searchLanguages("Punjabi");
		languageScreen.click_PunjabiLanguage();
		
		Thread.sleep(2000);
	    
		//MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
		MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
		//el1.click();
		el2.click();
		
		Thread.sleep(2000);
		
		/**
		 * The VIDEO call to PUNJABI INTERPRETER is initiated.
		 * The call will go to LINC and will be accepted by the Punjabi Interpreter. 
		 * 
		 */
        
		
		//Verifying that Authorizing is displayed on SCreen when Call gets Initiated
	    
		HoldScreen_Audio holdScreen_Audio = new HoldScreen_Audio(driver);
		holdScreen_Audio.LabelAuthorizingDisplayed();
		System.out.println("Label AUTHORIZING is displayed");
		
		
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);
		

	}

}
