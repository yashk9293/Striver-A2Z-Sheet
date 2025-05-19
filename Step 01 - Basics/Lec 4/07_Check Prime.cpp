// Question Link :- https://www.naukri.com/code360/problems/check-prime_624934
// Check Prime


// Brute Force Solution
// T.C = O(n)
// S.C = O(1)
bool isPrime(int n) {
	int cnt = 0;
	for(int i=1; i <= n; i++) {
		if(n%i == 0) {
			cnt++;
		}
	}
	if(cnt == 2) {
		return true;
	}
	return false;
}



// Optimal Solution
// T.C = O(sqrt(n))
// S.C = O(1)
bool isPrime(int n) {
	int cnt = 0;
	for(int i=1; i*i <= n; i++) {
		if(n%i == 0) {
			cnt++;
			if(i != n/i) {
				cnt++;
			}
		}
	}
	if(cnt == 2) {
		return true;
	}
	return false;
}