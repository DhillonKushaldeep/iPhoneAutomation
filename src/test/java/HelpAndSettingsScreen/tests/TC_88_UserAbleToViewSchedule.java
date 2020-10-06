/**
 * 
 */
package HelpAndSettingsScreen.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HelpAndSettingsLink;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_88_UserAbleToViewSchedule extends BaseTest{

	@Test
	public void UserAbleToViewSchedule()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");
		driver.switchTo().alert().accept();                //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                //To give access to Camera
		} catch (Exception e) {
			
		
		}		
		
		loginPage.HelpAndSettingsLink_GearIconAfterLOGIN();           
		
		HelpAndSettingsLink helpAndSettingsLink = new HelpAndSettingsLink(driver); //Video Interpreter Availability
		helpAndSettingsLink.clickVideoAvailability();
		
		helpAndSettingsLink.verifyVideoAvailability_Language();
		helpAndSettingsLink.verifyVideoAvailability_LanguageAlbanian();
		helpAndSettingsLink.verifyVideoAvailability_LanguageASL();
		
		helpAndSettingsLink.clickVideoAvailability_Close();
		
			
		//To RESET the DEVICE
	    Thread.sleep(2000);
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
