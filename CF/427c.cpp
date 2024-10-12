#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<int> st;
vector<int> adj[100001];
vector<map<int, int>> scc; //存scc節點
bool instk[100001];
int cost[100001];
int n, m, scc_cnt = 0, idx = 0, dfn[100001], low[100001];;

void tarjan(int x){
	++idx;
	dfn[x] = low[x] = idx;
	st.push(x);
	instk[x] = true;
	
	for(int u: adj[x]){
		if(!dfn[u]){
			tarjan(u);
			low[x] = min(low[x], low[u]);
		}
		else if(instk[u]) low[x] = min(low[x], dfn[u]);
	}
	if(dfn[x] == low[x]){ //此為ap
		scc.push_back({});
		int nxt = -1;
		while(nxt != x){
			nxt = st.top();
			st.pop();
			scc[scc_cnt][cost[nxt]]++;
			instk[nxt] = false;
		}
		scc_cnt++;
	}
}

void find_scc(){
	for(int i=1; i<=n; i++) if(!dfn[i]) tarjan(i);
}

int main() {
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> cost[i+1];
	
	
	cin >> m;
	for(int s, t, i=0; i<m; i++) {
		cin >> s >> t;
		adj[s].push_back(t);
	}
	
	find_scc();
	ll res1 = 0, res2 = 1;
	for(int i=0; i<scc_cnt; i++){
		res1 += scc[i].begin()->first;
		res2 = (res2 * scc[i].begin()->second) % 1000000007;
	}
	
	cout << res1 << ' ' << res2;
}