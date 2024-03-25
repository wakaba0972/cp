#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int ns[n];
        for(int i=0; i<n; i++) cin >> ns[i];
        sort(ns, ns+n);

        int m = ns[n>>1];

        int ans = 0;
        for(int i: ns) ans += abs(i - m);

        cout << ans << '\n';
    }
}