class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort ( intervals.begin() , intervals.end());
        int n = intervals.size() ; 
        int s1 = intervals[0][0];
        int e1 = intervals[0][1];

        

        int count = 0 ; 
        int i = 0; 


        for(i = 1 ; i< n ; i++) { 
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];

            if( e1 > s2) { 
                count++;
              
              e1 = min (e1 , e2);
                
            } else { 
                s1 = s2; 
                e1 = e2;
            }


        }

        return count;
    }
};