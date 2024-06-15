package main

import (
	"context"
	"fmt"
	"google.golang.org/grpc"
	"net"
	"protoDemo/user"
)

// 这里需要继承服务端UserServiceServer
type userService struct {
	user.UserServiceServer
}

// 这里需要实现getUser方法
func (userService) GetUser(ctx context.Context, use *user.User) (result *user.Result, err error) {
	fmt.Println("入参： ", use)

	return &user.Result{
		Code:    "200",
		Message: "结果是: " + use.Name,
	}, nil
}

func main() {
	listen, listenErr := net.Listen("tcp", ":8080")
	if listenErr != nil {
		fmt.Println(listenErr)
	}

	s := grpc.NewServer()
	server := userService{}
	user.RegisterUserServiceServer(s, &server)
	fmt.Println("grpc server running :8080")

	err := s.Serve(listen)
	if err != nil {
		return
	}

}
