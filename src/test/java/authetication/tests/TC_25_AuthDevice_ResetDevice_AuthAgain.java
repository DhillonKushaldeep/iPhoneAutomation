/**
 * 
 */
package authetication.tests;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_25_AuthDevice_ResetDevice_AuthAgain extends BaseTest{

	@Test
	public void AuthDevice_ResetDevice_AuthAgain()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();   //To give access to Camera
		} catch (Exception e) {
			
		
		}			
				
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.settingSymbolAtTop_click();
		Thread.sleep(2000);
		resetDevice.resetDeviceApp();
		Thread.sleep(5000);
		
		//Authenticating again with new auth code
		
		LoginPage loginPage1 = new LoginPage(driver);
		loginPage1.loginInAppAgain("ABCDE12345", "test");	
		
		
		/*    ACCESS FOR CAMERA AND MICROPHONE HAS ALREADY BEEN GIVE TO DEVICE. SO NO NEED TO DO IT AGAIN.
		 *    AND ALSO NO NEED TO TURN ON TEST MODE ON AGAIN TOO..AS THE DEVICE IS ALREADY IN TEST MODE WITH 1st AUTHENTICATION.
		 * 
		 * driver.switchTo().alert().accept(); //To give access to MicroPhone
		 * Thread.sleep(2000);
		 * 
		 * try {
		 * 
		 * driver.switchTo().alert().accept(); //To give access to Camera } catch
		 * (Exception e) {
		 * 
		 * 
		 * }
		 */		
				
		ResetDevice resetDevice1 = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice1.settingSymbolAtTop_click();
		Thread.sleep(2000);
		resetDevice1.resetDeviceApp();
		Thread.sleep(2000);

	}

}
