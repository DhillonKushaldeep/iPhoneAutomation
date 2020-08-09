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
 * The call should be successfully initiated and connected to the interpreter
 *
 */
public class TC_142_VideoCall_WithinNetworkRestriction extends BaseTest{  //Authcod139

	@Test
	public void VideoCall_WithinNetworkRestriction () throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("Authcod139", "test");	
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
        
		
		
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);
	}

}
