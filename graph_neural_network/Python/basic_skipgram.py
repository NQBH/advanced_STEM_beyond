import numpy as np
CONTEXT_SIZE = 2
text = """Lorem ipsum dolor sit amet, consectetur
adipiscing elit. Nunc eu sem scelerisque, dictum eros
aliquam, accumsan quam. Pellentesque tempus, lorem ut
semper fermentum, ante turpis accumsan ex, sit amet
ultricies tortor erat quis nulla. Nunc consectetur ligula
sit amet purus porttitor, vel tempus tortor scelerisque.
Vestibulum ante ipsum primis in faucibus orci luctus
et ultrices posuere cubilia curae; Quisque suscipit
ligula nec faucibus accumsan. Duis vulputate massa sit
amet viverra hendrerit. Integer maximus quis sapien id
convallis. Donec elementum placerat ex laoreet gravida.
Praesent quis enim facilisis, bibendum est nec, pharetra
ex. Etiam pharetra congue justo, eget imperdiet diam
varius non. Mauris dolor lectus, interdum in laoreet
quis, faucibus vitae velit. Donec lacinia dui eget
maximus cursus. Class aptent taciti sociosqu ad litora
torquent per conubia nostra, per inceptos himenaeos.
Vivamus tincidunt velit eget nisi ornare convallis.
Pellentesque habitant morbi tristique senectus et netus
et malesuada fames ac turpis egestas. Donec tristique
ultrices tortor at accumsan.
""".split()
skipgrams = []
for i in range(CONTEXT_SIZE, len(text) - CONTEXT_SIZE):
	array = [text[j] for j in np.arange(i - CONTEXT_SIZE, i + CONTEXT_SIZE + 1) if j != i]
	skipgrams.append((text[i], array))
print(skipgrams[0:2])

# skip-gram model
vocab = set(text)
VOCAB_SIZE = len(vocab)
print(f"Length of vocabulary = {VOCAB_SIZE}")

from gensim.models.word2vec import Word2Vec
model = Word2Vec([text], # initialize a skip-gram model with a Word2Vec object & skip-gram = 1
    sg = 1, # skip-gram
    vector_size = 10,
    min_count = 0,
    window = 2,
    workers = 2,
    seed = 0)
print(f'Shape of W_embed: {model.wv.vectors.shape}') # check shape of 1st weight matrix, corresponding to the vocabulary size & the word embedding's dimensionality
model.train([text], total_examples = model.corpus_count, epochs = 10) # train model for 10 epochs
print('Word embedding = ')
print(model.wv[0])