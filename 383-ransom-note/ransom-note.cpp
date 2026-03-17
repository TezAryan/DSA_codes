class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    //     unordered_map<char,int> have;
    //     unordered_map<char , int> need;

    //     for(int i = 0 ; i<ransomNote.size() ; i++) {
    //         need[ransomNote[i]]++;
    //     } for(int i =0; i<magazine.size() ; i++) {
    //         have[magazine[i]]++;
    //     }

    //     return func(have , need);
    // }

    // bool func(unordered_map<char,int> &have , unordered_map<char,int> &need) {
        
    //     for(auto i : need) {
    //         char c = i.first;
    //         int fneed = i.second;
    //         int fhave = have[c]; 
            
    //         if( fhave < fneed ) return false;

    
    //      }

    //      return true;




    vector<int> count(26, 0);


    for( char c: magazine) {
        count[c  - 'a']++;
    }

    for( char c : ransomNote) {
        count[c - 'a']--;

        if(count[c-'a'] < 0) return false;

    }

    return true;



    }
    
};