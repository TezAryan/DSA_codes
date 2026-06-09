class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        
        if( m > n ) return ans;
        
        vector<int> freq1(26 , 0);
        vector<int> freq2(26,0);

        for( auto ch : p) {
            freq1[ch - 'a']++;
        }

        for(int i=0; i<m ; i++) {
            freq2[s[i] - 'a']++;
        }

        if( freq1 == freq2)
         ans.push_back(0);

        for(int r = m ; r < n ; r++) {
            freq2[s[r] - 'a']++; 
            freq2[s[r-m] - 'a']--;

            if(freq1 == freq2 ) 
            ans.push_back(r-m+1);
        }

        return ans;
    }
};