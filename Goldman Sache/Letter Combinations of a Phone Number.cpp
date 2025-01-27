/*
Question Overview

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/


class Solution {
public:
    void solve(int i, string digit,string temp, vector<string>&ans, string track[]) {
        if(digit.size() <= i) {
            ans.push_back(temp);
            return ;
        }
        int digi = digit[i] - '0';
        string val = track[digi];
        for(int j=0; j<val.size(); j++) {
            
            solve(i+1,digit,temp+val[j],ans,track);
            
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string track[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp;
        solve(0,digits,temp,ans,track);
        return ans;
    }
};