import os
import numpy as np
import librosa
from keras.models import Sequential, load_model
from keras.layers import Dense, Conv2D, MaxPooling2D, Flatten, Reshape
from keras.utils import to_categorical
import matplotlib.pyplot as plt
from keras.callbacks import ModelCheckpoint


class SpeechRecognitionModel:
    def __init__(self, train_path='data/train', test_path='data/test', classes=['0', '1', '2', '3']):
        self.train_path = train_path
        self.test_path = test_path
        self.classes = classes
        self.model = None
        self.history = None
        self.checkpoint_path = "best_model.h5"  # 保存模型的文件路径

    def load_data(self, data_path):
        data = []
        labels = []
        for label, class_name in enumerate(self.classes):
            class_path = os.path.join(data_path, class_name)
            for file_name in os.listdir(class_path):
                file_path = os.path.join(class_path, file_name)
                y, sr = librosa.load(file_path)
                mfccs = np.mean(librosa.feature.mfcc(y=y, sr=sr, n_mfcc=40).T, axis=0)
                data.append(mfccs)
                labels.append(label)
        data = np.array(data)
        labels = np.array(labels)
        data = np.expand_dims(data, axis=-1)  # 添加通道维度
        labels = to_categorical(labels, num_classes=len(self.classes))
        return data, labels

    def build_model(self):
        self.model = Sequential()
        self.model.add(Reshape((40, 1, 1), input_shape=(40, 1)))
        self.model.add(Conv2D(32, (3, 3), activation='relu', padding='same'))
        self.model.add(MaxPooling2D((2, 2), padding='same'))
        self.model.add(Flatten())
        self.model.add(Dense(64, activation='relu'))
        self.model.add(Dense(len(self.classes), activation='softmax'))
        self.model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])

    def train_model(self, epochs=80, batch_size=32):
        train_data, train_labels = self.load_data(self.train_path)
        test_data, test_labels = self.load_data(self.test_path)
        checkpoint = ModelCheckpoint(self.checkpoint_path, monitor='val_accuracy', verbose=1, save_best_only=True,
                                     mode='max')
        self.history = self.model.fit(train_data, train_labels, epochs=epochs, batch_size=batch_size,
                                      validation_data=(test_data, test_labels), callbacks=[checkpoint])

    def plot_history(self):
        plt.plot(self.history.history['accuracy'], label='Training Accuracy')
        plt.plot(self.history.history['val_accuracy'], label='Validation Accuracy')
        plt.title('Model Accuracy')
        plt.xlabel('Epoch')
        plt.ylabel('Accuracy')
        plt.legend()
        plt.show()
        # 保存图片
        plt.savefig('model_accuracy.png')

        plt.plot(self.history.history['loss'], label='Training Loss')
        plt.plot(self.history.history['val_loss'], label='Validation Loss')
        plt.title('Model Loss')
        plt.xlabel('Epoch')
        plt.ylabel('Loss')
        plt.legend()
        plt.show()
        # 保存图片
        plt.savefig('model_history.png')


    def recognize_command(self, audio_file):
        y, sr = librosa.load(audio_file)
        mfccs = np.mean(librosa.feature.mfcc(y=y, sr=sr, n_mfcc=40).T, axis=0)
        mfccs = np.reshape(mfccs, (40, 1))
        mfccs = np.expand_dims(mfccs, axis=0)  # 添加一个批次维度
        prediction = self.model.predict(mfccs)
        return np.argmax(prediction)

    def load_trained_model(self):
        self.model = load_model(self.checkpoint_path)

if __name__=='__main__':
    # 实例化语音识别模型类
    model = SpeechRecognitionModel()

    # 构建并训练模型
    model.build_model()
    model.train_model()

    # 绘制训练历史曲线
    model.plot_history()

    # 加载已训练的模型
    model.load_trained_model()

    # 测试语音命令识别系统
    test_audio_file = 'data/audio.wav'
    command_id = model.recognize_command(test_audio_file)
    print(f'Recognized command ID: {command_id}')


