/*
Question Overview

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = size(nums), max_i = 0;
        
        vector<int> dp(n, 1), pred(n, -1), ans;
        for(int i = 1; i < n; i++) {          
            for(int j = 0; j < i; j++)

                if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1, pred[i] = j;
            if(dp[i] > dp[max_i]) max_i = i;
        }
        
        for(; max_i >= 0; max_i = pred[max_i]) 
            ans.push_back(nums[max_i]);
        return ans;
    }
};