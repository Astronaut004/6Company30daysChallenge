/*
Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing and one number b occurs twice in the array. Find numbers a and b.

Note: The test cases are generated such that there always exists one missing and one repeating number within the range [1,n].

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.
Constraints:
2 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size()
*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        // vector<int>v(n+1,0);
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
        }
        int f=0;
        int s=0;
        for(int i=1; i<=n; i++) {
            if(mp[i] == 2) f = i;
            if(mp[i] == 0) s = i;
        }
        return {f,s};
    }
};