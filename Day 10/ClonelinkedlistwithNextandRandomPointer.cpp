#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;
    
    Node(int val) {
        data = val;
        next = random = nullptr;
    }
};

class Solution {
public:
    Node* copyList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* copyNode = new Node(curr->data);
            copyNode->next = curr->next;
            curr->next = copyNode;
            curr = copyNode->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* original = head;
        Node* copyHead = head->next;
        Node* copyCurr = copyHead;

        while (original) {
            original->next = original->next->next;
            if (copyCurr->next) {
                copyCurr->next = copyCurr->next->next;
            }
            original = original->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};

// Helper function to print the cloned list and verify the random pointers
bool verifyRandomPointers(Node* original, Node* copy) {
    while (original && copy) {
        if (original->random) {
            if (!copy->random || original->random->data != copy->random->data) {
                return false;
            }
        } else if (copy->random) {
            return false;
        }
        original = original->next;
        copy = copy->next;
    }
    return true;
}

// Function to create the linked list from input
Node* createLinkedList(int n, unordered_map<int, int>& randomMap) {
    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<int, Node*> nodeMap;

    for (int i = 1; i <= n; ++i) {
        Node* newNode = new Node(i);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        nodeMap[i] = newNode;
    }

    for (auto& pair : randomMap) {
        int a = pair.first;
        int b = pair.second;
        nodeMap[a]->random = nodeMap[b];
    }

    return head;
}

int main() {
    // Input: LinkedList: 1->2->3->4 , pairs = [{1,2},{2,4}]
    int n = 4;
    unordered_map<int, int> randomMap = { {1, 2}, {2, 4} };

    Node* head = createLinkedList(n, randomMap);
    
    Solution solution;
    Node* clonedList = solution.copyList(head);

    // Output verification
    if (verifyRandomPointers(head, clonedList)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
