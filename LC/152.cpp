class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];
        vector<int> dp1(nums.size()), dp2(nums.size());
        dp1[0] = nums[0], dp2[0] = nums[0];

        for(int i=1; i<nums.size(); i++){
            dp1[i] = max({dp1[i-1]*nums[i], dp2[i-1]*nums[i], nums[i]});
            dp2[i] = min({dp1[i-1]*nums[i], dp2[i-1]*nums[i], nums[i]});
            mx = max(mx, dp1[i]);
        }

        return mx;
    }
};