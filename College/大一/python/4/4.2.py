for i in range(1,5):
    for j in range(1,5):
        for k in range(1,5):
            if i==j or i==k or j==k:
                continue
            print(str(i)+str(j)+str(k),end=" ")
            print("%d%d%d"%(i,j,k),end=" ")