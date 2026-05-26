class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            if ( i > 0 && nums[i] == nums[i - 1])
                continue;

            int sum = -1 * nums[i];
        
        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r) {
            int S = nums[l] + nums[r];

            if (S == sum) {
                result.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
            

            while (l < n && nums[l] == nums[l - 1]) 
                l++;
            
            while (r > 0 && nums[r] == nums[r + 1]) 
                r--;
            
            }

             else if (S < sum)
                l++;
            else
                r--;
        }
        }
        return result;
    }
};