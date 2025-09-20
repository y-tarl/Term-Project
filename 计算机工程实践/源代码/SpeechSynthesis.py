# -*- coding: utf-8 -*-
# import os
from aip import AipSpeech
# os.chdir(r'C:\Users\justb\Desktop\爬虫2')
from playsound import playsound

""" 你的 APPID AK SK """
APP_ID = '89992083'                            #自己的app——id
API_KEY = "C5ZMNPXi2kGV0IzDuSVRZEJj"
SECRET_KEY = "633zJW1czQHUWbu9HhsW1Z0A1rwyUPJP"

class TextToSpeechAPI:
    def __init__(self, app_id= '89992083' , api_key="C5ZMNPXi2kGV0IzDuSVRZEJj", secret_key="633zJW1czQHUWbu9HhsW1Z0A1rwyUPJP"):
        """
        Initialize the AipSpeech client with the provided credentials.
        """
        self.client = AipSpeech(app_id, api_key, secret_key)

    def synthesize_text(self, text, file_path='audio.mp3'):
        """
        Convert text to speech and save the output as an MP3 file.

        :param text: The text to be converted to speech.
        :param file_path: The path where the MP3 file will be saved.
        """
        # Perform the text-to-speech synthesis
        result = self.client.synthesis(text, 'zh', 4, {
            'vol': 5,
        })

        # If the result is not a dictionary, it means the synthesis was successful
        if not isinstance(result, dict):
            with open(file_path, 'wb') as f:
                f.write(result)
            playsound(file_path)
        else:
            print("Error during text-to-speech synthesis:", result)

if __name__ == '__main__':
        # Initialize the API with your credentials
    tts_api = TextToSpeechAPI('89992083', 'C5ZMNPXi2kGV0IzDuSVRZEJj', '633zJW1czQHUWbu9HhsW1Z0A1rwyUPJP')
    # Use the API to convert text to speech
    tts_api.synthesize_text("放下木块")
    # playsound("right.mp3")