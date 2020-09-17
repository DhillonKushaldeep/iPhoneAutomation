/**
 * 
 */
package searchLanguage.tests;

import static org.testng.Assert.assertEquals;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_40_AlertMessage_NoLanguageMatchYourSearch extends BaseTest {

		@Test
		public void AlertMessage_NoLanguageMatchYourSearch() throws InterruptedException {
		
			LoginPage loginPage = new LoginPage(driver);
			loginPage.loginInApp("kushaltest", "test");	
			driver.switchTo().alert().accept();        //To give access to MicroPhone
	        Thread.sleep(2000);
			
			try {
				
			driver.switchTo().alert().accept();       //To give access to Camera
			} catch (Exception e) {
				
			
			}			
			
			
			LanguageScreen languageScreen = new LanguageScreen(driver);
		    Thread.sleep(2000);
		    languageScreen.click_searchLanguages("hhhjj");
		    Thread.sleep(2000);
		    languageScreen.verify_AlertMessageDisplayed();       //verify that ALERTMESSAGE is displayed in dropdown when we enter hhhjj in search box     
		    Thread.sleep(2000);
		    
		    MobileElement element = (MobileElement) driver.findElementByAccessibilityId("noSearchResults");
		    String message = element.getText();
			String SucessMessage = "No languages match your search. Please double check your entry.";	                   
							 
		    assertEquals(message, SucessMessage);					
			Thread.sleep(5000);	
					
			//To RESET the DEVICE
		    Thread.sleep(2000);
		    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
		    
		    
			ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
			resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
			resetDevice.resetDeviceApp();
			Thread.sleep(2000);

	}

}
