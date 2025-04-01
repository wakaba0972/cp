/*
	呈上題，只是多了k，表示每次能跳1~k階。
	因此有初始狀態	f(0)=0,
					f(1)=abs(stones[1]-stones[0]),
					f(2)=min(abs(stones[2]-stones[1])+f(1), abs(stones[2]-stones[0])+f(0))
					f(3)=min(abs(stones[3]-stones[2])+f(2), abs(stones[3]-stones[1])+f(1), abs(stones[3]-stones[0])+f(0))
					...
					f(k-1)=min(abs(stones[k-1]-stones[k-2])+f(k-2), abs(stones[k-1]-stones[k-3])+f(k-3), ..., abs(stones[k-1]-stones[0])+f(0))
	
	轉移方程: 對i>=k, f(i)=min(abs(stones[i]-stones[i-1])+f(i-1), abs(stones[i]-stones[i-2])+f(i-2), ..., abs(stones[i]-stones[i-k])+f(i-k))
	複雜度: O(nk)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	// input
	int n, k;
	cin >> n >> k;
	
	int stones[n];
	for(int i=0; i<n; ++i) cin >> stones[i];

	// init
	vector<int> dp(n, 2147483647);
	dp[0] = 0;
	
	for(int i=1; i<k && i<n; ++i){
		for(int j=0; j<i; ++j){
			dp[i] = min(dp[i], abs(stones[i]-stones[j])+dp[j]);
		}
	}
	
	// trans
	for(int i=k; i<n; ++i){
		for(int j=i-k; j<i; ++j){
			dp[i] = min(dp[i], abs(stones[i]-stones[j])+dp[j]);
		}
	}
	
	// output
	cout << dp[n-1];
}