word=input("请输入文字:")
while 1:
    q=input("请输入要替换的字符:")
    if q not in word:
        print(word)
        print("结束了")
        break
    word=word.replace(q,"*")
    print(word)
