class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int right = n - 1;
        int left = 0;
        int max_vol = 0;
        int temp;
        
        while (right > left) {
            temp = min(height[left], height[right]) * (right - left);
            max_vol = max(max_vol, temp);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_vol;
        
    }
};