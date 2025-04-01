/*
    設dp0[i], dp1[i], dp2[i]分別為第i天選擇游泳、抓蟲、作業時，0~第i天的最大收益
    則有轉移式:  dp0[i] = max(dp1[i-1], dp2[i-1]) + vs[i][0]
                dp1[i] = max(dp0[i-1], dp2[i-1]) + vs[i][1]
                dp2[i] = max(dp0[i-1], dp1[i-1]) + vs[i][2]
    複雜度: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define eb emplace_back
#define pb push_back
#define rep(s, n) for(int i=s; i<n; ++i)
#define oo 2e10

int main(){
	fastio;

	// input
	int n;
	cin >> n;
	
	vector<vector<int>> vs(n, vector<int>(3));
	for(int i=0; i<n; ++i){
		cin >> vs[i][0] >> vs[i][1] >> vs[i][2];
	}
	
	// init
	vector<int> dp0(n), dp1(n), dp2(n);
	dp0[0] = vs[0][0];
	dp1[0] = vs[0][1];
	dp2[0] = vs[0][2];
	
	// trans
	for(int i=1; i<n; ++i){
		dp0[i] = max(dp1[i-1], dp2[i-1]) + vs[i][0];
		dp1[i] = max(dp0[i-1], dp2[i-1]) + vs[i][1];
		dp2[i] = max(dp0[i-1], dp1[i-1]) + vs[i][2];
	}
	
	// output
	cout << max({dp0[n-1], dp1[n-1], dp2[n-1]});
	
}