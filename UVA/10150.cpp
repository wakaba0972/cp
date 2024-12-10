/*
    將Doublets的字串視為相連的節點, 以此見出一張圖, BFS找最短路徑
*/

#include<bits/stdc++.h>
using namespace std;

#define long long ll
#define all(x) x.begin(), x.end()
#define em emplace_back

struct trip{
	int idx, lst;
};

bool cmp(string &a, string &b){
	if(a.size() != b.size()) return false;
	int dif = 0;
	for(int i=0; i<a.size(); ++i){
		if(a[i] != b[i]) if(++dif > 1) return false;
	}
	return true;
}

int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	
	int id = 0;
	string s;
	stringstream ss;
	
	unordered_map<string, int> dict;
	vector<string> vs;
	
	while(getline(cin, s)){
		if(s == "") break;
		
		ss << s;
		while(getline(ss, s, ' ')) {
			dict[s] = id++;
			vs.em(s);
		}
		
		ss.str(""); 
		ss.clear();
	}
	
	int len = id;
	vector<int> adj[len];
	for(int i=0; i<len; ++i){
		for(int j=i+1; j<len; ++j){
			if(cmp(vs[i], vs[j])){
				adj[i].em(j);
				adj[j].em(i);
			}
		}
	}
	
	bool fst = true;
	string s1, s2;
	while(cin >> s1 >> s2){
		if(!fst) cout << endl;
		else fst = false;
	
		vector<bool> done(len);
		vector<int> lst(len, -1);
		
		int st = dict[s1], ed = dict[s2];

		queue<trip> Q;
		Q.push({st, -1});

		while(!Q.empty()){
			auto u = Q.front();
			Q.pop();
			
			if(done[u.idx]) continue;
			done[u.idx] = true;
			lst[u.idx] = u.lst;
			
			if(u.idx == ed) break;
			
			for(int v: adj[u.idx]) Q.push({v, u.idx});
		}
		
		/*for(int i: lst) cout << i << ' ';
		cout << endl;*/
		
		if(lst[ed] == -1) cout << "No solution.\n";
		else{
			int cur = ed;
			vector<int> ans;
			while(cur >= 0){
				ans.em(cur);
				cur = lst[cur];
			}
			
			for(auto it=ans.rbegin(); it!=ans.rend(); ++it) cout << vs[*it] << endl;
		}
	}
	
}