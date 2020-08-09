package com.appium.core;

import io.appium.java_client.AppiumDriver;
import io.appium.java_client.MobileElement;
import io.appium.java_client.TouchAction;
import io.appium.java_client.android.AndroidDriver;

import java.util.List;

import org.openqa.selenium.By;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

public abstract class BasePage implements IBasePage {

	protected AppiumDriver driver;
	public int globalWaitTime = 30;

	public BasePage(AppiumDriver<MobileElement> driver) {
		this.driver = driver;
	}

	public AppiumDriver<MobileElement> getApiumDriver() {
		return driver;
	}
	
	@Override
	public void moveElement(By source, By target) {
		WebElement elSource = this.find(source);
		WebElement elDest = this.find(target);
		TouchAction action = new TouchAction(driver);
		//Taction.longPress(elSource).moveTo(elDest).release().perform();		
	}

	@Override
	public String getAttribute(By by, String attribute) {
		WebElement element = find(by);
		return element.getAttribute(attribute);
	}

	@Override
	public String getText(By by) {
		WebElement element = find(by);
		return element.getText();
	}

	@Override
	public void hideKeyboard() {
		driver.hideKeyboard();
	}

	@Override
	public void clickOn(By by) {
		driver.findElement(by).click();
	}

	@Override
	public WebElement click(By by) {
		waitForElementPresent(by);
		WebElement element = find(by);
		element.click();
		return element;
	}

	public WebElement tap(By by) {
		waitForElementPresent(by);
		TouchAction touchAction = new TouchAction(driver);
		WebElement element = find(by);
		//touchAction.tap(element).perform();	
		return element;
	}
	
	@Override
	public WebElement click(WebElement element) {
		element.click();
		return element;
	}

	@Override
	public WebElement clear(By by) {
		WebElement element = find(by);
		element.clear();
		return element;
	}

	@Override
	public MobileElement setText(By by, String text) {
		MobileElement element = find(by);
		element.clear();
		element.sendKeys(text);
		return element;
	}

	@Override
	public WebElement appendText(By by, String text) {
		WebElement element = find(by);
		element.sendKeys(text);
		return element;
	}

	@Override
	public MobileElement find(By by) {
		waitForElementPresent(by);
		return driver.findElement(by).findElement(by);
	}

	@Override
	public WebElement waitForElementPresent(By by) {
		WebDriverWait wait = new WebDriverWait(driver, globalWaitTime);
		return wait.until(ExpectedConditions.visibilityOfElementLocated(by));
		
	}

	@Override
	public void waitForElementClickable(By by) {
		WebDriverWait wait = new WebDriverWait(driver, globalWaitTime);
		wait.until(ExpectedConditions.elementToBeClickable(by));
	}	

	@Override
	public void TouchScreen() {
		Dimension size = driver.manage().window().getSize();
		int x = size.width / 2;
		int y = size.height / 2;
		//TouchAction action1 = new TouchAction(driver).longPress(x, y);
		//action1.perform();
	}

	@Override
	public List<MobileElement> getMobileElements(By by) {
		return driver.findElements(by);
	}


}
