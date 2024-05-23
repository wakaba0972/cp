#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    
    int t, x, y;
    cin >> t;
    while(t--){
        cin >> x >> y;
        int alst = ceil(y / 2.0);
        int nspac = (y >> 1) * 7 + (y & 1) * 11;
        x -= nspac;
        
        if(x <= 0) cout << alst << '\n';
        else cout << alst + ceil(x / 15.0) << '\n';
    }
}