import keras
from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense, Dropout

(x_train, y_train) = mnist.load_data()

x_train = x_train.reshape(x_train.shape[0], 784)
x_train = x_train.astype('float32')
x_train /= 255
y_train = keras.utils.to_categorical(y_train, 10)

model = Sequential()
model.add(Dense(512, activation='relu', input_dim=784))
model.add(Dropout(0.2))
model.add(Dense(512, activation='relu'))
model.add(Dropout(0.2))
model.add(Dense(10, activation='softmax'))

model.compile(loss='categorical_crossentropy',
              optimizer='rmsprop',
              metrics=['accuracy'])

model.fit(x_train, y_train, batch_size=128, epochs=20)
