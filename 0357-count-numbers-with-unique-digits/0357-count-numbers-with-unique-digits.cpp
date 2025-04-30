class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        int res = 10;
        int dig = 9;
        int avail = 9;
        for(int i = 2;i<=n && avail>0;i++){
            dig *= avail;
            res += dig;
            avail--; 
        }
        return res;
    }
};