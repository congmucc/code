package main

import "fmt"

func main() {
	type void struct{}
	var member void
	fmt.Println("hello, world")
	set := make(map[string]bool)
	set["foo"] = true
	for k := range set {
		fmt.Println(k)
	}
	delete(set, "foo")
	size := len(set)
	exists := set["foo"]
}
