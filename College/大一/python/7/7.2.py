lst=[12,2,16,30,28,10,16,20,6,18]
print("个数：",len(lst))
lst.sort(reverse=True)
print("min:",lst[9])
print("max:",lst[0])
print("new:",lst,sep='\n')
u=0
for i in lst:
    u=u+i
print("average:",u/10)