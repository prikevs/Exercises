package main

import "fmt"

type Header map[string]string

func (h Header) add(key, val string) {
	h[key] = val
}

func (h Header) show(key string) {
	val, ok := h[key]
	if ok {
		fmt.Println(val)
	} else {
		fmt.Println("None")
	}
}

func main() {
	h := make(Header)
	h.add("a", "b")
	h.show("b")
}
