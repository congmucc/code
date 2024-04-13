import hashlib

with open(r"C:\Users\Administrator\Downloads\python-3.12.0-amd64.exe", 'rb') as f :
    m1 = hashlib.md5(f.read())
    print(m1.hexdigest())
    #写一个排序算法