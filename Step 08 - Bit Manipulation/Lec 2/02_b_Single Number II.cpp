// Question Link :- https://leetcode.com/problems/single-number-ii/
// Single Number II


// Brute Force
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num : nums) {
            mp[num]++;
        }
        for(auto val: mp) {
            if(val.second == 1) {
                return val.first;
            }
        }
        return -1;
    }
};





// Optimal Solution
// T.C = O(32*n)
// S.C = O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<32; i++) {
            int temp = 1 << i;
            int countZero = 0;
            int countOne = 0;
            for(int &num : nums) {
                if((num & temp) == 0) {
                    countZero++;
                } else {
                    countOne++;
                }
            }
            if(countOne % 3 == 1) {
                result = (result | temp);
            }
        }
        return result;
    }
};