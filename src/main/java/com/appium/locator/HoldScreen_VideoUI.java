package com.appium.locator;

import org.openqa.selenium.By;

public enum HoldScreen_VideoUI implements ILocator {

	
	
	//Connecting to Your French(any) Interpreter 
	labelConnectingToYour(By.xpath("//XCUIElementTypeStaticText[@name=\"labelConnecting\"]")),
	labelWaiting(By.xpath("//XCUIElementTypeStaticText[@name=\"labelWaiting\"]")),
	labelInterpreter(By.xpath("//XCUIElementTypeStaticText[@name=\"labelInterpreter\"]")),
	
	//loading spinner for Video
	LoadingSpinner(By.xpath("//XCUIElementTypeImage[@name=\"loading-animation.png\"]")),
	
	//Cancel Video call below: Connecting to Your French(any) Interpreter 
	CancelCall(By.xpath("//XCUIElementTypeButton[@name=\"cancelVideoCall\"]")),
	
	
	
	
	
	//Sorry, we are currently unable to connect to your video interpreter at this time. 
	//Please try again later or switch to an audio interpreter immediately.
	//Below of this text: Cancel Video Call and Switch To Audio are displayed
	
	sorryNoVideoINTavailableMessage(By.xpath("//XCUIElementTypeStaticText[@name=\"Sorry, we are currently unable to connect to your video interpreter at this time. "
			                                                                   + "Please try again later or switch to an audio interpreter immediately.\"]")),
	
	Cancel_VideoCall(By.xpath("//XCUIElementTypeButton[@name=\"errorCancelVideoCall\"]")),
	SwitchToAudio(By.xpath("//XCUIElementTypeStaticText[@name=\"switchToAudioButton\"]"));

	
	
	
	
	

	private final By locator;

	HoldScreen_VideoUI(By locator) {
		this.locator = locator;
	}

	@Override
	public By toBy() {
		return locator;
	}

}
