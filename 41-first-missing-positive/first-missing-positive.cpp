class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] <= 0) {
                i++;
                continue;
            } else {
                int curr = nums[i] - 1;
                if (curr < n && nums[i] != nums[curr]) {
                    swap(nums[i], nums[curr]);
                } else {
                    i++;
                }
            } 
        }
            for(i = 0; i<n ; i++) {
                if( nums[i] != i+1) 
                return i+1;
            
        }

        return n+1;
    }
};