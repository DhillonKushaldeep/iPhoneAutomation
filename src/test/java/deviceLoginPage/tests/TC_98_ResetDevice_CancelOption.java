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
public class TC_98_ResetDevice_CancelOption extends BaseTest{

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
		loginPage1.HelpAndSettingsLink_GearIconAfterLOGIN();
		
		
		HelpAndSettingsLink  helpAndSettingsLink = new HelpAndSettingsLink(driver);
		helpAndSettingsLink.click_DeviceLogin();
		Thread.sleep(2000);
        
		ResetDevice resetDevice = new ResetDevice(driver);              //Reset Device --> Reset/Cancel --> Cancel 
		resetDevice.resetDevice_changeCode();
		Thread.sleep(2000);
		resetDevice.resetDevice_clickCancel();
		
		HelpAndSettingsLink  helpAndSettingsLink1 = new HelpAndSettingsLink(driver);
		helpAndSettingsLink1.clickHelpAndSettingsLink_TOP();
        
		
		//To RESET the DEVICE
	    Thread.sleep(2000);
		ResetDevice resetDevice1 = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice1.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice1.resetDeviceApp();
		Thread.sleep(2000);
		
	}

}
