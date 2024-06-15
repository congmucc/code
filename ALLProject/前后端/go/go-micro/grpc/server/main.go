package main

import (
	"fmt"
	"net"
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

func (this Result) AddUser(user User, res *Result) error {
	fmt.Println(user)

	res.code = "200"
	res.msg = "添加成功" + user.name

	return nil
}

func main() {
	// 1、注册服务
	rpcErr := rpc.RegisterName("goods", new(Goods))
	if rpcErr != nil {
		fmt.Println(rpcErr)
	}

	// 2、监听端口
	listen, listenErr := net.Listen("tcp", "127.0.0.1:8087")
	if listenErr != nil {
		fmt.Println(listenErr)
	}

	// 3、关闭监听
	defer func(listen net.Listener) {
		err := listen.Close()
		if err != nil {
			fmt.Println(err)
		}
	}(listen)

	for {
		// 4、监听客户端连接
		fmt.Println("监听中...")
		accept, acceptErr := listen.Accept()
		if acceptErr != nil {
			fmt.Println(acceptErr)
		}
		rpc.ServeConn(accept)
	}

}
