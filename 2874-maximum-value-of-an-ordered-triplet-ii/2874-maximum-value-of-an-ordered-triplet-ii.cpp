class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> prefixMax(n, 0), suffixMax(n, 0);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        suffixMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }

        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            long long a = prefixMax[j - 1];
            long long c = suffixMax[j + 1];
            long long value = (a - nums[j]) * c;
            ans = max(ans, value);
        }

        return ans;
    }
};
