x=input("place enter 10 numbers,and use separatede by spaces：")
lst=[]
lst=x.split(" ")
print(lst)
lst=[int(lst[i]) for i in range(len(lst))]
lst.sort(reverse=True)
del lst[0]
del lst[8]
print(lst)
a=sum(lst)/len(lst)
print("average:",a)