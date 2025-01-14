/*
Question Overview

You are given a positive integer 0-indexed array nums.

A subset of the array nums is square-free if the product of its elements is a square-free integer.

A square-free integer is an integer that is divisible by no square number other than 1.

Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.

A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [3,4,4,5]
Output: 3
Explanation: There are 3 square-free subsets in this example:
- The subset consisting of the 0th element [3]. The product of its elements is 3, which is a square-free integer.
- The subset consisting of the 3rd element [5]. The product of its elements is 5, which is a square-free integer.
- The subset consisting of 0th and 3rd elements [3,5]. The product of its elements is 15, which is a square-free integer.
It can be proven that there are no more than 3 square-free subsets in the given array.
Example 2:

Input: nums = [1]
Output: 1
Explanation: There is 1 square-free subset in this example:
- The subset consisting of the 0th element [1]. The product of its elements is 1, which is a square-free integer.
It can be proven that there is no more than 1 square-free subset in the given array.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 30
*/

const long long mod  = 1e9 + 7;
class Solution {
public:
    vector<int>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    long long getMask(long long num) {
        long long mask = 0;
        for(int i=0; i<10; i++) {
            int tim = 0;
            while(num%primes[i] == 0) {
                tim += 1;
                num /= primes[i];
            }

            if(tim > 1) return -1;

            if(tim == 1) {
                mask |= (1 << (i+1));
            }
        }
        return mask;
    }

    long long dfs(int ind, long long prodmask, vector<int>& nums, vector<vector<long long>>& dp) {
        if(ind >= nums.size()) return 1;

        if(dp[ind][prodmask] != -1 ) return dp[ind][prodmask];

        long long mask = getMask(nums[ind]);
        long long ans = dfs(ind+1, prodmask, nums,dp);

        if((prodmask & mask) == 0) {
            ans += dfs(ind+1, prodmask | mask, nums,dp)%mod;
        }

        return dp[ind][prodmask] = ans;
    }

    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size();
        int a = 1<<11;
        vector<vector<long long>>dp(n,vector<long long>(a,-1));
        return (dfs(0,1,nums,dp) - 1) % mod;

    }
};

// TC: O(n * 1024) ===> O(n)

// SC: O(n * 1024) ===> O(n)