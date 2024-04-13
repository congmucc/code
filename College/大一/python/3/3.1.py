sum=15.99+23.8+100
print(sum)
print("*******去除小数*******")
um=sum%1
if um>=0.5:
    print(int(sum+1))
else :
    print(int(sum))