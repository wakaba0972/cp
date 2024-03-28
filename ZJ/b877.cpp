#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int a, b;
    while(cin >> a >> b){
        cout << (b-a+200)%100 << '\n';
    }
}