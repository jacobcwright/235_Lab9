#ifndef HASHMAP_H
#define HASHMAP_H
#include <utility>
#include <sstream>
#include "HashMapInterface.h"

template <typename K, typename V>
class HashMap : public HashMapInterface<K, V> {
private:
	std::pair<K, V>** hashTable;

	/** Hash function, using a character polynomial */
	size_t hashFunction(const std::string key){
		size_t length = key.size();
		unsigned long long value = 0;
		for (size_t i = 0; i < length; i++) {
			value += key.at(i) * power(HASH_CONSTANT, (length - i - 1));
		}
		return (value % capacity);
	}

	/* Function to raise a base to an exponent */
	unsigned long long power(unsigned long long base, int exponent) {
		if (exponent > 0) {
			base = base * power(base, exponent - 1);
		}
		else {
			return 1;
		}
		return base;
	}
	size_t capacity;
	size_t numPairs;
public:
	HashMap(size_t givenCapacity = DEFAULT_MAP_HASH_TABLE_SIZE) {
		hashTable = new std::pair<K, V>*[givenCapacity];
		for (size_t i = 0; i < givenCapacity; i++) {
			hashTable[i] = nullptr; 
		}
		capacity = givenCapacity;
		numPairs = 0;
	}

	~HashMap() {
		for (size_t i = 0; i < capacity; i++) {
			delete hashTable[i];
		}
		delete[] hashTable;
	}

	/** Read/write index access operator.
	If the key is not found, an entry is made for it.
	@return: Read and write access to the value mapped to the provided key. */
	V& operator[](const K& key) {
		size_t index = hashFunction(key);
		if (hashTable[index] != nullptr) {
			size_t k = 1;
			while (hashTable[index] != nullptr) {
				if (hashTable[index]->first == key) return hashTable[index]->second;
				index = (index + k) % capacity;
				k += 2;
			}
		}
		hashTable[index] = new std::pair<K, V>(key, V());
		numPairs++;
		return hashTable[index]->second;
	}

	/** @return: the number of elements that match the key in the Map. */
	size_t count(const K& key) {
		size_t numFound = 0;
		for (size_t i = 0; i < capacity; i++) {
			if (hashTable[i]->first == key) { 
				numFound++;
			}
		}
		return numFound;
	}

	/** Removes all items from the Map. */
	void clear() {
		for (size_t i = 0; i < capacity; i++) {
			delete hashTable[i];
			hashTable[i] = nullptr;
		}
		delete[] hashTable;
		hashTable = nullptr;
	}

	/** @return: number of Key-Value pairs stored in the Map. */
	size_t size() const {
		return numPairs;
	}

	/** @return: maximum number of Key-Value pairs that the Map can hold. */
	size_t max_size() const {
		return capacity;
	}

	/** @return: string representation of Key-Value pairs in Map. */
	std::string toString() const {
		std::ostringstream out;
		std::string perfect;
		for (size_t i = 0; i < capacity; i++) {
			if (hashTable[i] == nullptr) continue;
			else {
				out << "  [" << i << ":" << hashTable[i]->first << "->" << hashTable[i]->second << "]" << std::endl;
			}
		}
		return out.str();
	}

};

#endif