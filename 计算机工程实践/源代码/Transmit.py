import Recognition as R
import RC as rc
import socket
from  SpeechSynthesis import TextToSpeechAPI
from playsound import playsound
def send_message_to_server(message, host='localhost', port=65432):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        s.sendall(message.encode())
        print('Message sent to server')

if __name__=='__main__':
    model = R.SpeechRecognitionModel()
    # 加载已训练的模型
    model.load_trained_model()
    r = rc.RC("audio.wav")
    r.do_record(5)
    r.close()
    test_audio_file = 'audio.wav'
    command_id = model.recognize_command(test_audio_file)
    print(f'Recognized command ID: {command_id}')
    if command_id == 0:
        send_message_to_server("0")
        answer_text = "这就去坐标A点"
        tts_api = TextToSpeechAPI()
        tts_api.synthesize_text(answer_text)
        playsound("audio.mp3")
    elif command_id == 1:
        send_message_to_server("1")
        answer_text = "这就去坐标A点"
        tts_api = TextToSpeechAPI()
        tts_api.synthesize_text(answer_text)
        playsound("audio.mp3")
    elif command_id == 2:
        send_message_to_server("2")
        answer_text = "这就把货物放在坐标A点"
        tts_api = TextToSpeechAPI()
        tts_api.synthesize_text(answer_text)
        playsound("audio.mp3")
    elif command_id == 3:
        send_message_to_server("3")
        answer_text = "这就把货物放在坐标B点"
        tts_api = TextToSpeechAPI()
        tts_api.synthesize_text(answer_text)c
        playsound("audio.mp3")