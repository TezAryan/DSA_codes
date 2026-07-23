class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin() , tokens.end());
        
        int low = 0 ; 
        int high = tokens.size() - 1; 
        int score = 0; 
        int maxScore=0;


        while ( low <= high) { 

            if( power >= tokens[low] ) {
                power = power - tokens[low];
                score++; 

                maxScore = max( score , maxScore);

                low++; 


            } else if ( score >= 1) { 

                power = power + tokens[high];
                score--;
                high--;
            } else { 
                return maxScore;
            }

        }

        return maxScore;
    }
};