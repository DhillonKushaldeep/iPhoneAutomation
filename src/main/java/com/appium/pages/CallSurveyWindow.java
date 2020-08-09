package com.appium.pages;

import static com.appium.locator.CallSurveyWindowUI.*;
import static com.appium.locator.LanguageScreenUI.SearchLanguages;

import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class CallSurveyWindow extends BasePage {
	
	public CallSurveyWindow(AppiumDriver driver) {
		super(driver);
	}
	

    //********************************************** Survey Window Start **************************************************//
    
    public void verifyCallEndedIconDisplayed() throws InterruptedException{		
  		
	  	   waitForElementPresent(CallEndedIcon.toBy());
	  	   Thread.sleep(1000);
	  	
	}
    
    public void verifyHowDidWeDo_Displayed() throws InterruptedException{		
  		
	  	   waitForElementPresent(HowDidWeDo.toBy());
	  	   Thread.sleep(1000);
	  	
	}
    
    public void click_CallEnded_StarOne() throws InterruptedException{		
		
 	     click(CallEndedStarOne.toBy());
	     Thread.sleep(2000);
	
	}

    public void click_Skip() throws InterruptedException{		
		
  	     click(Skip.toBy());
	     Thread.sleep(2000);
	
	}
    
    public void click_TextBox(String text) throws InterruptedException{		
		
    	click(CallEndedTextFeedback.toBy());
		Thread.sleep(2000);	
		setText(CallEndedTextFeedback.toBy(), text);
	}
    
    public void click_Done() throws InterruptedException{		
		
 	     click(Done.toBy());
	     Thread.sleep(2000);
	
	}
    
    
   //*********************************************** Survey Window End ***************************************************//   


    
}
	
	

