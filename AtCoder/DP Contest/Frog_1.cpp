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

	cin >> N;
	for(int i=0; i<N; i++) cin >> vs[i];

	dp[1] = abs(vs[1] - vs[0]);
    
    for(int i=2; i<N; i++){
    	dp[i] = min(abs(vs[i] - vs[i-1]) + dp[i-1], abs(vs[i] - vs[i-2]) + dp[i-2]);
    }
    
    cout << dp[N-1];
    
}