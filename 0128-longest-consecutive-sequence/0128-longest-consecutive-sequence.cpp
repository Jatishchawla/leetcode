class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){return 0;}
        int max_len_sf = 1; // max length so far

        unordered_set<int> st;

        for(int i : nums){
            st.insert(i);
        }
        
        for(auto it: st){
            int x = it; // current element 
            if(st.find(x-1) == st.end()){ // x-1 not found in set
                int count=1;
                while(st.find(x+1) != st.end()){
                    count++;
                    x++;
                }
                max_len_sf = max(max_len_sf , count);
            }
        }    
        return max_len_sf;   

        // better approach

        // sort(nums.begin(),nums.end());

        // int curr_len = 1;
        // for(int i =0; i<n-1 ; i++){
        //     if(nums[i]==nums[i+1]){
        //         continue;
        //     }
        //     if(nums[i] + 1 == nums[i+1]){
        //         curr_len++;
        //         max_len_sf = max(max_len_sf , curr_len);
        //     }
        //     else{
        //         curr_len=1;
        //     }
        // }
        // return max_len_sf; 
    }
};