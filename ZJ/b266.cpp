#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int r, c, m;
    vector<vector<short>> mtx(10, vector<short>(10));
    bool mdy[10];

    while(cin >> r >> c >> m){
        for(int t, i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> mtx[i][j];
            }
        }
        for(int i=0; i<m; i++) cin >> mdy[m - i - 1];
        for(int i=0; i<m; i++){
            if(mdy[i]){
                reverse(mtx.begin(), mtx.begin() + r);
            }
            else{
                vector<vector<short>> tmp(10, vector<short>(10));
                for(int i=0; i<r; i++){
                    for(int j=0; j<c; j++){
                        tmp[c-j-1][i] = mtx[i][j];  
                    }
                }
                mtx = tmp;
                swap(r, c);
            }
        }
        cout << r << ' ' << c << '\n';
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout << mtx[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}