package _chan

import (
	"fmt"
	"testing"
	"time"
)

// stop goroutine 退出函数。
func stop(stopCh chan struct{}, fn func()) {
	for {
		select {
		// stopCh，close掉了，然后读到值
		case <-stopCh:
			return
		case <-time.After(1 * time.Second):
			fmt.Println("begin running fn()")
			fn()
		}
	}
}

func Test_Stop(t *testing.T) {
	stopCh := make(chan struct{})

	fn := func() {
		fmt.Println("fn run")
	}

	// 模拟3s之后停止
	go func(stopCh chan struct{}) {
		select {
		case <-time.After(3 * time.Second):
			close(stopCh)
			fmt.Println("stopCh closed")
		}
	}(stopCh)

	stop(stopCh, fn)
}
