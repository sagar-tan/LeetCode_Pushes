// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long left = -1;
        long low = 1, high = n;
        while(low<=high){
            long mid = (high+low)/2;
            if(isBadVersion(mid)){
                left = mid;
                high = mid-1;
            }
            else if(mid<n){
                low = mid+1;
            }
            else{//arr[mid]>tg
                high = mid-1;
            }
        }
        return left;
        
    }
};