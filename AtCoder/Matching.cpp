#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    bool matched[N][N];
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin >> matched[i][j];

    long long dp[N+1][1<<N];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    
    for(int i=0; i<N; ++i){
        for(int s=0; s<(1<<N); ++s){
            for(int j=0; j<N; ++j){
                if(matched[i][j] && !(s&(1<<j))){
                    dp[i+1][s|(1<<j)] += dp[i][s];
                    dp[i+1][s|(1<<j)] %= 1000000007;
                }
            }
        }
    }

    cout << dp[N][(1<<(N)-1)];
}