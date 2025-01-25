import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import tensorflow.keras.backend as K

def letter_to_encoding(letter):
	letters = ['e','d','h','l','o','r','w']
	vec = np.zeros((7), dtype="float32")
	vec[letters.index(letter)] = 1
	return vec

for letter in "hello":
	print(letter_to_encoding(letter))

model = keras.Sequential()
model.add(keras.Input(shape=(3,7,)))
model.add(layers.SimpleRNN(7, activation="softmax", return_sequences=True))
model.summary()

train_text = "helloworld"*30
def generate_train_set(train_text, as_words=False):
	x_train = []
	y_train = []
	for i in range(len(train_text) - 4):
		if as_words:
			x_train += [[train_text[i:i+3]]]
			y_train += [[train_text[i+1:i+4]]]
		else:
			x_train += [[letter_to_encoding(letter) for letter in train_text[i:i+3]]]
			y_train += [[letter_to_encoding(letter) for letter in train_text[i+1:i+4]]]
	if as_words:
		print(x_train[0][:5])
		print(y_train[0][:5])
	else:
		print(np.array(x_train)[0,:5])
		print(np.array(x_train).shape)
	return np.array(x_train), np.array(y_train)

generate_train_set(train_text, True)
x_train, y_train = generate_train_set(train_text)

# What happens when generate an output phrase using untrained network?
letters = ['e','d','h','l','o','r','w']

seed = "hel"
result = "hel"
input_data = np.array([[letter_to_encoding(letter) for letter in seed]])
model.get_weights()

for i in range(7):
	out = model(input_data)
	print_output = K.eval(out)
	for row in print_output[0]:
		next_letter = letters[np.argmax(row)]
	result += next_letter
	print(result)
	input_data = np.array([[letter_to_encoding(letter) for letter in result[-3:]]])

model.compile(optimizer=keras.optimizers.Adam(learning_rate=0.01), loss=tf.keras.losses.CategoricalCrossentropy())
model.fit(x_train, y_train, batch_size=24, epochs=300, verbose=0)

input_data = np.array([[letter_to_encoding(letter) for letter in seed]])
model.get_weights()
result = "hel"
for i in range(7):
	out = model(input_data)
	print_output = K.eval(out)
	for row in print_output[0]:
		next_letter = letters[np.argmax(row)]
	result += next_letter
	print(result)
	input_data = np.array([[letter_to_encoding(letter) for letter in result[-3:]]])