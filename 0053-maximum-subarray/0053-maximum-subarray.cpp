class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0];
        int res = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int curr = max(prev + nums[i], nums[i]);
            res = max(curr, res);
            prev = curr;
        }
        return res;
    }
};