#include "grapheBipartie.hpp"

// Initialisation graphs
void 	GrapheBipartie::init(void) {
	// Create nodes
	for(int i = 0; i < N; i++) {
		vRight.push_back(new Node(i));
		vLeft.push_back(new Node(i + N));
	}
	// Create neighbours (Link)
	for(int i = 0; i < vRight.size(); i++) {vRight[i]->addNeighbours(vLeft, P);}
}

// Remove a link in Maximum coupling
void 	GrapheBipartie::removeLink(Node* a) {
	for(int i = 0; i < vLink.size(); i++) {
		// Research the link with A
		if(a->number == vLink[i]->nodeA->number || a->number == vLink[i]->nodeB->number) {
			if(a->number == vLink[i]->nodeA->number) {
				vLink[i]->nodeB->free = true;
			} else {
				vLink[i]->nodeA->free = true;
			}
			delete vLink[i];
			vLink.erase(vLink.begin() + i);
			return;	
		}
	}
}

// Continuation of Hopcroft-Karp
int 	GrapheBipartie::researchLink(Node* n) {
	n->check = true;
	for(int j = 0; j < n->neighbours.size(); j++) {
        	if(n->neighbours[j]->isFree() && !n->neighbours[j]->isCheck()) {
			removeLink(n);
                	vLink.push_back(new Link(n, n->neighbours[j]));
                        n->free = false;
                        n->neighbours[j]->free = false;
			return 0;
                }
        }
	for(int j = 0; j < n->neighbours.size(); j++) {
		if(!n->neighbours[j]->isCheck()) {
			int r = researchLink(n->neighbours[j]);
			if(r == 0) {
				removeLink(n);
				return 1;
			} else if (r == 1)  {
				removeLink(n);
				vLink.push_back(new Link(n, n->neighbours[j]));
                	        n->free = false;
                        	n->neighbours[j]->free = false;
				return 0;
			}
		}
	}
	return 2;
}


// Algo of Hopcroft-Karp for bipartis Graphs
bool 	GrapheBipartie::algoBiPartie(void) {
	// Initialisation of Graph
	init();

	int lastSize = -1;
	while(vLink.size() != lastSize) {
		lastSize = vLink.size();
		for(int i = 0; i < N; i++) {
			if(!vRight[i]->isCheck()) {
				if(vRight[i]->isFree()) {researchLink(vRight[i]);}
			}
		}
                for(int i = 0; i < N; i++) {
                        if(!vLeft[i]->isCheck()) {
                                if(vLeft[i]->isFree()) {researchLink(vLeft[i]);}
                        }
                }
		for(int i = 0; i < N; i++) {
			vRight[i]->check = false;
			vLeft[i]->check = false;
		}
	}

	// Perfect Coupling
	if(verificationLink()) {
		clearGraph();
		return true;
	}
	
	clearGraph();

	// No Perfect Coupling
	return false;
}


// Clear Graph
void	GrapheBipartie::clearGraph(void) {
        for(int k = 0; k < vLink.size(); k++) {
                delete vLink[k];
        }
        for(int k = 0; k < N; k++) {
                delete vRight[k];
                delete vLeft[k];
        }
        vRight.clear();
        vLeft.clear();
	vLink.clear();
}


// Check graph
bool	GrapheBipartie::verificationLink(void) {
	if(vLink.size() == N) {
		for(int i = 0; i < vLink.size(); i++) {
			for(int j = 0; j < vLink.size(); j++) {
				if(i != j
					&& (vLink[i]->nodeA->number == vLink[j]->nodeA->number
					|| vLink[i]->nodeB->number == vLink[j]->nodeB->number
					|| vLink[i]->nodeA->number == vLink[j]->nodeB->number
					|| vLink[i]->nodeB->number == vLink[j]->nodeA->number)) {
					return false;
				}
			}
		}
		return true;
	} else {
		return false;
	}
}
