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
public class TC_07_Navigate_HelpSettingsPage extends BaseTest{

	@Test
	public void NavigateTo_HelpSettingsPage()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.HelpAndSettingsLink_GearIcon();
		
		Thread.sleep(1000);
		loginPage.verifyTechnicalAssistance();
		System.out.println("Technical Assistance is displayed");
		
		Thread.sleep(1000);
		loginPage.verifyGetAssistance();
		System.out.println("Get Assistance is displayed");
		
		Thread.sleep(1000);
		loginPage.verifyVersion();    //code for version number
			
		
		
		
		Thread.sleep(1000);
		loginPage.clickBack();
		System.out.println("Authetication Page is displayed");
		
				
		

	}

}
