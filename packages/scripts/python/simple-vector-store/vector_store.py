import numpy as np

class VectorStore:
    def __init__(self) -> None:
        self.vector_data = {}  # dict of vector_id -> vector
        self.vector_index = {} # dict of vector_id -> index
        
    def add_vector(self, vector_id, vector):
        """add a vector to the vector store

        Args:
            vector_id (str or int): A unique identifier for the vector
            vector (numpy:darray): The vector to store
        """
        self.vector_data[vector_id] = vector
        self._update_index(vector_id, vector)
        
    def get_vector(self, vector_id):
        """get a vector from the vector store

        Args:
            vector_id (str or int): A unique identifier for the vector

        Returns:
            numpy:darray: The vector if it exists, None otherwise
        """
        return self.vector_data.get(vector_id)
    
    def _update_index(self, vector_id, vector):
        """update the vector indexing structure for a given vector

        Args:
            vector_id (str or int): A unique identifier for the vector
            vector (numpy:darray): The vector to store
        """
        for exisiting_vector_id, exisiting_vector in self.vector_data.items():
            similarity = np.dot(vector, exisiting_vector) / (np.linalg.norm(vector) * np.linalg.norm(exisiting_vector))
            if exisiting_vector_id not in self.vector_index:
                self.vector_index[exisiting_vector_id] = {}
                
            self.vector_index[exisiting_vector_id][vector_id] = similarity
            
    def find_similar_vectors(self, query_vector, num_results=5):
        """find similar vectors to a given query vector
        
        Args:
            query_vector (numpy:darray): The vector to find similar vectors to
            num_results (int): The number of results to return
            
        Returns:
            list: A list of (vector_id, similarity) tuples
        """
        results = []
        for vector_id, vector in self.vector_data.items():
            similarity = np.dot(query_vector, vector) / (np.linalg.norm(query_vector) * np.linalg.norm(vector))
            results.append((vector_id, similarity))
            
        # sort by similarity in descending order
        results = sorted(results, key=lambda x: x[1], reverse=True)
        # return the top N results
        return results[:num_results]