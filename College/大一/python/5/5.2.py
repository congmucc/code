sin=0.5
cos=0.3
si="sin的值是：{}"
co="cos的值是：{}"
print("**************%格式化字符***************")
print("sin的值是：%s cos的值是：%s"%(sin,cos))
print("**************format()方法格式化字符串***************")
print(si.format(sin),co.format(cos))
print("**************f-string 格式化字符串***************")
print(f'sin的值：{sin},cos的值：{cos}')


