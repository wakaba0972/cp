#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n, m;
    while(cin >> n >> m){
        bool flag = 0;
        vector<int> ns;

        if(m == 0) flag = 1;
        else {
            while(n > 1){
            ns.push_back(n);

            if(n % m) {
                flag = 1;
                break;
            }
            else n /= m;
            }
        }

        if(flag) cout << "Boring!\n";
        else{
            for(int i: ns) cout << i << ' ';
            cout << "1\n";
        }
    }   
}