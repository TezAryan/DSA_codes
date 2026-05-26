class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area = 0;
        int ans = INT_MIN;
        int n = height.size();
        int l = 0 ;
        int r = n-1;
        while ( l < r ) {
           int area = min(height[l] , height[r]) * (r-l);
         ans = max(area , ans);
            if(height[l] < height[r]) l++;
            else r--;
        }

        return ans;
    }
};