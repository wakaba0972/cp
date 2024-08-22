/*
	定義f(i, j) = 考慮第i個人, 把j個糖果分完的方法數
	f(i, j) = sum of f(i-1, j-k), k=[0, min(a_i, j)]
	也就是將第i-1個人的k個扣打分給第i個人, 複雜度為O(NK^2)
	注意到上述轉移式的第i項都是由i-1項的區間和組成, 因此能用前綴和優化, 複雜度為O(NK+K)	
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long
#define mod 1000000007

int n, k;
ll dp[100][100001];
ll presum[100][100002];


int main(){
	cin >> n >> k;
	
	int as[n];
	for(int i=0; i<n; i++){
		cin >> as[i];
	}
	
	for(int i=0; i<=as[0]; i++) dp[0][i] = 1;
	for(int i=1; i<=k+1; i++) presum[0][i] = presum[0][i-1] + dp[0][i-1];
	
	for(int i=1; i<n; i++){
		for(int j=0; j<=k; j++){
			//模除減法(前綴和裡都是mod p後的值, 有可能出現 "小-大" 的情況, 為了確保mod的正確性, 需要先+p後再mod p)
			dp[i][j] = (presum[i-1][j+1] - presum[i-1][max(0, j-as[i])] + mod) % mod;
			presum[i][j+1] = (presum[i][j] + dp[i][j]) % mod;
		}
	}
	
	cout << dp[n-1][k];
}