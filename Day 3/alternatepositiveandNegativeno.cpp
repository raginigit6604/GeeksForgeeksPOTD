#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rearrange(vector<int> &arr) {
        int n = arr.size(); // Get the size of the input array
        vector<int> pos;  // To store positive numbers (including 0)
        vector<int> neg;  // To store negative numbers

        // Separate positive and negative numbers
        for(int x = 0; x < n; x++) {
            if (arr[x] >= 0) {  // 0 is considered positive
                pos.push_back(arr[x]);
            } else {
                neg.push_back(arr[x]);
            }
        }
        
        int i = 0, j = 0, k = 0; // i -> for pos, j -> for neg, k -> for result array index

        // Merge the arrays alternately
        while (i < pos.size() && j < neg.size()) {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }

        // If any positive elements remain, add them to the result
        while (i < pos.size()) {
            arr[k++] = pos[i++];
        }

        // If any negative elements remain, add them to the result
        while (j < neg.size()) {
            arr[k++] = neg[j++];
        }
    }
};

int main() {
    // Initialize the array with both positive and negative numbers
    vector<int> arr = {3, -2, 5, -7, -1, 4, 0, -3};

    // Create an instance of the Solution class
    Solution sol;

    // Call the rearrange function
    sol.rearrange(arr);

    // Output the rearranged array
    cout << "Rearranged array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
