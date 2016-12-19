#pragma once
#include <iostream>
#include "NodeInterface.h"

using namespace std;

struct Node : public NodeInterface {
	int data;
	Node* left;
	Node* right;

	Node(int the_data,
		Node* left_value = NULL,
		Node* right_value = NULL) :
		data(the_data), left(left_value), right(right_value) {}
	virtual ~Node();
	virtual int getData();
	virtual NodeInterface * getLeftChild();
	virtual NodeInterface * getRightChild();
};
