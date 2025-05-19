// Question Link :- https://leetcode.com/problems/sort-characters-by-frequency
// Sort Characters By Frequency


// Approach - 1
// T.C = O(NlogN) + O(N) = O(NlogN)
// S.C = O(N) -> result stores all the n characters
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for(char &ch : s) {  // O(N)
            mpp[ch]++;       // O(logk) at worst case, all unique character, k=n.. O(logN)
        }
        vector<pair<int, char>> vec;
        for(auto it : mpp) {
            vec.push_back({it.second, it.first});
        }

        // sort(vec.begin(), vec.end(), greater<pair<int, char>>());
        sort(vec.rbegin(), vec.rend());  // sort in descending order

        string result;
        // The loop runs N times (since we append each character back into result). therefore, O(n)
        for (auto& it : vec) {
            int freq = it.first;
            char ch = it.second;
            for(int i=0; i<freq; i++) {
                result += ch;
            }
        }
        return result;
    }
};



// Approach - 2 (Optimal Solution)
// T.C = O(NlogN)
// S.C = O(256) ~ O(1)
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++) {
            freq[s[i]]++;
        }

        auto compare = [&](char& a, char& b) {
            if (freq[a] == freq[b]) {
                return a < b;   // Sort lexicographically if frequencies are the same
            }
            return freq[a] > freq[b];  // Sort by frequency (descending order)
        };

        sort(s.begin(), s.end(), compare);
        
        return s;
    }
};