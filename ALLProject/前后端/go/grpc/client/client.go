package main

import (
	"context"
	"fmt"
	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
	"log"
	"protoDemo/user"
)

// 这个是固定的
func getClient() user.UserServiceClient {
	addr := ":8080"
	conn, dialErr := grpc.Dial(addr, grpc.WithTransportCredentials(insecure.NewCredentials()))

	if dialErr != nil {
		log.Fatalf(fmt.Sprint("grpc connect addr [%s] 连接失败 %s", addr, dialErr))
	}

	client := user.NewUserServiceClient(conn)
	return client
}

func main() {
	client := getClient()

	result, err := client.GetUser(context.Background(), &user.User{
		Name:    "张三",
		Age:     18,
		Address: "北京",
		Email:   "123@qq.com",
	})

	result2, err2 := client.GetUser(context.Background(), &user.User{
		Name:    "李四",
		Age:     18,
		Address: "北京",
		Email:   "123@qq.com",
	})

	fmt.Println(result, err)

	fmt.Println(result2, err2)
}
