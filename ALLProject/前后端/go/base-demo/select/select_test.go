package _select

import (
	"fmt"
	"testing"
	"time"
)

func TestSelect(t *testing.T) {
	ch1 := make(chan int, 3)
	ch2 := make(chan int, 3)
	ch3 := make(chan int, 3)
	ch1 <- 1
	ch2 <- 1
	ch3 <- 1

	select {
	case <-ch1:
		fmt.Println("ch1")
	case <-ch2:
		fmt.Println("ch2")
	case <-ch3:
		fmt.Println("ch3")
	case <-time.After(3 * time.Second):
		fmt.Println("timeout")
	}
	time.Sleep(4 * time.Second)

}
