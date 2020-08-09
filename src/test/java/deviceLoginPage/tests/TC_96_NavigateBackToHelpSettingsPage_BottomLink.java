/**
 * 
 */
package deviceLoginPage.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HelpAndSettingsLink;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_96_NavigateBackToHelpSettingsPage_BottomLink extends BaseTest{

	@Test
	public void NavigateBackToHelpSettingsPage_BottomLink()  throws InterruptedException {
		
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
		helpAndSettingsLink.clickHelpAndSettingsLink_BOTTOM();
		helpAndSettingsLink.verifyHelpAndSettingsTextAtTOP();
        
				
		ResetDevice resetDevice = new ResetDevice(driver);              //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();
		Thread.sleep(2000);
	}

}
