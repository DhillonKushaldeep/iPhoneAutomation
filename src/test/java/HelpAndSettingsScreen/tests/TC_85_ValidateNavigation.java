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
public class TC_85_ValidateNavigation extends BaseTest{

	@Test
	public void ValidateNavigation()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();   //To give access to Camera
		} catch (Exception e) {
			
		
		}		
		
		loginPage.HelpAndSettingsLink_GearIcon();
		
		HelpAndSettingsLink helpAndSettingsLink = new HelpAndSettingsLink(driver);
		helpAndSettingsLink.verifyDeviceLogin();
		System.out.println("Device Login is displayed");
		
		helpAndSettingsLink.verifyTechnicalAssistance();
		System.out.println("Technical Assistance is displayed");
		
		helpAndSettingsLink.verifyVideoAvailability();
		System.out.println("Video Availability is displayed");
		
		helpAndSettingsLink.verifyGetAssistance();
		System.out.println("GetAssistance is displayed");
		
		helpAndSettingsLink.verifyCallHistory();
		System.out.println("Call History is displayed");
		
		helpAndSettingsLink.verifyNetworkDiagnostics();
		System.out.println("Network Diagnostics is displayed");
		
		helpAndSettingsLink.verifyPlaceTestCall();
		System.out.println("Place Test Call is displayed");
		
				
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);
		
	}

}
