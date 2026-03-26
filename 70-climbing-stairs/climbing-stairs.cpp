class Solution {
public:
    int climbStairs(int n) {

        int prev = 1;
        int prev1 = 1;
        int curr = 0;

        for(int i = 2 ; i<=n ; i++) {
            curr = prev + prev1;
            prev =prev1;
            prev1 = curr;

            
        } return prev1;
        
    }
};