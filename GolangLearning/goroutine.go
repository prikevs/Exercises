package main

import (
	"fmt"
	"time"
)

func run(arg string) {
	time.Sleep(2 * time.Second)
	fmt.Println("In run" + arg)
}

func main() {
	go run("tt")
	fmt.Println("In main")
	time.Sleep(3 * time.Second)
}
