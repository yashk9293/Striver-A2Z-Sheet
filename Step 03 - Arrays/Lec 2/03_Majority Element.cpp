// Question Link - https://leetcode.com/problems/majority-element/
// Majority Element

// Brute Force
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }
            if(count > n/2) {
                return nums[i];
            }
        }
        return -1;
    }
};



// Better Solution
// T.C = O(n logn)
// S.C = O(n)
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        map<int, int> mpp;

        // storing the elements with its occurnce:
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        // searching for the majority element:
        for (auto it : mpp) {
            if (it.second > (n / 2)) {
                return it.first;
            }
        }
        return -1;
    }
};







// Optimal Solution (Boyer Moore Voting Algorithm)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        int count = 0;
        int maj = NULL;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count = 1;
                maj = nums[i];
            } else if (nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }
        return maj;
    }
};