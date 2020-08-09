package com.appium.locator;

import org.openqa.selenium.By;

public enum LanguageScreenUI implements ILocator {
	
		
	TopLanguages(By.xpath("//XCUIElementTypeStaticText[@name=\"Top Languages\"]")),
	AllLanguages(By.xpath("//XCUIElementTypeStaticText[@name=\"All Languages\"]")),
	
	
	AudioLanguageTileSplit(By.id("selectedAudioLanguage")),  
	VideoLanguageTileSplit(By.id("selectedVideoLanguage")),  
	
	
	
	
	
	//XCUIElementTypeApplication[@name="LanguageLine"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell[1]/XCUIElementTypeOther
	
	//XCUIElementTypeApplication[@name="LanguageLine"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell[1]/XCUIElementTypeOther  Audio
	//XCUIElementTypeApplication[@name="LanguageLine"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell[2]/XCUIElementTypeOther  Audio
	//XCUIElementTypeApplication[@name="LanguageLine"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell[3]/XCUIElementTypeOther  Audio
	//XCUIElementTypeApplication[@name="LanguageLine"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell[4]/XCUIElementTypeOther  Audio
	//XCUIElementTypeApplication[@name="LanguageLine"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell[8]/XCUIElementTypeOther  Video
	
	SectionIndex(By.xpath("//XCUIElementTypeApplication[@name=\"LanguageLine\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther/XCUIElementTypeOther[6]/XCUIElementTypeOther]")),
	
	
	Alphabet_S_Displayed(By.xpath("//XCUIElementTypeStaticText[@name=\"alphaIndexS\"]")),
	SamoanLanguage(By.xpath("//XCUIElementTypeCell[@name=\"Samoan\"]")),
	SangoLanguage(By.xpath("//XCUIElementTypeCell[@name=\"Sango\"]")),
	SeraikiLanguage(By.xpath("//XCUIElementTypeCell[@name=\"Seraiki\"]")),
	VietnameseLanguage(By.xpath("//XCUIElementTypeCell[@name=\"Vietnamese\"]")),
	VietnameseSectionIUndex(By.xpath("//XCUIElementTypeStaticText[@name=\"alphaIndexV\"]")),
	
	
	Alphabet_F_Displayed(By.xpath("//XCUIElementTypeStaticText[@name=\"alphaIndexF\"]")),
	FrenchLanguage(By.xpath("//XCUIElementTypeCell[@name=\"French\"]")),
	GermanLanguage(By.xpath("//XCUIElementTypeCell[@name=\"German\"]")),
	
	
	SearchLanguages(By.xpath("//XCUIElementTypeSearchField[@name=\"Search Languages\"]")),
	SpanishBySearch(By.xpath("//XCUIElementTypeCell[@name=\"Spanish\"]")),
	Punjabi(By.xpath("//XCUIElementTypeCell[@name=\"Punjabi\"]")),
	AmericanSignLanguage(By.xpath("//XCUIElementTypeCell[@name=\"American Sign Language\"]")),
	Portuguese(By.xpath("//XCUIElementTypeCell[@name=\"Portuguese\"]")),
	Cantonese(By.xpath("//XCUIElementTypeCell[@name=\"Cantonese\"]")),
	Chaochow(By.xpath("//XCUIElementTypeCell[@name=\"Chaochow\"]")),
	
	Acholi(By.xpath("//XCUIElementTypeCell[@name=\"Acholi\"]")),
	
	
	//*******************************************************When we Click on ASL, next page opens up on top of it with its schedule     BEGIN **************************************************************************//
	
	ASL_VideoLanguage(By.xpath("//XCUIElementTypeStaticText[@name=\"American Sign Language Video Schedule\"]")),     //Page that opens up when we click on ASL language --> View Video Availability
	ShowAllLanguagesLinkBelow(By.xpath("//XCUIElementTypeSearchField[@name=\"Search Languages\"]")),                 //Show All Languages Link present below the schedule
	CloseAtTop(By.xpath("//XCUIElementTypeOther[@name=\"InterpreterAvailabilityClose\"]")),                          //Close displayed at the Top
	
	//*******************************************************When we Click on ASL, next page opens up on top of it with its schedule     END **************************************************************************//
	
	//  "LanguageLine LOGO" on Main page where All Languages and TOP languagaes are displayed
	Logo_HomePage(By.xpath("//XCUIElementTypeImage[@name=\"homePageSmallLogo\"]")),
	
	
	
	AlertMessage_NoLanguagesMatchYourSearch(By.xpath("//XCUIElementTypeStaticText[@value=\"No languages match your search. Please double check your entry.\n" + 
			"\"]")),
	
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

}
