class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &image, int originalColor, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        // Boundary check
        if(r < 0 || r >= n || c < 0 || c >= m) return;
        
        // If color doesn't match, stop
        if(image[r][c] != originalColor) return;
        
        // Change color
        image[r][c] = newColor;

        // 4 directions
        dfs(r-1, c, image, originalColor, newColor);
        dfs(r+1, c, image, originalColor, newColor);
        dfs(r, c-1, image, originalColor, newColor);
        dfs(r, c+1, image, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        // If same color, no need to change
        if(originalColor == color) return image;

        dfs(sr, sc, image, originalColor, color);

        return image;
    }
};