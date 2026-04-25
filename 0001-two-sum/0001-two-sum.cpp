class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // BETTER: NlogN - hash map
        map<int,int> mpp; // (element, index)
        for(int i=0; i<nums.size(); i++){
            int a = nums[i];
            int required = target -a;
            if(mpp.find(required) != mpp.end() ){
                return {mpp[required],i };
            }
            mpp[a]=i;
        }
        return {0,1};
        // OPTIMAL but not for this varient , it return yes or no only - use two pointer approach
        // for(int i=0; i<nums.size() ; i++){
        //     mpp[nums[i]]=i;
        // }
        // sort(nums.begin(),nums.end());
        // int left = 0;
        // int right = nums.size()-1;
        // int sum = nums[left]+nums[right];
        // while( sum != target && left < right ){
        //     if(sum>target){
        //         right--;
        //     }
        //     else{left++;}
        //     sum = nums[left]+nums[right];
        // }
        // if(sum==target){
        //     return "yes";
        // }
        // return "no";
    }
};