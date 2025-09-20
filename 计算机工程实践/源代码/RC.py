import pyaudio
import wave
import numpy as np
import time


class RC:
    def __init__(self, filename="output.wav"):
        self.filename = filename
        # 设置参数
        self.THRESHOLD = 500  # 音量阈值
        self.CHUNK = 1024  # 每个块的帧数
        self.FORMAT = pyaudio.paInt16  # 采样格式
        self.CHANNELS = 1  # 单声道
        self.RATE = 16000  # 采样率
        self.SILENCE_DURATION = 3  # 低于阈值停止录音的秒数
        # 初始化 PyAudio
        self.p = pyaudio.PyAudio()

        # 打开音频流
        self.stream = self.p.open(format=self.FORMAT,
                                  channels=self.CHANNELS,
                                  rate=self.RATE,
                                  input=True,
                                  frames_per_buffer=self.CHUNK)

    def is_silent(self, data_chunk):
        """判断是否静音"""
        return np.mean(np.abs(data_chunk)) < self.THRESHOLD

    def record_audio(self, data, max_record_time=10):
        """录音功能"""
        print("Recording...")

        frames = []
        frames.append(data)
        silent_chunks = 0
        silence_threshold = int(self.RATE / self.CHUNK * self.SILENCE_DURATION)
        max_chunks = int((self.RATE / self.CHUNK) * max_record_time)  # Calculate max chunks based on max_record_time
        chunks_processed = 0  # Initialize counter for chunks processed

        while True:
            data = self.stream.read(self.CHUNK)
            data_chunk = np.frombuffer(data, dtype=np.int16)
            frames.append(data)
            chunks_processed += 1  # Increment chunks processed

            if self.is_silent(data_chunk):
                silent_chunks += 1
            else:
                silent_chunks = 0

            # Check if recording should stop due to silence or max recording time reached
            if silent_chunks > silence_threshold or chunks_processed >= max_chunks:
                break

        print("Recording stopped")

        # Save the recording
        wf = wave.open(self.filename, 'wb')
        wf.setnchannels(self.CHANNELS)
        wf.setsampwidth(self.p.get_sample_size(self.FORMAT))
        wf.setframerate(self.RATE)
        wf.writeframes(b''.join(frames))
        wf.close()

    def do_record(self, max_record_time=10):
        print("Listening...")
        try:
            while True:
                data = self.stream.read(self.CHUNK)
                data_chunk = np.frombuffer(data, dtype=np.int16)

                if not self.is_silent(data_chunk):
                    self.record_audio(data, max_record_time)
                    break
                time.sleep(0.1)
        except Exception as e:
            print(str(e))

    def close(self):
        self.stream.stop_stream()
        self.stream.close()
        self.p.terminate()


if __name__ == '__main__':
    r = RC()
    r.do_record()
    r.close()



