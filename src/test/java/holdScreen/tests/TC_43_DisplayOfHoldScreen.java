/**
 * 
 */
package holdScreen.tests;

import org.openqa.selenium.WebElement;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HoldScreen_Video;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileBy;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_43_DisplayOfHoldScreen extends BaseTest{

	@Test
	public void DisplayOfHoldScreen() throws InterruptedException {
		
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
	    languageScreen.click_searchLanguages("French");
	    Thread.sleep(2000);
	    languageScreen.click_FrenchLanguageAfterSearch(); 
	    
	    WebElement el = driver.findElement(MobileBy.AccessibilityId("selectedVideoLanguage")); //clicking on the VIDEO TILE
	    el.click();
	    
	    
	    HoldScreen_Video holdScreen_Video = new HoldScreen_Video(driver);
	    holdScreen_Video.verifyConnectingtoYourInterpreterdDisplayed();
	    System.out.println("Connecting to Your Interpreter is displayed");
	    holdScreen_Video.click_CancelCall();
	    System.out.println("Clicked on Cancel call successfully");
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
