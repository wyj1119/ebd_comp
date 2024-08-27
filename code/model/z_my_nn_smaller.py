import csv
import numpy as np
import tensorflow as tf
from keras import Model, layers
import keras
import z_load_data
from keras.models import Sequential
from tensorflow import keras
from tensorflow.keras import layers
from matplotlib import pyplot as plt 

def my_model_train(x_train,y_train,save_path,show_loss=0):
    my_model = Sequential([
                            layers.Conv2D(16, (3, 3), strides=(1, 1), padding='same', use_bias=False),
                            layers.BatchNormalization(),
                            layers.Activation('relu'),
                            layers.MaxPooling2D(),#1
                            layers.Conv2D(32, (3, 3), strides=(1, 1), padding='same', use_bias=False),
                            layers.BatchNormalization(),
                            layers.Activation('relu'),
                            layers.MaxPooling2D(),#2
                            layers.Conv2D(64, (3, 3), strides=(2, 2), padding='same', use_bias=False),
                            layers.BatchNormalization(),
                            layers.Activation('relu'),
                            layers.MaxPooling2D(),#3
                            tf.keras.layers.GlobalAveragePooling2D(),
                            tf.keras.layers.Dense(3, activation="softmax")])
    
    my_model.compile(loss='categorical_crossentropy', optimizer='Adam',metrics = ['accuracy'])

    my_model.fit(x=x_train,
             y=y_train,
             batch_size=64,
             epochs=50,
             shuffle=True)
    
    my_model.save(save_path)
    if show_loss==1:
        epochs=range(len(my_model.history.history['loss']))
        plt.figure()
        plt.plot(epochs,my_model.history.history['loss'],'b',label='Training loss')
        plt.title('Traing loss')
        plt.show()

    return my_model




x_train_1,y_train_1 =z_load_data.load_data_3_res_mfcc(r"E:\STM32_AED\MY_NN\AUDIO_DATAS_FROM_STM32",
                                 r"E:\STM32_AED\MY_NN\data_list.csv",
                                 'stm32_dsp_mfcc')

x_train_2,y_train_2 = z_load_data.load_data_wav(r"E:\STM32_AED\MY_NN\leak_wav_phone_record.wav" , 8080,[1,0,0])

x_train_3,y_train_3 = z_load_data.load_data_wav(r"E:\STM32_AED\MY_NN\leak_wav_phone_record1.wav",8080,[1,0,0])

x_train_4,y_train_4 = z_load_data.load_data_wav(r"E:\STM32_AED\MY_NN\noise_phone_record0.wav",8080,[0,0,1])

x_train = np.append(x_train_1,x_train_2,axis=0)
y_train = np.append(y_train_1,y_train_2,axis=0)

x_train = np.append(x_train,x_train_3,axis=0)
y_train = np.append(y_train,y_train_3,axis=0)

x_train = np.append(x_train,x_train_4,axis=0)
y_train = np.append(y_train,y_train_4,axis=0)

print(x_train.shape,y_train.shape)

model = my_model_train(x_train,y_train,r"E:\STM32_AED\MY_NN\AUDIO_DATAS_FROM_STM32\temp_model",1)





