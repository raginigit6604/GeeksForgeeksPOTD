#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        long long S = 0, P = 0; // S is sum of array elements, P is sum of squares of array elements
        long long S_n = (n * (n + 1)) / 2; // Sum of first n natural numbers
        long long P_n = (n * (n + 1) * (2 * n + 1)) / 6; // Sum of squares of first n natural numbers
        
        // Calculating S (sum of elements in array) and P (sum of squares of elements in array)
        for (int i = 0; i < n; i++) {
            S += arr[i];
            P += (long long)arr[i] * arr[i]; 
        }
        
        // Solving the two equations
        long long diff = S - S_n; // B - A
        long long sum = (P - P_n) / diff; // B + A

        // Solving for A and B
        long long B = (sum + diff) / 2;
        long long A = sum - B;
        
        return {(int)B, (int)A};
    }
};

int main() {
    // Example 1
    vector<int> arr1 = {2, 2};
    Solution sol;
    vector<int> result1 = sol.findTwoElement(arr1);
    cout << "Repeating number: " << result1[0] << ", Missing number: " << result1[1] << endl;

    // Example 2
    vector<int> arr2 = {1, 3, 3};
    vector<int> result2 = sol.findTwoElement(arr2);
    cout << "Repeating number: " << result2[0] << ", Missing number: " << result2[1] << endl;

    return 0;
}
