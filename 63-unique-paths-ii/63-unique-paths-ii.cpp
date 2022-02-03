class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        if(g[0][0]) return 0;
        vector<vector<int>> dp(g.size(),vector<int>(g[0].size()));
        int n = g.size();
        int m = g[0].size();
        dp[0][0] = 1;
        for(int i = 1 ; i< n; i++)
        {
            dp[i][0] = (g[i][0] == 0? dp[i-1][0] : 0);
        }
        
        for(int i = 1 ; i< m; i++)
        {
            dp[0][i] = (g[0][i] == 0? dp[0][i-1] : 0);
        }
        
        for(int i = 1; i<n; i++)
        {
            for(int j = 1; j<m; j++)
            {
                if(g[i][j]) dp[i][j] = 0;
                else
                {
                    dp[i][j] = dp[i-1][j] +dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};