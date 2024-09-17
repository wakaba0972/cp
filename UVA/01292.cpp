/*
	注意這題要監視的是edge, 不是node
	定義f(v, b) = 以v為root的樹放/不放兵的最小花費
	如果v不放兵, 則每個children(v)一定要放
	如果v放兵, 則每個children(v)可放可不放
	此題和某dp入門題類似, 只是變成樹的形式
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long

int dp(int v, bool b, int pre, vector<int> *adj, vector<vector<int>> &mem){
	if(mem[v][b] >= 0) return mem[v][b];
	if(!b){
		int s = 0;
		for(int u: adj[v]){
			if(u == pre) continue;
			s += dp(u, 1, v, adj, mem);
		}
		return mem[v][b] = s;
	}
	else {
		int s = 1;
		for(int u: adj[v]){
			if(u == pre) continue;
			s += min(dp(u, 0, v, adj, mem), dp(u, 1, v, adj, mem));
		}
		return mem[v][b] = s;
	}
}

int main(){
	fastio;

	int n;
	while(cin >> n){
		vector<int> adj[n];
		vector<vector<int>> mem(1500, vector<int>(2, -1));

		int u, t, v, root;
		for(int i=0; i<n; i++){
			cin >> u;
			cin.ignore();
			cin.ignore();
			cin >> t;
			cin.ignore();
			for(int j=0; j<t; j++){
				cin >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		cout << min(dp(0, 0, -1, adj, mem), dp(0, 1, -1, adj, mem)) << '\n';
	}
}