class Solution {
    vector <vector <int>> primeFactors;
public:
    vector <int> findPrimeFactors(int n, int idx) {
        vector <int> factors;
        if (n % 2 == 0) {
            primeFactors[2].push_back(idx);
            factors.push_back(2);
            while (n % 2 == 0) {
                n = n/2;
            }
        }
        for (int i = 3; i <= sqrt(n); i = i + 2) {
            if (n % i == 0) {
                primeFactors[i].push_back(idx);
                factors.push_back(i);
                while (n % i == 0) {
                    n = n/i;
                }
            }
        }
        if (n > 2) {
            primeFactors[n].push_back(idx);
            factors.push_back(n);
        }
        return factors;
    }
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        primeFactors = vector <vector <int>> (1e6 + 5);
        vector <vector <int>> factors(n);
        for (int i=0; i<n; ++i) {
            factors[i] = findPrimeFactors(nums[i], i);
        }
        int mx = -1;
        for (int i=0; i<n-1; ++i) {
            for (int factor: factors[i]) {
                mx = max(mx, primeFactors[factor][primeFactors[factor].size() - 1]);
            }
            if (mx == i) return i;
        }
        return -1;
    }
};