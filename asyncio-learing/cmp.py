#!/usr/bin/env python3

import requests
import re

URL = 'http://202.119.228.6:8080/reader/redr_verify.php'
FORM = {
    "number": "B13040205",
    "passwd": "B13040205",
    "select": "cert_no",
    "returnUrl": "redr_info.php",
}

ReSFZ = re.compile(r'身份证号： </span>(.*?)</TD>')
ReFK = re.compile(r'读者条码号：</span>(.*?)</TD>')
def print_page(url):
    response = requests.request('POST', url, data=FORM)
    response.encoding = "utf-8"
    body = response.text
    print(ReSFZ.findall(body))

for i in range(0, 20):
    print_page(URL)
