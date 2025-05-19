// Question Link :- https://www.naukri.com/code360/problems/armstrong-number_1462443
// Armstrong Number


// T.C = O(log10(num)) + O(log10(num) × log10(num)) = O((logn)^2) = O(logn)
// S.C = O(1)
#include <bits/stdc++.h>
int countDigits(int n) {  // O(log10(n))
    int cnt = 0;
    while(n>0) {
        cnt++;
        n = n/10;
    }
    return cnt;
}

bool isArmstrong(int num) {
    // int k = floor(log10(num) + 1);
    int k = countDigits(num);

    int n = num;
    int sum = 0;

    while(n) {   // O(log10(n))
        int digit = n % 10;
        sum += pow(digit, k);  // O(log10(n))
        n = n/10;
    }
    return num == sum;
}