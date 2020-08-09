package com.appium.core;

import io.appium.java_client.MobileElement;

import java.util.List;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;

public interface IBasePage {

	public void clickOn(By by);

	WebElement find(By by);

	WebElement click(By by);

	WebElement clear(By by);

	WebElement setText(By by, String text);

	WebElement appendText(By by, String text);

	void moveElement(By source, By target);

	String getAttribute(By by, String attribute);

	void TouchScreen();

	List<MobileElement> getMobileElements(By by);

	String getText(By by);

	void hideKeyboard();

	WebElement click(WebElement element);

	WebElement waitForElementPresent(By by);

	void waitForElementClickable(By by);

}
