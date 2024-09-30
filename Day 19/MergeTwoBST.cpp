#include <iostream>
#include <vector>
using namespace std;

// Definition of the Node of the tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Solution class with merge function and helper methods
class Solution {
public:
    // Helper function to perform in-order traversal and store values in a vector
    void inorder(Node* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }

    // Function to merge two sorted arrays into a single sorted array
    vector<int> mergeSortedArrays(vector<int>& list1, vector<int>& list2) {
        vector<int> mergedList;
        int i = 0, j = 0;

        // Merge the two sorted lists
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] <= list2[j]) {
                mergedList.push_back(list1[i++]);
            } else {
                mergedList.push_back(list2[j++]);
            }
        }

        // Append any remaining elements from list1
        while (i < list1.size()) {
            mergedList.push_back(list1[i++]);
        }

        // Append any remaining elements from list2
        while (j < list2.size()) {
            mergedList.push_back(list2[j++]);
        }

        return mergedList;
    }

    // Function to return a list of integers denoting the node values of both BSTs in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> list1, list2;

        // Perform in-order traversal on both BSTs to get sorted lists
        inorder(root1, list1);
        inorder(root2, list2);

        // Merge the two sorted lists
        return mergeSortedArrays(list1, list2);
    }
};

// Helper function to insert a node into the BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int main() {
    Solution sol;

    // Create the first BST
    Node* root1 = NULL;
    root1 = insert(root1, 3);
    root1 = insert(root1, 1);
    root1 = insert(root1, 5);

    // Create the second BST
    Node* root2 = NULL;
    root2 = insert(root2, 4);
    root2 = insert(root2, 2);
    root2 = insert(root2, 6);

    // Merge both BSTs and store the result
    vector<int> mergedResult = sol.merge(root1, root2);

    // Print the merged result
    cout << "Merged BSTs in sorted order: ";
    for (int val : mergedResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
