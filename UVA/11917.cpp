#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        unordered_map<string, int> ump;

        string s;
        int k;
        while(n--) {
            cin >> s >> k;
            ump[s] = k;
        }

        int d;
        cin >> d;

        string hws;

        cin >> hws;

        if(!ump.count(hws)) cout << "Case " << i+1 << ": Do your own homework!\n";
        else if(ump[hws] <= d) cout << "Case " << i+1 << ": Yesss\n";
        else if(ump[hws] <= d+5) cout << "Case " << i+1 << ": Late\n";
        else cout << "Case " << i+1 << ": Do your own homework!\n";
    }
}