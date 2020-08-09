package com.appium.pages;

import static com.appium.locator.LanguageScreenUI.*;
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
	
	}
	
    public void click_RunNetworkDiagnostic() throws InterruptedException{		
		
    	click(RunNetworkDiagnostic.toBy());
		Thread.sleep(1000);
	
	}

   public void verifyGreenCheckmark() throws InterruptedException{		
		
	   waitForElementPresent(GreenCheckAPIConnectivity.toBy());
	   Thread.sleep(1000);
	   waitForElementPresent(GreenCheckVideoCalls.toBy());
	   Thread.sleep(1000);
		waitForElementPresent(GreenCheckAudioCalls.toBy());
		Thread.sleep(1000);
		waitForElementPresent(Complete_GreenLabel.toBy());
		Thread.sleep(1000);
	
	}

   public void verifyTestSkipped() throws InterruptedException{		
		
	   waitForElementPresent(TestSkippedVideoCalls.toBy());
	   Thread.sleep(1000);
	   waitForElementPresent(TestSkippedAudioCalls.toBy());
	   Thread.sleep(1000);
		waitForElementPresent(TestStopped_RedLabel.toBy());
		Thread.sleep(1000);
	
	}
   
   public void videoCallsErrorCodeMessage2A() throws InterruptedException{		
		
	   waitForElementPresent(VideoCalls_ErrorCodeMessage2A.toBy());
	   Thread.sleep(1000);
	
	}
   
   public void audioCallsErrorCodeMessage3A() throws InterruptedException{		
		
	   waitForElementPresent(AudioCalls_ErrorCodeMessage3A.toBy());
	   Thread.sleep(1000);
	
	}
   
   
   public void completeFail() throws InterruptedException{		
		
	   waitForElementPresent(Complete_Fail.toBy());
	   Thread.sleep(1000);
	
	}
    
   public void click_StopTest() throws InterruptedException{		
		
   	    click(StopTest.toBy());
		Thread.sleep(1000);
	
	}



















    
}
	
	

