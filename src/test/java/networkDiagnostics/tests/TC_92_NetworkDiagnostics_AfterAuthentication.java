/**
 * 
 */
package networkDiagnostics.tests;

import java.util.concurrent.TimeUnit;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.NetworkDiagnostics;
import com.appium.pages.ResetDevice;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_92_NetworkDiagnostics_AfterAuthentication extends BaseTest{

	@Test
	public void NetworkDiagnostics_AfterAuthentication() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();      //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		
		LanguageScreen languageScreen = new LanguageScreen(driver);
		Thread.sleep(2000);
		languageScreen.click_HelpAndSettingsLink_GearIcon();
		
		NetworkDiagnostics networkDiagnostics = new NetworkDiagnostics(driver);
		networkDiagnostics.click_NetworkDiagnosticsLink();
		networkDiagnostics.click_RunNetworkDiagnostic();
		TimeUnit.SECONDS.sleep(30);
		networkDiagnostics.verifyGreenCheckmark();
		System.out.println("Test Complete is displayed Successfully");
		
				
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.clickBack();
		resetDevice.DeviceLoginresetDeviceApp();
		Thread.sleep(2000);

	}

}
