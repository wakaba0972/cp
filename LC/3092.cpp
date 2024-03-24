class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> ans;
        map<int, pair<long long, int>> mp; // {id, {times, ver}}
        priority_queue<pair<long long, pair<int, int>>> pq; // {times, {id, ver}}
        
        int l = nums.size();
        for(int i=0; i<l; i++){
            mp[nums[i]].first += freq[i];
            mp[nums[i]].second++;
            pq.push({mp[nums[i]].first, {nums[i], mp[nums[i]].second}});
            
            while(!pq.empty() && pq.top().second.second != mp[pq.top().second.first].second){
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};