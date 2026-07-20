class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0; 
        int high = 0 ; 
        int zeros = 0 ;
        int res = 0;

        for(  high = 0 ; high < nums.size() ; high++) { 
            if(nums[high] == 0) zeros++; 


            while( zeros > k ) { 
                if( nums[low] == 0) zeros--;

                low++;
            }

            res = max( res , high-low+1);
        }

        return res;
    }
};