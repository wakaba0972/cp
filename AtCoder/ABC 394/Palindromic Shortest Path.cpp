/*
	迴文把左右字元拿掉後依然是迴文，利用此定義，我們首先找出最小單位(長度為1、2)的迴文，然後用BFS找出所有的迴文
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define em emplace_back
#define rep(i, n) for(int i=0; i<n; ++i)
#define oo 2000000000

int main(){
	fastio;
	
	int n;
	cin >> n;
	
	char m[n][n];
	rep(i, n) rep(j, n) cin >> m[i][j];
	
	vector<vector<int>> ans(n, vector<int>(n, oo));
	queue<pair<int, int>> Q;
	
	rep(i, n) {
		Q.push({i, i});
		ans[i][i] = 0;
	}
	rep(i, n) rep(j, n) {
		if(i == j || m[i][j] == '-') continue;
		Q.push({i, j});
		ans[i][j] = 1;
	}
	
	while(!Q.empty()){
		int st = Q.front().first;
		int ed = Q.front().second;
		Q.pop();
		
		rep(i, n) rep(j, n){
			if(m[ed][j] != '-' && m[i][st] == m[ed][j] && ans[i][j] == oo) { //因為是BFS，第二次到訪時ans[i][j]長度如果不是oo，則此時的迴文長度一定比較大
				ans[i][j] = ans[st][ed]+2;
				Q.push({i, j});
			}
		}
	}
	
	rep(i, n) {
		rep(j, n){
			if(ans[i][j] == oo) cout << -1 << ' ';
			else cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}