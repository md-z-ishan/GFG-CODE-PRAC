/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> ans;

    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        ans.push_back(root->data);
        inorder(root->right);
    }

    vector<int> inOrder(Node* root) {
        inorder(root);
        return ans;
    }
};