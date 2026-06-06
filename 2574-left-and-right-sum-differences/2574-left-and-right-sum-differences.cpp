class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer;

        int lssf = 0;  // left sum so far
        int rssf = accumulate(nums.begin(), nums.end(),0);  // right sum so far , fill it first 

        // right se minus kro 
        // left me add kro


        // for( int i : nums ){
        //     rssf+=i; 
        // } 

        for(int i : nums){
            rssf-=i; // rssf is total next sum - current element

            int ans = abs(lssf -  rssf  );
            
            answer.push_back(ans);
            lssf +=i; // updating lssf for next element & lssf is total prev sum + curr ele
        }
        return answer;
    }
};