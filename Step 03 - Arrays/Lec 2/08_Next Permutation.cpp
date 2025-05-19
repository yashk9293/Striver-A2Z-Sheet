// Question Link - https://leetcode.com/problems/next-permutation/
// Next Permutation


// Brute Force:-
// T.C = O(N! * N)
// S.C = O(N)
// Step 1: Find all possible permutations of elements present and store them.

// Step 2: Search input from all possible permutations.

// Step 3: Print the next permutation present right after it.
class Solution {
public:
    vector<vector<int>> allPermutations;  // Store all permutations

    void generatePermutations(vector<int>& arr, int start) {
        if(start == arr.size() - 1) {
            allPermutations.push_back(arr);
            return;
        }

        for(int i = start; i < arr.size(); i++) {
            if (i != start && arr[i] == arr[start]) {  // avoiding duplicates for cases like [1,1,5]
                continue;
            }
            swap(arr[start], arr[i]);            // Choose
            generatePermutations(arr, start + 1);  // Explore
            swap(arr[start], arr[i]);            // Un-choose (backtrack)
        }
    }

    void nextPermutation(vector<int>& nums) {
        generatePermutations(nums, 0);

        sort(allPermutations.begin(), allPermutations.end());    // Sort all permutations to find the lexicographical order
        
        // Find the index of the current permutation
        auto it = find(allPermutations.begin(), allPermutations.end(), nums);
        
        if (it != allPermutations.end() && it + 1 != allPermutations.end()) {
            nums = *(it + 1);
        } else {  
            // If it's the last permutation, wrap around to the first
            nums = allPermutations[0];
        }
    }
};




// Approach - 2 (Using in-built function)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};



// Optimal Solution
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // Step 1 : Find the breakpoint
        int element_idx = -1;
        for(int i = n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                element_idx = i;
                break;
            }
        }

        if (element_idx == -1) {   // If break point does not exist:
            reverse(nums.begin(), nums.end());   // reverse the whole array
            return;
        }

        // Step 2: Find the next greater element and swap it with arr[ind]
        for(int i = n-1; i>= element_idx; i--) {
            if(nums[i] > nums[element_idx]) {
                swap(nums[i], nums[element_idx]);
                break;
            }
        }

        reverse(nums.begin() + element_idx + 1, nums.end());
    }
};