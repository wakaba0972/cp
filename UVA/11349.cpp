#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int cnt=1, t, n;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        cin >> s;
        cin >> n;

        vector<vector<long long>> mx(n, vector<long long>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> mx[i][j];
            }
        }

        bool f = 1;
        for(int i=0; i<((n+1)>>1); i++){
            for(int j=0; j<n; j++){
                if(mx[i][j] != mx[n-i-1][n-j-1] || mx[i][j] < 0 || mx[n-i-1][n-j-1] < 0) {
                    f = 0;
                    break;
                }
            }
        }   

        cout << "Test #" << cnt++ << ": " << (f? "Symmetric.\n": "Non-symmetric.\n");
    }
}