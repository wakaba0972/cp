#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n;
    while(cin >> n){
        int ns[n];
        for(int i=0; i<n; i++) cin >> ns[i];

        sort(ns, ns+n);

        int a1, a2, a3;

        a1 = n&1? ns[n>>1]: ns[(n>>1) - 1];
        
        if(n&1){
            a2 = 0;
            for(int i: ns) if(i == a1) a2++;
        }
        else{
            a2 = 0;
            for(int i: ns) if(i == ns[n>>1] || i == ns[(n>>1) - 1]) a2++;
        }

        a3 = n&1? 1: ns[(n>>1)] - ns[(n>>1) - 1] + 1;

        cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
    }
}