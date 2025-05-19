// Question Link :- https://leetcode.com/problems/flood-fill
// Flood Fill

// Approach - 1 (Using DFS)
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int initialColor, int n, int m, vector<vector<bool>>& visited) {
        if(i<0 || j<0 || i>=n || j>= m || image[i][j] != initialColor || visited[i][j] == true) {
            return;
        }
        image[i][j] = color;
        visited[i][j] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            dfs(image, i + dx[k], j + dy[k], color, initialColor, n, m, visited);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // if (image[sr][sc] == color) {
        //     return image;
        // }
        dfs(image, sr, sc, color, image[sr][sc], n, m, visited);

        return image;
    }
};





// Approach - 2 (Using BFS)
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int initialColor = image[sr][sc];
        image[sr][sc] = color;

        queue<pair<int,int>> que;
        que.push({sr, sc});
        vis[sr][sc] = 1;   // Mark the starting cell as visited

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            for(int i=0; i<4; i++) {
                int di = x + dx[i];
                int dj = y + dy[i];

                if(di >= 0 && di < n && dj >= 0 && dj < m && image[di][dj] == initialColor && vis[di][dj] == 0) {
                    image[di][dj] = color;  // put the new colour
                    vis[di][dj] = 1;   // mark visited
                    que.push({di, dj});
                }
            }
        }
        return image;
    }
};