#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    vector<pair<int, int>> vs;

    bool b = 0;
    int t=1, l=1;
    while(t < 10000000){
        for(int r=l; r>0; r--){
            if(b) vs.push_back({l-r+1, r});
            else vs.push_back({r, l-r+1});
            t++;
        }
        b = !b;
        l++;
    }

    int n;
    while(cin >> n){
        cout << "TERM " << n << " IS " << vs[n-1].first << '/' << vs[n-1].second << '\n';
    }
}