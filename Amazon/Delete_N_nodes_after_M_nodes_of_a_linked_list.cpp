/*
Question overview

Given a linked list, delete n nodes after skipping m nodes of a linked list until the last of the linked list.
Examples:

Input: Linked List: 9->1->3->5->9->4->10->1, n = 1, m = 2

Output: 9->1->5->9->10->1

Explanation: Deleting 1 node after skipping 2 nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
Input: Linked List: 1->2->3->4->5->6, n = 1, m = 6

Output: 1->2->3->4->5->6

Explanation: After skipping 6 nodes for the first time , we will reach of end of the linked list, so, we will get the given linked list itself.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= size of linked list <= 1000
0 < n, m <= size of linked list


*/



class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node* curr = head;
        while(curr != nullptr) {
            
            for(int i=0; i<m-1 && curr != nullptr; i++) {
                curr = curr->next;
            }
            
            
            if (curr == nullptr || curr->next == nullptr) {
                break;
            }
            
            Node* t = curr->next;
            
            for(int i = 1; i<n && t != nullptr; i++) {
                t = t->next;
            }
            
            if (t != nullptr) {
                curr->next = t->next;
                t->next = nullptr;
            } else {
                curr->next = nullptr; 
            }
  
            if (!curr) return head;
            curr = curr->next;
        }
        return head;
    }
};