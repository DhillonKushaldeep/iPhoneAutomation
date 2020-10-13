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
		
		loginPage.HelpAndSettingsLink_GearIconAfterLOGIN();
		
		NetworkDiagnostics networkDiagnostics = new NetworkDiagnostics(driver);
		networkDiagnostics.click_NetworkDiagnosticsLink();
		networkDiagnostics.click_RunNetworkDiagnostic();
		System.out.println("Waiting for 30 seconds........");
		TimeUnit.SECONDS.sleep(30);
		
		networkDiagnostics.verifyGreenCheckmark();
		networkDiagnostics.clickClose();
		
		//To RESET the DEVICE
	    Thread.sleep(2000);
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
