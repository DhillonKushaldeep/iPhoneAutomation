/**
 * 
 */
package videoScreen.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.Connected_VideoScreen;
import com.appium.pages.HoldScreen_Video;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_66_HoldScreenDisplayed extends BaseTest{

	@Test
	public void HoldScreenDisplayed() throws InterruptedException {
		
		LoginPage loginPage = new LoginPage(driver);
		loginPage.loginInApp("kushaltest", "test");	
		driver.switchTo().alert().accept();        //To give access to MicroPhone
        Thread.sleep(2000);
		
		try {
			
		driver.switchTo().alert().accept();       //To give access to Camera
		} catch (Exception e) {
			
		
		}			
		
		
		LanguageScreen languageScreen = new LanguageScreen(driver);
		languageScreen.click_searchLanguages("Punjabi");
		languageScreen.click_PunjabiLanguage();
	    
	    Thread.sleep(2000);
	    
	   // MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
	    MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
	    //el1.click();
	     el2.click();
	    
	     HoldScreen_Video holdScreen_Video = new HoldScreen_Video(driver);
		 holdScreen_Video.verifyConnectingtoYourInterpreterdDisplayed();
		 System.out.println("Connecting to Your Interpreter is displayed");
		 Thread.sleep(2000);
		    
		    
	    Connected_VideoScreen connected_VideoScreen = new Connected_VideoScreen(driver);
	    connected_VideoScreen.click_CallEnd();
	    Thread.sleep(1000);
	    
	    CallSurveyWindow callSurveyWindow = new CallSurveyWindow(driver);
	    callSurveyWindow.verifyCallEndedIconDisplayed();
	    callSurveyWindow.click_Skip();
	    System.out.println("Call Survey Window is displayed and press on Skip button");
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);

	}

}
