#include "Node.h"

Node::~Node() {}

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() {
	return data;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getLeftChild() {
	if (left == NULL) {
		return NULL;
	}
	else {
		return left;
	}
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getRightChild() {
	if (right == NULL) {
		return NULL;
	}
	else {
		return right;
	}
}