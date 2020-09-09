/**
 * 
 */
package com.appium.locator;

import org.openqa.selenium.By;

/**
 * @author kushaldeepdhillon
 *
 */

	public enum ResetDeviceUI implements ILocator {
		
		//SettingsSymbol_AtTOP(By.xpath("//XCUIElementTypeStaticText[@name=\"helpAndSettings\"]")),
		HelpSettingsGEAR(By.xpath("//XCUIElementTypeButton[@name=\"helpAndSettings\"]")),
		
		DeviceConfigLink(By.xpath("//XCUIElementTypeOther[@name=\"deviceLoginContainer\"]")),
		ChangeCode(By.xpath("//XCUIElementTypeStaticText[@name=\"Change Code\"]\n")),
		ChangeName(By.xpath("//XCUIElementTypeStaticText[@name=\"Change Name\"]\n")),
		
		ResetDeviceActivation_RESET(By.xpath("//XCUIElementTypeButton[@name=\"Reset\"]")),  
		ResetDeviceActivation_CANCEL(By.xpath("//XCUIElementTypeButton[@name=\"Cancel\"]")),  
		
		ResetDevice_Julia_iPhone(By.xpath("//XCUIElementTypeButton[@name=\"Reset\"]"));

	

		private final By locator;

		ResetDeviceUI(By locator) {
			this.locator = locator;
		}

		@Override
		public By toBy() {
			return locator;
		}

	}