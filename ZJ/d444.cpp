#include<bits/stdc++.h>
using namespace std;

vector<int> ns = {1,2,3,4,5,6,7,8,9,10};
vector<int> cnb;
vector<vector<int>> ans;

int lcm(int a, int b){
	return a*b/__gcd(a,b);
}

int lcms(vector<int> vs){
	int res = vs[0];
	for(int i=1; i<vs.size(); i++) res = lcm(res, vs[i]);
	return res;
}

void dfs(int k=0){
	if(k >= ns.size()) return;
	cnb.push_back(ns[k]);
	ans.push_back(cnb);
	dfs(k+1);
	
	cnb.pop_back();
	dfs(k+1);
}

int main(){
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	
	long long n, m;
	
	while(cin >> n >> m){
		if(n==0 && m==0) break;
		
		ns.clear();
		cnb.clear();
		ans.clear();
		
		for(int t, i=0; i<m; i++){
			cin >> t;
			ns.push_back(t);
		}
		
		dfs();
		
		long long nn = 0;
		for(vector<int> v: ans){
			long long mul = 1;
			mul = lcms(v);
			//for(int i: v) cout << i  << ' ';
			//cout << endl;
			//cout << ((v.size()&1)? '+': '-') << n / mul << endl << endl;;
			if(v.size() & 1) nn += (n / mul);
			else nn -= (n / mul);
		}
		cout << n - nn << endl;
	}
}