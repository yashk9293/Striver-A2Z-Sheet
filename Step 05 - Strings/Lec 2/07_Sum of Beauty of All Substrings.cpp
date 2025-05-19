// Question Link :- https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// Sum of Beauty of All Substrings



// T.C = O(n^2)
// S.C = O(26) ~ O(1) at max character 26 can be stored in map
class Solution {
public:
    int getMinCount(map<char, int>& mpp) {   // O(26) at worst case
        int minCount = INT_MAX;
        for (auto& it : mpp) {
            minCount = min(minCount, it.second);
        }
        return minCount;
    }

    int getMaxCount(map<char, int>& mpp) {  // O(26) at worst case
        int maxCount = 0;
        for (auto& it : mpp) {
            maxCount = max(maxCount, it.second);
        }
        return maxCount;
    }

    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i<n; i++) {
            map<char, int> mpp;
            for (int j = i; j<n; j++) {
                mpp[s[j]]++;
                int beauty = getMaxCount(mpp) - getMinCount(mpp);
                ans += beauty;
            }
        }
        return ans;
    }
};