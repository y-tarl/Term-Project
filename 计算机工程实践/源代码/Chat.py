import RC as rc
import QA as qa
import os
from playsound import playsound
from  SpeechSynthesis import TextToSpeechAPI
# from SpeechClient

if __name__ == '__main__':
    #记录音频
    r = rc.RC()
    r.do_record()
    r.close()
    question_text = qa.get_text("output.wav")
    print("已识别: " + question_text)

    answer_text = qa.get_ai_answer(question_text)
    print("回答: " + answer_text)
    # tts_api = TextToSpeechAPI()
    # tts_api.synthesize_text(answer_text)
    # playsound("audio.mp3")
    qa.get_audio(answer_text)
    os.system("aplay audio.mp3")
    # playsound("audio.wav")


