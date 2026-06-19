class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        
    // vector<int>runningSum(nums.size()) ; 
    // runningSum[0] = nums[0];

    // for(int i = 1 ; i< nums.size() ; i++) {
    //     runningSum[i] =  runningSum[i-1] + nums[i];
    // }

    // return runningSum;
    
    for(int i = 1 ; i < nums.size() ; i++) {
        nums[i] += nums[i-1];
    }

    return nums;


     }
};