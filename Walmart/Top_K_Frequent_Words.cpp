/*
Question Overview

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto str:words) {
            mp[str]++;
        }


        // initialise the priority queue

        class customSort{
            public:
                bool operator()(const pair<int,string>a, const pair<int,string>b) {
                    if(a.first == b.first) return a.second > b.second;

                    return a.first < b.first;
                }
        };

        priority_queue<pair<int,string>, vector<pair<int,string>>, customSort>pq;

        // store your diamonds hehehe
        for(auto p:mp) {
            pq.push({p.second,p.first});
        }

        // store first k elements from queue

        vector<string>ans;
        while(k > 0 && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};

// TC: O(nlogn), SC: O(n)