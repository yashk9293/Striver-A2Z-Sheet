// Question Link - https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_6828164
// Missing And Repeating Numbers


// Brute Force
// T.C = O(2N)
// S.C = O(N)
vector<int> findMissingRepeatingNumbers(vector<int> arr) {
    int n = arr.size();
    vector<int> vec(n+1, 0);
    for(int i=0; i<n; i++) {
        vec[arr[i]]++;
    }
    
    int missing = -1, repeating = -1;
    for(int i=1; i<=n; i++) {
        if(vec[i] == 2) {
            repeating = i;
        } else if(vec[i] == 0) {
            missing = i;
        }
        if(repeating != -1 && missing != -1) {
            break;
        }
    }
    return {repeating, missing};
}





// Optimal Solution
// T.C = O(N)
// S.C = O(1)
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}