#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    char c;
    for(int s, i=0; i<9; i++){
        s = 45;
        for(int j=0; j<9; j++){
            cin >> c;
            s -= c - '0';
        }
        cout << s << '\n';
    }
}