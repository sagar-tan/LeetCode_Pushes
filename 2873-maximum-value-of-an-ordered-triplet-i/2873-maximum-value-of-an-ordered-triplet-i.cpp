class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n  = nums.size();
        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            long long a = 0;
            for (int i = j - 1; i >= 0; i--) {
                a = max(a, (long long) nums[i]); 
            }
            long long c = 0;
            for (int k = j +  1; k < n; k++) {
                c = max(c, (long long) nums[k]); 
            }
            long long value = (a - nums[j]) * c;
            ans = max(ans, value);
        }
        return ans; 
    }
};
