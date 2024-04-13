/*
    大部分跟dijkstra一樣
    如果當前節點時間 + 權重 > disappear time 就不加入priority_queue;
*/

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int, int>> adj[n];
        vector<bool> done(n);
        vector<int> dis(n);
        fill(dis.begin(), dis.end(), 2000000000);

        for(auto v: edges){
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }

        priority_queue<pair<int, int>> pq;
        pq.push({dis[0] = 0, 0});

        while(!pq.empty()){
            auto v = pq.top().second;
            pq.pop();
            
            if(done[v]) continue;
            done[v] = true;

            for(auto p: adj[v]){
                int u = p.first;
                int val = dis[v] + p.second;
                
                if(dis[u] > val && val < disappear[u]){
                    dis[u] = val;
                    pq.push({-val, u});
                }
            }
        }

        vector<int> ans;
        for(int i: dis){
            if(i == 2000000000) ans.push_back(-1);
            else ans.push_back(i);
        }

        return ans;
    }
};