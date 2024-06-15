package main

import "fmt"

type Shape interface {
	Area() float64
}

type Circle struct {
	radius float64
}

func (c Circle) Area() float64 {
	return 3.14 * c.radius * c.radius
}

type Rectangle struct {
	width, height float64
}

func (r Rectangle) Area() float64 {
	return r.width * r.height
}

func PrintArea(s Shape) {
	fmt.Printf("Area: %.2f\n", s.Area())
}

func main() {
	circle := Circle{radius: 5}
	rectangle := Rectangle{width: 4, height: 6}

	PrintArea(circle)    // 直接传递 Circle 实例，不需要 &
	PrintArea(rectangle) // 直接传递 Rectangle 实例，不需要 &
}
