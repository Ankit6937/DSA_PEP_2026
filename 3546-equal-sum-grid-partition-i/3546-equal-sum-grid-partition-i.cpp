class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        // Total sum calculate
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        // If total odd -> impossible
        if (total % 2 != 0) return false;

        long long prefix = 0;

        // Horizontal cut (last row skip)
        for (int i = 0; i < m - 1; i++) {
            long long rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }

            prefix += rowSum;

            if (prefix == total - prefix) return true;
        }

        // Reset prefix
        prefix = 0;

        // Vertical cut (last column skip)
        for (int j = 0; j < n - 1; j++) {
            long long colSum = 0;
            for (int i = 0; i < m; i++) {
                colSum += grid[i][j];
            }

            prefix += colSum;

            if (prefix == total - prefix) return true;
        }

        return false;
    }
};