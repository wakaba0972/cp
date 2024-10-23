/*
    樹直徑裸題
*/

#include<bits/stdc++.h>
using namespace std;

int n, deep=0, deepu;
vector<int> adj[100001];

void dfs(int cur, int lst, int dep=0){
	if(dep > deep) {
		deep = dep;
		deepu = cur;
	}
	
	for(int u: adj[cur]) {
		if(u == lst) continue;
		dfs(u, cur, dep+1);
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int s, t;
		cin >> s >> t;
		adj[s].push_back(t);
		adj[t].push_back(s);
	}
	
	dfs(0, -1);
	deep = 0;
	dfs(deepu, -1);
	cout << deep;
}