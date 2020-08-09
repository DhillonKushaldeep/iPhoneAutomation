package com.appium.pages;

import static com.appium.locator.LanguageScreenUI.*;
import static com.appium.locator.LoginUI.*;
import static com.appium.locator.LoginUI.HelpAndSettingsLink_GearIcon;

import java.util.List;

import org.openqa.selenium.WebElement;

import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class LanguageScreen extends BasePage {
	
	public LanguageScreen(AppiumDriver driver) {
		super(driver);
	}
	
    public void verifyLogo_isPresentHomePage() throws InterruptedException{		
		
    	waitForElementPresent(Logo_HomePage.toBy());
		Thread.sleep(1000);
	
	}
    
    public void verify_TopLanguages() throws InterruptedException{		
		
    	waitForElementPresent(TopLanguages.toBy());
		Thread.sleep(1000);
	
	}
    
    public void verify_AllLanguages() throws InterruptedException{		
		
    	waitForElementPresent(AllLanguages.toBy());
		Thread.sleep(1000);
	
	}
    
    public void click_AllLanguages() throws InterruptedException{		
		
    	click(AllLanguages.toBy());
		Thread.sleep(1000);
	
	}
    
   
    public void click_AudioLanguageTileSplit() throws InterruptedException{		//
		
    	click(AudioLanguageTileSplit.toBy());
		Thread.sleep(1000);
	
	}

    public void click_VideoLanguageTileSplit() throws InterruptedException{		//
	
	   click(VideoLanguageTileSplit.toBy());
	   Thread.sleep(1000);

   }
    
   public void verify_searchLanguagesDisplayed() throws InterruptedException{		
		
    	waitForElementPresent(SearchLanguages.toBy());
		Thread.sleep(1000);
		
	}
    
    public void click_searchLanguages(String text) throws InterruptedException{		
		
    	click(SearchLanguages.toBy());
		Thread.sleep(2000);	
		setText(SearchLanguages.toBy(), text);
	}
    
    public void verify_SectionIndexDisplayed() throws InterruptedException{		
		
    	waitForElementPresent(SearchLanguages.toBy());
		Thread.sleep(1000);
		
	}
    
    public void verify_AlertMessageDisplayed() throws InterruptedException{		
		
    	waitForElementPresent(AlertMessage_NoLanguagesMatchYourSearch.toBy());
		Thread.sleep(1000);
		
	}
    
    public void verify_SpanishLanguageDisplayed() throws InterruptedException{		
		
    	waitForElementPresent(SpanishBySearch.toBy());
		Thread.sleep(1000);
		
	}
    
    public void click_SpanishLanguage() throws InterruptedException{		
		
    	click(SpanishBySearch.toBy());
		Thread.sleep(2000);	
	}
    
   public void click_AmericanSignLanguage() throws InterruptedException{		
		
    	click(AmericanSignLanguage.toBy());
		Thread.sleep(4000);	
	}
    
    public void click_PunjabiLanguage() throws InterruptedException{		
		
    	click(Punjabi.toBy());
		Thread.sleep(2000);	
		
	}
    
    public void click_PortugueseLanguage() throws InterruptedException{		
		
    	click(Portuguese.toBy());
		Thread.sleep(2000);	
		
	}
    
    public void clickFrenchLanguage() throws InterruptedException{		
		
    	click(FrenchLanguage.toBy());
		Thread.sleep(2000);	
		
	}
    
   public void clickCantonese() throws InterruptedException{		
		
    	click(Cantonese.toBy());
		Thread.sleep(2000);	
		
	}
    
    public void click_AcholiLanguage() throws InterruptedException{		
		
    	click(Acholi.toBy());
		Thread.sleep(2000);	
		
	}
    
   public void click_Vietnamese() throws InterruptedException{		
		
    	click(VietnameseLanguage.toBy());
		Thread.sleep(2000);	
		
	}
   
   public void click_GearIconAtTOP() throws InterruptedException{		
		
   	click(GearIconAtTOP.toBy());
		Thread.sleep(2000);	
		
	}
    
    
    public void verify_LanguageDisplayed_BySeaching_forChina() throws InterruptedException{		
		
    	waitForElementPresent(Cantonese.toBy());
		Thread.sleep(1000);
		waitForElementPresent(Chaochow.toBy());
		Thread.sleep(1000);
		
	}
    
    public void verify_LanguageDisplayed_BySeaching_forSWI() throws InterruptedException{		
		
    	waitForElementPresent(FrenchLanguage.toBy());
		Thread.sleep(1000);
		waitForElementPresent(GermanLanguage.toBy());
		Thread.sleep(1000);
		
	}
    
    public void verify_LanguageDisplayed_BySeaching_forDEUT() throws InterruptedException{		
		
		waitForElementPresent(GermanLanguage.toBy());
		Thread.sleep(1000);
		
	}
    
    public void click_VietnameseLanguage() throws InterruptedException{		
		
	    click(VietnameseSectionIUndex.toBy());              //click on Alpabet V in Section Index and then click on Vietnamese language
		Thread.sleep(1000);
    	click(VietnameseLanguage.toBy());
		Thread.sleep(1000);
		
	}

     public void click_FrenchLanguage() throws InterruptedException{		
		
	    click(Alphabet_F_Displayed.toBy());              //click on Alpabet F
		Thread.sleep(1000);
    	click(FrenchLanguage.toBy());
		Thread.sleep(1000);
		click(FrenchLanguage.toBy());
	
	}
  
     public void click_AudioFrenchLanguage() throws InterruptedException{		
 		
 	    click(Alphabet_F_Displayed.toBy());              //click on Alpabet F
 		Thread.sleep(1000);
     	click(FrenchLanguage.toBy());
 		Thread.sleep(1000);
 	
 	}
     
     public void click_FrenchVideoLanguage() throws InterruptedException{		
 		
 	    click(Alphabet_F_Displayed.toBy());              
 		Thread.sleep(1000);
     	click(FrenchLanguage.toBy());
 		Thread.sleep(1000);
 	
 	}
  
  
    public void click_alpahbetS() throws InterruptedException{		
		
    	click(Alphabet_S_Displayed.toBy());              //click on Alpabet S
		Thread.sleep(1000);
		waitForElementPresent(SamoanLanguage.toBy());    //Samoan language is displayed
		Thread.sleep(1000);
		waitForElementPresent(SangoLanguage.toBy());     //Sango language is displayed
		Thread.sleep(1000);
		waitForElementPresent(SeraikiLanguage.toBy());    //Seraiki language is displayed
		Thread.sleep(1000);
		
	}
 
    public void click_HelpAndSettingsLink_GearIcon() throws InterruptedException{		
		
    	click(HelpAndSettingsLink_GearIcon.toBy());
		Thread.sleep(1000);
	
	}
    
  //*******************************************************When we Click on ASL, next page opens up on top of it with its schedule     BEGIN **************************************************************************//
	
    public void click_CloseAtTopLink() throws InterruptedException{		
		
    	click(CloseAtTop.toBy());
		Thread.sleep(1000);
	
	}

    public void verify_ASL_VideoLanguageDisplayed() throws InterruptedException{		
		
		waitForElementPresent(ASL_VideoLanguage.toBy());
		Thread.sleep(1000);
		
	}

    public void verify_ShowAllLanguagesLinkBelowDisplayed() throws InterruptedException{		
	
	    waitForElementPresent(	ShowAllLanguagesLinkBelow.toBy());
	    Thread.sleep(1000);
	
}

    
  //*******************************************************When we Click on ASL, next page opens up on top of it with its schedule     END **************************************************************************//
	
    
   
    
}