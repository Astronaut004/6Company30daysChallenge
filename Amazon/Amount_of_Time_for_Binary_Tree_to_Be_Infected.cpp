/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 

Example 1:

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
Example 2:


Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.
*/


class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
    

    TreeNode* find(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }
        if (root->val == target) {
            return root;
        }
        TreeNode* left = find(root->left, target);
        if (left) return left;
        return find(root->right, target);
    }
    

    int distanceK(TreeNode* root, TreeNode* target) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;

        while (!queue.empty()) {
            int size = queue.size();
            bool found = false;
            for (int i = 0; i < size; ++i) {
                TreeNode* current = queue.front();
                queue.pop();
                if (current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            if (!queue.empty()) {
                curr_level++;
            }
        }
        return curr_level;
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* targetNode = find(root, start);
        if (!targetNode) {
            return 0;  
        }
        return distanceK(root, targetNode);
    }
};

