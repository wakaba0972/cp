// 把合法區間的st, ed記錄下來放進array裡
//再用二分搜判斷query是否合法

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> pos;
        vector<bool> ans;

        bool lst=0;
        int st = 0;
        int len = nums.size();

        for(int i=0; i<len; i++) {
            if(st == i){
                lst = (nums[i] & 1);
                continue;
            }
            
            if(lst == (nums[i] & 1)){
                pos.push_back(st);
                pos.push_back(i-1);
                st = i;
                lst = (nums[i] & 1);
                continue;
            }
            else {
                lst = (nums[i] & 1);
                continue;
            }
        }

        pos.push_back(st);
        pos.push_back(len-1);

        for(auto q: queries){
            int stit = lower_bound(pos.begin(), pos.end(), q[0]) - pos.begin();
            int edit = lower_bound(pos.begin(), pos.end(), q[1]) - pos.begin();

            if(edit - stit > 1 || (stit & 1 && !(edit & 1))){
                ans.push_back(0);
            }
            else ans.push_back(1);
        }

        return ans;
    }
};