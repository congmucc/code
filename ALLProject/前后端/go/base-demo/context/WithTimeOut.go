package context

import (
	"context"
	"time"
)

func withTimeOut() {
	myContext := context.Background()

	// 建一个带有取消函数的子级Context，设置超时时间为2秒
	timeout, cancelFunc := context.WithTimeout(myContext, 2*time.Second)
	context.WithValue(timeout, "end", "结束了")
	defer cancelFunc()

	// 在子级 Context 中启动一个 goroutine
	go doSomething(timeout)

	time.Sleep(3 * time.Second)

	// 调用取消函数，取消子级 Context 中的操作
	cancelFunc()

	// 阻塞等待一段时间
	time.Sleep(1 * time.Second)
}

func doSomething(ctx context.Context) {
	// 模拟一个耗时操作
	for {
		select {
		case <-ctx.Done():
			// 如果 Context 被取消，则退出循环
			ctx.Value("end")
			return
		default:
			// 否则，继续执行耗时操作
			time.Sleep(1 * time.Second)
			println("do something")
		}
	}
}
