#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, m, n, q;
    cin >> t;

    while(t--){
        cin >> m >> n >> q;
        cout << m << ' ' << n << ' ' << q << '\n';
        char mx[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> mx[i][j];
            }
        }

        while(q--){
            int r, c, w = 1;
            cin >> r >> c;

            while(1){
                w += 2;

                if(r-1 < 0 || r-1+w-1 >= m || c-1 < 0 || c-1+w-1 >= n){
                    w -= 2;
                    break;
                }

                bool f = 0;
                for(int i=0; i<w; i++){
                    if(mx[r-1+i][c-1] != mx[r][c] || mx[r-1][c-1+i] != mx[r][c] || mx[r-1+w-1][c-1+i] != mx[r][c] || mx[r-1+i][c-1+w-1] != mx[r][c]){
                        w -= 2;
                        f = 1;
                        break;
                    }
                }

                if(f) break;

                r -= 1;
                c -= 1;
            }

            cout << w << '\n';
        }
    }
}