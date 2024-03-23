#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int ns[n];
    for(int i=0; i<n; i++) cin >> ns[i];

    for(int t, i=0; i<k; i++){
        cin >> t;
        auto it = lower_bound(ns, ns+k, t);
        if(t == *it) cout << it - ns + 1<< '\n';
        else cout << 0 << '\n';
    }
}