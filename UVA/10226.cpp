#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int t;
    cin >> t;
    
    cin.ignore();
    cin.ignore();

    while(t--){
        double sum = 0;
        string s;
        map<string, int> mp;

        while(getline(cin, s)){
            if(s.size() == 0) break;

            mp[s]++;
            sum++;

        }

        for(auto p: mp) cout << p.first << ' ' << fixed << setprecision(4) << p.second / sum * 100<< '\n';
        if(t>0) cout << '\n';
    }
}