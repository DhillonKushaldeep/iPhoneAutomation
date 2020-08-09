/**
 * 
 */
package locationBased_SecurityControls.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 * 
 * 1.The "Authorizing Call" message should be displayed.        
 * 2. The default deny text message should be displayed with an 'Ok' button.       
 * 3. When user clicks on 'Ok' button, the alert should be dismissed and language screen should be displayed. 
 *
 */
public class TC_140_VideoCall_OutsideGeoFence extends BaseTest{   //Kushauth02

	@Test
	public void VideoCall_OutsideGeoFence() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushauth02", "test");	
		driver.switchTo().alert().accept();                      //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                     //To give access to Camera
		} catch (Exception e) {
			
		
		}	
		
		

		LanguageScreen languageScreen = new LanguageScreen(driver);
		Thread.sleep(3000);
		driver.switchTo().alert().accept();                      //To give access to LOCATION
        Thread.sleep(1000);
		languageScreen.click_searchLanguages("Punjabi");
		languageScreen.click_PunjabiLanguage();
		
		Thread.sleep(2000);
	    
		//MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
		MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
		//el1.click();
		el2.click();
		
		Thread.sleep(2000);
		
	
        //Print the alert message
        System.out.println(driver.findElementByName("Call failed due to location").getText());
       // System.out.println(driver.findElementByName("Your organization allows access to InSight interpreters from specific locations. "
        //		+ "Based on your device location, you are outside the approved area for access. Please contact your administrator for more information.").getText());
       
        //tap on "OK" button
        driver.findElement(By.name("Ok")).click();
        System.out.println("Clicked on OK Button");
		
	
		
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);
		
		
		
	}

}
