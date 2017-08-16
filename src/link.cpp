#include "link.hpp"

// Constructor
Link::Link(Node* a, Node* b) {
	nodeA = a;
	nodeB = b;
}

// To _string
string Link::toString(void) {
	return "Link between : " + to_string(nodeA->number) + " --- " 
				 + to_string(nodeB->number) + "\n";
}
