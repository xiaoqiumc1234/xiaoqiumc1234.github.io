import requests

string = str(input("请输入要翻译的句或词>>>"))
data = {
'doctype': 'json',
'type': 'AUTO',
'i':string
}
url = "http://fanyi.youdao.com/translate"
r = requests.get(url,params=data)
result = r.json()
print(result)
input()

