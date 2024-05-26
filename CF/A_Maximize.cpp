#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << (#x) << " " << (x) << endl

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;

        map<int, int> mp;
        for(int i=1; i<a; i++){
            mp[__gcd(a, i)+i] = i;
        }

        cout << (*(prev(mp.end(), 1))).second << '\n';
    }
}