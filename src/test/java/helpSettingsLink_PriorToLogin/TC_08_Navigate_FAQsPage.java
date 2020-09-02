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
public class TC_08_Navigate_FAQsPage extends BaseTest{

	@Test
	public void NavigateTo_TechnicalAssistancePage()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.HelpAndSettingsLink_GearIcon();
		
		Thread.sleep(1000);
		loginPage.verifyFreqAskedQues();      //Frequently asked questions
		Thread.sleep(1000);
		loginPage.clickFreqAskedQuestions();   //click on Frequently asked questions
		Thread.sleep(2000);
		loginPage.verifyHeader_FAQ();            //FAQ
		loginPage.clickCloseAtTOP();    //CLOSE at TOP
		
		
		Thread.sleep(1000);
		loginPage.clickBack();
		
		loginPage.verifyAuthenticateYourDevicePresent();     //Authenticate your Device
		

	}

}
