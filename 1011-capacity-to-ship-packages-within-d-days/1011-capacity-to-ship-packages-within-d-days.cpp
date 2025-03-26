class Solution {
    bool check(int x,vector<int>& weights,int days){
        int c=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>x){
                c++;
                sum=0;;
            }
            sum+=weights[i];
        }
        return c<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=0;
        int l = *max_element(weights.begin(), weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        while(l<=r){
            int mid=l+(r-l) /2;
            if(check(mid,weights,days)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};