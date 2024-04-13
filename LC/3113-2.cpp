/*
    官解

    單調遞減隊列，
    如果x > top，清空stack
    如果stack為空，將x加入
    如果top == x，ans += cnt(x), cnt(x)++，(只有x連續時cnt會增加)
    如果top > x，將x加入，ans += 1
*/

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = 0;
        stack<vector<int>> stk;

        for(int i: nums){
            while(!stk.empty() && stk.top()[0] < i) stk.pop();

            if(stk.empty()) {
                stk.push({i, 1});
                ans += 1;
                continue;
            }

            if(stk.top()[0] == i){
                stk.top()[1]++;
                ans += stk.top()[1];
                continue;
            }

            if(stk.top()[0] > i) {
                stk.push({i, 1});
                ans += 1;
                continue;    
            }
        }

        return ans;
    }
};