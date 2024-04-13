import random
ss = []
sl=[]
sr=[]
while True:
    s=random.randint(1,100)
    if s not in ss:
        ss.append(s)

    if len(ss)==100:
        print("old:")
        print(ss)
        break
for i in ss:
    if (i%2==1):
        sl.append(i)
    else:
        sr.append(i)
print("new:")
sl.extend(sr)
print(sl)

    