#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long

// 拓樸排序 by queue
vector<int> topo_sort(int n, vector<int> adj[], vector<int> &ideg){
	queue<int> qu;
	for(int i=1; i<=n; i++){
		if(!ideg[i]) qu.push(i);
	}
	
	vector<int> tps_vs;
	while(!qu.empty()){
		int u = qu.front();
		tps_vs.push_back(u);
		qu.pop();
		
		for(int v: adj[u]){
			ideg[v]--;
			if(!ideg[v]) qu.push(v);
		}
	}

	return tps_vs;
}

int main(){
	fastio;
	
	int n, m;
	cin >> n >> m;
	
	vector<int> adj[n+1]; //鄰接串列
	vector<int> ideg(n+1); //入度
	
	for(int i=0, x, y; i<m; i++){
		cin >> x >> y;
		adj[x].push_back(y); 
		ideg[y]++;
	}
	
	vector<int> tpvs = topo_sort(n, adj, ideg);
	
	// 令dp[i] = 到達第i點的最長路徑長, dp[i] = max(當前長度, j的長度 + 1)
	vector<int> dp(n+1);
	for(int u: tpvs){
		for(int v: adj[u]){
			dp[v] = max(dp[v], dp[u] + 1);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
	
}