#include "Node.h"

// // // THE FRIEND METHODS ARE ALREADY IMPLEMENTED. // // //
// // // // // // // DO NOT CHANGE THEM! // // // // // // //

Node::Node(int id) {
	// TODO
	this->id = id;
}

Node::~Node() {
	// TODO
	int i, s = children.size();
	for (i = 0; i < s; ++i) {
	    try {
            children[i]->getData();
            delete (DataNode*) children[i];
        }
        catch (InvalidRequest e) {
            delete children[i];
        }
        children[i] = NULL;
    }
	children.clear();
}

Node::Node(const Node& node) {
	// TODO
	int i, s = node.children.size();
	this->id = node.id;
	/* for (i = 0; i < s; ++i)
        this->children.push_back(new Node(*node.children[i])); */
    for (i = 0; i < s; ++i) {
	    try {
            node.children[i]->getData();
            this->children.push_back(new DataNode(*(DataNode*) node.children[i]));
        }
        catch (InvalidRequest e) {
            this->children.push_back(new Node(*node.children[i]));
        }
	}
}

int Node::getId() const {
	// TODO
	return id;
}

char Node::getData() const {
	// TODO
	throw InvalidRequest();
	return 0;
}

vector<Node*>& Node::getChildren() {
	// TODO
	return children;
}

void Node::operator+=(Node& childNode) {
	// TODO
	this->children.push_back(&childNode);
}

Node* Node::operator&(const Node& node) const {
	// TODO
	try {
	    this->getData();
	    // return new DataNode(*(DataNode*) this);
	    return new DataNode(this->getId(), this->getData());
	}
	catch (InvalidRequest e) {
	    
	    try {
	        node.getData();
	        // return new DataNode(*(DataNode*) &node);
	        return new DataNode(node.getId(), node.getData());
	    }
	    catch (InvalidRequest e) {
	        // return new Node(*this);
	        return new Node(this->getId());
	    }
	}
}

// This is already implemented for you, do NOT change it!
ostream& operator<<(ostream& os, const Node& node) {
	try {
		node.getData();
		os << *(DataNode*)&node;
	}
	catch (InvalidRequest e) {
		os << "[" << node.id;
		for (int i = 0; i < node.children.size(); i++)
			os << ", " << *node.children[i];
		os << "]";
	}
	return os;
}

/*************** DataNode *****************/

DataNode::DataNode(int id, char data)
    : Node(id) {
	// TODO
	this->data = data;
}

DataNode::~DataNode() {
	// TODO
	int i, s = children.size();
	for (i = 0; i < s; ++i) {
	    try {
            children[i]->getData();
            delete (DataNode*) children[i];
        }
        catch (InvalidRequest e) {
            delete children[i];
        }
        children[i] = NULL;
    }
	children.clear();
}

DataNode::DataNode(const DataNode& dataNode)
    : Node(dataNode) {
	// TODO
	this->data = dataNode.data;
}

DataNode::DataNode(const Node& node, char data)
    : Node(node) {
	// TODO
	this->data = data;
}

char DataNode::getData() const {
	// TODO
	return data;
}

// This is already implemented for you, do NOT change it!
ostream& operator<<(ostream& os, const DataNode& dataNode) {
	os << "[" << "(" << dataNode.id << ", \'" << dataNode.data << "\')";
	for (int i = 0; i < dataNode.children.size(); i++)
		os << ", " << *dataNode.children[i];
	os << "]";
	return os;
}
