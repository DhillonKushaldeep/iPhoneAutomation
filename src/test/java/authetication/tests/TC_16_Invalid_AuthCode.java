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
public class TC_16_Invalid_AuthCode extends BaseTest{

	@Test
	public void Invalid_AuthCode()  throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushal", "test");	
		driver.switchTo().alert().accept();     //To give access to MicroPhone
		Thread.sleep(2000);
		
		try {
			
			driver.switchTo().alert().accept();   //To give access to Camera
		} catch (Exception e) {
			
			
		}				
		
		loginPage.errorMessage_AuthCodeLessMinLength();		
		MobileElement element = (MobileElement) driver.findElementByAccessibilityId("activationError");
		
		String message = element.getText();
		String SucessMessage = "Your code is not complete.  Please\ndouble check it.";	                   
						 
	    assertEquals(message, SucessMessage);					
		Thread.sleep(5000);	
	}

}
