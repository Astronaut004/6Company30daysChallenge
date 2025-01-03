/*

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/




class Solution {
private:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        if(k < 0) return 0;
        int sum = 0;
        /*
            Design Window from if current element is odd add 1 else 0 
            for contracting window substract 1 for odd and else 0

            calculate the total count whther odd number present is 0,1,2.....
        */
        int l = 0, r = 0;
        int count = 0;
        while(r < n) {
            sum += (nums[r]&1?1:0);
            while(sum > k) {
                sum -= (nums[l]&1?1:0);
                l += 1;
            }
            count = count + r-l+1;
            r += 1;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // it's complicated to find exactly with k so we will consider it from 
        /*
            0 to k - 0 to k-1
        */

        int in = solve(nums,k);
        int ex = solve(nums,k-1);
        return in - ex;
    }
};