#include<bits/stdc++.h>
using namespace std;


int n, lgN;
vector<pair<int, long long>> adj[100001]; // {node, length}
vector<int> dep(100001);
int par[100001][20];
long long presum[100001];

void build(int u=0, int h=1, long long s=0, int lst=-1){
	dep[u] = h;
	presum[u] = s;
	par[u][0] = lst;
	for(auto p: adj[u]) {
		if(p.first == lst) continue;
		build(p.first, h+1, s+p.second, u);
	}
}

void build_par(){
	for(int i=0; i<=lgN; i++){
		for(int j=0; j<n; j++){
			par[j][i+1] = par[par[j][i]][i];
			//cout << par[j][i+1] << endl;
		}
	}
}

int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	
	int d = dep[u] - dep[v];
	for(int i=0; d>0; d>>=1, i++) {
		if(d&1) u = par[u][i];
	}
	
	if(u == v) return u;
	
	for(int i=lgN; i>=0; i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	
	return par[u][0];
}

long long dist(int u, int v){
	int a = lca(u, v);
	return presum[u] + presum[v] - (presum[a] << 1);
}

int main(){	
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	while(cin >> n){
		if(!n) break;
		
		long long a, l;
		for(int i=1; i<n; i++){
			cin >> a >> l;
			adj[i].push_back({a, l});
			adj[a].push_back({i, l});
		}
			
		lgN = log2(n);
		build();
		build_par();
		
		int q;
		cin >> q;
		for(int s, t, i=0; i<q; i++){
			cin >> s >> t;
			if(i == q-1) cout << dist(s, t);
			else cout << dist(s, t) << ' ';
		}
		cout << '\n';
		
		dep.clear();
		memset(adj, 0, sizeof(adj));
		memset(par, 0, sizeof(par));
		memset(presum, 0, sizeof(presum));
	}
}
