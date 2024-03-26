class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        vector<bool> done(n+1);
        vector<int> dis(n+1);
        fill(dis.begin(), dis.end(), 2000000000);
        dis[k] = 0;

        for(auto v: times){
            adj[v[0]].push_back({v[1], v[2]});
        }

        priority_queue<pair<int, int>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto v = pq.top().second;
            pq.pop();

            if(done[v]) continue;
            done[v] = true;

            for(auto p: adj[v]){
                int u = p.first;
                int val = dis[v] + p.second;
                
                if(dis[u] > val){
                    dis[u] = val;
                    pq.push({-val, u});
                }
            }
        }

        int ans = -1;
        for(int i=1; i<=n; i++){
            if(!done[i]){
                ans = -1;
                break;
            }
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};