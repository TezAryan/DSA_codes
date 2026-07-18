class Solution {
public:
    int solve( int i , string& s , vector<int>& dp) { 
        int n = s.size(); 


        if( i == n) return 1; 

        if( s[i] == '0' ) return 0; 

        if( dp[i] != -1) return dp[i];

        int ways = solve(i+1 , s , dp);

        if( i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){

            ways += solve(i+2 , s , dp);
        }

        return dp[i] = ways ; 
    }
    int numDecodings(string s)  {

            vector<int> dp( s.size() , -1);

            return solve( 0 , s , dp );

    }
};