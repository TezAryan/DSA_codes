class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
 

       
        for(int i = 0 ; i< n ; i++ ){
             if(st.empty()) {
            st.push(s[i]);
            continue;
        }

            if(st.top() == s[i]) {
                st.pop();
                
            
            } else { 
                st.push(s[i]);
            }

        }
        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

    reverse(result.begin() , result.end());
         return result;
    }
};