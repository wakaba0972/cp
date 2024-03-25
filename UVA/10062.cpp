#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first > b.first;
    else return a.second < b.second;
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    string s;
    while(getline(cin, s)){
        unordered_map<int, int> ump;
        for(char c: s) ump[c]++;

        vector<pair<int, int>> ps;
        for(auto it=ump.begin(); it!=ump.end(); it++) ps.push_back(*it);
        sort(ps.begin(), ps.end(), cmp);

        for(auto p: ps){
            cout << p.first << ' ' << p.second << '\n';
        }
        cout << '\n';
    }
}