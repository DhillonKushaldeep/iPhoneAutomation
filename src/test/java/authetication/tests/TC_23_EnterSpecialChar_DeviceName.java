/**
 * 
 */
package authetication.tests;

import static com.appium.locator.ResetDeviceUI.ResetDeviceActivation_RESET;
import static com.appium.locator.ResetDeviceUI.ResetDeviceButton;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_23_EnterSpecialChar_DeviceName extends BaseTest{

	@Test
	public void EnterSpecialChar_DeviceName()  throws InterruptedException {
	
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "Julia's iPhone");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();       //To give access to Camera
		} catch (Exception e) {			
		
		}	
		
		ResetDevice resetDevice = new ResetDevice(driver); // Setting Symbol at TOP --> Device Login 
		resetDevice.settingSymbolAtTop_click();
		Thread.sleep(2000);
		
        MobileElement element = (MobileElement) driver.findElementByAccessibilityId("lastActivated");
		
		String message = element.getText();
		System.out.println(message);					
		Thread.sleep(5000);
		
		ResetDevice resetDevice1 = new ResetDevice(driver); //Reset Device --> Reset/Cancel --> Reset 
		resetDevice1.resetDevice_clickReset();
		Thread.sleep(2000);

	}

}
