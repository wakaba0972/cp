#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

unordered_map<ull, ull> ump;

ull build(ull n){
    if(n == 1) return 1;

    int t;

    if(ump.count(n)) return ump[n];
    else if(n&1) t = build(3 * n + 1) + 1;
    else t = build(n >> 1) + 1;

    ump[n] = t;
    return ump[n];
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    ump[1] = 1;

    ull a, b, l, r, mx;
    while(cin >> a >> b){
        l = min(a, b);
        r = max(a, b);

        mx = 0;
        for(int i=l; i<=r; i++) mx = max(mx, build(i));
        cout << a << ' ' << b << ' ' << mx << '\n';
    }
}