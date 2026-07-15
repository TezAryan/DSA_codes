class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0; 
        int h = 0; 
        int res = 0 ; 
        unordered_map<int , int> freq; 

        for( h = 0 ; h < fruits.size() ; h++) { 
            freq[fruits[h]]++;
            while (freq.size() > 2) {
                freq[fruits[low]]--;
            if( freq[fruits[low]] == 0) { 
                freq.erase(fruits[low]);
            }
                low++;

            }

            res = max(res , h - low + 1);
        }

        return res;
    }
};