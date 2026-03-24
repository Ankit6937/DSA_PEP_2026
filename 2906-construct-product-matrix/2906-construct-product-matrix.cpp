class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        
        // Initialize the result matrix with the same dimensions
        vector<vector<int>> res(n, vector<int>(m));
        long long running_product = 1;

        // Pass 1: Forward (Prefix Product)
        // Store the product of all elements appearing BEFORE the current cell
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = running_product;
                // Update running product with current element and take modulo
                running_product = (running_product * (grid[i][j] % MOD)) % MOD;
            }
        }

        // Pass 2: Backward (Suffix Product)
        // Multiply the current prefix by the product of all elements AFTER the cell
        running_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                res[i][j] = (res[i][j] * running_product) % MOD;
                // Update running product with current element and take modulo
                running_product = (running_product * (grid[i][j] % MOD)) % MOD;
            }
        }

        return res;
    }
};