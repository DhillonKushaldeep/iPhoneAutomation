/**
 * 
 */
package holdScreen.tests;

import static org.testng.Assert.assertEquals;

import org.openqa.selenium.WebElement;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HoldScreen_Video;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileBy;
import io.appium.java_client.MobileElement;

/**
 * @author kushal
 *
 */
public class TC_45_VideoLang_NoVideoINTLogged extends BaseTest{

	@Test
	public void VideoLang_NoVideoINTLogged() throws InterruptedException {
		
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
	    languageScreen.click_searchLanguages("Punjabi");
	    Thread.sleep(2000);
	    languageScreen.click_PunjabiLanguage();  
	    
	    WebElement el = driver.findElement(MobileBy.AccessibilityId("selectedVideoLanguage")); //clicking on the VIDEO TILE
	    el.click();
	    
	    
	    HoldScreen_Video holdScreen_Video = new HoldScreen_Video(driver);
	    holdScreen_Video.verifysorryNoVideoINTavailableMessageDisplayed();
	    System.out.println("Sorry, we are currently unable to connect to your video interpreter at this time. "
	    		         + "Please try again later or switch to an audio interpreter immediately.");
		
		
	    holdScreen_Video.click_CancelVideoCall();
	    System.out.println("Clicked on Cancel Video call successfully");
	    Thread.sleep(2000);
	    
	    
	    //To RESET the DEVICE
	    Thread.sleep(2000);
	    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);


	}

}
