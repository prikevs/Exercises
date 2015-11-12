#/usr/bin/python2.7
#coding:utf8
import requests
import pymysql
import re

# 数据库信息
# 
HOST = "localhost"
DBNAME = "teach"

# 改成你的数据库用户名和密码
USER = "***"
PASSWD = "***"

# 获取主页上新闻的链接
def get_list(base_url):
    # 打开网页获取内容
    r = requests.get(base_url) 
    foo = r.text.encode('utf8')
    # 正则表达式匹配所有url
    p1 = re.compile(r"<a href='(.+?)'")
    bar = p1.findall(foo)
    ret = []
    # 找出符合要求的url
    p2 = re.compile(r"/[/0-9a-z]*?info[\d]*?.htm")
    for d in bar:
        if not p2.match(d) is None: 
            ret.append("http://www.njupt.edu.cn" + d) 
    return ret

# 根据url获取网页内容
def get_page(url):
    r = requests.get(url) 
    page = r.text.encode('utf8')
    return page

# 将内容存进数据库
def save(cursor, page):
    sql = 'insert into pages (page) values (%s)'
    cursor.execute(sql, (page))


if __name__ == "__main__":
    # 连接数据库
    conn = pymysql.connect(host=HOST,
                           user=USER,
                           passwd=PASSWD,
                           db=DBNAME)
    cursor = conn.cursor()
    # 主页
    base_url = 'http://www.njupt.edu.cn'
    # 获取所有符合条件的url
    urls = get_list(base_url)
    # 遍历url，打开网页并存储结果
    for url in urls:
        page = get_page(url)
        save(cursor, page)
    # 将缓存内容写进数据库
    conn.commit()
    # 关闭数据库连接
    conn.close()
