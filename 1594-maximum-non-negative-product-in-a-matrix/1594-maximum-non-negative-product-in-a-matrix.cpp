class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<long long>> maxP(m, vector<long long>(n));
        vector<vector<long long>> minP(m, vector<long long>(n));
        
        maxP[0][0] = minP[0][0] = grid[0][0];
        
        // First row
        for(int j = 1; j < n; j++) {
            maxP[0][j] = maxP[0][j-1] * grid[0][j];
            minP[0][j] = maxP[0][j];
        }
        
        // First column
        for(int i = 1; i < m; i++) {
            maxP[i][0] = maxP[i-1][0] * grid[i][0];
            minP[i][0] = maxP[i][0];
        }
        
        // Fill DP
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                long long a = maxP[i-1][j] * grid[i][j];
                long long b = minP[i-1][j] * grid[i][j];
                long long c = maxP[i][j-1] * grid[i][j];
                long long d = minP[i][j-1] * grid[i][j];
                
                maxP[i][j] = max({a, b, c, d});
                minP[i][j] = min({a, b, c, d});
            }
        }
        
        long long ans = maxP[m-1][n-1];
        if(ans < 0) return -1;
        
        return ans % 1000000007;
    }
};