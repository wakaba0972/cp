/*
    因為是按字典排列，給定長度n字串，求第a個排列，可以用 a / (n-1)! 來求字首。
    此題跟2024/5/21 CPE p6 類似。
*/

#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull fac(int n){
    ull res = 1;
    for(int i=1; i<=n; i++) res *=i;
    return res;
}

int main(){
    int t;
    cin >> t;

    for(int c=1; c<=t; c++){
        string s;
        ull a;
        cin >> s >> a;

        int len = s.size();
        ull f = fac(len-1);
        vector<int> ord(len);
        for(int i=0; i<len; i++) ord[i] = i;

        vector<int> ori;

        while(len > 1){
            ori.push_back(ord[a / f]);
            ord.erase(ord.begin() + (a / f));
            a %= f;
            f /= (--len);
        }
        //ori.push_back(ord[0]);
        for(int i: ori) cout << i << ' ';
        cout << endl;
    }
}