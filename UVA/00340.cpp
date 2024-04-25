#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    int n, t = 1;
    
    while(cin >> n){
        if(!n) break;

        cout << "Game " << t++ << ":\n";

        int s[n];
        unordered_map<int, int> ts_ori;

        for(int i=0; i<n; i++) {
            cin >> s[i];
            ts_ori[s[i]]++;
        }


        while(1){
            int g[n], a = 0, b = 0, z = 0;
            unordered_map<int, int> ts;
            unordered_map<int, int> as;

            for(int i=0; i<n; i++) {
                cin >> g[i];
                if(!g[i]) z++;
                if(g[i] == s[i]) {
                    as[g[i]]++;
                    a++;
                }
                else ts[g[i]]++;
            }

            if(z == n) break;

            for(auto p: ts){
                b += min(p.second, ts_ori[p.first] - (as.count(p.first)? as[p.first]: 0));
            }

            cout << '(' << a << ',' << b << ")\n";
        }
    }
}