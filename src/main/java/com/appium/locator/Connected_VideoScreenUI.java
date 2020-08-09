package com.appium.locator;

import org.openqa.selenium.By;

public enum Connected_VideoScreenUI implements ILocator {
	
		
	videoHangupButton(By.xpath("//XCUIElementTypeStaticText[@name=\"videoHangupButton\"]")),   //Call Hangup button in Red
	
	videoButtonImageOn(By.xpath("//XCUIElementTypeImage[@name=\"videoButtonImageOn\"]")),      //video Mute sign button ON
	videoButtonImageOff(By.xpath("//XCUIElementTypeImage[@name=\"videoButtonImageOff\"]")),    //video Mute sign button OFF
	
	
	audioMuteON(By.xpath("//XCUIElementTypeImage[@name=\"muteButtonImageOn\"]")),              //microphone button  ON
	audioMuteOFF(By.xpath("//XCUIElementTypeImage[@name=\"muteButtonImageOff\"]")),            //microphone button  OFF
	
	speakerButton(By.xpath("//XCUIElementTypeOther[@name=\"speakerButton\"]")),               //speaker button

	
	VideoON_atTOP(By.xpath("//XCUIElementTypeOther[@name=\"localVideoView\"]")),              //when Video is ON
	VideoOFF_atTOP(By.xpath("//XCUIElementTypeStaticText[@name=\"localVideoIcon\"]")),        //when Video is disabled by customer
	
	videoDisabledbyINT(By.xpath("//XCUIElementTypeOther[@name=\"remoteVideo\"]"));          //when Video is disabled by Interpreter
	
	
	
	

	private final By locator;

	Connected_VideoScreenUI(By locator) {
		this.locator = locator;
	}

	@Override
	public By toBy() {
		return locator;
	}

}
