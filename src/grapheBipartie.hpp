#ifndef GRAPHEBIPARTIE_HPP
#define GRAPHEBIPARTIE_HPP

#include "node.hpp"
#include "link.hpp"

// Graph bipartie
class GrapheBipartie {
	public :
		// Right Node
		vector<Node*> vRight;
		// Left Node
		vector<Node*> vLeft;
		// Good Link
		vector<Link*> vLink;
		// Number of node
		int N = 500;
		// Probability
		double P;

		GrapheBipartie(double p) : P(p) {};
		// Initialisation graphs
		void    init(void);
		// Remove a link in Maximum coupling
		void    removeLink(Node* a);
		// Continuation of Hopcroft-Farp
		int     researchLink(Node* n);
		// Clear Graph
		void    clearGraph(void);
		// Algo of Hopcroft-Karp for bipartis Graphs
		bool    algoBiPartie(void);
		// Check graph
		bool    verificationLink(void);
};

#endif
