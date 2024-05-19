#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, len, mx = -1;
    cin >> t;

    string s;
    stringstream ss;
    vector<int> vs;

    getline(cin, s);

    while(t--){

        getline(cin, s);
        ss << s;
        while(ss >> a) vs.push_back(a);

        len = vs.size();
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                mx = max(__gcd(vs[i], vs[j]), mx);
            }
        }
        cout << mx << '\n';

        mx = -1;       
        ss.str("");
        ss.clear();
        vs.clear();
    }
}