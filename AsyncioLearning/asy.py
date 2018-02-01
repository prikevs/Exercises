#!/usr/bin/env python3

import asyncio
import aiohttp
import re
import tqdm

URL = 'http://202.119.228.6:8080/reader/redr_verify.php'
sem = asyncio.Semaphore(5)

FORM = {
    "number": "B13040205",
    "passwd": "B13040205",
    "select": "cert_no",
    "returnUrl": "redr_info.php",
}

ReSFZ = re.compile(r'身份证号： </span>(.*?)</TD>')
ReFK = re.compile(r'读者条码号：</span>(.*?)</TD>')

@asyncio.coroutine
def print_page(url):
    with (yield from sem):
        response = yield from aiohttp.request('POST', url, data=FORM)
    body = yield from response.read_and_close(decode=False)
    body = body.decode()
#    print(ReSFZ.findall(body))
#    print(ReFK.findall(body))

@asyncio.coroutine
def wait_with_progress(coros):
    for f in tqdm.tqdm(asyncio.as_completed(coros), total=len(coros)):
        yield from f

loop = asyncio.get_event_loop()
loop.run_until_complete(
        wait_with_progress([print_page(URL) for i in range(0, 20)])
)
