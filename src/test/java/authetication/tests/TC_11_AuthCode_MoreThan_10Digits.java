/**
 * 
 */
package authetication.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author KushaldeepDhillon
 * 
 * TC_11 and TC_12 are combined in one script. 
 * Authentication code - Digits more than the allowed length    (Note: authentication Code length is 10 digits)
 * Device name field -   Digits more than the allowed length    (Note: Device name maximum length is 15 Digits)
 */

public class TC_11_AuthCode_MoreThan_10Digits extends BaseTest{

	@Test
	public void AuthCode_MoreThan_10Digits()  throws InterruptedException{
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest12345", "test1234567890");	
		driver.switchTo().alert().accept();                   //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                 //To give access to Camera
		} catch (Exception e) {			
		
		}			
				
		
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Change Code --> Reset/Cancel --> Reset 
		resetDevice.settingSymbolAtTop_click();
		resetDevice.resetDeviceApp();
		//resetDevice.resetDevice_changeCode();
		//resetDevice.resetDevice_clickReset();
		
	
		
	}

}
