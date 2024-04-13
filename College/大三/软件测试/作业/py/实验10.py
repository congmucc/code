from selenium import webdriver
from selenium.webdriver.common.by import By
from time import sleep


def test01():
    driver = webdriver.Edge()
    driver.get("https://www.baidu.com")
    driver.find_element(By.NAME, "wd").send_keys("天气")
    driver.find_element(By.ID, "su").click()
    sleep(10)
    driver.quit()


def test02():
    driver = webdriver.Edge()
    driver.maximize_window()
    driver.get("https://www.baidu.com")
    driver.find_element("xpath", "//*[@id='kw']").send_keys("软件测试")
    driver.find_element("xpath", "//*[@id='su']").click()
    sleep(10)
    driver.quit()


def test03():
    driver = webdriver.Edge()
    driver.get("https://www.taobao.com")
    driver.find_element(By.ID, "q").send_keys("笔记本")
    driver.find_element("xpath", "//*[@id='J_TSearchForm']/div[1]/button").click()
    sleep(10)
    driver.quit()


# test01()
# test02()
test03()
