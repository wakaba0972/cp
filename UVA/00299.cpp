#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for(int t, i=0; i<n; i++){
        cin >> t;
        
        int ns[t];
        for(int i=0; i<t; i++) cin >> ns[i];

        int ans = 0;
        for(int i=0; i<t; i++){
            for(int j=t-1; j>i; j--){
                if(ns[j] < ns[j-1]) {
                    swap(ns[j], ns[j-1]);
                    ans++;
                }
            }
        }
        cout << "Optimal train swapping takes " << ans << " swaps.\n";
    }
}