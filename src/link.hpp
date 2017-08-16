#ifndef LINK_HPP
#define LINK_HPP

#include "node.hpp"

// Link between a node A and a node B
class Link {
	public :
		Node* nodeA;
		Node* nodeB;

		Link(Node* a, Node* b);
		string toString(void);
};

#endif
