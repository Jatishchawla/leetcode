class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left=0;
        int right=n-1;

        while(left<right){
            int val =  nums[left]+nums[right]; 

            if(val == target){
                break;
            }
            else if(val > target){
                right --;
            }
            else{
                left++;
            }
        }
        return {left+1,right+1};
    }
};