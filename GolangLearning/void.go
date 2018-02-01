package main

import "fmt"
import "reflect"

type test struct {
	a int
	b string
}

func T(t interface{}) {
	at := reflect.ValueOf(t)
	fmt.Println(at.FieldByName("a"))
}

func main() {
	var tt test = test{1, "abc"}
	T(tt)
	var anything interface{} = 123
	switch anything.(type) {
	case string:
		fmt.Println("String")
	case int:
		fmt.Println("int")
	default:
		fmt.Println("unknown")
	}
}
