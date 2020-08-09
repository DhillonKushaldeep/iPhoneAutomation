/**
 * 
 */
package com.appium.locator;

import org.openqa.selenium.By;

/**
 * @author KushaldeeDhillon
 *
 */

	public enum LocationBased_SecurityControlsUI implements ILocator {
		
		CallFailed(By.xpath("//XCUIElementTypeStaticText[@name=\"Call failed due to location\"]")),
		
		Message(By.xpath("//XCUIElementTypeStaticText[@name=\"Your organization allows access to InSight interpreters from specific locations. "
				+ "Based on your device location, you are outside the approved area for access. "
				+ "Please contact your administrator for more information.\"]")),
		
		
		OK(By.xpath("//XCUIElementTypeButton[@name=\"Ok\"]"));
		
		
		
		private final By locator;

		LocationBased_SecurityControlsUI(By locator) {
			this.locator = locator;
		}

		@Override
		public By toBy() {
			return locator;
		}

	}