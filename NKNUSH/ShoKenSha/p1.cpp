#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for(int n, m, k, i=0; i<t; i++){
        cin >> n >> m >> k;

        if(k == (n-1)+n*(m-1)) cout << "YES\n";
        else cout << "NO\n";
    }
}