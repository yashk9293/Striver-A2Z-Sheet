// Question Link :- https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// N meetings in one room
// (Same as Non Overlapping Intervals)

// T.C = O(nlogn + n) = O(nlogn)
// S.C = O(n)
class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> intervals;
        
        auto lambda = [&](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        };
        
        for(int i=0; i<n; i++) {
            intervals.push_back({start[i], end[i]});
        }
        sort(intervals.begin(), intervals.end(), lambda); 
        
        int cnt = 1;
        int last = intervals[0].second;
        for(int i=1; i<n; i++) {
            if(intervals[i].first > last) {
                cnt++;
                last = intervals[i].second;
            }
        }
        return cnt;
    }
};