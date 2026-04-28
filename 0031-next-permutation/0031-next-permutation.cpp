class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //  keep longest prefix match
        int msf=-1; // max so far
        int max_indexSF=-1; // index with maximum possible order match

        int n = nums.size();
        // finding the index at which maximum prefix match possible in next permutation
        for(int i = n-1; i>=0 ; i--){
            // cout<<i<<" , "<<max_indexSF<<endl; // --- did debuging
            if (nums[i]<msf){
                max_indexSF = i;
                break;
            }
            msf = max(msf,nums[i]);
        }
        // cout<<endl; // --- did debuging
        
    // we require an index at which the element is least but greater than nums[max_indexSF] 
        if(max_indexSF>=0){
            int e = max_indexSF+1;
            // find index of an element(e) such that its least but greater than nums[i] and comes after n theoriginal given permutation
            for(int i=max_indexSF+1 ; i<n ; i++){
                if( nums[i] > nums[max_indexSF] && nums[i] < nums[e] ){
                    e = i;
                }
            }
            // --- did debuging
            // cout<<"misf: "<<max_indexSF<<" e: " << e<<endl;
            // for(int i : nums){
            //     cout<<i<<", ";
            // }
            // cout<<endl;

            // in order to find next permutation we know nums[e] will be creating next permutation because nums[max_indexSF] has alreday done with its last permutation
            swap(nums[max_indexSF],nums[e]);
// 2154300-> 2 1 54300 -> 2 1 54 3 00 -> 2 3 54100 ->2 3 00145->2300145

            // for(int i : nums){
            //     cout<<i<<", ";
            // }

            //  in order to find next permutation 
            sort(nums.begin()+max_indexSF+1,nums.end()); // sort the entire array to get 1st permutation
        }
        else{
            sort( nums.begin() , nums.end() );
        }
    }
};