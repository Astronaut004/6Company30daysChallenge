/*
Question Overview

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;
        for(int i=0; i<lists.size(); i++) {
            ListNode* head = lists[i];
            while(head != nullptr) {
                ans.push_back(head->val);
                head = head->next;
            }
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        for(int i=0; i<ans.size(); i++) {
            tail->next = new ListNode(ans[i]);
            tail = tail->next;
        }
        return dummy->next;
    }
};