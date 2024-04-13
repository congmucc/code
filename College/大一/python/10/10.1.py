import os
with open(r'C:\Users\lenovo\Desktop\data.txt','r+') as f:
    f.seek(11,0)
    print(f.read())
os.rename(r'C:\Users\lenovo\Desktop\data.txt',r'C:\Users\lenovo\Desktop\data-finally.txt')

