package com.appium.pages;

import static com.appium.locator.Connected_VideoScreenUI.*;
import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class Connected_VideoScreen extends BasePage {
	
	public Connected_VideoScreen(AppiumDriver driver) {
		super(driver);
	}
	

	
	public void verifyAudioMuteON_isPresent() throws InterruptedException{		
 		
	  	   waitForElementPresent(audioMuteON.toBy());
	  	   Thread.sleep(1000);
	  	
  	}
	
	 public void click_AudioMuteON() throws InterruptedException{		
	 		
	     	click(audioMuteON.toBy());
	 		Thread.sleep(1000);
	 	
	 	}
	
	public void verifyAudioMuteOFF_isPresent() throws InterruptedException{		
 		
	  	   waitForElementPresent(audioMuteOFF.toBy());
	  	   Thread.sleep(1000);
	  	
	}
    
    
     public void click_AudioMuteOFF() throws InterruptedException{		
 		
     	click(audioMuteOFF.toBy());
 		Thread.sleep(1000);
 	
 	}
    
     public void click_VideoMuteON() throws InterruptedException{		//To turn back OFF the Video
  		
      	click(videoButtonImageOn.toBy());
  		Thread.sleep(1000);
  	
  	}
     
     public void verifyVideoMuteOFF_isPresent() throws InterruptedException{		
  		
	  	   waitForElementPresent(videoButtonImageOff.toBy());
	  	   Thread.sleep(1000);
	  	
	}
     
     public void click_VideoMuteOFF() throws InterruptedException{		//To turn back ON the Video
  		
      	click(videoButtonImageOff.toBy());
  		Thread.sleep(1000);
  	
  	}
     
     public void verifyVideoON_isPresent() throws InterruptedException{		     //when Video is ON
   		
	  	   waitForElementPresent(VideoON_atTOP.toBy());
	  	   Thread.sleep(1000);
	  	
	}
     
     public void verifyVideoOFF_isPresent() throws InterruptedException{		//when Video is disabled by customer
   		
	  	   waitForElementPresent(VideoOFF_atTOP.toBy());
	  	   Thread.sleep(1000);
	  	
	}
     
     
     
     
    
    public void verifyCallEndDisplayed() throws InterruptedException{		
  		
	  	   waitForElementPresent(videoHangupButton.toBy());
	  	   Thread.sleep(1000);
	  	
	}
   
    public void click_CallEnd() throws InterruptedException{		
 		
     	click(videoHangupButton.toBy());
 		Thread.sleep(1000);
 	
 	}
    
    
    
    

    
}
	
	

