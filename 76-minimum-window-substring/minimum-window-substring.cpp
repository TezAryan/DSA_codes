class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> need ( 128 , 0); 
        vector<int> window(128 , 0); 

        for(char c : t) {
            need[c]++;
        }

        int needCount = 0; 

        for(int i =0 ; i< 128 ; i++) { 
            if(need[i] > 0) 
            needCount++;
        }

        int left = 0; 
        int minLen = INT_MAX; 
        int start = 0; 
        int have = 0;

        for(int right = 0 ; right < s.size() ; right++) { 

            window[s[right]]++; 

        if( need[s[right]] > 0 && window[s[right]] == need[s[right]]) { 
            have++;
        }

        while( have == needCount ) { 
            

            if(right-left+1 < minLen) {
                minLen = right - left + 1; 
                start = left;
            }

            window[s[left]]--; 

            if( need[s[left]] > 0 && window[s[left]] < need[s[left]])
            have--;


            left++;


        }


        }

        if(minLen == INT_MAX) return "";

        return s.substr(start , minLen);
    }
};