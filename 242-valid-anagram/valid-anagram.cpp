class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        for (char c : t)
            freq[c - 'a']--;

        for (int x : freq) {
            if (x != 0)
                return false;
        }

        return true;
    }
};