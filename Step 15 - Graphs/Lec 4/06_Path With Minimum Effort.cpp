// Question Link :- https://leetcode.com/problems/path-with-minimum-effort/
// Path With Minimum Effort

// Dijkstra's Algo
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        result[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});  // {d, {x, y}}

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!pq.empty()) {
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            // without this if condition also, it will pass.. but this will reduce repeatitive push in pq
            if (diff > result[x][y]) {  // Skip if we already found a better effort for (x, y)
                continue;
            }
            for(int i=0; i<4; i++) {
                int di = x + dx[i];
                int dj = y + dy[i];

                if(di>=0 && dj>=0 && di<n && dj<m) {
                    int newDiff = max(diff, abs(heights[x][y] - heights[di][dj]));
                    if(newDiff < result[di][dj]) {
                        result[di][dj] = newDiff;
                        pq.push({newDiff, {di, dj}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};