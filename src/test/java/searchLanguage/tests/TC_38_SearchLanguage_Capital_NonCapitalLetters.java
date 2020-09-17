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
 * @author KushaldeepDhillon
 *
 */
public class TC_38_SearchLanguage_Capital_NonCapitalLetters extends BaseTest {

	@Test
	public void SearchLanguage_CapitalNonCapitalLetters() throws InterruptedException {
		
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
	    languageScreen.click_searchLanguages("SPANISH");
	    Thread.sleep(2000);
	    languageScreen.searchFor_LanguagesTypedInSearchBox();    //verify that SPANISH language is displayed in dropdown when we enter SPANISH in search box    
	    Thread.sleep(2000);
	    
	    languageScreen.click_searchLanguages("Spanish");
	    languageScreen.searchFor_LanguagesTypedInSearchBox();    //verify that Spanish language is displayed in dropdown when we enter Spanish in search box   
				
	    //To RESET the DEVICE
	    Thread.sleep(2000);
	    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
