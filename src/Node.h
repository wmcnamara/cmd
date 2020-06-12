#pragma once
#include "Object.h"
#include <vector>

class Node
{
public:
	//Creates a new node, with a parent.
	Node(Node* parent, Object* obj, std::string name) : m_obj(obj), m_parent(parent), m_name(name) {}
	//Creates a new node with object data and no parent.
	Node(Object* obj) : m_obj(obj) {}
	//Creates a new node with no object data, and a parent.
	Node(Node* parent) { Debug::Log(std::cout, "Empty Node Created", LOG_CREATION); }

	//Creates an empty node with no object data or parent.
	Node() {}

	void AddChild(Node* child) { m_children.push_back(child); }
	void ParentTo(Node* parent) { parent->AddChild(this); }

	std::string m_name;
private:
	Object* m_obj;

	Node* m_parent;
	std::vector<Node*> m_children;
};