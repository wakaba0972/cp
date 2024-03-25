#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n;
    cin >> n;

    char c;
    unordered_map<char, int> ump;
    vector<pair<char, int>> vs;

    while(cin.get(c)) if(isalpha(c)) ump[toupper(c)]++;
    for(auto p: ump) vs.push_back(p);
    sort(vs.begin(), vs.end(), cmp);
    for(auto p: vs){
        cout << p.first << ' ' << p.second << '\n';
    }   
}