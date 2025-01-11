/*
Question overview

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

    void Track_Parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp) {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; i++) {
                TreeNode* f = q.front();
                q.pop();
                if(f->left) {
                    mp[f->left] = f;
                    q.push(f->left);
                }
                if(f->right) {
                    mp[f->right] = f;
                    q.push(f->right);
                }
            }
        }
    }

    int distance(TreeNode* root, TreeNode* target) {
        // track all parent;
        unordered_map<TreeNode*, TreeNode*> parent;
        Track_Parent(root,parent);

        unordered_map<TreeNode*, bool> visit;
        queue<TreeNode*> q;

        q.push(target);
        visit[target] = true;

        int curr = 0;

        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left && !visit[temp->left]) {
                    q.push(temp->left);
                    visit[temp->left] = true;
                }

                if(temp->right && !visit[temp->right]) {
                    q.push(temp->right);
                    visit[temp->right] = true;
                }

                if(parent[temp] && !visit[parent[temp]]) {
                    q.push(parent[temp]);
                    visit[parent[temp]] = true;
                }
            }
            if(!q.empty()) {
                curr++;
            }
        }
            return curr;
    }
    // }

//find the target
    TreeNode* find(TreeNode* root, int start) {
        if(!root) return nullptr;

        if(root->val == start) return root;
        TreeNode* left = find(root->left, start);
        if(left) return left;
        return find(root->right, start);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* targetNode = find(root,start);
        if(!targetNode) return 0;

        return distance(root,targetNode);
    }
};
