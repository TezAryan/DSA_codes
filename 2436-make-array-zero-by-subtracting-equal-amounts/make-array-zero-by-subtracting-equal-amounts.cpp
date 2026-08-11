class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       
       unordered_set<int> st; 

       for(int i = 0 ; i< nums.size(); i++) { 
        if( nums[i] != 0) { 
            st.insert(nums[i]);
        }
       }

       return st.size();

        
        
    }
};