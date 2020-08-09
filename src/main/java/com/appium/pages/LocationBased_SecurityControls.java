package com.appium.pages;

import static com.appium.locator.LocationBased_SecurityControlsUI.*;
import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class LocationBased_SecurityControls extends BasePage {
	
	public LocationBased_SecurityControls(AppiumDriver driver) {
		super(driver);
	}
	

    //**********************************************  Start **************************************************//
    
    public void verifyAlertMessageDisplayed_CallFailedDueToLocation() throws InterruptedException{		
  		
	  	   waitForElementPresent(CallFailed.toBy());
	  	   Thread.sleep(1000);
	  	  
	  	
	}

    public void verifyAlertMessageDisplayed_YourOrganizAllowAccess() throws InterruptedException{		
  		
	  	   waitForElementPresent(Message.toBy());
	  	   Thread.sleep(1000);
	  	   
	  	
	}
    
    public void click_OKOnAlert() throws InterruptedException{		
		
 	       click(OK.toBy());
	       Thread.sleep(2000);
	
	}
    
   
    
    
   //***********************************************  End   ***************************************************//   


    
}
	
	