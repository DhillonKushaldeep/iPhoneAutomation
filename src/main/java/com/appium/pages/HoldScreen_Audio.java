package com.appium.pages;

import static com.appium.locator.HoldScreen_AudioUI.*;
import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class HoldScreen_Audio extends BasePage {
	
	public HoldScreen_Audio(AppiumDriver driver) {
		super(driver);
	}
	
   
		
    public void click_AudioCallHangup() throws InterruptedException{	
    	
    	 waitForElementPresent(AudioCallHangupButton.toBy());
    	 Thread.sleep(1000);
    	click(AudioCallHangupButton.toBy());
		Thread.sleep(1000);
	
	}

   public void verifyConnectedLabelDisplayed() throws InterruptedException{		
		
	   waitForElementPresent(ConnectedLabel.toBy());
		Thread.sleep(1000);
	
	}

   public void verifyAudioCallSpeakerButtonDisplayed() throws InterruptedException{		
		
	   waitForElementPresent(AudioCallSpeakerButtonOn.toBy());
		Thread.sleep(1000);
	
	}
   
   public void verifyAudioCallMuteButtonOnDisplayed() throws InterruptedException{		
		
	   waitForElementPresent(AudioCallMuteButtonOn.toBy());
		Thread.sleep(1000);
	
	}
    
    
   public void verifyAudioCallMuteButtonOFFDisplayed() throws InterruptedException{		
		
	   click(AudioCallMuteButtonOn.toBy());
	   Thread.sleep(1000);
	   waitForElementPresent(AudioCallMuteButtonOff.toBy());
		Thread.sleep(2000);
		 click(AudioCallMuteButtonOn.toBy());
	    System.out.println("Audio Call Mute Button is ON again");
	
	}
   
   

   public void LabelAuthorizingDisplayed() throws InterruptedException{		
		
	   waitForElementPresent(LabelAuthorizing.toBy());
		
	
	}
   
   public void LabelInitializingDisplayed() throws InterruptedException{		
		
	   waitForElementPresent(LabelInitializing.toBy());
	
	}
   
   public void LabelConnectingDisplayed() throws InterruptedException{		
		
	   waitForElementPresent(LabelConnecting.toBy());
	
	
	}
   
   public void LabelConnectedDisplayed() throws InterruptedException{		
		
	   waitForElementPresent(LabelConnected.toBy());
		
	
	}






    
}
	
	

