class Solution {
public:
int solve ( int i ,int sum , vector<int>& nums) {

        if( i == nums.size())
        return sum == 0;

        int take = solve( i+1 , sum - nums[i] , nums );

        int notTake = solve( i+1 , sum , nums);

        return take + notTake; 
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        
        int total = 0 ;

        for(int x : nums) {
            total += x;
        }

        if(abs(target) > total) return 0;

        if((total + target) % 2 != 0) return 0; 

        int s1 = (total + target ) / 2;

        return solve( 0 , s1 , nums);
    }
};