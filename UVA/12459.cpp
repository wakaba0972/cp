#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    vector<ull> fib = {1, 1, 2};
    for(int i=3; i<=80; i++) fib.push_back(fib[i-1] + fib[i-2]);

    int n;
    while(cin >> n){
        if(!n) break;
        cout << fib[n] << '\n';
    }
}