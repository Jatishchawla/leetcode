class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        // MOORE'S VOTING ALGO
        int candidate;
        int count =0;
        for(int curr : nums){
            if(count == 0){
                count =1 ;
                candidate=curr;
            }
            else if(candidate != curr){
                count--;
            }
            else{
                count++;
            }
        }
        return candidate;



        // easy sol, 
        // sort(nums.begin(),nums.end());
        // return(nums[n/2]); // majority ele always exist , and have occurence >n/2 , in any case majority ele will be present at nums[n/2] if nums is sorted
        //-------------------------------
        // map<int,int> mpp;

        // for(int i =0; i < n  ; i++ ){
            
        //     if (++ mpp[nums[i]] > n/2){
        //         return nums[i];
        //     }
        // }
        // return -1;
    }
};