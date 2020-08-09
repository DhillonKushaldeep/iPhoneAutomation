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
public class TC_36_SearchLanguage_SWI extends BaseTest {

	@Test
	public void SearchLanguage_SWI() throws InterruptedException {
		
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
	    languageScreen.click_searchLanguages("SWI");
	    Thread.sleep(2000);
	    languageScreen.verify_LanguageDisplayed_BySeaching_forSWI();    //verify that SWI languages(French, German) are displayed in dropdown when we enter SWI in search box    
	    Thread.sleep(2000);
	    
		ResetDevice resetDevice = new ResetDevice(driver);               //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
