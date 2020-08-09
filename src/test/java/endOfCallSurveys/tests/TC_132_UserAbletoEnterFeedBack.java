/**
 * 
 */
package endOfCallSurveys.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 *
 */
public class TC_132_UserAbletoEnterFeedBack extends BaseTest{

	@Test
	public void UserAbletoEnterFeedBack() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();                      //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();                     //To give access to Camera
		} catch (Exception e) {
			
		
		}	
		
		

		LanguageScreen languageScreen = new LanguageScreen(driver);
		Thread.sleep(1000);
		
		languageScreen.click_searchLanguages("Punjabi");
		languageScreen.click_PunjabiLanguage();
		
		Thread.sleep(2000);
	    
		//MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
		MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
		//el1.click();
		el2.click();
		
		Thread.sleep(5000);
		
	/**
	 * The VIDEO call to PUNJABI INTERPRETER is initiated.
	 * The call will go to LINC and will be accepted by the Punjabi Interpreter. 
	 * After few seconds, the call will be ended to check if the Call Survey Window is DISPLAYED
	 */
		
		
		
		
		CallSurveyWindow callSurveyWindow = new CallSurveyWindow(driver);
		
		callSurveyWindow.click_CallEnded_StarOne();                                               //Select any star icon in survey window. 
		System.out.println("STAR ONE is clicked on Survey window");
		callSurveyWindow.click_TextBox("TEST");                                                   //Enter feedback message in the text field
		System.out.println("TEST is being typed on Survey window");
		callSurveyWindow.click_Done();                                                            //Tap the option 'Done'
		System.out.println("Done is clicked on Survey window");
		
		
		
		
		Thread.sleep(2000);
		ResetDevice resetDevice = new ResetDevice(driver); //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
