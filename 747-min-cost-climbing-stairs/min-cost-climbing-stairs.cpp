class Solution {
public:
        vector<int> dp ;
    int helper ( int idx , vector<int>& cost , vector<int>& dp) { 

        if( idx <= 1) return 0;

        if( idx == 2) return min(cost[idx-1] , cost[idx -2]);

        if( dp[idx] != -1 ) {
            return dp[idx];
        }

        return dp[idx] = min( cost[idx-1] + helper(idx-1 , cost , dp) , cost[idx-2] + helper(idx-2 , cost , dp));
        
    }

    int minCostClimbingStairs(vector<int>& cost) {

       
        int n = cost.size(); 
       
         dp.resize( n+1 , -1);

        int idx = n; 

        return helper(idx , cost , dp);



    }
};

