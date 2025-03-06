class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
//        vector<int> pref(n);
//        pref [0] = nums[0];
//        int minPrefSum = pref[0];
//        for(int i = 1; i<n ; i++){
//            pref[i] = pref[i-1]+nums[i];
//            minPrefSum = min(minPredfSum, pref[i]);
//        }
        int prefSum = nums[0];
        int minPrefSum = prefSum;
        for(int i = 1; i<n ; i++){
            prefSum += nums[i];
            minPrefSum = min(minPrefSum, prefSum);
        }
        if(minPrefSum >= 0) return 1;
        return 1-minPrefSum;
    }
}; 