/*
    設dp[i][j]是前i個人選擇前j攤的最大值,
    用deque維護一個窗口，窗口內的元素不重複,
    則dp[i][j] = max(dp[i][j-1], dp[i-1][j-len] + len), len為將第j攤加入窗口後的最大長度,
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> vs(n+1);
	vector<vector<int>> dp(k+1, vector<int>(n+1));
	for(int i=1; i<=n; i++) cin >> vs[i];
	
	for(int i=1; i<=k; i++){
		bitset<5000001> inq; 
		deque<int> dq;
		for(int j=i+1, len=0; j<=n; j++){
			if(inq[vs[j]]){
				while(dq.front() != vs[j]) {
					inq[dq.front()] = 0;
					dq.pop_front();
					--len;
				}
				inq[vs[j]] = 0;
				dq.pop_front();
				--len;
			}
			inq[vs[j]] = 1;
			dq.push_back(vs[j]);
			++len;
			
			dp[i][j] = max(dp[i][j-1], dp[i-1][j-len] + len);
		}
	}
	
	cout << dp[k][n];
}