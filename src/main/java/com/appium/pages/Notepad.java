package com.appium.pages;

import static com.appium.locator.NotepadUI.*;
import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class Notepad extends BasePage {
	
	public Notepad(AppiumDriver driver) {
		super(driver);
	}
	

    //********************************************** Notepad Window Start **************************************************//
    
    public void verifyMessageDisplayedInNotepad() throws InterruptedException{		//Message like "This is a TEST" in TEXTBOX
  		
	  	   waitForElementPresent(Notepad_Message.toBy());
	  	   Thread.sleep(1000);
	  	
	}
    
    public void verifyWhiteBoardDetailsDisplayed() throws InterruptedException{		//WhiteBoard Details like Punjabi/316250 Kushal
  		
	  	   waitForElementPresent(WhiteBoardDetails.toBy());
	  	   Thread.sleep(1000);
	  	
	}

    public void click_MinimizeNotepad() throws InterruptedException{		
		
  	     click(Notepad_Minimize.toBy());
	     Thread.sleep(2000);
	
	}
    
    public void click_ScrollUP() throws InterruptedException{		
		
 	     click(ScrollUP.toBy());
	     Thread.sleep(2000);
	
	}
    
    public void click_ScrollDown() throws InterruptedException{		
		
 	     click(ScrollDown.toBy());
	     Thread.sleep(2000);
	
	}
    
    
   //*********************************************** Notepad Window End ***************************************************//   


    
}
	
	