// https://takeuforward.org/data-structure/print-all-divisors-of-a-given-number/
// Print all Divisors of a given Number


// Brute Force
// T.C = O(n)
// S.C = O(n)
#include<bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> res = printDivisors(n);

    for(auto &it : res) {
        cout << it << " ";
    }
    return 0;
}                   



// Optimal Approach
// T.C = O(sqrt(N))
// S.C = O(2*sqrt(N))  (since at most 2*sqrt(N) divisors are stored).

vector<int> printDivisors(int n) {
    vector<int> divisors;
    int sqrtN = sqrt(n); 
    for (int i = 1; i <= sqrtN; i++) {   // for (int i = 1; i *i <= n; i++)
        if (n % i == 0) { 
            divisors.push_back(i); 
            if (i != n / i) {
                divisors.push_back(n / i); 
            }
        }
    }
    return divisors; 
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> res = printDivisors(n);

    for(auto &it : res) {
        cout << it << " ";
    }
    return 0;
}   