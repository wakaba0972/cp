/*
    區間dp
    設dp(l, r): 表示將區間[l, r]合併成一個slime所需的最小代價
    窮舉i, dp(l, r) = min(dp(l, i)+dp(i+1, r)) + sum(vs[l]~vs[r])
*/

#include<bits/stdc++.h>
using namespace std;
#define oo LLONG_MAX

int n;
vector<long long> vs, ps(1);
vector<vector<long long>> mem;

long long dp(int l=0, int r=n-1){
	if(mem[l][r] != oo) return mem[l][r];
	if(r - l == 1) return mem[l][r] = vs[l] + vs[r];
	if(l == r) return mem[l][r] = 0;
	
	for(int i=l; i<r; i++){
		mem[l][r] = min(mem[l][r], dp(l, i)+dp(i+1, r));
	}
	
	mem[l][r] += ps[r+1]-ps[l];
	return mem[l][r];
}

int main(){
	cin >> n;
	for(int t, i=0; i<n; i++) {
		cin >> t;
		vs.push_back(t);
		ps.push_back(ps[i]+t);
	}
	
	mem.resize(n);
	for(int i=0; i<n; i++) mem[i].resize(n, oo);
	
	cout << dp();
	
}