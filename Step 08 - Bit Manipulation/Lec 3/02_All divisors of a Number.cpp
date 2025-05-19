// Question Link :- https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
// All divisors of a Number


// T.C = O(sqrt(n)*mlog(m)) ~ O(sqrt(n))
// S.C = O(m)
class Solution {
  public:
    void print_divisors(int n) {
        vector<int> ans;
        for(int i=1; i<=sqrt(n); i++) {
            if(n%i == 0) {
                ans.push_back(i);
                if(n/i != i) {
                    ans.push_back(n/i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        for(auto &it : ans) {
            cout << it << " ";
        }
    }
};



// T.C = O(sqrt(n)*log(m)) ~ O(sqrt(n))
// S.C = O(m)
class Solution {
  public:
    void print_divisors(int n) {
        set<int> ans;
        for(int i=1; i<=sqrt(n); i++) {
            if(n%i == 0) {
                ans.insert(i);
                if(n/i != i) {
                    ans.insert(n/i);
                }
            }
        }
        for(auto &it : ans) {
            cout << it << " ";
        }
    }
};