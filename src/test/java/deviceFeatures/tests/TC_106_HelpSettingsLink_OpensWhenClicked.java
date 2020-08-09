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
public class TC_106_HelpSettingsLink_OpensWhenClicked extends BaseTest{

	@Test
	public void HelpSettingsLink_OpensWhenClicked() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.HelpAndSettingsLink_GearIcon();
		System.out.println("Help and Settings Link is displayed and is clickable");
		Thread.sleep(1000);
			
		loginPage.clickBack();
		System.out.println("Authetication Page is displayed");

	}

}
