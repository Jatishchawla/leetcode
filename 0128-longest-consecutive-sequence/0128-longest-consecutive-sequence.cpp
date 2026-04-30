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
    // Optimal Solution (Hashing) (12:56 - 22:30)
    // Concept: Use a Set (unordered_set in C++ or HashSet in Java) to achieve O(1) lookup time.
    // Logic:
    // Insert all elements into a Set.
    // Iterate through the Set. For each element x, check if x-1 exists.
    // If x-1 exists, x is not the start of a sequence, so skip it.
    // If x-1 does not exist, x is the start. Start counting consecutive elements (x+1, x+2, ...) using the Set to check existence.
    // Keep track of the maximum sequence length found.
    // Time Complexity: O(3N) which simplifies to O(N) on average, as each element is visited a constant number of times.
    // Space Complexity: O(N) to store elements in the Set.
    // ----------------------
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