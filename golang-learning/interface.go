package main

import "fmt"

type Integer int

type LessAdder interface {
	Less(b Integer) bool
}

func (a Integer) Less(b Integer) bool {
	return a < b
}

func (a *Integer) Add(b Integer) {
	(*a) += b
}

func main() {
	var a Integer = 1
	fmt.Println(a.Less(1))
	a.Add(2)
	fmt.Println(a)
	var b LessAdder = a
	fmt.Println(b.Less(1))

}
