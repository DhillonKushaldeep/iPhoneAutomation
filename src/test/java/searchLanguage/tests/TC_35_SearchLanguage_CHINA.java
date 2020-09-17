/**
 * 
 */
package searchLanguage.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_35_SearchLanguage_CHINA extends BaseTest {

	@Test
	public void SearchLanguage_CHINA() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();       //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		
		LanguageScreen languageScreen = new LanguageScreen(driver);
		languageScreen.verify_TopLanguages();
	    Thread.sleep(2000);
	    languageScreen.click_searchLanguages("CHINA");
	    Thread.sleep(2000);
	    languageScreen.searchFor_LanguagesTypedInSearchBox();    //verify that Chinese languages(Cantonese, Chaochow) are displayed in dropdown when we enter CHINA in search box    
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
