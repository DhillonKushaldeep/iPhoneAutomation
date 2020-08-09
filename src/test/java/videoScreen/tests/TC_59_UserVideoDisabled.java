/**
 * 
 */
package videoScreen.tests;

import org.openqa.selenium.By;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.Connected_VideoScreen;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_59_UserVideoDisabled extends BaseTest{

	@Test
	public void UserVideoDisabled() throws InterruptedException {
		
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
	    
	   
	    
	    Connected_VideoScreen connected_VideoScreen = new Connected_VideoScreen(driver);
	    connected_VideoScreen.verifyVideoON_isPresent();
	    System.out.println("Video is ON at the TOP when the connection is successfully established between Customer and Interpreter");
	    
	    connected_VideoScreen.click_VideoMuteON();
	    System.out.println("Video Mute was ON and is displayed but after clicking it it goes to OFF");
	    
	    connected_VideoScreen.verifyVideoMuteOFF_isPresent();
	    System.out.println("Video Mute is OFF and is displayed");
	    
	    connected_VideoScreen.verifyVideoOFF_isPresent();
	    System.out.println("Video is OFF at the TOP when the connection is disabled between Customer and Interpreter");
	    
	    
	    connected_VideoScreen.verifyCallEndDisplayed();
	    System.out.println("End Call button is displayed");
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
