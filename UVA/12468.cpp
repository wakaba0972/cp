#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int a, b, c, d;
    while(cin >> a >> b){
        if(a == -1 && b == -1) break;
        if(a >= b) {
            c = a-b;
            d = 100-c;
        }
        else{
            c = b-a;
            d = 100-c;
        }
        cout << min(c, d) << '\n';
    }
}