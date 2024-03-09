/*
100. Same Tree
Solved
Easy
Topics
Companies
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q){
        if(!p && !q){ // p and q both NULL
            return true;
        }
        if(!p || !q){ // Any 1 null
            return false;
        }

        queue<TreeNode*> que1;
        queue<TreeNode*> que2;

        que1.push(p);
        que2.push(q);

        while(!que1.empty() && !que2.empty()){
            TreeNode* node1 = que1.front(); 
            que1.pop();
            TreeNode* node2 = que2.front(); 
            que2.pop();

            if(node1->val != node2->val){
                return false;
            }
            if(node1->left != NULL && node2->left != NULL){
                que1.push(node1->left);
                que2.push(node2->left);
            }
            else if(node1->left != NULL || node2->left != NULL){
                return false;
            }

            if(node1->right != NULL && node2->right != NULL){
                que1.push(node1->right);
                que2.push(node2->right);
            }
            else if(node1->right != NULL || node2->right != NULL){
                return false;
            }
        }
        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};