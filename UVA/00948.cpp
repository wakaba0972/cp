#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

vector<ull> fib;
bitset<40> bs;

void build(){
    fib.push_back(1);
    fib.push_back(2);

    ull a = 0, i = 1;
    while(a < 100000000){
        a = fib[i] + fib[i-1];
        fib.push_back(a);
        i++;
    }
}

int findlow(int n){
    auto it = lower_bound(fib.begin(), fib.end(), n);
    if(*it > n) it--;

    if(bs[it - fib.begin() + 1]) it--;

    return it - fib.begin();
}

void sol(ull n){
    if(n < 1) return;

    int bits = findlow(n);
    n -= fib[bits];
    bs[bits] = 1;

    sol(n);
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    build();

    int n, a;
    cin >> n;

    while(n--){
        cin >> a;
        sol(a);

        cout << a << " = ";

        int i = 39;
        while(!bs[i]) i--;
        for(; i>=0; i--) cout << bs[i];
        cout << " (fib)\n";

        bs.reset();
    }
}