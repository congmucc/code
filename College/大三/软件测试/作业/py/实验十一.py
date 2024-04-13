from selenium import webdriver
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
import time

def task1_edge():
    # 启动Edge浏览器
    driver = webdriver.Edge()

    try:
        # 打开百度
        driver.get("https://www.baidu.com")

        # 最大化浏览器窗口
        driver.maximize_window()

        # 等待一段时间，模拟用户操作
        time.sleep(2)

        # 最小化浏览器窗口
        driver.minimize_window()

        # 等待一段时间
        time.sleep(2)

        # 设置浏览器窗口大小和位置
        driver.set_window_size(200, 300)
        driver.set_window_position(300, 500)

        # 等待一段时间
        time.sleep(2)

    finally:
        # 关闭浏览器
        driver.quit()


# task1_edge()


def task2_edge():
    # 启动Edge浏览器
    driver = webdriver.Edge()

    try:
        # 打开京东首页
        driver.get("https://www.jd.com")
        time.sleep(2)

        # 打开淘宝首页
        driver.get("https://www.taobao.com")
        time.sleep(2)

        # 模拟浏览器后退按钮
        driver.back()
        time.sleep(2)

        # 模拟浏览器前进按钮
        driver.forward()
        time.sleep(2)

        # 模拟刷新页面按钮
        driver.refresh()
        time.sleep(2)

        # 模拟鼠标单击操作（以京东首页的搜索框为例）
        search_box = driver.find_element("id", "key")
        ActionChains(driver).click(search_box).perform()
        time.sleep(2)

        # 模拟鼠标双击操作
        ActionChains(driver).double_click(search_box).perform()
        time.sleep(2)

        # 模拟鼠标悬浮操作（以京东首页的登录链接为例）
        login_link = driver.find_element("link text", "你好，请登录")
        ActionChains(driver).move_to_element(login_link).perform()
        time.sleep(2)

    finally:
        # 关闭浏览器
        driver.quit()


# task2_edge()

def task3_right_click_edge():
    # 启动Edge浏览器
    driver = webdriver.Edge()

    try:
        # 打开百度
        driver.get("https://www.baidu.com")

        # 定位“地图”链接
        map_link = driver.find_element("link text", "地图")

        # 执行右击操作
        ActionChains(driver).context_click(map_link).perform()
        time.sleep(2)  # 为了观察右击效果，可以适当延时

    finally:
        # 关闭浏览器
        driver.quit()


# task3_right_click_edge()

def task4_hover_and_wait_edge():
    # 启动Edge浏览器
    driver = webdriver.Edge()

    try:
        # 打开百度
        driver.get("https://www.baidu.com")

        # 定位“设置”按钮
        settings_button = driver.find_element("id", "s-usersetting-top")

        # 悬浮在“设置”按钮上，停留5秒
        action = ActionChains(driver)
        action.move_to_element(settings_button).perform()
        time.sleep(5)  # 悬浮停留5秒

        # 等待用户查看结果
        time.sleep(5)  # 添加额外的等待时间

    finally:
        # 关闭浏览器
        driver.quit()

# 调用函数执行浏览器操作
# task4_hover_and_wait_edge()

def task5_search_weather_edge():
    # 启动Edge浏览器
    driver = webdriver.Edge()

    try:
        # 打开百度
        driver.get("https://www.baidu.com")

        # 定位百度搜索框
        search_box = driver.find_element("css selector", "input#kw")

        # 输入关键词
        search_box.send_keys("今天天气真好啊")

        # 等待两秒
        time.sleep(2)

        # 删除最后一个字符
        search_box.send_keys(Keys.BACK_SPACE)

        # 输入一个空格
        search_box.send_keys(" ")

        # 全选文本框内容
        search_box.send_keys(Keys.CONTROL, 'a')

        # 剪切选择的内容
        search_box.send_keys(Keys.CONTROL, 'x')

        # 粘贴剪切的内容
        search_box.send_keys(Keys.CONTROL, 'v')

        # 模拟回车键代替点击搜索按钮
        search_box.send_keys(Keys.RETURN)

        # 等待一段时间，观察搜索结果
        time.sleep(5)

    finally:
        # 关闭浏览器
        driver.quit()

task5_search_weather_edge()