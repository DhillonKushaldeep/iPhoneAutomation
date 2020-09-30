package com.appium.pages;

import static com.appium.locator.LanguageScreenUI.*;
import static com.appium.locator.LoginUI.*;
import static com.appium.locator.LoginUI.HelpAndSettingsLink_GearIcon;

import java.util.ArrayList;
import java.util.List;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.testng.Assert;

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
    
    public void click_HelpSettingsGEAR() throws InterruptedException{		
		
    	click(HelpSettingsGEAR.toBy());
		Thread.sleep(1000);
		System.out.println("Help and Settings GEAR");
	
	}
    
    public void click_AllLanguages() throws InterruptedException{		
		
    	click(AllLanguages.toBy());
		Thread.sleep(1000);
		System.out.println("clicked on All languages");
	
	}
   
    public void click_AudioLanguageTileSplit() throws InterruptedException{		//
		
    	click(AudioLanguageTileSplit.toBy());
		Thread.sleep(1000);
		System.out.println("Audio Language Tile Split");
	
	}

    public void click_VideoLanguageTileSplit() throws InterruptedException{		//
	
	   click(VideoLanguageTileSplit.toBy());
	   Thread.sleep(1000);
	   System.out.println("Video Language Tile Split");

   }
    
   public void verify_searchLanguagesDisplayed() throws InterruptedException{		
		
    	waitForElementPresent(SearchLanguages.toBy());
		Thread.sleep(1000);
		System.out.println("Search Languages");
		
	}
    
    public void click_searchLanguages(String text) throws InterruptedException{		
		
    	click(SearchLanguages.toBy());
		Thread.sleep(2000);	
		setText(SearchLanguages.toBy(), text);
		System.out.println("Search Languages displayed");
	}
    
    public void verify_SectionIndexDisplayed() throws InterruptedException{		
		
    	waitForElementPresent(SearchLanguages.toBy());
		Thread.sleep(1000);
		
	}
    
    public void verify_AlertMessageDisplayed() throws InterruptedException{		
		
    	waitForElementPresent(AlertMessage_NoLanguagesMatchYourSearch.toBy());
		Thread.sleep(1000);
		System.out.println("No languages match your search. Please double check your entry.");
		
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
   
   public void viewAmericanSignLanguageSchedule() throws InterruptedException{		
		
	   waitForElementPresent(AmericanSignLanguageVideoSchedule.toBy());
	   Thread.sleep(2000);
		
	   click(CloseSchedule.toBy());
	   Thread.sleep(2000);	
	}   
    
    public void click_PunjabiLanguage() throws InterruptedException{		
		
    	click(Punjabi.toBy());
		Thread.sleep(2000);	
		System.out.println("Clicked on PUNJABI successfully");
		
	}
    
    public void click_PortugueseLanguage() throws InterruptedException{		
		
    	click(Portuguese.toBy());
		Thread.sleep(2000);	
		System.out.println("Clicked on Portuguese successfully");
		
	}
    
    public void clickFrenchLanguage() throws InterruptedException{		
		
    	click(FrenchLanguage.toBy());
		Thread.sleep(2000);	
		System.out.println("Clicked on French successfully");
	}
    
   public void clickCantonese() throws InterruptedException{		
		
    	click(Cantonese.toBy());
		Thread.sleep(2000);
		System.out.println("Clicked on Cantonese successfully");
		
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
    
    public void click_FrenchLanguageAfterSearch() throws InterruptedException{
		
    	waitForElementPresent(FrenchLanguage.toBy());
		Thread.sleep(5000);
		System.out.println("French Language displayed");
		click(FrenchLanguage.toBy());
 		Thread.sleep(1000);
 		System.out.println("Clicked on French language");
 		
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
  
  
     //Method to Get the list of languages THAT start with "S" when we click on letter "S"
    //Samoan  Sango  Seraiki  Serbian  Shanghainese  Shona  Sichuan Yi  Sicilian Sinhala
     
    public void click_alpahbetS() throws InterruptedException{		
		
    	click(Alphabet_S_Displayed.toBy());              //click on Alphabet S
		Thread.sleep(1000);
		System.out.println("Alphabet S displayed and clicked");
		
		List<WebElement> elements =   driver.findElements(LanguageListBasedOnIndex.toBy());
		
         for(WebElement element : elements ){                
             System.out.println(element.getAttribute("name"));
             Assert.assertTrue(element.getAttribute("name").startsWith("S"));
        
     }
				
 }
    
	public void click_alpahbetF() throws InterruptedException{		
			
	    	click(Alphabet_F_Displayed.toBy());              //click on Alphabet F
			Thread.sleep(1000);
			System.out.println("Alphabet F displayed and clicked");
					
	 }
    
    
	    //Method to Get the list of languages THAT shows up after searching in search box "SPA" or "CHINA"
	    // "SPA" -->    Basque, Catalan, Spanish
       // "CHINA" -->   Cantonese  Chaochow Fukienese Fuzhou Hakka-china Hmong Hunanese Jinyu Kyrgyz
       // "SWI"  -->    French  German
       // "DUET"  -->   German
	     
	    public void searchFor_LanguagesTypedInSearchBox() throws InterruptedException{		
			
	    	waitForElementPresent(LanguageListBasedOnSearch.toBy());              //search for SPA, CHINA
			Thread.sleep(1000);
			System.out.println("LETTERS typed in Search Box");
			
			List<WebElement> elements =   driver.findElements(LanguageListBasedOnSearch.toBy());
			
	         for(WebElement element : elements ){                
	             System.out.println(element.getAttribute("name"));        
	        
	     }
					
	 }
    
    
    
		public void verify_Samoan_LanguageDisplayed() throws InterruptedException{	
				
				waitForElementPresent(SamoanLanguage.toBy());
				Thread.sleep(1000);
				System.out.println("Samoan Language displayed");
			}
		
		
		public void verify_Sango_LanguageDisplayed() throws InterruptedException{		
			
			waitForElementPresent(SangoLanguage.toBy());
			Thread.sleep(1000);
			System.out.println("Sango Language displayed");
		}
		
		
		public void verify_Seraiki_LanguageDisplayed() throws InterruptedException{		
			
			waitForElementPresent(SeraikiLanguage.toBy());
			Thread.sleep(1000);
			System.out.println("Seraiki Language displayed");
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