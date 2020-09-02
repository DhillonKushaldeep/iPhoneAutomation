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
public class TC_09_Navigate_ContactUsPage extends BaseTest{

	@Test
	public void Navigate_ContactUsPage()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.HelpAndSettingsLink_GearIcon();
		
		Thread.sleep(1000);
		loginPage.clickContactUs();
		loginPage.verifyHeader_ContactUs();
		
        loginPage.clickCloseAtTOP();    //CLOSE at TOP
		
		
		Thread.sleep(1000);
		loginPage.clickBack();
		
		loginPage.verifyAuthenticateYourDevicePresent();     //Authenticate your Device
		

	}

}
