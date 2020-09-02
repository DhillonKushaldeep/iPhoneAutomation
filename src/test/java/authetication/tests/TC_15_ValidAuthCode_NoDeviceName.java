/**
 * 
 */
package authetication.tests;

import static org.testng.Assert.assertEquals;

import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LoginPage;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_15_ValidAuthCode_NoDeviceName extends BaseTest{

	@Test
	public void ValidAuthCode_NoDeviceName()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "");	
		driver.switchTo().alert().accept();     //To give access to MicroPhone
		Thread.sleep(2000);
		
		try {
			
			driver.switchTo().alert().accept();   //To give access to Camera
		} catch (Exception e) {
			
			
		}				
		
		loginPage.errorMessage_EnterDeviceName();		
		MobileElement element = (MobileElement) driver.findElementByAccessibilityId("deviceNameError");
		
		String message = element.getText();
		String SucessMessage = " enter a device name";	                   
						 
	    assertEquals(message, SucessMessage);					
		Thread.sleep(5000);

	}

}
