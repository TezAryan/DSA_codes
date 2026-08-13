class Solution {
public:
    unordered_map<string , int > mp;
    vector<string> ans;

    void helper( int i , int j , string s , string temp , string checkString) { 

        int n = s.size();

        if( j == n ) { 
            if( i == n) {
            ans.push_back(temp);}
            return;
        }

        checkString = "";
         helper( i , j+1 , s , temp , checkString);

        checkString = s.substr( i , j-i+1);

        if(mp.find(checkString) != mp.end()) { 

            if( !temp.empty()) { 
                temp+= " ";
            }
            temp += checkString;
            helper(j+1 , j+1 , s , temp , checkString);
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        
        for(auto it: wordDict) {

            mp[it]++;
        }

        

          helper( 0 , 0 , s , "" , "");
        return ans;

    }
};