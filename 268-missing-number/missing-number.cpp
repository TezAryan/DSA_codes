class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int i= 0;
        int n = nums.size();

        while(i < n) {
            int correct = nums[i];

            if(nums[i] < n && nums[i] != nums[correct]) {
                swap(nums[i] , nums[correct]);
            } else { 
                i++;
            }

        }

        for(i=0 ; i<n ; i++) {
            if( nums[i] != i) return i;
        }
         return n;
    }
};