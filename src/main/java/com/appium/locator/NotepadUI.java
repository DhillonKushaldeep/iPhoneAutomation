/**
 * 
 */
package com.appium.locator;

import org.openqa.selenium.By;

/**
 * @author KushaldeeDhillon
 *
 */

	public enum NotepadUI implements ILocator {
		
		Notepad_Minimize(By.xpath("//XCUIElementTypeStaticText[@name=\"whiteBoardStateButton\"]")),
		
		Notepad_Message(By.xpath("	//XCUIElementTypeTextView[@name=\"whiteboard\"]")),
		
		ScrollUP(By.xpath("//XCUIElementTypeOther[@name=\"whiteboardUp\"]")),
		ScrollDown(By.xpath("//XCUIElementTypeOther[@name=\"whiteboardDown\"]")),
		
		
		
		
		//If message is not sent by the INTERPRETER from LINC Side, Then we will not see --> Notepad_Message, ScrollUP, ScrollDown  on the Customer Mobile Side
		//Only we could see is Punjabi/316250 Kushal
		//There will be no "Text Message Box" to receive or type the message
		
		WhiteBoardDetails(By.xpath("//XCUIElementTypeOther[@name=\"whiteboardDetails\"]"));
		
		
		
		
		
		
		private final By locator;

		NotepadUI(By locator) {
			this.locator = locator;
		}

		@Override
		public By toBy() {
			return locator;
		}

	}