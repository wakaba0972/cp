/*
    騙人題目
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    
    while(t--){
        cin >> n >> k;
        if(n == k){
            while(n--) cout << 1 << ' ';
            cout << '\n';
        }
        else if(k == 1){
            for(int i=1; i<=n; i++) cout << i << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
}