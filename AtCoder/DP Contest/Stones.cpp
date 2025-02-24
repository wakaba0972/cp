/*
	給定k個石頭和集合A, 雙方使用最佳策略的結果一定唯一(不然這題會有問題), 因此一定至少存在一條f(k-i, !t) = false
	定義f(k, t)=剩餘k個石頭,輪到t玩時t能否取勝
	遍歷A, 如果存在f(k-i, !t) = false, 代表取了i個石頭後對方絕對贏不了, 則此為t此時的最佳策略
	
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long

int n, k;
vector<int> vs;
bool mem[100001][2], vis[100001][2];

bool f(int k, bool t=1){
	if(vis[k][t]) return mem[k][t];
	vis[k][t] = true;
	
	for(int i: vs){
		if(k >= i) if(!f(k-i, !t)) {
			return mem[k][t] = true;
		}
	}
	
	return mem[k][t] = false;
}

int main(){
	fastio;
	
	cin >> n >> k;
	for(int t, i=0; i<n; i++) {
		cin >> t;
		vs.push_back(t);
	}
	
	if(f(k)) cout << "First";
	else cout << "Second";
}