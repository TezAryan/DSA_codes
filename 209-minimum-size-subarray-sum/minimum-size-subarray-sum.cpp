class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int low = 0;
        int high = 0;
        int res = INT_MAX;

        for (high = 0 ; high < n ; high++) {
            sum += nums[high];
        

        while ( sum >= target) {
            res = min(res , high - low + 1);
            sum=sum - nums[low];
            low++;
        }
        }

        return res == INT_MAX ? 0 : res;
       
    }
};