// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int i = 0; 
//         int j =1; 

//         while ( j < nums.size()) {
//             while(  i< nums.size() && nums[i] != 0 ) 
//             i++; 

//             if ( j < i)
//             j = i+1;

//             while( j < nums.size() && nums[j] == 0) 
//             j++; 

//             if( j < nums.size()) { 
//                 swap(nums[i] , nums[j]); 
//                 i++; 
//                 j++;
//             }
//         }
//     }
// };


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i = 0; 
        int j = -1 ; 
        int n = nums.size(); 

        for(int i = 0 ; i <n ; i++) {
            if( nums[i] == 0 )  {
            j = i ; 
            break;
            }
        }


        if (j == -1) return; 

        for( i =j+1 ; i < n ;i++) { 
            if(nums[i] != 0) {
                swap( nums[i] , nums[j]); 
                j++;
            }
        }
}
};
