/**
 * 
 */
package com.appium.locator;

import org.openqa.selenium.By;

/**
 * @author KushaldeepDhillon
 *
 */

	public enum HelpAndSettingsLinkUI implements ILocator {
		
		CallTime(By.xpath("//XCUIElementTypeApplication[@name=\"LanguageLine\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell")),
		
		
		DeviceLogin(By.xpath("//XCUIElementTypeOther[@name=\"deviceLoginContainer\"]")),
		FAQ(By.xpath("//XCUIElementTypeOther[@name=\"technicalAssistanceContainer\"]")),
		VideoAvailability(By.xpath("//XCUIElementTypeOther[@name=\"availabilityContainer\"]")),
		contactUs(By.xpath("//XCUIElementTypeOther[@name=\"assistanceContainer\"]")),
		CallHistory(By.xpath("//XCUIElementTypeOther[@name=\"historyContainer\"]")),
		NetworkDiagnostics(By.xpath("//XCUIElementTypeOther[@name=\"networkDiagnostics\"]")),
		PlaceTestCall(By.xpath("//XCUIElementTypeOther[@name=\"testCallContainer\"]")),
		
		CallHistoryBackButton(By.xpath("//XCUIElementTypeOther[@name=\"callHistoryBackButton\"]")),
		
	   //  "LanguageLine LOGO" 
		Logo_HelpSettingsPage(By.xpath("//XCUIElementTypeImage[@name=\"logoForIphone\"]")),
		
		Logo_DeviceLoginPage(By.xpath("//XCUIElementTypeImage[@name=\"logoForIphone\"]")),
		Logo_TechnicalAssistancePage(By.xpath("//XCUIElementTypeImage[@name=\"logoForIphone\"]")),
		Logo_VideoAvailabilityPage(By.xpath("//XCUIElementTypeImage[@name=\"logoForIphone\"]")),
		Logo_GetAssistancePage(By.xpath("//XCUIElementTypeImage[@name=\"logoForIphone\"]")),
		Logo_CallHistoryPage(By.xpath("//XCUIElementTypeImage[@name=\"logoForIphone\"]")),
		Logo_NetworkDiagnosticsPage(By.xpath("//XCUIElementTypeImage[@name=\"small_logo.png\"]")),
		
		
		LastActivated(By.xpath("//XCUIElementTypeStaticText[@name=\"lastActivated\"]")),
		ActivationCode(By.xpath("//XCUIElementTypeStaticText[@name=\"activationCode\"]")),
		
		//clicking on Technical Assistance 
		TechnicalAssistanceFirstQues(By.xpath("//XCUIElementTypeStaticText[@name=\"How do I access LanguageLine InSight Video Interpreting® services?\"]")),
		TechnicalAssistanceFAQ(By.xpath("//XCUIElementTypeStaticText[@name=\"FAQ\"]")),
		
		//clicking on Get Assistance
		GetAssistanceFirstQues(By.xpath("//XCUIElementTypeStaticText[@name=\"How Do I Contact LanguageLine?\"]")),
		GetAssistanceContactUs(By.xpath("//XCUIElementTypeStaticText[@name=\"Contact Us\"]")),
		CloseButton(By.xpath("//XCUIElementTypeStaticText[@name=\"webviewCloseButton\"]")),
		
		//clicking on Video Availability
		VideoAvailability_Language(By.xpath("//XCUIElementTypeStaticText[@name=\"Language\"]")),
		VideoAvailability_LanguageAlbanian(By.xpath("//XCUIElementTypeLink[@name=\"Albanian\"]")),
		VideoAvailability_LanguageASL(By.xpath("//XCUIElementTypeLink[@name=\"American Sign Language\"]")),
		VideoAvailability_Close(By.xpath("//XCUIElementTypeOther[@name=\"InterpreterAvailabilityClose\"]")),
		
		//clicking on  Place Test Call
		TestVideoDisplay(By.xpath("//XCUIElementTypeOther[@name=\"whiteboardDetails\"]")),
		smallVideoScreen(By.xpath("//XCUIElementTypeOther[@name=\"localVideoView\"]")),
		videoHangupButton(By.xpath("//XCUIElementTypeButton[@name=\"videoHangupButton\"]")), 
		
		
		HelpAndSettingsLink_TOP(By.xpath("//XCUIElementTypeOther[@name=\"helpAndSettingsInHeader\"]")),
		HelpAndSettingsLink_BOTTOM(By.xpath("//XCUIElementTypeOther[@name=\"backToSettings\"]")),
		HelpAndSettingsTextAtTOP(By.xpath("//XCUIElementTypeStaticText[@name=\"Help & Settings\"]")),
		ReturnToHelpAndSettings(By.xpath("//XCUIElementTypeOther[@name=\"backToSettings\"]")),
		Back(By.xpath("//XCUIElementTypeOther[@name=\"callHistoryBackButton\"]")),
		
		HelpAndSettingsLink_GearIcon(By.xpath("//XCUIElementTypeOther[@name=\"helpAndSettingsContainer\"]"));
		
		

		private final By locator;

		HelpAndSettingsLinkUI(By locator) {
			this.locator = locator;
		}

		@Override
		public By toBy() {
			return locator;
		}

	}