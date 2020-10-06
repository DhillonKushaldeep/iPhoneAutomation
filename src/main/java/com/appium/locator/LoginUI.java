package com.appium.locator;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;

public enum LoginUI implements ILocator {
		
	
	AuthYourDevice(By.xpath("//XCUIElementTypeStaticText[@name=\"Authenticate Your Device\"]")),
	AuthCode(By.xpath("//XCUIElementTypeTextField[@name=\"activationCode\"]")),
	DeviceName(By.xpath("//XCUIElementTypeTextField[@name=\"deviceName\"]")),
	ActivateDevice(By.xpath("//XCUIElementTypeButton[@name=\"activateDevice\"]")),
	
	errorMessageAuthCodeLessMinLength(By.xpath("//XCUIElementTypeStaticText[@name=\"activationError\"]")),
	errorMessageCodeNotComlete(By.xpath("By.xpath(\"//XCUIElementTypeStaticText[@name=\\\"activationError\"]")),
	errorMessageEnterAuthCode(By.xpath("//XCUIElementTypeStaticText[@name=\\\"activationError\\\"]")),	
	errorMessageInvalidAuthCode(By.xpath("//XCUIElementTypeStaticText[@name=\"activationError\"]")),
	
	errorMessageMaxActivationLimit(By.xpath("//XCUIElementTypeStaticText[@name=\"activationError\"]")),
	
	
	errorMessageEnterDeviceName(By.xpath("//XCUIElementTypeStaticText[@name=\"deviceNameError\"]")),
	
    //  "LanguageLine LOGO" on Main page displayed    9/02/2020
	Logo_BeforeLogin(By.xpath("//XCUIElementTypeImage[@name=\"logoForIphone\"]")),
	
	TestMode_ON(By.xpath("//XCUIElementTypeSwitch[@name=\"testModeSwitch\"]")),
	BackButton(By.xpath("//XCUIElementTypeOther[@name=\"backButtonContainer\"]")),
	
	TechnicalAssistance(By.xpath("//XCUIElementTypeOther[@name=\"technicalAssistanceContainer\"]")),   //No more exists   9/02/2020
	
	
	
	FreqAskedQuestions(By.xpath("//XCUIElementTypeOther[@name=\"technicalAssistanceContainer\"]")), //Frequently Asked Questions    9/02/2020
	ContactUs(By.xpath("//XCUIElementTypeOther[@name=\"assistanceContainer\"]")),                    //Contact Us                   9/02/2020
	
	//once we click on FAQ link, next page opens up. "FAQ" and "Contact us" on the top of the page
	FAQ(By.xpath("//XCUIElementTypeStaticText[@name=\"FAQ\"]")),                             //9/02/2020
	ContactUsHeaderAtTOP(By.xpath("//XCUIElementTypeStaticText[@name=\"Contact Us\"]")),     //9/02/2020

	
	contactUs(By.xpath("//XCUIElementTypeOther[@name=\"assistanceContainer\"]")),
	VersionNumber(By.xpath("//XCUIElementTypeButton[@name=\"versionNumber\"]")),             //9/14/2020
	
	
	                        
	
	TechnicalAssistanceFirstQues(By.xpath("//XCUIElementTypeStaticText[@name=\"How do I access LanguageLine InSight Video Interpreting® services?\"]")),
	GetAssistanceFirstQues(By.xpath("//XCUIElementTypeStaticText[@name=\"How Do I Contact LanguageLine?\"]")),
	CloseButton(By.xpath("//XCUIElementTypeButton[@name=\"webviewCloseButton\"]")),
	
	
	HelpAndSettingsLink_GearIcon(By.xpath("//XCUIElementTypeOther[@name=\"helpAndSettingsContainer\"]")),  
	HelpAndSettingsLink_AfterLogin(By.xpath("//XCUIElementTypeButton[@name=\"helpAndSettings\"]")),
	CloseAtTOP(By.xpath("//XCUIElementTypeButton[@name=\"webviewCloseButton\"]"));       //Updated      9/02/2020

	private final By locator;

	LoginUI(By locator) {
		this.locator = locator;
	}

	@Override
	public By toBy() {
		return locator;
	}
	
	//@FindBy()
	//private WebElement AuthID;
	
	

	public String getText() {
		// TODO Auto-generated method stub
		return null;
	}
	
	

}




