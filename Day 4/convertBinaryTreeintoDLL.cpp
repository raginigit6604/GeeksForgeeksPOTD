#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Class containing the conversion function
class Solution {
public:
    // Helper function for recursive in-order traversal
    void inorder(Node* root, Node*& prev, Node*& head) {
        if (!root) return;
        
        // Recur on the left subtree
        inorder(root->left, prev, head);
        
        // If prev is null, we are at the leftmost node (head of DLL)
        if (prev == nullptr) {
            head = root;  // This node becomes the head of the DLL
        } else {
            // Otherwise, link the current node with the previous node
            prev->right = root;  // prev's next is the current node
            root->left = prev;   // current node's previous is prev
        }
        
        // Move prev to the current node
        prev = root;
        
        // Recur on the right subtree
        inorder(root->right, prev, head);
    }

    // Main function to convert BT to DLL
    Node* bToDLL(Node* root) {
        Node* prev = nullptr;  // To store the previous node in the DLL
        Node* head = nullptr;  // To store the head of the DLL
        
        // Perform in-order traversal and convert the tree to DLL
        inorder(root, prev, head);
        
        // Return the head of the DLL
        return head;
    }
};

// Function to print the DLL from the head node
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main() {
    // Construct the binary tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    // Create a solution object
    Solution solution;
    
    // Convert the binary tree to DLL
    Node* head = solution.bToDLL(root);
    
    // Print the resulting DLL
    printDLL(head);
    
    return 0;
}
