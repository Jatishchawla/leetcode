constexpr int mod=1e9+7;
int dp[500][2];// dp[j][dir] where dir=0/1 stand for right/down
using ll=long long;
class Solution {
public:
    static int uniquePaths(vector<vector<int>>& grid) {
        const int r=grid.size(), c=grid[0].size();
        memset(dp, 0, (c*2)*sizeof(int));
        // 0th row
        for(int j=0; j<c; j++){
            dp[j][0]=1;
            if (grid[0][j]) break;
        }
        bool isM=grid[0][0];
        for(int i=1; i<r; i++){
            //0th col
            dp[0][1]=!isM;
            isM|=grid[i][0];
            dp[0][0]=0;
            for(int j=1; j<c; j++){
                int left=dp[j-1][1], top=dp[j][0]; 
                bool is1=grid[i][j];    
                dp[j][0]=left+(-!is1 & top);
                if (dp[j][0]>=mod) dp[j][0]-=mod;
                
                dp[j][1]=(-!is1 & left)+top;
                if (dp[j][1]>=mod) dp[j][1]-=mod;
            }
        }
        return dp[c-1][0];
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();