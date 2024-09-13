#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // Function to convert a binary tree into its mirror tree
    void mirror(Node* node) {
        if (node == nullptr) {
            return;  // Base case: If the node is null, return
        }

        // Swap the left and right children of the current node
        swap(node->left, node->right);

        // Recursively call mirror on the left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};

// Helper function to perform inorder traversal
void inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);            // Visit left subtree
    cout << node->data << " ";      // Visit node
    inorder(node->right);           // Visit right subtree
}

int main() {
    // Creating a binary tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    // Print the inorder traversal before mirroring
    cout << "Inorder traversal before mirroring: ";
    inorder(root);
    cout << endl;

    // Creating an object of Solution and calling the mirror function
    Solution sol;
    sol.mirror(root);

    // Print the inorder traversal after mirroring
    cout << "Inorder traversal after mirroring: ";
    inorder(root);
    cout << endl;

    return 0;
}
