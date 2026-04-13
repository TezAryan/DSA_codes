class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char , int> f;
        for( char c : s) {
            f[c]++;
        }

        int n = s.length();
        for(auto &it : f) {
            if (it.second > (n+1) / 2 ) return "";
        }

        priority_queue<pair<int , char>> pq;
        for(auto it : f) {
            pq.push({it.second , it.first});
        }



        string result = "";
        pair<int , char> prev =  { 0 , '#' };

        while(!pq.empty()) { 
         auto curr = pq.top();
            pq.pop();

            result += curr.second;
            curr.first--;

            if(prev.first > 0 )
            pq.push(prev);

            prev = curr;
        }

        return result.length() == s.length() ? result : "";
    }
};