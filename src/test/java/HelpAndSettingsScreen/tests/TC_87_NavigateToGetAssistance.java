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
public class TC_87_NavigateToGetAssistance extends BaseTest{

	@Test
	public void NavigateToGetAssistance()  throws InterruptedException {
		
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
		helpAndSettingsLink.ClickGetAssistance();
		System.out.println("Get Assistance page is displayed. After clicking on it, verify the text for the First Question: How Do I Contact LanguageLine?");
		
		helpAndSettingsLink.verifyGetAssistanceContactUs();
		System.out.println("Contact Us at the TOP");
		
		helpAndSettingsLink.clickCloseAtTOP();
		System.out.println("Click Close link at the TOP");
			
		ResetDevice resetDevice = new ResetDevice(driver);             //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
