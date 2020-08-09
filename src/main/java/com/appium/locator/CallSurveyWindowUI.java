package com.appium.locator;

import org.openqa.selenium.By;

public enum CallSurveyWindowUI implements ILocator {
	
	
	
	//******************************** Survey Window START ****************************************//
	
	//Call Ended Survey Window
	CallEndedIcon(By.xpath("//XCUIElementTypeStaticText[@name=\"Call Ended\"]")),              //Call Ended Icon
	CallEndedText(By.xpath("//XCUIElementTypeStaticText[@name=\"Call Ended\"]")),              //Call Ended text
	HowDidWeDo(By.xpath("//XCUIElementTypeStaticText[@name=\"How did we do?\"]")),             //How Did We Do?
	Skip(By.xpath("//XCUIElementTypeButton[@name=\"callEndedDoneButton\"]")),                  //Skip
	CallEndedStarOne(By.xpath("//XCUIElementTypeButton[@name=\"callEndedStarOne\"]")),         //Star Symbol One
	CallEndedStarFive(By.xpath("//XCUIElementTypeButton[@name=\"callEndedStarFive\"]")),        //Star Symbol Five
	
	CallEndedTextFeedback(By.xpath("//XCUIElementTypeTextView[@name=\"callEndedComment\"]")),       //Plesae enter your FEEDBACK here
	Done(By.xpath("//XCUIElementTypeButton[@name=\"callEndedDoneButton\"]"));                       //DONE
	
	//******************************** Survey Window END ****************************************//
	

	private final By locator;

	CallSurveyWindowUI(By locator) {
		this.locator = locator;
	}

	@Override
	public By toBy() {
		return locator;
	}

}
