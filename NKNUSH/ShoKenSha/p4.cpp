#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    int ns[n];
    for(int i=0; i<n; i++) cin >> ns[i];

    int ps[n+1];
    ps[0] = 0;

    for(int i=0; i<n; i++){
        ps[i+1] = ps[i] + ns[i];
    }

    for(int l, r, i=0; i<q; i++){
        cin >> l >> r;
        cout << ps[r+1] - ps[l] << '\n';
    }
}