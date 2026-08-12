class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> mp;

        int n = s.size();

        for (auto it : s) {
            mp[it]++;
        }

        priority_queue < pair<int, char>> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

            string ans = "";

        while( !pq.empty()) { 

            auto first = pq.top();
            pq.pop(); 

            if(!pq.empty()) { 
                auto second = pq.top();
                pq.pop(); 
            

            ans+= first.second;
            ans+=second.second;

            first.first--;
            second.first--;


            if( first.first > 0) {
                pq.push(first);
            }

            if(second.first >0 ) { 
                pq.push(second);
            }


            } else { 
                if(first.first > 1) 
                return "";

                ans+= first.second;
            }
               
        }

        return ans;

    }
};