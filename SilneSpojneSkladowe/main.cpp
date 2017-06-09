#include <bits/stdc++.h>

using namespace std;

// Graph G1 and G2 which is G1 transposed
vector < vector < int > > G1;
vector < vector < int > > G2;

// Visited arrays for G1 and G2
vector < bool > G1vis;
vector < bool > G2vis;

// stack of Edges ids
stack < int > twy;

int dfs1(int e){
	if(G1vis[e])return 0;
	G1vis[e]=true;
	
	for(int i=0;i<(int)G1[e].size();i++){
		dfs1(G1[e][i]);
	}
	
	twy.push(e);
	return 0;
}

int dfs2(int e){
	if(G2vis[e])return 0;
	G2vis[e]=true;
	printf("%d ", e+1);
	
	for(int i=0;i<(int)G2[e].size();i++){
		dfs2(G2[e][i]);
	}
	
	
	return 0;
}

int main(){
	int maxEdge = 1e6; //One and 6 zeros
	scanf("%d", &maxEdge);
	
	int n; // Vertex number
	scanf("%d", &n);
	
	//resize vectors
	G1.resize(maxEdge); G2.resize(maxEdge);
	G1vis.resize(maxEdge, false); G2vis.resize(maxEdge, false);
	
	//construck Graph
	for(int i=0;i<n;i++){
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		tmp1--;tmp2--; // no Edge called 0;
		G1[tmp1].push_back(tmp2);
		G2[tmp2].push_back(tmp1);
	}
	//first step
	for(int i=0;i<maxEdge;i++)dfs1(i);

	
	//second dfs
	while(!twy.empty()){
		if(!G2vis[twy.top()]){
			dfs2(twy.top());
			printf("\n");
		}
		twy.pop();
	}
	
	
	return 0;
}
