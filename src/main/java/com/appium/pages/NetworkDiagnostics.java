package com.appium.pages;

import static com.appium.locator.LanguageScreenUI.*;
import static com.appium.locator.LoginUI.CloseButton;
import static com.appium.locator.HelpAndSettingsLinkUI.*;
import static com.appium.locator.NetworkDiagnosticsUI.*;
import static com.appium.locator.ResetDeviceUI.*;

import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class NetworkDiagnostics extends BasePage {
	
	public NetworkDiagnostics(AppiumDriver driver) {
		super(driver);
	}
	
	
		
    public void click_NetworkDiagnosticsLink() throws InterruptedException{		
		
    	click(NetworkDiagnosticsLink.toBy());
		Thread.sleep(1000);
		System.out.println("Clicked on Network Diagnostics Link");
	
	}
	
    public void click_RunNetworkDiagnostic() throws InterruptedException{		
		
    	click(RunNetworkDiagnostic.toBy());
		Thread.sleep(1000);
		System.out.println("Clicked on Run Network Diagnostic Link");
	
	}

   public void verifyGreenCheckmark() throws InterruptedException{		
		
	   waitForElementPresent(GreenCheckAPIConnectivity.toBy());
	   Thread.sleep(1000);
	   System.out.println("Green checkmark for API Connectivity is displayed Successfully");
	   
	   waitForElementPresent(GreenCheckVideoCalls.toBy());
	   Thread.sleep(1000);
	   System.out.println("Green checkmark for Video Calls is displayed Successfully");
	   
		waitForElementPresent(GreenCheckAudioCalls.toBy());
		Thread.sleep(1000);
		System.out.println("Green checkmark for Audio Calls is displayed Successfully");
	
	}

   public void verifyTestSkipped() throws InterruptedException{		
		
	   waitForElementPresent(TestSkippedVideoCalls.toBy());
	   Thread.sleep(1000);
	   System.out.println("Test Skipped for Video Calls is displayed Successfully");
	   
	   waitForElementPresent(TestSkippedAudioCalls.toBy());
	   Thread.sleep(1000);
	   System.out.println("Test Skipped for Audio Calls is displayed Successfully");
	
	}
   
   public void videoCallsErrorCodeMessage2A() throws InterruptedException{		
		
	   waitForElementPresent(VideoCalls_ErrorCodeMessage2A.toBy());
	   Thread.sleep(1000);
	   System.out.println("Failed, Error Code: 2A is displayed Successfully"); 
	
	}
   
   public void audioCallsErrorCodeMessage3A() throws InterruptedException{		
		
	   waitForElementPresent(AudioCalls_ErrorCodeMessage3A.toBy());
	   Thread.sleep(1000);
	   System.out.println("Failed, Error Code: 3A is displayed Successfully"); 
	
	}
   
   
   public void completeFail() throws InterruptedException{		
		
	   waitForElementPresent(Complete_Fail.toBy());
	   Thread.sleep(1000);
	   System.out.println("Test Complete FAILED is displayed Successfully"); 
	
	}
    
   public void click_StopTest() throws InterruptedException{		
		
   	    click(StopTest.toBy());
		Thread.sleep(1000);
		System.out.println("Clicked on STOP TEST");
	
	}



   public void clickClose() throws InterruptedException{		//At Top
	 	
 	    click(Close.toBy());
		Thread.sleep(1000);
		System.out.println("Click Close link at the TOP");
	
	}















    
}
	
	

