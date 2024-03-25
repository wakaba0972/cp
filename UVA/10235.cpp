#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001

bool table[MAX];

void build(){
    fill(table, table + MAX, true);
    table[0] = table[1] = false;

    for(int i=2; i<=sqrt(MAX); i++){
        if(table[i]){
            for(int j=(i<<1); j<MAX; j += i) table[j] = false;
        }
    }

    //for(int i=1; i<100; i++) cout << i << ' ' << table[i] << endl;
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    build();

    bool b1, b2;
    string s, rs;
    while(cin >> s){
        rs = s;
        reverse(rs.begin(), rs.end());

        b1 = table[stoi(s)];
        b2 = table[stoi(rs)];

        if(b1 && b2 && s != rs) cout << s << " is emirp.\n";
        else if(b1) cout << s << " is prime.\n";
        else cout << s << " is not prime.\n";     
    }
}