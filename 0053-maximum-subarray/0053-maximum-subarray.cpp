class Solution {
public:
    int maxSubArray(vector<int>& nums) {//Unoptimised Using 2 Loops
        int n  = nums.size(); 
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i<n;i++){
            pref[i] = pref[i-1]+ nums[i];
        }
        int minP = 0;
        int maxS = INT_MIN;
        for(int i = 0; i<n; i++){
            int curr_sum  = pref[i] - minP;
            maxS = max(maxS, curr_sum);
            minP = min(minP, pref[i]);
        }
        return maxS;
        
    }
};