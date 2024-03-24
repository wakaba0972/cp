#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int cnt = 0;
    char c;
    while(cin.get(c)){
        if(c == '"') {
            if(cnt & 1) cout << "''";
            else cout << "``";
            cnt++;
        }
        else cout << c;
    }
}