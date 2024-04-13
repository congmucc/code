lst=[12,2,16,30,28,10,16,20,6,18]
lst.sort(reverse=True)
print("个数：",len(lst))
print("min:",lst[9])
print("max:",lst[0])
print("大到小排序:",lst,sep='\n')
u=0
for i in lst:
    u=u+i
print("average:",u/10)

