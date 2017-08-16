#include "grapheGeneral.hpp"


struct_edge pool[M*M*2];
edge top = pool;
edge adj[M];
int father[M],match[M],base[M],q[M];
bool inq[M],inb[M],ed[M][M];
int qt,qh;
int i = 0;


// Initialisation graphs
void GrapheGeneral::init(void){
	for(int i = 0; i < N; i++){
		vNodes.push_back(new Node(i));
	}
	vector<Node*> neighb;
	for(int i = 0; i < M; i++)
		memset(&adj[i],0,sizeof(edge));

	for(int i = 0; i < vNodes.size(); i++){
		vNodes[i] -> addNeighbours(vNodes, P);
		neighb = vNodes[i]-> neighbours;
		for(int j = 0; j < neighb.size(); j++){
			int u = vNodes[i] -> number;
			int v = neighb[j] -> number;
			add_edge(u,v);
			ed[u][v] = ed[v][u] = true;
		}

	}
	neighb.clear();
	top = pool;
	/*for(int i = 0; i < vNodes.size(); i++){
		cout << vNodes[i] -> toString();
	}*/

}

// Add the edge between u and v
void GrapheGeneral::add_edge(int u,int v)
{
  top->v=v;top->n=adj[u];
  adj[u]=top++;
  top->v=u;top->n=adj[v];
  adj[v]=top++;
}

//find ancestor, return the number of node
int GrapheGeneral::LCA(int root, int u, int v){
	static bool inp[M];
	memset(inp,0,sizeof(inp));
	while(1)
	{
	  inp[u=base[u]]=true;
	  if (u==root) break;
	  u=father[match[u]];
	}
	while(1)
	{
	  if (inp[v=base[v]]) return v;
	  else v=father[match[v]];
	}
}


void GrapheGeneral::mark_blossom(int lca,int u)
{
  while (base[u]!=lca)
    {
      int v=match[u];
      inb[base[u]]=inb[base[v]]=true;
      u=father[v];
      if (base[u]!=lca) father[u]=v;
    }
}

int GrapheGeneral::blossom_contraction(int s, int u, int v){
	int lca = LCA(s,u,v);
	memset(inb,0,sizeof(inb));
	mark_blossom(lca,u);
	mark_blossom(lca,v);
	if (base[u]!=lca)
    father[u]=v;
	if (base[v]!=lca)
	father[v]=u;
	for (int u=0;u<N;u++)
	if (inb[base[u]]){
		base[u]=lca;
		if (!inq[u])
	  		inq[q[++qt]=u]=true;
	}

}

int GrapheGeneral::find_augmenting_path(int s){
	memset(inq,0,sizeof(inq));
	memset(father,-1,sizeof(father));
	for(int i = 0; i < N; i++)
		base[i] = i;
	inq[q[qh=qt=0]=s]=true;
	while (qh<=qt){
    	int u=q[qh++];
    	for (edge e=adj[u];e;e=e->n){
	  		int v=e->v;
	  		if (base[u]!=base[v]&&match[u]!=v)
	    		if ((v==s)||(match[v]!=-1 && father[match[v]]!=-1))
	    			blossom_contraction(s,u,v);
	    	else if (father[v]==-1){
				father[v]=u;
				if (match[v]==-1)
		  			return v;
				else if (!inq[match[v]])
		  			inq[q[++qt]=match[v]]=true;
	    	}
      	}
    }
  return -1;
}


int GrapheGeneral::augment_path(int s,int t)
{
  int u=t,v,w;
  while (u!=-1)
    {
      v=father[u];
      w=match[v];
      match[v]=u;
      match[u]=v;
      u=w;
    }
  return t!=-1;
}


//algo of edmonds
int GrapheGeneral::edmonds()
{
  int matchc=0;
  memset(match,-1,sizeof(match));
  for (int u=0;u<N;u++)
    if (match[u]==-1)
      matchc+=augment_path(u,find_augmenting_path(u));

  return matchc;
}


void GrapheGeneral::print(){
	for(int i = 0; i < N; i++){
		if(i < match[i])
			cout << i << " " << match[i] << endl;
	}
}

//Check if a perfect match
bool GrapheGeneral::checkPerfect(){
	//cout << 6 << endl;
	bool perfect = true;
	for(int i = 0; i < N; i++){
		if(match[i] == -1){
			perfect = false;
			break;
		}	
	}
	return perfect;
}

void GrapheGeneral::clearGraph(){
	for(int i = 0; i < N; i++){
		delete vNodes[i];
	}
	vNodes.clear();
}
