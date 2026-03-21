// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         int n = text.size();
//         unordered_map<char, int> have;
//         for (char c : text) {
//             have[c]++;
//         }
//         unordered_map<char, int> need;
//         need['b'] = 1;
//         need['a'] = 1;
//         need['l'] = 2;
//         need['o'] = 2;
//         need['n'] = 1;

//         int res = INT_MAX;

//         for(auto i : need) {
//             char c = i.first;
//             int fneed = i.second;
//             int fhave = have[c];
//             int times = fhave / fneed;

//             res= min(res,times);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         vector<int> freq(26, 0);

//         for (char c : text) {
//             freq[c - 'a']++;
//         }

//         return min({
//             freq['b' - 'a'],
//             freq['a' - 'a'],
//             freq['l' - 'a'] / 2,
//             freq['o' - 'a'] / 2,
//             freq['n' - 'a']
//         });
//     }
// };

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();

        unordered_map<char , int > have;

        for(char c : text) {
            have[c]++;
        }
        unordered_map<char , int > need;
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;
      
      int res = INT_MAX;


        for(auto i : need) {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            int times = fhave/fneed;

            res = min ( res , times);
        }

        return res;

     }
};