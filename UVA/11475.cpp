#include<bits/stdc++.h>
using namespace std;

string s;

bool isPalindrome(int l, int r){
    for(; l<r; l++, r--){
        if(s[l] != s[r]) return false;
    }
    return true;
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    register int l, r;

    while(cin >> s){
        l = 0, r = s.size()-1;
        for(; l <= r; l++){
            if(isPalindrome(l, r)) {

                cout << s;
                for(l-=1; l>=0; l--) cout << s[l];
                cout << '\n';

                break;
            }
        }

    }
}