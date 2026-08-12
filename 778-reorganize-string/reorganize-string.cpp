class Solution {
public:
    string reorganizeString(string s) {

       vector<int> freq ( 26 , 0);
        int n = s.size();

        for (auto it : s) {
            freq[ it - 'a']++;
        }

        priority_queue < pair<int, char>> pq;

        for (int i = 0 ; i<26 ; i++) {
            if( freq[i] > 0) 
            pq.push({freq[i] , 'a' + i});
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