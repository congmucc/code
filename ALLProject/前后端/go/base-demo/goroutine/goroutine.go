package main

import (
	"fmt"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := 0; i < 10; i++ {
			fmt.Println(i)
		}
	}()
	wg.Wait()
	// 这里如果想要多个线程交替打印1-10，可以使用阻塞通道进行
}
