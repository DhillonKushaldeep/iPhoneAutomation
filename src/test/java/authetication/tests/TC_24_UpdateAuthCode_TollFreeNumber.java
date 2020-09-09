/**
 * 
 */
package authetication.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_24_UpdateAuthCode_TollFreeNumber extends BaseTest{

	@Test
	public void UpdateAuthCode_TollFreeNumber()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("8312345678", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();   //To give access to Camera
		} catch (Exception e) {
			
		
		}		
		
		LanguageScreen languageScreen = new LanguageScreen(driver);
		languageScreen.verify_TopLanguages();               //successful authentication verified "TOP Languages" at TOP being displayed. 
	    Thread.sleep(2000);
				
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.settingSymbolAtTop_click();
		Thread.sleep(2000);
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);
		

	}

}
