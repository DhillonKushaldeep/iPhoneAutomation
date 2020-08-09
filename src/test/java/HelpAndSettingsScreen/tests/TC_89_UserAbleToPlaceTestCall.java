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
public class TC_89_UserAbleToPlaceTestCall extends BaseTest{

	@Test
	public void UserAbleToPlaceTestCall()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");
		driver.switchTo().alert().accept();                //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                //To give access to Camera
		} catch (Exception e) {
			
		
		}		
		
		loginPage.HelpAndSettingsLink_GearIcon();           
		
		HelpAndSettingsLink helpAndSettingsLink = new HelpAndSettingsLink(driver);
		helpAndSettingsLink.clickPlaceTestCall();
		System.out.println("Click on Place Test Call");
		
		helpAndSettingsLink.clickPlaceTestCall();
		Thread.sleep(2000);
		helpAndSettingsLink.verifySmallVideoScreen();
		System.out.println("Verify Small Video Screen at the Top Corner");
		helpAndSettingsLink.verifyTestVideoDisplay();
		System.out.println("Verify TestVideo text is Displayed ");
		helpAndSettingsLink.clickVideoHangupButton();
		System.out.println("Click on Video Hangup Button");
			
		ResetDevice resetDevice = new ResetDevice(driver);             //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
