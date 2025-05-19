// Question Link :- https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1
// Swap two numbers


// Approach - 1 (With Temporary variable)


// Approach - 2 (Without Temporary Variable)
// T.C = O(1)
// S.C = O(1)
class Solution{   
public:
    pair<int, int> get(int a, int b){
        a = a^b;
        b = a^b;
        a = a^b;
        return pair<int,int>{a,b};
    }
};