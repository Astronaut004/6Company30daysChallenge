/*
Question Overview

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.

*/


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;

        for(auto i:s) {
            mp[i]++;
        }

        sort(s.begin(),s.end(), [&](char a, char b) {
            if(mp[a] == mp[b]) {
                return a > b;
            }
            return mp[a] > mp[b];
        });
        return s;
    }
};


TC: O(nlogn), SC: O(n)


// solution with priority queue


class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }


        priority_queue<pair<int, char>> pq; 
        


        for (auto& entry : freqMap) {
            pq.push({entry.second, entry.first});
        }
        
        string result = "";
        while (!pq.empty()) {
            char c = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            
            
            result.append(freq, c); // append freq times 
        }
        return result;
    }
};

TC:O(n), SC(n)