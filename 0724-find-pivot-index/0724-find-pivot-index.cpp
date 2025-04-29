class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix = 0;
        int n = nums.size();
        int total = 0;
        for(int num : nums){
            total += num;
        }
        for(int i = 0;i<n;i++){
            int suffix = total-prefix-nums[i];
            if(suffix == prefix)return i;
            prefix += nums[i];
        }
        return -1;

        
    }
};