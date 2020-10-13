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
 * @author KushaldeepDhillon
 *
 */
public class TC_95_VerifyAuthenticationDetails extends BaseTest{

	@Test
	public void VerifyAuthenticationDetails()  throws InterruptedException {
		
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
		helpAndSettingsLink.verifyActivationCode();
		Thread.sleep(1000);
		helpAndSettingsLink.verifyLastActivated();
		Thread.sleep(1000);
		
		MobileElement element1 = (MobileElement) driver.findElementByAccessibilityId("activationCode");
		String message1 = element1.getText();
		System.out.println("Authentication Code:  " + message1);
		
		MobileElement element = (MobileElement) driver.findElementByAccessibilityId("lastActivated");
		String message = element.getText();
		System.out.println("Activated on:  " + message);
				
		//To RESET the DEVICE
	    Thread.sleep(2000);
		ResetDevice resetDevice = new ResetDevice(driver);   //Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);
		
	}

}
