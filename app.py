from vector_store import VectorStore
import numpy as np

vector_store = VectorStore()

#define list of sentences
sentences = [
    "I like to eat broccoli and bananas.",
    "I ate a banana and spinach smoothie for breakfast.",
    "Chinchillas and kittens are cute.",
    "My sister adopted a kitten yesterday.",
    "Look at this cute hamster munching on a piece of broccoli."
]

# Tokenization and vocabulary building
vocabulary = set()

for sentence in sentences:
    tokens = sentence.lower().split(" ")
    vocabulary.update(tokens)

print("Vocabulary: ", vocabulary)

# assign a unique indeces to words in vocabulary
word_to_index = {word: i for i, word in enumerate(vocabulary)}
print("Word to index: ", word_to_index)

# vectorization
sentence_vectors = {}
for sentence in sentences:
    tokens = sentence.lower().split(" ")
    print("Tokens: ", tokens)
    vector = np.zeros(len(vocabulary))
    for word in tokens:
        vector[word_to_index[word]] += 1
    print("Vector: ", vector)
    sentence_vectors[sentence] = vector
  
# add vectors to vector store
for sentence, vector in sentence_vectors.items():
    vector_store.add_vector(sentence, vector)
    
    
# search for the most similar sentence
query_sentence = "I like kittens"
query_vector = np.zeros(len(vocabulary))
query_tokens = query_sentence.lower().split(" ")
for word in query_tokens:
    query_vector[word_to_index[word]] += 1
print("Query vector: ", query_vector)

similar_sentence = vector_store.find_similar_vectors(query_vector, num_results=2)
print("Query sentence: ", query_sentence)
print("Similar sentence: ")
for sentence, similarity in similar_sentence:
    print(f"{sentence}. Similarity = {similarity: .4f}")