import random
m=random.randint(1,100)
i=0
for i in range(9):
    if i==8 :
        print("你猜的次数已经超过八次，停止游戏")
        print("答案是：",m)
        break  
    i+=1
    k=int(input("请输入第%d次猜的数字："%(i)))
    if k>m:
        print("你的数字太大了，请重猜")
        continue
    if k<m:
        print("你的数字太小了，请重猜")
        continue
    if k==m:
        print("恭喜你第%d次猜中了，答案是："%(i),m)
        break
    print(m)   