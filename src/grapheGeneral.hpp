#ifndef GRAPHEGENERAL_HPP
#define GRAPHEGENERAL_HPP

#include "node.hpp"
#include "link.hpp"
#include <memory.h>
#define M 1000

struct struct_edge{int v;struct_edge* n;};
typedef struct_edge* edge;

class GrapheGeneral{
	public:
		// The nodes
		vector<Node*> vNodes;
		// Number of node
		int N = 1000;
		// Probability
		double P;

		
		GrapheGeneral(double p):P(p){};

		void init(void);

		void  add_edge(int u,int v);

		int  LCA(int root, int u, int v);

		void mark_blossom(int lca,int u);
		
		int blossom_contraction(int s, int u, int v);

		int find_augmenting_path(int s);
		
		int augment_path(int s,int t);

		int edmonds();

		void print();

		bool checkPerfect();

		void clearGraph();


};


#endif
