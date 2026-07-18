class Solution {
public:

    int helper( vector<int> &dp , int n) { 

        if( n == 0 || n == 1) return 1; 

        if(dp[n] != -1) return dp[n];

        int a = helper(dp , n-1);
        int b = helper( dp , n-2);


        return dp[n] = a + b ;
    }

    int climbStairs(int n) {
        vector<int> dp( n+1 , -1);

        return helper( dp , n);
        
    }
};