#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long

int N;
vector<int> vs(100001);
vector<int> dp(100001);

int main(){
	fastio;

	int n, k;
	cin >> n >> k;
	
	for(int i=0; i<n; i++) cin >> vs[i];
	for(int i=1; i<k; i++){
		dp[i] = 2147483647;
		for(int j=0; j<i; j++){
			dp[i] = min(dp[i], dp[j] + abs(vs[i] - vs[j]));
		}
	}
	
	for(int i=k; i<n; i++){
		dp[i] = 2147483647;
		for(int j=1; j<=k; j++){
			dp[i] = min(dp[i], dp[i-j] + abs(vs[i] - vs[i-j]));
		}
	}
	
    cout << dp[n-1];
}