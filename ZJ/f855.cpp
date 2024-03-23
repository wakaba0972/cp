#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n;
    cin >> n;

    priority_queue<pair<int, int>> pq;
    for(int l, r, i=0; i<n; i++){
        cin >> l >> r;
        pq.push({-l, r});
    }

    int ans = 0;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        if(cur.second < -pq.top().first) ans += (cur.second + cur.first);
        else {
            while(!pq.empty() && cur.second >= -pq.top().first) {
                cur.second = max(cur.second, pq.top().second);
                pq.pop();
            }
            ans += (cur.second + cur.first);
        }
    }

    cout << ans;
}