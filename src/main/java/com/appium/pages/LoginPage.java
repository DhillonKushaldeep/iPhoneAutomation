package com.appium.pages;

import static com.appium.locator.LoginUI.*;
import static com.appium.locator.ResetDeviceUI.ResetDeviceActivation_RESET;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;

import com.appium.core.BasePage;
import com.appium.locator.LoginUI;

import io.appium.java_client.AppiumDriver;

public class LoginPage extends BasePage {

	public LoginPage(AppiumDriver driver) {
		super(driver);
	}
	
    public void verifyLogo_isPresentBeforeLogin() throws InterruptedException{        
		
    	waitForElementPresent(Logo_BeforeLogin.toBy());		    
		Thread.sleep(1000);
					
	}

    
    public void verifyAuthenticateYourDevicePresent() throws InterruptedException {     //Method added on 9/02/2020
       	
    	waitForElementPresent(AuthYourDevice.toBy());
    	Thread.sleep(2000);
    	System.out.println("Autheticate your device is displayed");
    	
       }
    
    

	public void loginInApp(String userName, String password) throws InterruptedException{
		
		waitForElementPresent(AuthCode.toBy());
		click(HelpAndSettingsLink_GearIcon.toBy());
		Thread.sleep(1000);
		click(TestMode_ON.toBy());
		Thread.sleep(1000);
		click(BackButton.toBy());
		
		waitForElementPresent(AuthCode.toBy());		
		setText( By.xpath("//XCUIElementTypeTextField[@name=\"activationCode\"]"), userName);
		setText(DeviceName.toBy(), password);
		click(ActivateDevice.toBy());	
		
	}
	
    public void loginInAppAgain(String userName, String password) throws InterruptedException{
		
		waitForElementPresent(AuthCode.toBy());
		//click(HelpAndSettingsLink_GearIcon.toBy());
		//Thread.sleep(1000);
		//click(TestMode_ON.toBy());
		//Thread.sleep(1000);
		//click(BackButton.toBy());
		
		waitForElementPresent(AuthCode.toBy());		
		setText( By.xpath("//XCUIElementTypeTextField[@name=\"activationCode\"]"), userName);
		setText(DeviceName.toBy(), password);
		click(ActivateDevice.toBy());	
		
	}

    public void verifyLoginInfoPresent() throws InterruptedException{
		
		waitForElementPresent(AuthCode.toBy());
		waitForElementPresent(DeviceName.toBy());
		waitForElementPresent(ActivateDevice.toBy());
		Thread.sleep(1000);
	}

	public void testMode_ON() throws InterruptedException{
		
		click(HelpAndSettingsLink_GearIcon.toBy());
		Thread.sleep(1000);
		click(TestMode_ON.toBy());
		Thread.sleep(1000);
		click(BackButton.toBy());			
	}
	
	
    public void HelpAndSettingsLink_GearIcon() throws InterruptedException{        
		
		click(HelpAndSettingsLink_GearIcon.toBy());
		Thread.sleep(1000);
		System.out.println("Help and Settings Gear icon at TOP");
				
	}
	
    public void verifyHelpAndSettingsLink_GearIconDisplayed() throws InterruptedException{        
		
    	waitForElementPresent(HelpAndSettingsLink_GearIcon.toBy());		    
		Thread.sleep(1000);
					
	}

  //  public void verifyTechnicalAssistance() throws InterruptedException{ //This one exists no more...Replaced by Frequently asked questions       
		
    //	waitForElementPresent(TechnicalAssistance.toBy());		    
	//	Thread.sleep(1000);
					
	//}
    
  public void clickFreqAskedQuestions() throws InterruptedException{		//Frequently Asked Questions   Prior to Login - 09/02/2020
	 	
  	    click(FreqAskedQuestions.toBy());
		Thread.sleep(1000);
		System.out.println("clicked on Frequently Asked Questions");
	
	}

  public void verifyFreqAskedQues() throws InterruptedException{        // created on 9/1/2020  Prior to Login - 09/02/2020
		
    	waitForElementPresent(FreqAskedQuestions.toBy());		    
		Thread.sleep(1000);
		System.out.println("Frequently Asked Questions is displayed before login");
					
	}
  
  public void verifyHeader_FAQ() throws InterruptedException{ //After we click on link - Frequently Asked Questions, it take to next page. 
	                                                          //Verify header "FAQ" on TOP   Prior to Login - 09/02/2020
	 	
	    click(FAQ.toBy());
		Thread.sleep(1000);
		System.out.println("FAQ header present at TOP");
	
	}
 
  public void verifyContactUs() throws InterruptedException{           // created on 9/1/2020    Prior to Login - 09/02/2020
		
 	waitForElementPresent(ContactUs.toBy());		    
		Thread.sleep(1000);
		System.out.println("Contact Us is displayed");
					
	}
  
  public void clickContactUs() throws InterruptedException{		//created on 9/1/2020     Prior to Login - 09/02/2020
	 	
	    click(ContactUs.toBy());
		Thread.sleep(1000);
		System.out.println("Contact Us is displayed and is clicked"); 

	}
  
  public void verifyHeader_ContactUs() throws InterruptedException{ //After we click on link - ContactUs, it take to next page. 
	                                                                   //Verify header "ContactUs" on TOP    Prior to Login - 09/02/2020
	 	
	    click(ContactUsHeaderAtTOP.toBy());
		Thread.sleep(1000);
		System.out.println("Contact Us header present at TOP");
	
	}
	
   public void verifyGetAssistance() throws InterruptedException{        
		
    	waitForElementPresent(GetAssistance.toBy());		    
		Thread.sleep(1000);
					
	}
   
   public void verifyVersion() throws InterruptedException{        
		
   	    waitForElementPresent(VersionNumber.toBy());		    
		Thread.sleep(1000);
		System.out.println("Version number is displayed"); 
					
	}
   
   public void clickCloseAtTOP() throws InterruptedException{		//At Top
	 	
  	    click(CloseAtTOP.toBy());
		Thread.sleep(1000);
		System.out.println("CLOSE at TOP is displayed and is clicked"); 
	}
	
   public void TechnicalAssistance_click() throws InterruptedException{		
		
		click(TechnicalAssistance.toBy());
		Thread.sleep(2000);
		waitForElementPresent(TechnicalAssistanceFirstQues.toBy());
		Thread.sleep(1000);
		click(CloseButton.toBy());
		Thread.sleep(1000);
		click(BackButton.toBy());
	}
   
   public void GetAssistance_click() throws InterruptedException{		
		
	    click(GetAssistance.toBy());
		Thread.sleep(2000);
		waitForElementPresent(GetAssistanceFirstQues.toBy());
		Thread.sleep(1000);
		Thread.sleep(1000);
		click(CloseButton.toBy());
		Thread.sleep(1000);
		click(BackButton.toBy());
	}
   
   public void clickBack() throws InterruptedException{        //new
		
	   click(BackButton.toBy());
		Thread.sleep(1000);
		System.out.println("BACK at top is displayed and is clicked");
					
	}
   
    public void errorMessage_AuthCodeLessMinLength() throws InterruptedException{
	
	    waitForElementPresent(errorMessageAuthCodeLessMinLength.toBy());		    
		Thread.sleep(1000);
					
	}
    
    public void errorMessage_CodeNotComlete() throws InterruptedException{
    	
	    waitForElementPresent(errorMessageCodeNotComlete.toBy());		    
		Thread.sleep(1000);
					
	}
    
    public void errorMessage_EnterAuthCode() throws InterruptedException{
    	
	    waitForElementPresent(errorMessageEnterAuthCode.toBy());		    
		Thread.sleep(1000);
					
	}
    
    public void errorMessage_InvalidAuthCode() throws InterruptedException{
    	
	    waitForElementPresent(errorMessageInvalidAuthCode.toBy());	
	    System.out.println("Authentication code is disabled");
		Thread.sleep(1000);
					
	}
    
    public void errorMessage_MaxActivationLimit() throws InterruptedException{
    	
	    waitForElementPresent(errorMessageMaxActivationLimit.toBy());	
	    System.out.println("Max activation limit has been reached for this authentication code");
		Thread.sleep(1000);
					
	}
    
    
    
    public void errorMessage_EnterDeviceName() throws InterruptedException{
    	
	    waitForElementPresent(errorMessageEnterDeviceName.toBy());		    
		Thread.sleep(1000);
		System.out.println("");
					
	}
   
	
	
}
