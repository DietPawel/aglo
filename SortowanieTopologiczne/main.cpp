/*
 *  Sortowanie Topologiczne - algorytm na bazie DFS
*/
#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > G; //DAG

vector < bool > Gv; //visited arrey of G

stack < int > out; //sorted output

int sorttop(int e){
	
	if(Gv[e])
		return 0;
	
	Gv[e]=true;
	
	for(int i=0;i<(int)G[e].size();i++){
		sorttop(G[e][i]);
	}
	
	out.push(e+1);
	return 0;
}

int main () {
	int n,m; // number of edges and number of verticies
	scanf("%d %d", &n, &m);
	
	G.resize(n); Gv.resize(n);
	
	for(int i=0;i<m;i++){
		int tmp1, tmp2;
		scanf("%d %d" , &tmp1, &tmp2);
		tmp1--; tmp2--;
		G[tmp1].push_back(tmp2);
		//vertex form tmp1 to tmp2 means tmp1 if before tmp2
	}
	// sort
	for(int i=0;i<n;i++)
		sorttop(i);
	
	
	
	
	//print out 
	while(out.size()>0){
		printf("%d ", out.top());
		out.pop();
	}
	



	return 0;
}
