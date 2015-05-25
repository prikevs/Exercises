package main

import (
	"fmt"
	"strings"
	//	"unicode"
)

func WordCount(s string) map[string]int {
	m := make(map[string]int)
	f := func(c rune) bool {
		return c == ' '
	}
	re := strings.FieldsFunc(s, f)
	for _, word := range re {
		m[word]++
	}
	return m
}

func main() {
	//WordCount("i am learning go")
	fmt.Println(WordCount("i am learning go"))
}
