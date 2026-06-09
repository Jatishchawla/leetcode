class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // optimal approach
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i =0 ; i<n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0){ 
                    j++;
                } 
                else if(sum>0){
                    k--;
                }
                else{
                    // sum == 0 we have found a triplet
                    ans.push_back( { nums[i],nums[j],nums[k] } );
                    // Both j & k is already in this triplet and cant be used again so change it to next unique element
                    j++;
                    k--;
                    while( j<k && nums[j] == nums[j-1] ){
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1] ){
                        k--;
                    }
                }

            }
        }
        return ans;
        

        //---- better approach but not optimal ----
        // int n=nums.size();
        // set<vector<int>> set; // final set of unique triplets
        // for(int i =0; i<n ;i++){
        //     unordered_set<int> hashset ;
        //     for(int k=i+1; k<n ; k++){
        //         int target = -(nums[i]+nums[k]); // j eill lie in between i and k if the triplet esists
        //         if( hashset.find(target) != hashset.end() ){
        //             vector<int> triplet = {nums[i],target,nums[k]};
        //             sort(triplet.begin(), triplet.end());
        //             set.insert(triplet);
        //         }
        //         hashset.insert(nums[k]); // add current element so we can find in next iteration
        //     }
        // }
        // vector<vector<int>> ans(set.begin() , set.end());
        // return ans;
    }
};