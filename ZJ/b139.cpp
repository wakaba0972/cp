#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int l, m;
    cin >> l >> m;

    bool tr[l+1];
    fill(tr, tr+l+1, 1);
    for(int a, b, i=0; i<m; i++){
        cin >> a >> b;
        for(int j=a; j<=b; j++) tr[j] = false;
    }

    int ans = 0;
    for(int i=0; i<=l; i++) ans += tr[i];

    cout << ans;
}