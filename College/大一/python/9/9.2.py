def an(n):
    global i
    if n==1:
        print(i)
        return 1
    if n%2==0:
        n=n/2
        i+=1
        an(n)
    elif n%2==1:
        n=n*3+1
        i+=1
        an(n)
n=int(input('请输入一个n:'))
i=0
an(n)