package com.appium.locator;

import org.openqa.selenium.By;

public enum HoldScreen_AudioUI implements ILocator {
	
		
	AudioCallSpeakerButtonOn(By.xpath("//XCUIElementTypeStaticText[@name=\"audioCallSpeakerButtonOn\"]")),
	AudioCallSpeakerButtonOff(By.xpath("//XCUIElementTypeStaticText[@name=\"audioCallSpeakerButtonOff\"]")),
	
	
	AudioCallMuteButtonOn(By.xpath("//XCUIElementTypeStaticText[@name=\"audioCallMuteButtonOn\"]")),
	AudioCallMuteButtonOff(By.xpath("//XCUIElementTypeStaticText[@name=\"audioCallMuteButtonOff\"]")),
	
	
	AudioCallCancelButton(By.xpath("//XCUIElementTypeStaticText[@name=\"Cancel Call\"]")),
	
	
	
	LabelAuthorizing(By.xpath("//XCUIElementTypeStaticText[@name=\"Authorizing...\"]")),
	LabelInitializing(By.xpath("//XCUIElementTypeStaticText[@name=\"Initializing...\"]")),
	LabelConnecting(By.xpath("//XCUIElementTypeOther[@name=\"Connecting...\"]")),
	LabelConnected(By.xpath("//XCUIElementTypeStaticText[@name=\"Connected.\"]")),
	
	
	ConnectedLabel(By.xpath("//XCUIElementTypeStaticText[@name=\"Connected.\"]")),
	ConnectingLabel(By.xpath("//XCUIElementTypeStaticText[@name=\"labelConnecting\"]"));
	
	
	
	
	

	private final By locator;

	HoldScreen_AudioUI(By locator) {
		this.locator = locator;
	}

	@Override
	public By toBy() {
		return locator;
	}

}
