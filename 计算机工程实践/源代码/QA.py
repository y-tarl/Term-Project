import base64
import urllib
import requests
import json
import os

requests.packages.urllib3.disable_warnings()

app_id = "90044373"
API_KEY = "BcbHuKRwy7jles1mOIeRP8Hy"
SECRET_KEY = "JQiXVE6vc5MHSd0mRNAyfklXjpGjAf6N"



# base_url = "https://openapi.baidu.com/oauth/2.0/token?grant_type=client_credentials&client_id=%s&client_secret=%s"
# APIKey = "C5ZMNPXi2kGV0IzDuSVRZEJj"
# SecretKey = "633zJW1czQHUWbu9HhsW1Z0A1rwyUPJP"

def get_text(audio_path):
    """
    语音转文字接口，可直接调用

    :param audio_path: 音频文件路径
    :return: 文本信息
    """
    url = "https://vop.baidu.com/server_api"
    
    payload = json.dumps({
        "format": "pcm",
        "rate": 16000,
        "channel": 1,
        "cuid": "tplHFvY7JeV4N05xoqKqUeWZhmVuwk98",
        "token": get_access_token(),
        "speech": get_file_content_as_base64(audio_path,False),
        "len": get_len(audio_path)
    })
    headers = {
        'Content-Type': 'application/json',
        'Accept': 'application/json'
    }
    
    response = requests.request("POST", url, headers=headers, data=payload)
    
    return response.json().get("result")[0]

def get_audio(text):
    """
    文本转语音接口，可直接调用

    :param text: 文本
    """
    url = "https://tsn.baidu.com/text2audio"
    tex = urllib.parse.quote(text)
    
    payload='tex='+ tex +'&tok='+ get_access_token() +'&cuid=02RQ3PqQOsCiPSoDZTC2pCyShkhUo9sn&ctp=1&lan=zh&spd=5&pit=5&vol=5&per=1&aue=6'
    headers = {
        'Content-Type': 'application/x-www-form-urlencoded',
        'Accept': '*/*'
    }
    
    response = requests.request("POST", url, headers=headers, data=payload)
    
    with open("Semantic/data/audio.wav", "wb") as f:
        f.write(response.content)

def get_file_content_as_base64(path, urlencoded=False):
    """
    获取文件base64编码
    :param path: 文件路径
    :param urlencoded: 是否对结果进行urlencoded 
    :return: base64编码信息
    """
    with open(path, "rb") as f:
        content = base64.b64encode(f.read()).decode("utf8")
        if urlencoded:
            content = urllib.parse.quote_plus(content)
    return content

def get_access_token():
    """
    使用 AK，SK 生成鉴权签名（Access Token）
    :return: access_token，或是None(如果错误)
    """
    url = "https://aip.baidubce.com/oauth/2.0/token"
    params = {"grant_type": "client_credentials", "client_id": API_KEY, "client_secret": SECRET_KEY}
    return str(requests.post(url, params=params).json().get("access_token"))
    
def get_len(path):
    with open(path, "rb") as f:
        content = f.read()
    return len(content)

def get_ai_answer(text):
    data = requests.post('https://52.76.85.65/generativelanguage.googleapis.com/v1beta/models/gemini-pro:generateContent?key=AIzaSyA_5AnHv7rcDDFCaRQgs-Kqpopni9DcJ-o',
                            json={'contents': [{'parts': [{'text': text}]}]},
                            headers={'host': 'r.zhul.in'},
                            verify=False)
    try:
        return data.json()['candidates'][0]['content']['parts'][0]['text']
    except Exception as e:
        print(data.text)
        print(e)
        return "没听懂您说的话"

if __name__ == '__main__':
    question_text = get_text("output.wav")
    print("已识别: " + question_text)
    answer_text = get_ai_answer(question_text)
    print("回答: " + answer_text)
    get_audio(answer_text)
    os.system("aplay audio.wav")
