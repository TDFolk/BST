#include "BST.h"

BST::~BST() {}

NodeInterface * BST::getRootNode() {
	return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data) {	
	return add(this->root, data);
}
bool BST::add(Node*& local_root, int data) {
	if (local_root == NULL) {
		local_root = new Node(data);
		return true;
	}
	else if (data == local_root->data) {
		return false;
	}
	else {
		if (data < local_root->data) {
			return add(local_root->left, data);
		}
		else if (data > local_root->data) {
			return add(local_root->right, data);
		}
		else {
			return false;
		}
	}
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
// Shows another function that is also named remove in the powerpoint
bool BST::remove(int data) {
	return remove(this->root, data);
}
bool BST::remove(Node*& local_root, int data) {
	// Possibly use a temp variable to hold root instead of modifying it directly
	if (local_root == NULL) {
		return false;
	}
	else {
		if (data < local_root->data) {
			return remove(local_root->left, data);
		}
		else if (data > local_root->data) {
			return remove(local_root->right, data);
		}
		// This checks for: if (data == local_root->data). Found data
		else {
			Node* old_root = local_root;
			if (local_root->left == NULL) {
				local_root = local_root->right;
			}
			else if (local_root->right == NULL) {
				local_root = local_root->left;
			}
			else {
				replaceParent(old_root, old_root->left);
			}
			delete old_root;
			return true;
		}
	}
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
// Recursive algorithm to clear all Nodes in the BST
void BST::delete_all(Node* local_root) {
	if (local_root == NULL){
		return;
	} 
	if (local_root->left != NULL) {
		delete_all(local_root->left);
	}
	if (local_root->right != NULL) {
		delete_all(local_root->right);
	}
	delete local_root;
	return;
}
void BST::clear() {
	delete_all(root);
	root = NULL;
}

void BST::replaceParent(Node*& old_root, Node*& local_root) {
	if (local_root->right != NULL) {
		replaceParent(old_root, local_root->right);
	}
	else {
		old_root->data = local_root->data;
		old_root = local_root;
		local_root = local_root->left;
	}
}