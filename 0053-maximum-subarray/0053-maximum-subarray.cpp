class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sumSF = INT_MIN; // to store the maximum sum so far 
        int curr_sum = 0; // to store sum of current  subarray;
        for(int i : nums){
            curr_sum += i; // update curr sum

            max_sumSF=max(max_sumSF,curr_sum); // store max_sum so far

            if(curr_sum<=0){
                curr_sum=0;
            }            
        }
        return max_sumSF;
    }
};