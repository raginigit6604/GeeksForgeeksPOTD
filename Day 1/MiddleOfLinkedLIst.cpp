#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Solution class
class Solution {
public:
    // Function to find the length of the list
    int findlength(Node* head) {
        int length = 0;
        Node* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // Function to get the middle element of the list
    int getMiddle(Node* head) {
        int length = findlength(head); // Find total length
        int mid = length / 2; // Calculate the index of the middle node
        Node* temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
};

// Main function
int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create Solution object and find the middle element
    Solution sol;
    int middle = sol.getMiddle(head);

    // Output the middle element
    cout << "The middle element is: " << middle << endl;

    return 0;
}
