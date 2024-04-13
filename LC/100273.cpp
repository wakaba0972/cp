/*
    類似於APCS低地距離
    將數字x出現的位置pos_i記錄起來
    用線段數維護區間最大值
    對數字x，遍歷pos，如果query(pos_i, pos_i+1) <= x，則合法，否則不合法
*/


class Solution {
public:    
    long long tree[100000 << 2];
    
    void build(int l, int r, int pos, vector<int>& nums) {
        if(l == r) {tree[pos] = nums[l]; return;}
        
        long long mid = (l+r)>>1;
        
        build(l, mid, (pos<<1)+1, nums);
        build(mid+1, r, (pos<<1)+2, nums);
        
        tree[pos] = max(tree[(pos<<1)+1], tree[(pos<<1)+2]);
    }
    
    long long query(int gl, int gr, int l, int r, int pos=0){
        if(gl == l && gr == r) return tree[pos];
        
        long long mid = (l+r)>>1;
        
        if(gr <= mid) return query(gl, gr, l, mid, (pos<<1)+1);
        else if(gl > mid) return query(gl, gr, mid+1, r, (pos<<1)+2);
        else {
            return max(query(gl, mid, l, mid, (pos<<1)+1), query(mid+1, gr, mid+1, r, (pos<<1)+2));
        }
    }
    
    long long numberOfSubarrays(vector<int>& nums) {
        int len = nums.size();
        long long ans = len;
        
        //O(n)
        build(0, len-1, 0, nums);
        
        //O(n)
        unordered_map<int, vector<int>> ump;
        for(int i=0; i<len; i++){
            ump[nums[i]].push_back(i);
        }

        //窩不知道這裡複雜度怎麼算，大概不大於O(n log n)吧?
        for(auto p: ump) sort(p.second.begin(), p.second.end());
        
        //O(n log n)
        for(auto p: ump){
            int len2 = p.second.size();

            for(int i=0, j=1, t=1; j<len2;){
                while(j < len2 && query(p.second[i], p.second[j], 0, len-1) <= p.first){
                    ans += t;
                    j++;
                    t++;
                }
                i = j;
                j++;
                t = 1;
            }
        }
        
        return ans;
    }
};