class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int,int> mpp;
        sort(nums.begin(),nums.end());

        vector<int> majors;
        majors.push_back(INT_MIN);
        int curr = nums[0]; // current element
        int curr_count=0; // to store current's occurece count
        int n = nums.size()/3;
        for(int i : nums){
            if(curr == i){
                curr_count++; 
                // cout<<curr<<" "<<curr_count<<endl;            
            }
            else{
                curr=i;
                curr_count=1;

            }
            if(curr_count > n && curr != majors.back() ){            
                majors.push_back(curr);
            }
        }
        majors.erase(majors.begin() + 0);
        // for(auto it: mpp){
        //     if(it.second> n){
        //         majors.push_back(it.first);
        //     }
        // }

        return majors;
    }
};