/*
Question Overview


There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.

A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:

age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
Otherwise, x will send a friend request to y.

Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.

Return the total number of friend requests made.

 

Example 1:

Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.
Example 2:

Input: ages = [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
Example 3:

Input: ages = [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 

Constraints:

n == ages.length
1 <= n <= 2 * 104
1 <= ages[i] <= 120


*/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int arr[121] = {0};
        for(int i=0; i<ages.size(); i++) {
            arr[ages[i]]++;
        }
        int count = 0;
        for(int i=0; i<121; i++) {
            if(arr[i] == 0) continue;
            for(int j=0; j<121; j++) {
                int a = (0.5 * j) + 7;
                if(i <= a || i > j || (i > 100 && j < 100)) continue;

                if(i != j) {
                    count += arr[i] * arr[j];
                }
                else {
                    count += arr[i] * (arr[i] - 1);
                }
            }
        }
        return count;
    }
};


// optimised

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;


        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j]) {
                    string word = s.substr(j, i - j);
                    
                    if(wordSet.find(word) != wordSet.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

TC: O(n^2), SC : O(n) + O(m + w);
// m --> number of words
// w --> avg length of words