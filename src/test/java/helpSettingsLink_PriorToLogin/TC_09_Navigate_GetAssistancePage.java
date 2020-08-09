/**
 * 
 */
package helpSettingsLink_PriorToLogin;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_09_Navigate_GetAssistancePage extends BaseTest{

	@Test
	public void NavigateTo_GetAssistancePage()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.HelpAndSettingsLink_GearIcon();
		
		Thread.sleep(1000);
		loginPage.verifyGetAssistance();
		System.out.println("Get Assistance is displayed");
		Thread.sleep(1000);
		loginPage.GetAssistance_click();
		Thread.sleep(2000);
		System.out.println("Get Assistance page is displayed with Contact Information");
		Thread.sleep(1000);
		System.out.println("Authetication Page is displayed");

	}

}
