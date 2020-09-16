/**
 * 
 */
package helpSettingsLink_PriorToLogin;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LoginPage;

/**
 * @author Kushaldeep Dhillon
 *
 */
public class TC_10_Display_VersionNumber extends BaseTest{

	@Test
	public void Display_VersionNumber()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.HelpAndSettingsLink_GearIcon();
		
		Thread.sleep(1000);
		loginPage.verifyVersion();       //JIRA raised to update the locator
		Thread.sleep(1000);
	

	}

}
