/**
 * 
 */
package deviceFeatures.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.HelpAndSettingsLink;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_113_LogoDisplayed extends BaseTest{

	@Test
	public void LogoDisplayed() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.verifyLogo_isPresentBeforeLogin();
		System.out.println("Langugae Line LOGO is present before Login");
		
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();   //To give access to Camera
		} catch (Exception e) {
			
		
		}			
			
		LanguageScreen languageScreen = new LanguageScreen(driver);
		languageScreen.verifyLogo_isPresentHomePage();
		System.out.println("Language Line LOGO is present on HomePage");
        languageScreen.click_GearIconAtTOP(); 
		
		HelpAndSettingsLink helpAndSettingsLink = new HelpAndSettingsLink(driver);
		
		//add code help setting page logo
		helpAndSettingsLink.verifyLogo_isPresent_HelpSettingsPage();
		System.out.println("Language Line LOGO is present on Help and Settings Page");
		
		//add code for after we click on device login, we see the logo   
		//after that click on return to help settings link to go back to main help setting page
		helpAndSettingsLink.click_DeviceLogin();
		helpAndSettingsLink.verifyLogo_isPresent_DeviceLoginPage();
		System.out.println("Language Line LOGO is present on Device Login Page");
		helpAndSettingsLink.click_ReturnToHelpAndSettings();
		
		//click on technical assistance..verify the logo and click on CLOSE
		helpAndSettingsLink.ClickTechnicalAssistance();
		helpAndSettingsLink.verifyLogo_isPresent_TechnicalAssistancePage();
		System.out.println("Language Line LOGO is present on Technical Assistance page");
		helpAndSettingsLink.clickCloseAtTOP();
		
		//Click on video availability verify logo and then click on close
		helpAndSettingsLink.clickVideoAvailability();
		helpAndSettingsLink.verifyLogo_isPresent_VideoAvailabilityPage();
		System.out.println("Language Line LOGO is present on Video Availability Page");
		helpAndSettingsLink.clickVideoAvailability_Close();
		
		//click on get assistance verify logo and click on close
		helpAndSettingsLink.ClickGetAssistance();
		helpAndSettingsLink.verifyLogo_isPresent_GetAssistancePage();
		System.out.println("Language Line LOGO is present on Get Assistance Page");
		helpAndSettingsLink.clickCloseAtTOP();
		
		//click on call history verify logo and hit back
		helpAndSettingsLink.clickCallHistory();
		helpAndSettingsLink.verifyLogo_isPresent_CallHistoryPage();
		System.out.println("Language Line LOGO is present on Call History Page");
		helpAndSettingsLink.click_Back();
		
		//click on network diagnostic verify logo click back
		helpAndSettingsLink.click_NetworkDiagnosticsLink();
		helpAndSettingsLink.verifyLogo_isPresent_NetworkDiagnosticsPage();
		System.out.println("Language Line LOGO is present on Network Diagnostics Page");
		helpAndSettingsLink.click_Back();
		
		
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
