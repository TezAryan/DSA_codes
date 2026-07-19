class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

vector<int> freq1(26, 0);
vector<int> freq2(26, 0);

        if( m > n) return false; 


    for( int i = 0 ; i<m ; i++) {
        freq1[s1[i] - 'a']++;
    }

    int low = 0 ; 
    int high = m -1;

    for(int i = low ; i <= high ; i++) { 
        freq2[s2[i] - 'a']++ ;
    }

        if( freq1 == freq2) return true; 

        while( high < n-1) { 

            freq2[s2[low] - 'a']--; 

            low++; 
            high++; 

            freq2[s2[high] - 'a']++;

            if(freq1 == freq2 ) return true;
        }

        return false;

    }

};