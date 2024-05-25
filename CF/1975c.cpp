/*
    元素同為e，長度為3的子陣列{e, e, e}，可以透過operation將原始陣列全部改為e
    因此，只要檢查每個長度為3的子陣列，找出其中最大的中位數就好
    當然陣列長度為2時做例外處理
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    
    while(t--){
        cin >> n;
        vector<int> vs(n);
        for(int i=0; i<n; i++) cin >> vs[i];
        
        if(n == 2) cout << min(vs[0], vs[1]) << '\n';
        else{
            int mx = -1;
            for(int i=0; i<n-2; i++){
                int tmp[3] = {vs[i], vs[i+1], vs[i+2]};
                sort(tmp, tmp+3);
                mx = max(mx, tmp[1]);
            }
            cout << mx << '\n';
        }
    }
}