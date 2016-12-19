#pragma once
#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface {
protected:
	Node* root;
	// Constructs a BST with a given node as the root
	BST(Node* new_root) : root(new_root) {}

public:
	// Constructs an empty BST
	BST() : root(NULL) {}
	// Constructs a BST with two subtrees
	BST(int the_data,
		const BST& left_child =
		BST(),
		const BST& right_child =
		BST()) :
		root(new Node(the_data, left_child.root, right_child.root)) {}
	virtual ~BST();

	virtual NodeInterface * getRootNode();
	virtual bool add(int data);
	bool add(Node*& local_root, int data);
	virtual bool remove(int data);
	bool remove(Node*& local_root, int data);
	virtual void clear();
	void delete_all(Node* local_root);
	void replaceParent(Node*& old_root, Node*& local_root);
};
