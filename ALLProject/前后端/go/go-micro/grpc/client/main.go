package main

import (
	"fmt"
	"net/rpc"
)

type User struct {
	name    string
	age     int
	address string
	email   string
}

type Result struct {
	code string
	msg  string
}

func main() {
	// 1、注册服务
	dial, dialErr := rpc.Dial("tcp", "127.0.0.1:8087")
	if dialErr != nil {
		fmt.Println(dialErr)
	}

	defer dial.Close()

	var reply Result
	user := User{
		name:    "张三",
		age:     18,
		address: "北京",
		email:   "123@qq.com",
	}

	dial.Call("User.AddUser", "你好", &reply)

	fmt.Println(reply.code)
	fmt.Printf("%#v\n", reply.msg)
}
