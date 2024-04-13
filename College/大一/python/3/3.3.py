print("""
     1.乘法运算
     2.加法运算
     3.除法运算
     4.减法运算
     """)
ch=input("请输入数字进行运算：")
a=float(input("请输入a: "))
b=float(input("请输入b: "))
if ch=="1":
    print("a*b=",a*b)
elif ch=="2":
    print("a+b=",a+b)
elif ch=="3":
    print("a/b=",a/b)
elif ch=="4":
    print("a-b=",a-b)
