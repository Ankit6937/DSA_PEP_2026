class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Step 1: Push all rotten oranges
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0) return 0;
        
        int minutes = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        
        while(!q.empty()){
            int size = q.size();
            bool rotten = false;
            
            for(int i = 0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();
                
                for(int d = 0; d < 4; d++){
                    int nr = r + dir[d];
                    int nc = c + dir[d+1];
                    
                    if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        rotten = true;
                    }
                }
            }
            
            if(rotten) minutes++;
        }
        
        return fresh == 0 ? minutes : -1;
    }
};