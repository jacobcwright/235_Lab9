#ifndef SET_H
#define SET_H

#include "SetInterface.h"
#include "BST.h"

template<typename T>
class Set : public SetInterface<T> {
private:
	BST<T> tree;
public:
	Set() {} //not needed because BST constructor is called when tree is created ?

	~Set() { clear(); }

	/** Inserts item into the set, if the container doesn't
		already contain an element with an equivalent value.
		@return: pair.first = pointer to item
				 pair.second = true if successfully inserted, else false. */
				 //virtual Pair<T*, bool> insert(const T& item) = 0;
	bool insert(const T& item) {
		return tree.addNode(item);
	}

	/** Removes all items from the set. */
	void clear() {
			tree.clearTree();
	}

	/** @return: the number of elements contained by the Set. */
	size_t size() const {
		return tree.getSize();
	}

	/** @return: return 1 if contains element equivalent to item, else 0. */
	size_t count(const T& item) {
		return tree.find(item);
	}

	/** @return: string representation of items in Set. */
	std::string toString() const {
		return tree.inOrderToString();
	}
};

#endif