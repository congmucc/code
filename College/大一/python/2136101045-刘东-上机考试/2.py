print("以下是三位数有重复的：")
d=0
for a in range(1,6):
    for b in range(1,6):
        for c in range(1,6):
                d=a*100+b*10+c
                if(d<300):
                    print(d,end=' ')
                    
f=0
print(" ")
print("以下是三位数不重复的：")
for a in range(1,6):
    for b in range(1,6):
        for c in range(1,6):
            if a!=b and b!=c and a!=c:
                f=a*100+b*10+c
                if(f<300):
                    print(f,end=' ')