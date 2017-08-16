#include "node.hpp"

//If node is free
bool Node::isFree(void) {
	return free;
}

// If node is check
bool Node::isCheck(void) {
	return check;
}

// If node is neighbours of n
bool Node::isNeighbours(Node* n) {
	for(int i = 0; i < neighbours.size(); i++) {
		if(n->number == neighbours[i]->number) {
			return true;
		}
	}
	return false;
}

// Add Neign=hbours to this node with probability d
void Node::addNeighbours(vector<Node*> v, double d) {
	for(int i = 0; i < v.size(); i++) {
		// Probability
		double a = (double) (rand() % RAND_MAX) / RAND_MAX;
		if(a <= d && !v[i]->isNeighbours(this) && v[i]!=this) {
			neighbours.push_back(v[i]);
			v[i]->neighbours.push_back(this);
		}
	}
}

// To_String
string Node::toString(void) {
	string str;
  	int n = neighbours.size();	
	//Begin
	str = "Node N°" + to_string(number) + " : {";
	//Neighbours
	for(int i = 0; i < n - 1; i++) {str = str + to_string(neighbours[i]->number) + ", ";}
	//Last Neighbours
	if(n != 0) {str = str + to_string(neighbours[n - 1]->number);}
	//End
	str = str + "}\n";	
	
	return str;
}
