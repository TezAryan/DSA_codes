class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int low = 0 ; 
        int count = 0 ; 
        int n = nums.size();
        long long ans =0;

        int maxElement = *max_element(nums.begin() , nums.end()); 

        for(int high = 0 ; high < nums.size() ; high++) {

            if(nums[high] == maxElement)
            count++; 

            while( count >= k) { 
                ans += n - high;


                if(nums[low] == maxElement) count--; 

                low++;
            }

        }


        return ans;
    }
};