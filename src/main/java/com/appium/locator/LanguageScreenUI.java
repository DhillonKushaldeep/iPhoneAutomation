package com.appium.locator;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;

import io.appium.java_client.MobileBy;

public enum LanguageScreenUI implements ILocator {
	
		
	TopLanguages(By.xpath("//XCUIElementTypeStaticText[@name=\"Top Languages\"]")),
	AllLanguages(By.xpath("//XCUIElementTypeStaticText[@name=\"All Languages\"]")),
	
	HelpSettingsGEAR(By.xpath("//XCUIElementTypeButton[@name=\"helpAndSettings\"]")),
	
	
	AudioLanguageTileSplit(By.id("selectedAudioLanguage")),  
	VideoLanguageTileSplit(By.id("selectedVideoLanguage")), 
	
	SectionIndex(By.xpath("//XCUIElementTypeApplication[@name=\"LanguageLine\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther/XCUIElementTypeOther[6]/XCUIElementTypeOther]")),
	
	
	Alphabet_S_Displayed(By.xpath("//XCUIElementTypeButton[@name=\"alphaIndexS\"]")),                               
	SamoanLanguage(By.xpath("//XCUIElementTypeCell[@name=\"Samoan\"]")),  
	SangoLanguage(By.xpath("XCUIElementTypeCell[@name=\"Sango\"]")),
	SeraikiLanguage(By.xpath("XCUIElementTypeCell[@name=\"Seraiki\"]")),
	
	
	LanguageListBasedOnIndex(By.xpath("//XCUIElementTypeApplication[@name=\"InSight\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeOther[6]/XCUIElementTypeCollectionView/XCUIElementTypeCell")),   
	LanguageListBasedOnSearch(By.xpath("//XCUIElementTypeApplication[@name=\"InSight\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeOther[6]/XCUIElementTypeCollectionView/XCUIElementTypeCell")),
	
	VietnameseLanguage(By.xpath("XCUIElementTypeStaticText[@name=\"Vietnamese\"]")),
	VietnameseSectionIUndex(By.xpath("//XCUIElementTypeStaticText[@name=\"alphaIndexV\"]")),
	
	
	Alphabet_F_Displayed(By.xpath("//XCUIElementTypeButton[@name=\"alphaIndexF\"]")),
	FrenchLanguage(By.xpath("XCUIElementTypeStaticText[@name=\"French\"]")),
	GermanLanguage(By.xpath("XCUIElementTypeStaticText[@name=\"German\"]")),
	
	
	SearchLanguages(By.xpath("//XCUIElementTypeSearchField[@name=\"Search by Language or Country\"]")),
	SpanishBySearch(By.xpath("//XCUIElementTypeStaticText[@name=\"Spanish\"]")),  

	Punjabi(By.xpath("XCUIElementTypeStaticText[@name=\"Punjabi\"]")),
	AmericanSignLanguage(By.xpath("//XCUIElementTypeStaticText[@name=\"American Sign Language\"]")),
	Portuguese(By.xpath("XCUIElementTypeStaticText[@name=\"Portuguese\"]")),
	Cantonese(By.xpath("//XCUIElementTypeStaticText[@name=\"Cantonese\"]")),
	Chaochow(By.xpath("//XCUIElementTypeStaticText[@name=\"Chaochow\"]")),
	
	Acholi(By.xpath("//XCUIElementTypeStaticText[@name=\"Acholi\"]")),
	
	
	//*******************************************************When we Click on ASL, next page opens up on top of it with its schedule     BEGIN **************************************************************************//
	
	ASL_VideoLanguage(By.xpath("//XCUIElementTypeStaticText[@name=\"American Sign Language Video Schedule\"]")),     //Page that opens up when we click on ASL language --> View Video Availability
	ShowAllLanguagesLinkBelow(By.xpath("//XCUIElementTypeSearchField[@name=\"Search Languages\"]")),                 //Show All Languages Link present below the schedule
	CloseAtTop(By.xpath("//XCUIElementTypeOther[@name=\"InterpreterAvailabilityClose\"]")),                          //Close displayed at the Top                                                                                                                                                   
	
	//*******************************************************When we Click on ASL, next page opens up on top of it with its schedule     END **************************************************************************//
	
	//  "LanguageLine LOGO" on Main page where All Languages and TOP languagaes are displayed
	Logo_HomePage(By.xpath("//XCUIElementTypeImage[@name=\"homePageSmallLogo\"]")),
	
	
	
	//AlertMessage_NoLanguagesMatchYourSearch(By.xpath("XCUIElementTypeStaticText[@name=\"noSearchResults\"]")),
	
	AlertMessage_NoLanguagesMatchYourSearch(By.xpath("//XCUIElementTypeApplication[@name=\"InSight\"]/XCUIElementTypeWindow[1]"
			+ "/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeOther[6]/XCUIElementTypeStaticText")),	
	
	
	GearIconAtTOP(By.xpath("//XCUIElementTypeStaticText[@name=\"helpAndSettings\"]")),
	HelpAndSettingsLink_GearIcon(By.xpath("//XCUIElementTypeOther[@name=\"helpAndSettingsContainer\"]"));
	
	
	
	
	

	private final By locator;

	LanguageScreenUI(By locator) {
		this.locator = locator;
	}

	@Override
	public By toBy() {
		return locator;
	}
	
	
	
	//  WebElement el = driver.findElementByAccessibilityId(MobileBy.AccessibilityId("foo"));
	  
	  //public void clickDialogBox_Reset() { el.click(); }
	 
	
	
	
	
	
	
	
	
	

}
