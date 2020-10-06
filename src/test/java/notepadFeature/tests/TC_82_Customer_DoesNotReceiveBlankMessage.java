/**
 * 
 */
package notepadFeature.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.Notepad;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author KushaldeepDhillon
 *
 * The message should not be sent. Client should not receive any blank message. 
 * So, to verify this we are only verifying that only WhiteBoard details are being displayed. No textbox is present.
 * 
 */
public class TC_82_Customer_DoesNotReceiveBlankMessage extends BaseTest{

	@Test
	public void Customer_DoesNotReceiveBlankMessage() throws InterruptedException {
		
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
	    
		MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
		el2.click();
		
		Thread.sleep(5000);
		
	/**
	 * The VIDEO call to PUNJABI INTERPRETER is initiated.
	 * The call will go to LINC and will be accepted by the Punjabi Interpreter. 
	 * After few seconds, the call will be ended to check if the Call Survey Window is DISPLAYED
	 */
		
		Notepad notepad = new Notepad(driver);
		notepad.verifyWhiteBoardDetailsDisplayed();  //Punjabi/316250 Kushal    no "Text Message Box" displayed
		System.out.println("Punjabi/316250 Kushal is displayed as WhiteBoard details. No textbox is present with the message.");
		
		
		CallSurveyWindow callSurveyWindow = new CallSurveyWindow(driver);
		callSurveyWindow.click_Skip();
		System.out.println("SKIP is clicked on Survey window");
		
		//To RESET the DEVICE
	    Thread.sleep(2000);
	    languageScreen.click_HelpSettingsGEAR();  //click on the Help & Settings Gear icon on TOP
	    
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.DeviceLoginresetDeviceApp();   //click on the Device configuration link
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
