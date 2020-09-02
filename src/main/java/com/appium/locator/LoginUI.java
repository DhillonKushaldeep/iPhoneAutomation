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
	
    //  "LanguageLine LOGO" on Main page displayed
	Logo_BeforeLogin(By.xpath("//XCUIElementTypeImage[@name=\"logoForIphone\"]")),
	
	TestMode_ON(By.xpath("//XCUIElementTypeSwitch[@name=\"testModeSwitch\"]")),
	BackButton(By.xpath("//XCUIElementTypeOther[@name=\"backButtonContainer\"]")),
	
	TechnicalAssistance(By.xpath("//XCUIElementTypeOther[@name=\"technicalAssistanceContainer\"]")),   //No more exists
	
	
	
	FreqAskedQuestions(By.xpath("//XCUIElementTypeOther[@name=\"technicalAssistanceContainer\"]")), //Frequently Asked Questions
	ContactUs(By.xpath("//XCUIElementTypeOther[@name=\"assistanceContainer\"]")),                    //Contact Us
	
	//once we click on FAQ link, next page opens up. "FAQ" and "Contact us" on the top of the page
	FAQ(By.xpath("//XCUIElementTypeStaticText[@name=\"FAQ\"]")),
	ContactUsHeaderAtTOP(By.xpath("//XCUIElementTypeStaticText[@name=\"Contact Us\"]")),

	
	GetAssistance(By.xpath("//XCUIElementTypeOther[@name=\"assistanceContainer\"]")),
	VersionNumber(By.xpath("//XCUIElementTypeButton[@name=\"2.0 (229)\"]")),
	                        
	
	TechnicalAssistanceFirstQues(By.xpath("//XCUIElementTypeStaticText[@name=\"How do I access LanguageLine InSight Video Interpreting® services?\"]")),
	GetAssistanceFirstQues(By.xpath("//XCUIElementTypeStaticText[@name=\"How Do I Contact LanguageLine?\"]")),
	CloseButton(By.xpath("//XCUIElementTypeStaticText[@name=\"webviewCloseButton\"]")),
	
	
	HelpAndSettingsLink_GearIcon(By.xpath("//XCUIElementTypeOther[@name=\"helpAndSettingsContainer\"]")),
	CloseAtTOP(By.xpath("//XCUIElementTypeButton[@name=\"webviewCloseButton\"]"));

	private final By locator;

	LoginUI(By locator) {
		this.locator = locator;
	}

	@Override
	public By toBy() {
		return locator;
	}
	
	//@FindBy(id = "Authenticate Your Device")
	//private WebElement AuthYourDevice;
	

}
