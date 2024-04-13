word="Life is short. I use Visual Basic"
k=word.find("Visual Basic")
if k>=0:
    print("含有Visual Basic")
else:
    print("不含")
print("**********替换后*************")
n=word.replace("Visual Basic","Python")
print(n)