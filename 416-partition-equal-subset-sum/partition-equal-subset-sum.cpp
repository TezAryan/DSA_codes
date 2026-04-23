// class Solution {
// public:
//  /// 2d dp method
//     bool subsetSum(vector<int>& nums , int n , int sum) {
//         vector<vector<bool>>t(n+1 , vector<bool>(sum+1 , false));

//         for(int i = 0 ; i<= n ; i++) {
//             t[i][0] = true;
//         }
//         for( int i = 1 ; i<= n ; i++) {
//             for(int j = 1 ; j<= sum ; j++) {
//                 if(nums[i-1] <= j) {
//                     t[i][j] = t[i-1][j - nums[i-1]] || t[i-1][j];
//                 } else {
//                     t[i][j] = t[i-1][j];
//                 }
//             }
//         }
//         return t[n][sum];

//     }

//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for(int i = 0 ; i<n ; i++) {
//             sum += nums[i];
//         }

//         if(sum % 2 != 0) return false;
//         else
//         return subsetSum(nums , n , sum/2);
//     }
// };

class Solution {
public:
    /// 2d dp method

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for(int i = 0 ; i<n ; i++) {
            for(int j = target ; j>= nums[i] ; j--) {
                dp[j] =  dp[j] || dp[j-nums[i]] ;

            }
        }
        return dp[target];
    }
};