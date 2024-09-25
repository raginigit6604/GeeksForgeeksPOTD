#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(Node *head) {
        if (!head || !head->next) {
            return true;  // Empty list or single element list is a palindrome
        }

        Node* slow = head;
        Node* fast = head;

        // Find the middle of the linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        Node *previous = nullptr;
        while (slow) {
            Node *next_node = slow->next;
            slow->next = previous;  // Reverse the link
            previous = slow;
            slow = next_node;
        }

        // Compare the first half and the reversed second half
        Node* left = head;
        Node* right = previous;  // This is the head of the reversed second half

        while (right) {  // Only need to check the reversed part
            if (left->data != right->data) {
                return false;  // Not a palindrome
            }
            left = left->next;
            right = right->next;
        }

        return true;  // It's a palindrome
    }
};

// Function to create a linked list from an array
Node* createLinkedList(int arr[], int size) {
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to delete the linked list to free memory
void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 1};  // Example array for a palindrome
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedList(arr, size);
    Solution solution;

    if (solution.isPalindrome(head)) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    deleteLinkedList(head);  // Clean up the linked list
    return 0;
}
