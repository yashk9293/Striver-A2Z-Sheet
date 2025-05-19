// Question Link :- https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Shortest Path in Binary Matrix

// BFS [preferred]
// T.C = O(n*n)
// S.C = O(n*n)
class Solution {
public:
    vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] != 0 || grid[m-1][n-1] != 0) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            if(x>=0 && x<m && y>=0 && y<n) {
                return true;
            }
            return false;
        };

        queue<pair<int,int>> que;  // {x,y}
        que.push({0,0});
        grid[0][0] = 1;
        int count = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++) {
                auto curr = que.front();
                que.pop();
                int x = curr.first;
                int y = curr.second;
                
                if(x == m-1 && y == n-1) {
                    return count+1;
                }
                for(auto dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_, y_) && grid[x_][y_] == 0) {
                        que.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            count++;   
        }
        return -1;
    }
};







// Dijkstra's Algorithm (using priority queue)
// T.C = O(E log(V)) => O(nn log(8n*n)) => O(n^2 log(n^2))
// S.C = O(n^2)
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] != 0 || grid[m-1][n-1] != 0) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()) {
            int d = pq.top().first;
	        pair<int, int> node = pq.top().second;
	        pq.pop();
            int x = node.first;
            int y = node.second;
	        for(auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int wt = 1;
                if(isSafe(x_, y_) && grid[x_][y_] == 0 && d + wt < result[x_][y_]) {
                    result[x_][y_] = d + wt;
                    pq.push({d+wt, {x_, y_}});
                    grid[x_][y_] = 1;
                }
            }
        }
        if(result[m-1][n-1] == INT_MAX) {
            return -1;
        }
        return result[m-1][n-1]+1;
    }
};







// Dijkstra's Algorithm (using queue)
// T.C = O(8n^2)
// S.C = O(8n^2)
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] != 0 || grid[m-1][n-1] != 0) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        result[0][0] = 0;
        while(!q.empty()) {
            int d = q.front().first;
	        pair<int, int> node = q.front().second;
	        q.pop();
            int x = node.first;
            int y = node.second;
	        for(auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int wt = 1;
                if(isSafe(x_, y_) && grid[x_][y_] == 0 && d + wt < result[x_][y_]) {
                    result[x_][y_] = d + wt;
                    q.push({d+wt, {x_, y_}});
                    grid[x_][y_] = 1;
                }
            }
        }
        if(result[m-1][n-1] == INT_MAX) {
            return -1;
        }
        return result[m-1][n-1]+1;
    }
};