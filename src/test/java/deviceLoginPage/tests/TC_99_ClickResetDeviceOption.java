/**
 * 
 */
package deviceLoginPage.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HelpAndSettingsLink;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_99_ClickResetDeviceOption extends BaseTest{

	@Test
	public void ResetDevice_CancelOption()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();      //To give access to Camera
		} catch (Exception e) {
			
		
		}	
		
		LoginPage loginPage1 = new LoginPage(driver);
		loginPage1.HelpAndSettingsLink_GearIcon();
		
		
		HelpAndSettingsLink  helpAndSettingsLink = new HelpAndSettingsLink(driver);
		helpAndSettingsLink.click_DeviceLogin();
		Thread.sleep(2000);
		
		
		ResetDevice resetDevice1 = new ResetDevice(driver);              //Reset Device --> Reset/Cancel --> Reset 
		resetDevice1.resetDevice_clickReset();
		Thread.sleep(2000);
		
		loginPage1.verifyLoginInfoPresent();
		System.out.println("Auth code, Device name, Activate Device is displayed. Hence, we logged out successfully");
	}

}
