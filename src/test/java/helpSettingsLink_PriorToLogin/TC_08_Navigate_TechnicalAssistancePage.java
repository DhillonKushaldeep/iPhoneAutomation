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
public class TC_08_Navigate_TechnicalAssistancePage extends BaseTest{

	@Test
	public void NavigateTo_TechnicalAssistancePage()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.HelpAndSettingsLink_GearIcon();
		
		Thread.sleep(1000);
		loginPage.verifyTechnicalAssistance();
		System.out.println("Technical Assistance is displayed");
		Thread.sleep(1000);
		loginPage.TechnicalAssistance_click();
		Thread.sleep(2000);
		System.out.println("Technical Assistance page is displayed with Questions");
		Thread.sleep(1000);
		System.out.println("Authetication Page is displayed");

	}

}
