#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rotateDelete(vector<int>& arr) {
        int n = arr.size(); 
        int x = 1; // This will track the step number

        while (n > 1) {
            // Rotate the array to the right by one (simulated by moving the last element to the front)
            int last = arr[n-1];          // Store the last element
            arr.pop_back();                // Remove the last element
            arr.insert(arr.begin(), last); // Insert it at the beginning

            // Find the index to delete: (n - x)
            int id = n - x;

            // Make sure `id` doesn't go out of bounds
            if (id < 0) {
                id = 0;
            }

            // Remove the element at index `id`
            arr.erase(arr.begin() + id);

            // Update variables for the next iteration
            x++;
            n--;
        }

        // Return the last remaining element
        return arr[0];
    }
};

int main() {
    Solution solution;

    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {1, 2, 3, 4};
    
    cout << "Last remaining element for arr1: " << solution.rotateDelete(arr1) << endl; // Expected output: 3
    cout << "Last remaining element for arr2: " << solution.rotateDelete(arr2) << endl; // Expected output: 2

    return 0;
}
