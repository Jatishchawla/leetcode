class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> majors;
        for(int i:nums){
            mpp[i]++;
            
        }
        int n = nums.size()/3;
        for(auto it: mpp){
            if(it.second> n){
                majors.push_back(it.first);
            }
        }
        return majors;
    }
};