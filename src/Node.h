#pragma once
#include "Debug.h"
#include <vector>

class Node
{
public:
	//Creates an empty node.
	Node(std::string name) : m_name(name) {}
	//Creates a new node, with a parent.
	Node(Node& parent, std::string name) : m_parent(&parent) { Debug::Log(std::cout, "Empty Node Created", LOG_CREATION); }

	//Creates an empty node with no object data or parent.
	Node() {}
	~Node();

	void AddChild(Node& child) { m_children.push_back(&child); }
	void ParentTo(Node& parent) { parent.AddChild(*this); }
	
	const std::string& GetName() const { return m_name; }
private:
	std::string m_name;

	Node* m_parent = nullptr;
	std::vector<Node*> m_children;
};