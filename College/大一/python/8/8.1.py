print('='*20)
info='''
功能：
用户输入“1”执行添加联系人操作；
用户输入“2”执行查看通讯录操作；
用户输入“3”执行删除通讯录操作；
用户输入“4”执行查找联系人操作；
用户输入“5”执行退出操作:'''
print(info)
print("="*20)
b=[]
while True:
    
    x=input('请输入功能:')
    if x=='1':
        name=input("请输入联系人姓名：")
        number=input("请输入联系人手机号：")
        email=input("请输入联系人邮箱：")
        adds=input("请输入联系人地址：")
        b_i={}
        b_i={'名字':name,'手机号':number,'邮箱':email,'地址':adds}
        b.append(b_i)
        print(b) 
        print("保存成功")
    elif x=='2':
        print(b)
    elif x=='3':
        dname=input("请输入删除联系人的名字")
        i=0
        for item in b:
            i+=1
            if dname in item['名字']:
                del b[i-1]
                print(b)
            else:
                print("查无此人")
    elif x=='4':
        sname=input("请输入要查看的联系人：")
        for item in b:
            if sname in item['名字']:
                print("名字=",item['名字'],"手机号=",item['手机号'],"邮箱=",item['邮箱'],"地址=",item['地址'])
    elif x=='5':
        break;