package com.appium.pages;

import static com.appium.locator.LanguageScreenUI.*;
import static com.appium.locator.HoldScreen_AudioUI.AudioCallCancelButton;
import static com.appium.locator.HoldScreen_VideoUI.*;
import static com.appium.locator.ResetDeviceUI.*;

import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class HoldScreen_Video extends BasePage {
	
	public HoldScreen_Video(AppiumDriver driver) {
		super(driver);
	}
	

	//******************************************************************************************************8***************************//
	public void verifyLoadingSpinnerDisplayed() throws InterruptedException{		
 		
	  	   waitForElementPresent(LoadingSpinner.toBy());
	  	   Thread.sleep(1000);
	  	
  	}
	
	

     //Connecting to Your French(any) Interpreter is displayed
     public void verifyConnectingtoYourInterpreterdDisplayed() throws InterruptedException{		
		
	   waitForElementPresent(labelConnectingToYour.toBy());
	   Thread.sleep(1000);
	   waitForElementPresent(labelWaiting.toBy());
	   Thread.sleep(1000);
	   waitForElementPresent(labelInterpreter.toBy());
	   Thread.sleep(1000);
	
	}
    
     public void click_CancelCall() throws InterruptedException{		
 		
     	click(CancelCall.toBy());
 		Thread.sleep(1000);
 	
 	}
    
   //****************************************************************************************************************************************//
     
     
     
   //****************************************************************************************************************************************// 
     
     //FOR SCREEN: 
    //Sorry, we are currently unable to connect to your video interpreter at this time. 
 	//Please try again later or switch to an audio interpreter immediately.
 	//Below of this text: Cancel Video Call and Switch To Audio are displayed
     public void verifysorryNoVideoINTavailableMessageDisplayed() throws InterruptedException{		
  		
	  	   waitForElementPresent(sorryNoVideoINTavailableMessage.toBy());
	  	   Thread.sleep(1000);
	  	
	  	
	}

     public void click_CancelVideoCall() throws InterruptedException{		
  		
      	click(Cancel_VideoCall.toBy());
  		Thread.sleep(1000);
  	
  	}
     
     public void click_SwitchToAudio() throws InterruptedException{		
  		
      	click(SwitchToAudio.toBy());
  		Thread.sleep(1000);
  	
  	}

   //****************************************************************************************************************************************//





    
}
	
	

