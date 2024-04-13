
def add(num1,operation,num2):
    if operation=='+':
        k=num1+num2
        print(num1,"+",num2,"=",k,sep=' ')
    elif operation=='-':
        k=num1-num2
        print(num1,"-",num2,"=",k,sep=' ')
    elif operation=='*':
        k=num1*num2
        print(num1,"*",num2,"=",k,sep=' ')
    elif operation=='/':
        if num2!=0:
            k=num1/num2
            print(num1,"/",num2,"=",k,sep=' ')
        else:
            print("除数的分母不能为0")
    else:
        print("输入‘+’，‘-’，‘*’，‘、’的一种出现错误：")
        
num1=float(input("请输入第一个数："))
operation=input("请输入‘+’，‘-’，‘*’，‘、’的一种：")
num2=float(input("请输入第二个数："))
add(num1,operation,num2)