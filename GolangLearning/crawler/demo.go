package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"net/http"
	"regexp"
)

type Site struct {
	domain string
	ret    chan string
}

var pat = regexp.MustCompile("\\<[aA]\\s+href\\s*=\\s*(([\"']?)(.*?)[\"']?)(\\s*|\\s+.*?)\\>")

func (s *Site) GetUrls(body string) []string {
	//fmt.Println(body)
	m := pat.FindAllStringSubmatch(body, -1)
	urls := make([]string, 0)
	for i := 0; i < len(m); i++ {
		temp := m[i][3]
		if len(temp) > 4 && temp[:4] != "http" {
			if temp[0] != '/' {
				temp = "/" + temp
			}
			temp = s.domain + temp
			urls = append(urls, temp)
		}
	}
	return urls
}

func (s *Site) crawl(url string) {
	resp, err := http.Get(url)
	if err != nil {
		fmt.Println(url, err)
		return
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Println(err)
		return
	}
	urls := s.GetUrls(string(body))
	for _, v := range urls {
		s.ret <- v
	}
}

func main() {
	var visited map[string]bool = make(map[string]bool)
	flag.Parse()
	args := flag.Args()
	domain := args[0]
	ret := make(chan string, 1000)
	s := Site{domain: domain, ret: ret}
	go s.crawl(domain)
	count := 0
	for {
		url := <-ret
		_, ok := visited[url]
		if ok == true {
			continue
		}
		visited[url] = true
		count++
		fmt.Println(count)
		go s.crawl(url)
	}
	//fmt.Println(page.body)
	//fmt.Println(string(body))
}
