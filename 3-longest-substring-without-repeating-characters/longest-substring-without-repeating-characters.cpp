// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {

//         unordered_map<char, int> mp;

//         int low = 0;
//         int res = 0;

//         for (int high = 0; high < s.size(); high++) {

//             while (mp.find(s[high]) != mp.end()) { 
//                 mp.erase(s[low]);
//                 low++;
//             }

//             mp[s[high]] = 1;

//             res = max(res ,  high - low + 1);
        
//         }

//         return res;
//         }
//     };



class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mp;

        int low = 0;
        int ans = 0;

        for(int high = 0 ; high < s.size() ; high++) { 

            mp[s[high]]++; 

            while ( mp[s[high]] > 1) { 
                mp[s[low]]--;

                if(mp[s[low]] == 0 ) 
                mp.erase(s[low]);

                low++;
            }

            ans = max(ans , high-low+1);
        }

        return ans;
       
    }
};