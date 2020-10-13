/**
 * 
 */
package com.appium.locator;

import org.openqa.selenium.By;

/**
 * @author KushaldeeDhillon
 *
 */

	public enum NetworkDiagnosticsUI implements ILocator {
		
		NetworkDiagnosticsLink(By.xpath("//XCUIElementTypeOther[@name=\"networkDiagnostics\"]")),
		
		APIConnectivity(By.xpath("//XCUIElementTypeStaticText[@name=\"API Connectivity\"]")),
		VideoCalls(By.xpath("//XCUIElementTypeStaticText[@name=\"Video Calls\"]")),
		AudioCalls(By.xpath("//XCUIElementTypeStaticText[@name=\"Audio Calls\"]")),
		
		GreenCheckAPIConnectivity(By.xpath("//*[@name=\"assessAPI\"]")),
		GreenCheckVideoCalls(By.xpath("//*[@name=\"assessVideo\"]")),
		GreenCheckAudioCalls(By.xpath("//*[@name=\"assessAudio\"]")),
		Complete_GreenLabel(By.xpath("//XCUIElementTypeStaticText[@name=\"completeLabel\"]")),
		
		TestSkippedVideoCalls(By.xpath("(//XCUIElementTypeStaticText[@name=\"Test Skipped\"])[1]")),
		TestSkippedAudioCalls(By.xpath("(//XCUIElementTypeStaticText[@name=\"Test Skipped\"])[2]")),
		TestStopped_RedLabel(By.xpath("//XCUIElementTypeStaticText[@value=\"Test Stopped\"]")),
		
		VideoCalls_ErrorCodeMessage2A(By.xpath("//XCUIElementTypeStaticText[@name=\"Failed, Error Code: 2A \"]")),
		AudioCalls_ErrorCodeMessage3A(By.xpath("//XCUIElementTypeStaticText[@name=\"Failed, Error Code: 3A \"]")),
		Complete_Fail(By.xpath("")),
		
		StopTest(By.xpath("//XCUIElementTypeButton[@name=\"stopTest\"]")),
		Close(By.xpath("//XCUIElementTypeOther[@name=\"backButton\"]")),
		RunNetworkDiagnostic(By.xpath("//XCUIElementTypeButton[@name=\"runDiagnostics\"]"));
		

	

		private final By locator;

		NetworkDiagnosticsUI(By locator) {
			this.locator = locator;
		}

		@Override
		public By toBy() {
			return locator;
		}

	}