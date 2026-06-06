class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer;
        int size = nums.size();
        int n = size-1; // index of last element , 
        int lssf = 0;
        vector<int> ans;
        // right se minus kro 
        // left me add kro

        int rssf = 0;  // fill it first 

        // rssf is total next sum - current element
        // lssf is total prev sum + curr ele

        for( int i : nums ){
            rssf+=i;
        } 
        cout<<rssf;
        for(int i : nums){
            rssf-=i;
            cout<<i<<" lssf: "<< lssf <<" | rssf: "<<rssf<<endl;
            int ans = abs(lssf -  rssf  );
            answer.push_back(ans);
            lssf +=i;
            // rssf/
        }
        return answer;
    }
};