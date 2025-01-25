import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import keras.backend as K

def letter_to_encoding(letter):
	letters = ['e','d','h','l','o','r','w']
	vec = np.zeros((7),dtype="float32")
	vec[letters.index(letter)] = 1
	return vec

for letter in "hello":
	print(letter_to_encoding(letter))