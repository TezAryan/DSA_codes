class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int nStart = newInterval[0];
        int nEnd = newInterval[1];
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0; 

        while(i < n && intervals[i][1] < nStart) {
            result.push_back(intervals[i]);
            i++;
        }

        while ( i < n && intervals[i][0] <= nEnd) {
            nStart = min(intervals[i][0] , nStart);
            nEnd = max(intervals[i][1] , nEnd);
            i++;
        }
        
         result.push_back({nStart , nEnd});

        while ( i < n) { 

            result.push_back(intervals[i]);
            i++;

        }


        return result;
    }
};