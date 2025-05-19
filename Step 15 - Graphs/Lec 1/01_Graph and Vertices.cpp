// Question Link :- https://www.geeksforgeeks.org/problems/graph-and-vertices/1
// Graph and Vertices

/*
No. of edges in undirected graph = n(n-1)/2

Now each edge has 2 option, from move from start aur end. 
  *-------------*
      edge
      
So, ans is 2^(n(n-1)/2)
*/


class Solution {
  public:
    long long count(int n) {
        long long ans=n*(n-1)/2;
        return 1ll << ans;  // pow(2, ans)
    }
};