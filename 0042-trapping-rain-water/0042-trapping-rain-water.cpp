class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0 )
        return 0;
        int res = 0;
        int l = 0,r = height.size()-1;
        int maxl = height[l];int maxr = height[r];
        while(l<r){
            if(maxl<maxr){
                l++;
                maxl = max(maxl, height[l]);
                res += maxl - height[l];
            }
            else{
                r--;
                maxr = max(maxr,height[r]);
                res += maxr - height[r];
            }
        }
        return res;
    }
};