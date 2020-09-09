package com.appium.pages;

import static com.appium.locator.LoginUI.BackButton;
import static com.appium.locator.ResetDeviceUI.*;

import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class ResetDevice extends BasePage {
	
	public ResetDevice(AppiumDriver driver) {
		super(driver);
	}
	
    public void resetDeviceApp() throws InterruptedException{
		
		click(ChangeCode.toBy());
		Thread.sleep(1000);
		click(ResetDeviceActivation_RESET.toBy());
		Thread.sleep(1000);
		
	}
    
    
   public void DeviceLoginresetDeviceApp() throws InterruptedException{   //
		
		click(DeviceConfigLink.toBy());
		Thread.sleep(1000);
		
	}

    public void settingSymbolAtTop_click() throws InterruptedException{		
		
    	click(HelpSettingsGEAR.toBy());
		Thread.sleep(1000);
		click(DeviceConfigLink.toBy());
		Thread.sleep(1000);
		
	}
    
   public void resetDevice_changeCode() throws InterruptedException{		
		
		click(ChangeCode.toBy());
		Thread.sleep(1000);
		
	}
    
   public void resetDevice_clickReset() throws InterruptedException{		
		
		click(ResetDeviceActivation_RESET.toBy());
		Thread.sleep(1000);
		
	}
   
   public void resetDevice_clickCancel() throws InterruptedException{	
		
		click(DeviceConfigLink.toBy());
		Thread.sleep(1000);
		click(ResetDeviceActivation_CANCEL.toBy());
		Thread.sleep(1000);
		
	}
    
   public void clickBack() throws InterruptedException{		//new
		
	    click(BackButton.toBy());
		Thread.sleep(1000);
		
	}
    
}
	
	

