// Follow up question of previous problem

int maxSubArray(vector<int> &nums) {
    int maxi = INT_MIN; // maximum sum
    int sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < nums.size(); i++) {
        if(sum == 0) {
            start = i;
        }
        sum += nums[i];
        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    // printing subarray
    for(int i = ansStart; i<= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return maxi;
}