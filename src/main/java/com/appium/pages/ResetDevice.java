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
		
		click(SettingsSymbol_AtTOP.toBy());
		Thread.sleep(1000);
		click(DeviceLoginLink.toBy());
		Thread.sleep(1000);
		click(ResetDeviceButton.toBy());
		Thread.sleep(1000);
		click(ResetDeviceActivation_RESET.toBy());
		Thread.sleep(1000);
		
	}
    
    
   public void DeviceLoginresetDeviceApp() throws InterruptedException{   //
		
		click(DeviceLoginLink.toBy());
		Thread.sleep(1000);
		click(ResetDeviceButton.toBy());
		Thread.sleep(1000);
		click(ResetDeviceActivation_RESET.toBy());
		Thread.sleep(1000);
		
	}

    public void settingSymbolAtTop_click() throws InterruptedException{		
		
    	click(SettingsSymbol_AtTOP.toBy());
		Thread.sleep(1000);
		click(DeviceLoginLink.toBy());
		Thread.sleep(1000);
		
	}
    
   public void resetDevice_clickReset() throws InterruptedException{		
		
		click(ResetDeviceButton.toBy());
		Thread.sleep(1000);
		click(ResetDeviceActivation_RESET.toBy());
		Thread.sleep(1000);
		
	}
   
   public void resetDevice_clickCancel() throws InterruptedException{		//
		
		click(ResetDeviceButton.toBy());
		Thread.sleep(1000);
		click(ResetDeviceActivation_CANCEL.toBy());
		Thread.sleep(1000);
		
	}
    
   public void clickBack() throws InterruptedException{		//new
		
	    click(BackButton.toBy());
		Thread.sleep(1000);
		
	}
    
}
	
	

