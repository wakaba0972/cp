#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    
    int t, n, m, l, x, y, ans=0;
    
    cin >> t;
    while(t--){
        cin >> n >> m >> l;
        vector<vector<int>> adj(n+1);
        vector<bool> visit(n+1);
        queue<int> q;
        
        while(m--){
            cin >> x >> y;
            adj[x].push_back(y);
        }
        
        while(l--){
            cin >> x;
            q.push(x);
        }
        
        while(!q.empty()){
            int p = q.front();
            q.pop();
            //cout << p << endl;
            if(!p || visit[p]) continue;
            visit[p] = true;
            ans++;
            for(int i: adj[p]) q.push(i);
        }
        
        cout << ans << '\n';
        ans = 0;
    }
}