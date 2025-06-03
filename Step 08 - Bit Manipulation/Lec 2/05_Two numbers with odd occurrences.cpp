// Question Link :- https://leetcode.com/problems/single-number-iii/
// Single Number III

// Similar question :- https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1


// Approach - 1 (Brute Force)
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int n = nums.size();
        
        int i=0;
        while(i < n) {
            // If it's the last element or not equal to the next one
            if (i == n - 1 || nums[i] != nums[i + 1]) {
                result.push_back(nums[i]);
                i += 1;
            } else {
                i += 2;  // Skip the duplicate pair
            }

            if (result.size() == 2) break;
        }
        return result;
    }
};



// Approach - 2 (hashing)
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<int> ans;
        for (auto& entry : freq) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }

        if (ans[0] > ans[1]) {
            swap(ans[0], ans[1]);
        }
        return ans;
    }
};





// Approach - 3 (Optimal Solution)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;

        for(int &num : nums) {
            xorr ^= num;
        }
        
        //mask -> right most set bit search 
        int mask = (xorr & (xorr-1)) ^ xorr;

        int groupA = 0, groupB = 0;

        for(int &num : nums) {
            if(num & mask) {
                groupA ^= num;
            } else {
                groupB ^= num;
            }
        }
        return {groupA, groupB};
    }
};





/*
xorr can minimum be -2^31, so in line no. 43 (xorr - 1) can't be stored in int
So, we are taking xorr in long not int.
*/