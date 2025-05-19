// Question Link :- https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
// Minimum Multiplications to reach End

// T.C = O(100000 * arr.size()) hypothetical, as we could not generate all no. start from 0 to 999999
// S.C = O(100000)
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) {
            return 0;
        }
        int mod = 100000;
        queue<pair<int, int>> q;  // {dist, node}
        q.push({0, start});

        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        while (!q.empty()) {
            int d = q.front().first;  // no. of steps
            int node = q.front().second;
            q.pop();
            for (int &it : arr) {
                int v = (it * node) % mod;
                if(d + 1 < dist[v]) {
                    dist[v] = d + 1;
                    if(v == end) {
                        return dist[v];
                    }
                    q.push({d+1, v});
                }
            }
        }
        // If the end no. is unattainable.
        return -1;
    }
};