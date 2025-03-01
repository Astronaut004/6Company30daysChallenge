/*
Question Overview

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100 

*/


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<vector<int>>dp(m,vector<int>(n,0));

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(nums1[i] == nums2[j]) {
                    dp[i][j] = 1;

                    if(i > 0 && j> 0) {
                        dp[i][j] += dp[i-1][j-1];
                    }
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};