from selenium import webdriver
from selenium.webdriver.common.by import By
from time import sleep

# 定义一个对象
driver = webdriver.Edge()
# 打开百度网址
driver.get("https://www.baidu.com")
# 定位百度搜索框（通过id定位的方式）
# .send_keys() 发送关键词
driver.find_element(By.ID, "kw").send_keys("selenium")
# 通过id 定位到百度一下按钮， 并进行点击
driver.find_element(By.ID, "su").click()
# 停留5秒
sleep(5)
# 退出浏览器
driver.quit()