/**
 * 
 */
package deviceFeatures.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LoginPage;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_105_HelpSettingsPageDisplayed extends BaseTest{

	@Test
	public void HelpSettingsPageDisplayed() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.verifyHelpAndSettingsLink_GearIconDisplayed();
		System.out.println("Help and Settings Link is displayed at TOP");
		Thread.sleep(1000);

	}

}
