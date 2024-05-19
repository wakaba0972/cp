#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bitset<3000> bs;

    while(cin >> n){
        int ns[n], cnt = 0;
        for(int i=0; i<n; i++) cin >> ns[i];

        bs = 0;

        for(int i=0; i<n-1; i++){
            if(!bs[abs(ns[i+1] - ns[i])] && 1 <= abs(ns[i+1] - ns[i]) && abs(ns[i+1] - ns[i]) < n) cnt++;
            bs[abs(ns[i+1] - ns[i])] = 1;
        }

        if(cnt == n-1) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
}