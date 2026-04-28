class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int max_len_sf = 1; // max length so far
        sort(nums.begin(),nums.end());

        int curr_len = 1;
        for(int i =0; i<n-1 ; i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            if(nums[i] + 1 == nums[i+1]){
                curr_len++;
                max_len_sf = max(max_len_sf , curr_len);
            }
            else{
                curr_len=1;
            }
        }
        return max_len_sf;
    }
};