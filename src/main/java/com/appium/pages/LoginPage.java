package com.appium.pages;

import static com.appium.locator.LoginUI.*;
import static com.appium.locator.ResetDeviceUI.ResetDeviceActivation_RESET;
import static com.appium.locator.ResetDeviceUI.ResetDeviceButton;
import static com.appium.locator.ResetDeviceUI.SettingsSymbol_AtTOP;

import org.openqa.selenium.By;
import com.appium.core.BasePage;

import io.appium.java_client.AppiumDriver;

public class LoginPage extends BasePage {

	public LoginPage(AppiumDriver driver) {
		super(driver);
	}
	
    public void verifyLogo_isPresentBeforeLogin() throws InterruptedException{        
		
    	waitForElementPresent(Logo_BeforeLogin.toBy());		    
		Thread.sleep(1000);
					
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
					
	}
	
    public void verifyHelpAndSettingsLink_GearIconDisplayed() throws InterruptedException{        
		
    	waitForElementPresent(HelpAndSettingsLink_GearIcon.toBy());		    
		Thread.sleep(1000);
					
	}

    public void verifyTechnicalAssistance() throws InterruptedException{        
		
    	waitForElementPresent(TechnicalAssistance.toBy());		    
		Thread.sleep(1000);
					
	}
	
   public void verifyGetAssistance() throws InterruptedException{        
		
    	waitForElementPresent(GetAssistance.toBy());		    
		Thread.sleep(1000);
					
	}
   
   public void verifyVersion() throws InterruptedException{        
		
   	    waitForElementPresent(VersionNumber.toBy());		    
		Thread.sleep(1000);
					
	}
   
   public void clickCloseAtTOP() throws InterruptedException{		//At Top
	 	
  	    click(CloseButton.toBy());
		Thread.sleep(1000);
	
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
	    System.out.println("The authentication code is invalid");
		Thread.sleep(1000);
					
	}
    
    public void errorMessage_MaxActivationLimit() throws InterruptedException{
    	
	    waitForElementPresent(errorMessageMaxActivationLimit.toBy());	
	    System.out.println("The authentication code is invalid");
		Thread.sleep(1000);
					
	}
    
    
    
    public void errorMessage_EnterDeviceName() throws InterruptedException{
    	
	    waitForElementPresent(errorMessageEnterDeviceName.toBy());		    
		Thread.sleep(1000);
		System.out.println("");
					
	}
	
	
}
