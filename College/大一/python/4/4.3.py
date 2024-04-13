i=1
j=0
while i<=100:
    i+=1
    if i%10==3:
        continue
    j=i+j
print(j)