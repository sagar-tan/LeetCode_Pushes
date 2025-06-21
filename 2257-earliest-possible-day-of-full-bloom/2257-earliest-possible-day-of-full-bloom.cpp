class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n  = plantTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return growTime[a] > growTime[b];
        });
        int curr = 0;
        int res = 0;
        for(int i : idx){
            curr += plantTime[i];
            res = max(res, curr+growTime[i]);
        }
        return res;
    }
};