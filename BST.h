#ifndef BST_H
#define BST_H
#include <sstream>
#include "BSTInterface.h"

template<typename T>
class BST : public BSTInterface<T> {
private:
	struct Node {
		T data_;
		Node* left_;
		Node* right_;
		Node(T d) : data_(d), left_(nullptr), right_(nullptr) {}
	};
	Node* root_;
	size_t numNodes;

	/** Recursive function for addNode */
	bool insert(Node*& node, const T& data);

	/* Recursive for find */
	bool search(Node* node, const T& data) const;

	/* Recursive for removeNode */
	bool remove(Node*& node, const T& data);

	T predecessor(Node* node) const {
		while (node->right_ != nullptr) {
			node = node->right_;
		}
		return node->data_;
	}

	/* Recursive call to Output nodes in-order*/
	void inOrder(Node* node, std::stringstream& out) const;

public:
	BST() { 
		this->root_ = nullptr;
		numNodes = 0;
	}
	~BST() { clearTree(); }

	/** Return true if node added to BST, else false */
	bool addNode(const T& data);

	/** Return true if node removed from BST, else false */
	bool removeNode(const T& data);

	/** Return true if BST cleared of all nodes, else false */
	bool clearTree() { 
		while (root_ != nullptr) {
			remove(root_, root_->data_);
		}
		return true;
	} //while root != nullptr call remove on root

	/** Return a level order traversal of a BST as a string */
	std::string toString() const;

	/** Output nodes at a given level */
	bool outLevel(Node* root, int level, std::stringstream& out) const;

	bool find(const T& data) const {
		return search(root_, data);
	}

	size_t getSize() const {
		return numNodes;
	}

	/** Output nodes in order */
	std::string inOrderToString() const;
};
#endif // BST_H