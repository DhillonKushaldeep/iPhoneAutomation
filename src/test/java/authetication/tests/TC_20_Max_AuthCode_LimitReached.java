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
public class TC_20_Max_AuthCode_LimitReached extends BaseTest{

	@Test
	public void Max_AuthCode_LimitReached()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("ABCDE54321", "test");	
		driver.switchTo().alert().accept();                   //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                 //To give access to Camera
		} catch (Exception e) {			
		
		}			
				
		loginPage.errorMessage_MaxActivationLimit();
		MobileElement element = (MobileElement) driver.findElementByAccessibilityId("activationError");
		
		String message = element.getText();
		String SucessMessage = "Max activation limit has been reached for this authetication code";	                   
						 
	    assertEquals(message, SucessMessage);					
		Thread.sleep(5000);	

	}

}
