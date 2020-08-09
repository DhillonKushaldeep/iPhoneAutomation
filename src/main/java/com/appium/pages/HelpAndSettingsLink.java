package com.appium.pages;

import static com.appium.locator.LoginUI.CloseButton;
import static com.appium.locator.LoginUI.GetAssistance;
import static com.appium.locator.LoginUI.GetAssistanceFirstQues;
import static com.appium.locator.LoginUI.TechnicalAssistance;
import static com.appium.locator.LoginUI.TechnicalAssistanceFirstQues;
import static com.appium.locator.NetworkDiagnosticsUI.NetworkDiagnosticsLink;
import static com.appium.locator.HelpAndSettingsLinkUI.*;
import java.util.ArrayList;
import java.util.List;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;

import com.appium.core.BasePage;
import io.appium.java_client.AppiumDriver;

public class HelpAndSettingsLink extends BasePage {
	
	public HelpAndSettingsLink(AppiumDriver driver) {
		super(driver);
	}
	
	 public void click_CallTime() throws InterruptedException{		
			
		   	click(CallTime.toBy());
			Thread.sleep(1000);
			
			}
	
  public List<String> captureTimeLog() throws InterruptedException{		
		
    //	click(CallTime.toBy());
		Thread.sleep(1000);
		 
	  List<WebElement> elements = driver.findElements((CallTime).toBy());
	  List<String> tableColumnData = new ArrayList<String>();	  
	  
		  for(int i=1; i<= elements.size() ; i++ ){
			  String locator = "//XCUIElementTypeApplication[@name=\"LanguageLine\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]"
			  		+ "/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell["+i+"]/XCUIElementTypeOther/XCUIElementTypeOther[1]/XCUIElementTypeStaticText[2]";
			  WebElement el  = driver.findElement(By.xpath(locator));
			  
		  		tableColumnData.add(el.getText());
		  	}
	    	return tableColumnData;
	      }
		
  
  
 /*

  String locator1 = "//XCUIElementTypeApplication[@name=\"LanguageLine\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]"
	  		+ "/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell["+i+"]/XCUIElementTypeOther/XCUIElementTypeOther[2]/XCUIElementTypeStaticText[1]";
  String locator2 = "//XCUIElementTypeApplication[@name=\"LanguageLine\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]"
	  		+ "/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell["+i+"]/XCUIElementTypeOther/XCUIElementTypeOther[2]/XCUIElementTypeStaticText[2]";
	 

*/


   public List<String> captureLanguageLog() throws InterruptedException{		
		
	    //	click(CallTime.toBy());
			Thread.sleep(1000);
			 
		  List<WebElement> elements = driver.findElements((CallTime).toBy());
		  List<String> tableColumnData = new ArrayList<String>();	  
		  
			  for(int i=1; i<= elements.size() ; i++ ){
				  String locator1 = "//XCUIElementTypeApplication[@name=\"LanguageLine\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]"
					  		+ "/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell["+i+"]/XCUIElementTypeOther/XCUIElementTypeOther[2]/XCUIElementTypeStaticText[1]";
				  
				  
					WebElement el  = driver.findElement(By.xpath(locator1));
			  		tableColumnData.add(el.getText());
			  	}
		    	return tableColumnData;
		      }
    
    
   
   public List<String> captureDurationLog() throws InterruptedException{		
		
	    //	click(CallTime.toBy());
			Thread.sleep(1000);
			 
		  List<WebElement> elements = driver.findElements((CallTime).toBy());
		  List<String> tableColumnData = new ArrayList<String>();	  
		  
			  for(int i=1; i<= elements.size() ; i++ ){
				  String locator2 = "//XCUIElementTypeApplication[@name=\"LanguageLine\"]/XCUIElementTypeWindow[1]/XCUIElementTypeOther[2]"
					  		+ "/XCUIElementTypeOther/XCUIElementTypeOther/XCUIElementTypeCollectionView/XCUIElementTypeCell["+i+"]/XCUIElementTypeOther/XCUIElementTypeOther[2]/XCUIElementTypeStaticText[2]";
					  WebElement el  = driver.findElement(By.xpath(locator2));
				  
			  		tableColumnData.add(el.getText());
			  	}
		    	return tableColumnData;
		      }
  
  
  
  
    
	
  public void verifyLogo_isPresent_HelpSettingsPage() throws InterruptedException{		
		
  	waitForElementPresent(Logo_HelpSettingsPage.toBy());
		Thread.sleep(1000);
	
	}
		
   public void verifyLogo_isPresent_DeviceLoginPage() throws InterruptedException{		
		
  	waitForElementPresent(Logo_DeviceLoginPage.toBy());
		Thread.sleep(1000);
	
	}
  
   public void verifyLogo_isPresent_TechnicalAssistancePage() throws InterruptedException{		
		
   	waitForElementPresent(Logo_TechnicalAssistancePage.toBy());
		Thread.sleep(1000);
	
	}
   
   public void verifyLogo_isPresent_VideoAvailabilityPage() throws InterruptedException{		
		
	   	waitForElementPresent(Logo_VideoAvailabilityPage.toBy());
			Thread.sleep(1000);
		
		}
   
   public void verifyLogo_isPresent_GetAssistancePage() throws InterruptedException{		
		
	   	waitForElementPresent(Logo_GetAssistancePage.toBy());
			Thread.sleep(1000);
		
		}

   public void verifyLogo_isPresent_CallHistoryPage() throws InterruptedException{		
		
	   	waitForElementPresent(Logo_GetAssistancePage.toBy());
			Thread.sleep(1000);
		
		}
   
   public void verifyLogo_isPresent_NetworkDiagnosticsPage() throws InterruptedException{		
		
	   	waitForElementPresent(Logo_NetworkDiagnosticsPage.toBy());
			Thread.sleep(1000);
		
		}
   
   public void click_ReturnToHelpAndSettings() throws InterruptedException{		
		
   	click(ReturnToHelpAndSettings.toBy());
		Thread.sleep(1000);
	
	}
   
   public void click_Back() throws InterruptedException{		
		
	   	click(Back.toBy());
			Thread.sleep(1000);
		
		}
  
    public void click_DeviceLogin() throws InterruptedException{		
		
    	click(DeviceLogin.toBy());
		Thread.sleep(1000);
	
	}
    
   public void click_NetworkDiagnosticsLink() throws InterruptedException{		
		
    	click(NetworkDiagnosticsLink.toBy());
		Thread.sleep(1000);
	
	}

   public void verifyLastActivated() throws InterruptedException{		
		
	   waitForElementPresent(LastActivated.toBy());
		Thread.sleep(1000);
	
	}

    public void verifyActivationCode() throws InterruptedException{		
		
	   waitForElementPresent(ActivationCode.toBy());
		Thread.sleep(1000);
	}
    
    
    
    
    public void verifyDeviceLogin() throws InterruptedException{		
		
 	   waitForElementPresent(DeviceLogin.toBy());
 		Thread.sleep(1000);
 	}
    
    public void verifyTechnicalAssistance() throws InterruptedException{		
		
 	   waitForElementPresent(TechnicalAssistance.toBy());
 		Thread.sleep(1000);
 	}
    
    public void verifyVideoAvailability() throws InterruptedException{		
		
 	   waitForElementPresent(VideoAvailability.toBy());
 		Thread.sleep(1000);
 	}
    
    public void verifyGetAssistance() throws InterruptedException{		
		
 	   waitForElementPresent(GetAssistance.toBy());
 		Thread.sleep(1000);
 	}
    
    public void verifyCallHistory() throws InterruptedException{		
		
 	   waitForElementPresent(CallHistory.toBy());
 		Thread.sleep(1000);
 	}
    
    public void clickCallHistory() throws InterruptedException{		
		
  	   waitForElementPresent(CallHistory.toBy());
  		Thread.sleep(1000);
  	}
     
    public void clickCallHistoryBackButton() throws InterruptedException{		
		
   	   waitForElementPresent(CallHistoryBackButton.toBy());
   		Thread.sleep(1000);
   	}
    
    public void verifyNetworkDiagnostics() throws InterruptedException{		
		
 	   waitForElementPresent(NetworkDiagnostics.toBy());
 		Thread.sleep(1000);
 	}
    
    public void verifyPlaceTestCall() throws InterruptedException{		
		
 	   waitForElementPresent(PlaceTestCall.toBy());
 		Thread.sleep(1000);
 	}
    
    
   public void ClickTechnicalAssistance() throws InterruptedException{		  //After we have logged in
		
		click(TechnicalAssistance.toBy());
		Thread.sleep(2000);
		waitForElementPresent(TechnicalAssistanceFirstQues.toBy());
		Thread.sleep(1000);
		
	}
   
   public void verifyTechnicalAssistanceFAQ() throws InterruptedException{		
		
 	   waitForElementPresent(TechnicalAssistanceFAQ.toBy());
 		Thread.sleep(1000);
 	}
    
   public void ClickGetAssistance() throws InterruptedException{		   //After we have logged in
		
	    click(GetAssistance.toBy());
		Thread.sleep(2000);
		waitForElementPresent(GetAssistanceFirstQues.toBy());
		Thread.sleep(1000);
		
	}
   
   public void verifyGetAssistanceContactUs() throws InterruptedException{		
		
 	   waitForElementPresent(GetAssistanceContactUs.toBy());
 		Thread.sleep(1000);
 	}
   
    public void clickCloseAtTOP() throws InterruptedException{		//At Top
	 	
  	    click(CloseButton.toBy());
		Thread.sleep(1000);
	
	}
    
    
    // When we click on Video Availablity......the next page comes...
    
    public void clickVideoAvailability() throws InterruptedException{		
	 	
   	    click(VideoAvailability.toBy());
		Thread.sleep(2000);
	
	}
    
    public void verifyVideoAvailability_Language() throws InterruptedException{		
		
  	   waitForElementPresent(VideoAvailability_Language.toBy());
  		Thread.sleep(1000);
  	}
    
    public void verifyVideoAvailability_LanguageASL() throws InterruptedException{		
		
  	   waitForElementPresent(VideoAvailability_LanguageASL.toBy());
  		Thread.sleep(1000);
  	}
    
    public void verifyVideoAvailability_LanguageAlbanian() throws InterruptedException{		
		
  	   waitForElementPresent(VideoAvailability_LanguageAlbanian.toBy());
  		Thread.sleep(1000);
  	}
    
    public void clickVideoAvailability_Close() throws InterruptedException{		
	 	
   	    click(VideoAvailability_Close.toBy());
		Thread.sleep(1000);
	
	}

    //clicking on Place Test call
     public void clickPlaceTestCall() throws InterruptedException{		
	 	
   	    click(PlaceTestCall.toBy());
		Thread.sleep(1000);
	
	}
    
    public void verifyTestVideoDisplay() throws InterruptedException{		
		
   	   waitForElementPresent(TestVideoDisplay.toBy());
   		Thread.sleep(1000);
   	}
    
    public void verifySmallVideoScreen() throws InterruptedException{		
		
    	   waitForElementPresent(smallVideoScreen.toBy());
    		Thread.sleep(1000);
    	}
     
     public void clickVideoHangupButton() throws InterruptedException{		
 	 	
    	    click(videoHangupButton.toBy());
 		Thread.sleep(1000);
 	
 	}

   ///// 
    
	
 
    public void clickHelpAndSettingsLink_BOTTOM() throws InterruptedException{		
	 	
   	    click(HelpAndSettingsLink_BOTTOM.toBy());
		Thread.sleep(1000);
	
	}
    
    public void clickHelpAndSettingsLink_TOP() throws InterruptedException{		
	 	
   	    click(HelpAndSettingsLink_TOP.toBy());
		Thread.sleep(1000);
	
	}
   
    public void verifyHelpAndSettingsTextAtTOP() throws InterruptedException{		
		
	   waitForElementPresent(HelpAndSettingsTextAtTOP.toBy());
	   Thread.sleep(1000);
	}




















    
}
	
	

