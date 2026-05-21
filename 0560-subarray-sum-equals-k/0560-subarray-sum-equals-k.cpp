class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp; //presum map
        // int prev=0;
        int ssf=0 ; // subarray sum so far 
        int count=0; // number of subarrays with sum k
        
        mpp[0]=1;
        for(int i=0; i<n ; i++){
            ssf+=nums[i];
            if(mpp.find(ssf-k) != mpp.end()){
                count+=mpp[ssf-k];
            }
            mpp[ssf]++;
        }
        
        return count;
    }
};