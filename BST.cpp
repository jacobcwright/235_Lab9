#include "BST.h"

/** Recursive function for addNode */
template<typename T>
bool BST<T>::insert(Node*& node, const T& data) {
	if (node == nullptr) {
		node = new Node(data);
		numNodes++;
		return true;
	}
	else if (data == node->data_) {
		return false;
	}
	else if (data < node->data_) {
		return insert(node->left_, data);
	}
	else if (data > node->data_) {
		return insert(node->right_, data);
	}
	else {
		return false;
	}
}

/** Return true if node added to BST, else false */
template<typename T>
bool BST<T>::addNode(const T& data) {
	if (root_ == nullptr) {
		root_ = new Node(data);
		numNodes++;
		return true;
	}
	else if (data == root_->data_) {
		return false;
	}
	else if (data < root_->data_) {
		return insert(root_->left_, data); //call with left subtree
	}
	else if (data > root_->data_) {
		return insert(root_->right_, data); //call with right subtree
	}
	else {
		return false;
	}
}

/** Return a level order traversal of a BST as a string */
template<typename T>
std::string BST<T>::toString() const {
	std::stringstream out;
	if (root_ == NULL) out << " empty";
	else {
		int level = 0;
		do {
			out << std::endl << "  " << ++level << ":";
		} while (outLevel(root_, level, out));
	}
	return out.str();
}

/** Recursive Output nodes in order */
template<typename T>
void BST<T>::inOrder(Node* node, std::stringstream& out) const {
	if (node == nullptr) return;
	else if (node->left_ == nullptr) {
		out << node->data_ << " ";
		inOrder(node->right_, out);
		return;
	}
	else {
		inOrder(node->left_, out);
	}
	out << node->data_ << " ";
	if (node->right_ != nullptr) {
		inOrder(node->right_, out);
	}
	else {
		return;
	}
	return;
}

/* Output nodes in-order */
template<typename T>
std::string BST<T>::inOrderToString() const {
	std::stringstream out;
	inOrder(root_, out);
	return out.str();
}




/** Output nodes at a given level */
template<typename T>
bool BST<T>::outLevel(Node* root, int level, std::stringstream& out) const {
	if (root == NULL) return false;
	if (level == 1) {
		out << " " << root->data_;
		if ((root->left_ != NULL) || (root->right_ != NULL)) return true;
		return false;
	}
	if ((level == 2) && !root->left_ && root->right_) out << " _";
	bool left = outLevel(root->left_, level - 1, out);
	bool right = outLevel(root->right_, level - 1, out);
	if ((level == 2) && root->left_ && !root->right_) out << " _";
	return left || right;
}

/** Find node in BST. Return "found" or "not found" */
template<typename T>
bool BST<T>::search(Node* node, const T& data) const {
	if (node == nullptr) {
		return false;
	}
	else if (node->data_ == data) {
		return true;
	}
	else if (data < node->data_) {
		return search(node->left_, data);
	}
	else if (data > node->data_) {
		return search(node->right_, data);
	}
	else {
		return false;
	}
}

/* Recursive RemoveNode function */
template<typename T>
bool BST<T>::remove(Node*& node, const T& data) {
	if (node == nullptr) { //doesn't exist
		return false;
	}
	else if (data < node->data_) {
		return remove(node->left_, data); //call with left subtree
	}
	else if (data > node->data_) {
		return remove(node->right_, data); //call with right subtree 
	}
	else if (node->data_ == data) {
		if (node->left_ == nullptr && node->right_ == nullptr) { //no children
			delete node;
			node = nullptr;
			numNodes--;
			return true;
		}
		else if (node->left_ != nullptr && node->right_ == nullptr) { //left child only
			Node* tmp = node;
			node = node->left_;
			delete tmp;
			tmp = nullptr;
			numNodes--;
			return true;
		}
		else if (node->left_ == nullptr && node->right_ != nullptr) { //right child only
			Node* tmp = node;
			node = node->right_;
			delete tmp;
			tmp = nullptr;
			numNodes--;
			return true;
		}
		else if (node->left_ != nullptr && node->right_ != nullptr) { //two children
			node->data_ = predecessor(node->left_);
			remove(node->left_, node->data_);
		}
	}
	else {
		return false;
	}
}


template<typename T>
/** Return true if node removed from BST, else false */
bool BST<T>::removeNode(const T& data) {
	return remove(root_, data);
}