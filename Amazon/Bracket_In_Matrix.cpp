/*
Given an array arr[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is arr[i] * arr[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

NOTE:

Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also, please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
As there can be multiple possible answers, the console would print "true" for the correct string and "false" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.
Examples:

Input: arr[] = [40, 20, 30, 10, 30]
Output: true
Explanation: Let's divide this into matrix(only 4 are possible) [ [40, 20] -> A, [20, 30] -> B, [30, 10] ->C, [10, 30] -> D ]
First we perform multiplication of B & C -> (BC), then we multiply A to (BC) -> (A(BC)), then we multiply D to (A(BC)) -> ((A(BC))D)
so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.
Input: arr[] = [10, 20, 30]
Output: true
Explanation: There is only one way to multiply two matrices: (AB): The cost for the multiplication will be 6000
Input: arr = [3, 3, 3]
Output: true
Explanation: The solution returned the string (AB), which performs minimum multiplications. The total number of multiplications are (3*3*3) = 27.
Constraints:
2 ≤ arr.size() ≤ 26 
1 ≤ arr[i] ≤ 100 
*/


class Solution {
public:
    static string help(int i, int j, vector<vector<int>> &brackets) {
        if (i == j) {
            char a = 'A' + i - 1;
            string temp = "";
            temp += a;
            return temp;
        }
        return '(' + help(i, brackets[i][j], brackets) + help(brackets[i][j] + 1, j, brackets) + ')';
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size(); // Size of the input array

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> brackets(n, vector<int>(n, 0));

        // Base case: cost of multiplying one matrix is 0
        for (int i = 1; i < n; i++) {
            dp[i][i] = 0;
        }

        // Dynamic programming to calculate minimum cost
        for (int length = 2; length < n; length++) { // Length of the chain
            for (int i = 1; i < n - length + 1; i++) {
                int j = i + length - 1; // Ending index of the chain
                for (int k = i; k < j; k++) {
                    int total = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (total < dp[i][j]) {
                        dp[i][j] = total;
                        brackets[i][j] = k; // Store the index of partition
                    }
                }
            }
        }

        // Generate the optimal order of multiplication
        return help(1, n - 1, brackets);
    }
};