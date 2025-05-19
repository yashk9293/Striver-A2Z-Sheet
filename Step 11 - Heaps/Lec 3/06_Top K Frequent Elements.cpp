// Question Link :- https://leetcode.com/problems/top-k-frequent-elements/
// Top K Frequent Elements

// Brute Force (Using vector)
// T.C = O(nlogn)
// S.C = O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mpp;

        for(auto &it : nums) {
            mpp[it]++;
        }

        vector<pair<int, int>> vec(mpp.begin(), mpp.end());

        auto lambda = [&](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        for(int i=0; i<k; i++) {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};






// Better Approach (Using min heap)
// T.C = O(nlogk) because we are keeping only k items in the minHeap
// S.C = O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> mp;
        for(int i : nums) {
            mp[i]++;
        }
        // Push in min-heap and maintain size k
        for(auto it : mp) {
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        // Pick all top K elements
        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};








// Optimal Solution (Bucket Sort Algorithm)
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int &num : nums) {
            mp[num]++;
        }
        vector<vector<int>> bucket(n+1); // element can have maximum of n occurence, so we will make bucket of n+1 size
        // index = frequency
        // Value will be elements
        // bucket[i] = elements occuring ith time
        for(auto &it : mp) {
            int element = it.first;
            int freq = it.second;
            bucket[freq].push_back(element);
        }
        // Pick from right to left to find max frequency elements
        vector<int> result;
        for(int i = bucket.size()-1; i >= 0; i--) {
            if(bucket[i].size() == 0) {
                continue;
            }
            while(bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};