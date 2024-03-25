#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n;
    string s1, s2;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s1 >> s2;
        bitset<30> b1(s1);
        bitset<30> b2(s2);

        int a1 = b1.to_ulong();
        int a2 = b2.to_ulong();

        if(__gcd(a1, a2) > 1) cout << "Pair #" << i << ": All you need is love!\n";
        else cout << "Pair #" << i << ": Love is not all you need!\n";

    }
}