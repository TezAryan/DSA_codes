class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin() , people.end());

        int l =0;
        int h = people.size() - 1;
        int ans = 0;

    while(l <= h){

        if(people[l] + people[h] <= limit) {
           
            l++;
            h--;
        } else {
            h--;
        }
        ans++;
    }

    return ans;
    
    }
};