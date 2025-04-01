/*
	設f(i)為到達第i個石頭的最小花費，
	則有初始狀態 f(0) = 0, f(1) = abs(stones[1]-stones[0])
	轉移方程 f(i) = min(f(i-1)+abs(stones[i]-stones[i-1]), f(i-2)+abs(stones[i]-stones[i-2]))
	複雜度: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	// input
	int n;
	cin >> n;

	vector<int> stones(n);
	for(int i=0; i<n; ++i) cin >> stones[i];
	
	// init
	vector<int> dp(n);
	dp[1] = abs(stones[1]-stones[0]);
	
	// trans
	for(int i=2; i<n; ++i){
		dp[i] = min(abs(stones[i]-stones[i-1])+dp[i-1], abs(stones[i]-stones[i-2])+dp[i-2]);
	}
	
	// output
	cout << dp[n-1];
}