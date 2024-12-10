#include "Node.h"

Node::Node(std::string key, int value)
{
	this->key = key;
	this->value = value;
	next = nullptr;
}
