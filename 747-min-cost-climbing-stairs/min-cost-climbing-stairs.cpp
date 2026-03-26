class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();

       if (n == 1) return cost[0];
       if(n == 2 ) return min(cost[0] , cost[1]);

        int prev = cost[0];
        int prev1 = cost[1];
        int curr = 0;

        for(int i = 2 ; i<n ; i++) {
            curr = min(prev , prev1) + cost[i];
            prev = prev1;
            prev1 = curr;
        }

        return min(prev ,prev1);

    }
};