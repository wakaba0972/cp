#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int ts;
    cin >> ts;

    while(ts--){
        int n, m;
        cin >> n >> m;

        int ps[m];
        for(int i=0; i<m; i++) cin >> ps[i];

        vector<bool> dy(n+1);
        for(int i=1; i<n+1; i++){
            if((i % 7 == 6) || (i % 7 == 0)) continue;
            
            for(int j=0; j<m; j++){
                if(!(i % ps[j])) {
                    dy[i] = true;
                    break;
                }
            }
        }

        int ans = 0;
        for(int i=1; i<n+1; i++) ans += dy[i];
        cout << ans << '\n';
    }
}