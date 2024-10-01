#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long multiplyTwoLists(Node *first, Node *second) {
        // Initialize the numbers represented by the linked lists as 0
        long long num1 = 0, num2 = 0;
        
        // Traverse the first linked list and calculate the integer num1
        while (first != nullptr) {
            num1 = (num1 * 10 + first->data) % MOD; // build the number and take modulo at each step
            first = first->next;
        }
        
        // Traverse the second linked list and calculate the integer num2
        while (second != nullptr) {
            num2 = (num2 * 10 + second->data) % MOD; // build the number and take modulo at each step
            second = second->next;
        }
        
        // Multiply the two numbers and return the result modulo MOD
        return (num1 * num2) % MOD;
    }
};

Node* appendNode(Node* head, int data) {
    if (head == nullptr) {
        return new Node(data); // If the list is empty, create the first node
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; // Traverse to the end of the list
    }
    temp->next = new Node(data); // Append the new node at the end
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
        if (head != nullptr) cout << " -> ";
    }
    cout << endl;
}

int main() {
    // Create the first linked list: L1 = 3 -> 2
    Node* L1 = nullptr;
    L1 = appendNode(L1, 3);
    L1 = appendNode(L1, 2);
    
    // Create the second linked list: L2 = 2
    Node* L2 = nullptr;
    L2 = appendNode(L2, 2);

    cout << "L1: ";
    printList(L1);
    cout << "L2: ";
    printList(L2);
    

    Solution sol;
    long long result = sol.multiplyTwoLists(L1, L2);
    cout << "Result of multiplication: " << result << endl;

    return 0;
}
