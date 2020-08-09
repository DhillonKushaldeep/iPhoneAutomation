/**
 * 
 */
package videoScreen.tests;

import java.time.Duration;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.testng.annotations.Test;

import com.appium.core.BaseTest;
import com.appium.pages.CallSurveyWindow;
import com.appium.pages.Connected_VideoScreen;
import com.appium.pages.LanguageScreen;
import com.appium.pages.LoginPage;
import com.appium.pages.ResetDevice;

import io.appium.java_client.MobileElement;
import io.appium.java_client.TouchAction;
import io.appium.java_client.touch.WaitOptions;
import io.appium.java_client.touch.offset.PointOption;

/**
 * @author kushaldeepdhillon
 *
 */
public class TC_62_UserAbleToMoveSelfVideo extends BaseTest{

	@Test
	public void UserAbleToMoveSelfVideo() throws InterruptedException {
		
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
	    
	    //MobileElement el1 = (MobileElement) driver.findElement(By.id("selectedAudioLanguage"));
	    MobileElement el2 = (MobileElement) driver.findElement(By.id("selectedVideoLanguage"));
	    //el1.click();
	    el2.click();
	    Thread.sleep(9000);
	    
	 // touch, hold, and drag based on coordinates
	    Map<String, Object> args = new HashMap<>();
	    args.put("duration", 1.5);            //value of X and Y coordinates ::  29   49   after dragging   110 48
	    args.put("fromX", 29);
	    args.put("fromY", 49);
	    args.put("toX", 170);
	    args.put("toY", 68);
	    driver.executeScript("mobile: dragFromToForDuration", args);
	   
	    
	    Thread.sleep(2000);
	    
	    Connected_VideoScreen connected_VideoScreen = new Connected_VideoScreen(driver);
	    connected_VideoScreen.click_CallEnd();
	    Thread.sleep(2000);
	    
	    CallSurveyWindow callSurveyWindow = new CallSurveyWindow(driver);
	    callSurveyWindow.verifyCallEndedIconDisplayed();
	    callSurveyWindow.click_Skip();
	    System.out.println("Call Survey Window is displayed and press on Skip button");
	    
		ResetDevice resetDevice = new ResetDevice(driver);   //Device Login --> Reset Device --> Reset/Cancel --> Reset 
		resetDevice.resetDeviceApp();
		Thread.sleep(2000);
	}

}
