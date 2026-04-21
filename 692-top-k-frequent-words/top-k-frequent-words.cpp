class Solution {
    struct cmp {
    bool operator()(pair<int,string>& a, pair<int,string>& b) {
        if(a.first == b.first)
            return a.second < b.second; // lexicographically smaller first
        return a.first > b.first;       // smaller freq first
    }
};
public:
    vector<string> topKFrequent(vector<string>& nums, int k) {
        priority_queue<pair<int,string >, vector<pair<int,string>>, cmp> pq;
        unordered_map <string , int> mp;
        vector<string> res;

        for(string num : nums) {
            mp[num]++;                                  
        }


           
           for(auto i : mp) {
            pq.push({i.second, i.first});

            if(pq.size() > k) {   // ✅ keep only top k
                pq.pop();
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

         reverse(res.begin(), res.end());
        return res;
    }
};