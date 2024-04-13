import time

from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Edge()
driver.get("https://www.bilibili.com")
driver.find_element(By.CLASS_NAME, "channel-link").click()

time.sleep(3)
driver.quit()