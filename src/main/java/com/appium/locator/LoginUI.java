package com.appium.locator;

import org.openqa.selenium.By;

public enum LoginUI implements ILocator {
		
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
	
	TechnicalAssistance(By.xpath("//XCUIElementTypeOther[@name=\"technicalAssistanceContainer\"]")),
	GetAssistance(By.xpath("//XCUIElementTypeOther[@name=\"assistanceContainer\"]")),
	VersionNumber(By.xpath("//XCUIElementTypeStaticText[@name=\"1.7.0 (148)\"]")),
	
	TechnicalAssistanceFirstQues(By.xpath("//XCUIElementTypeStaticText[@name=\"How do I access LanguageLine InSight Video Interpreting® services?\"]")),
	GetAssistanceFirstQues(By.xpath("//XCUIElementTypeStaticText[@name=\"How Do I Contact LanguageLine?\"]")),
	CloseButton(By.xpath("//XCUIElementTypeStaticText[@name=\"webviewCloseButton\"]")),
	
	
	HelpAndSettingsLink_GearIcon(By.xpath("//XCUIElementTypeOther[@name=\"helpAndSettingsContainer\"]")),
	CloseAtTOP(By.xpath("//XCUIElementTypeStaticText[@name=\"webviewCloseButton\"]"));

	private final By locator;

	LoginUI(By locator) {
		this.locator = locator;
	}

	@Override
	public By toBy() {
		return locator;
	}

}
