/*
Question Overview

You are given an integer array nums. We call a subset of nums good if its product can be represented as a product of one or more distinct prime numbers.

For example, if nums = [1, 2, 3, 4]:
[2, 3], [1, 2, 3], and [1, 3] are good subsets with products 6 = 2*3, 6 = 2*3, and 3 = 3 respectively.
[1, 4] and [4] are not good subsets with products 4 = 2*2 and 4 = 2*2 respectively.
Return the number of different good subsets in nums modulo 109 + 7.

A subset of nums is any array that can be obtained by deleting some (possibly none or all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 6
Explanation: The good subsets are:
- [1,2]: product is 2, which is the product of distinct prime 2.
- [1,2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [1,3]: product is 3, which is the product of distinct prime 3.
- [2]: product is 2, which is the product of distinct prime 2.
- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [3]: product is 3, which is the product of distinct prime 3.
Example 2:

Input: nums = [4,2,3,15]
Output: 5
Explanation: The good subsets are:
- [2]: product is 2, which is the product of distinct prime 2.
- [2,3]: product is 6, which is the product of distinct primes 2 and 3.
- [2,15]: product is 30, which is the product of distinct primes 2, 3, and 5.
- [3]: product is 3, which is the product of distinct prime 3.
- [15]: product is 15, which is the product of distinct primes 3 and 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 30
*/

#define MOD 1000000007

class Solution {
public:
    // Function to calculate (base^exp) % MOD using modular exponentiation
    long long modPow(long long base, long long exp, long long modValue) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % modValue;
            base = (base * base) % modValue;
            exp /= 2;
        }
        return result;
    }
    
    int numberOfGoodSubsets(vector<int>& nums) {
        unordered_map<int, int> primes = {
            {2, 0}, {3, 1}, {5, 2}, {7, 3}, {11, 4},
            {13, 5}, {17, 6}, {19, 7}, {23, 8}, {29, 9}
        };
        
        vector<int> freq(31, 0); 
        for (int num : nums) freq[num]++;

        unordered_map<int, int> masks;
        for (int i = 2; i <= 30; i++) {
            int mask = 0, num = i;
            bool isValid = true;
            for (const auto& [prime, idx] : primes) {
                int count = 0;
                while (num % prime == 0) {
                    num /= prime;
                    count++;
                }
                if (count > 1) { isValid = false; break; }
                if (count == 1) mask |= (1 << idx);
            }
            if (isValid) masks[i] = mask;
        }

        vector<int> dp(1024, 0); 
        dp[0] = 1; 
        for (int i = 2; i <= 30; i++) {
            if (freq[i] == 0 || masks.find(i) == masks.end()) continue;

            int mask = masks[i];
            for (int state = 1023; state >= 0; state--) { 
                if ((state & mask) == mask) { 
                    int subsetsToExtend = dp[state ^ mask];
                    int newSubsets = 1LL * subsetsToExtend * freq[i] % MOD; 
                    dp[state] = (dp[state] + newSubsets) % MOD; 
                }
            }
        }

        int result = 0;
        for (int state = 1; state < 1024; state++) { 
            result = (result + dp[state]) % MOD;
        }

        if (freq[1] > 0) {
            result = (result * modPow(2, freq[1], MOD)) % MOD; 
        }

        return result;
    }
};
