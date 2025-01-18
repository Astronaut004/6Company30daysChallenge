/*
Question Overview

Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1
*/


class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<string> track = {"", "Thousand", "Million", "Billion"};
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string result = "";
        int chunkIndex = 0;

        while (num > 0) {
            int chunk = num % 1000;
            if (chunk > 0) {
                string chunkStr = convertChunk(chunk, ones, teens, tens);
                if (!track[chunkIndex].empty())
                    chunkStr += " " + track[chunkIndex];
                result = chunkStr + (result.empty() ? "" : " ") + result;
            }
            num /= 1000;
            chunkIndex++;
        }

        return result;
    }

private:
    string convertChunk(int num, const vector<string>& ones, const vector<string>& teens, const vector<string>& tens) {
        string chunkStr = "";

        if (num >= 100) {
            chunkStr += ones[num / 100] + " Hundred";
            num %= 100;
            if (num > 0)
                chunkStr += " ";
        }

        if (num >= 11 && num <= 19) {
            chunkStr += teens[num - 11];
        } else {
            if (num >= 10) {
                chunkStr += tens[num / 10];
                num %= 10;
                if (num > 0)
                    chunkStr += " ";
            }
            if (num > 0) {
                chunkStr += ones[num];
            }
        }

        return chunkStr;
    }
};
