#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// Node
class Node {

	public : 
		// Node's number
		int number;
		// If the node is not in a link
		bool free = true;
		// If the node is check
		bool check = false;
		//Neighbour nodes
		vector<Node*> neighbours;

		Node(int n) : number(n) {}

		bool isFree(void);
		bool isCheck(void);
		bool isNeighbours(Node* n);
		void addNeighbours(vector<Node*> v, double d);

		string toString(void);	
};

#endif
