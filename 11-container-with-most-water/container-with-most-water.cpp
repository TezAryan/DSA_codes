class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN ; 
        int n = height.size(); 
        int l = 0 ; 
        int r = n -1 ; 
        int ans = 0; 
        while ( l < r) {

            area = min(height[l] , height[r]) * (r-l);
            ans = max( ans , area); 

            if ( height[l] < height[r]) l++; 
            else 
            r--;

        }

        return ans;
     }
};