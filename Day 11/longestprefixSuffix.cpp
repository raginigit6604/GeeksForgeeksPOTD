#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int lps(string str) {
        int n = str.length(); 
        vector<int> lps(n, 0); // array to store longest prefix and suffix
        int length = 0; 
        for (int i = 1; i < n; i++) {
            while (length > 0 && str[i] != str[length]) {
                length = lps[length - 1];
            }
            if (str[i] == str[length]) {
                length++; // if there is a match, we increment length
            }
            lps[i] = length;
        }
        return lps[n - 1]; // return the length of the longest proper prefix which is also a suffix
    }
};

int main() {
    Solution solution;
    string str;

    // Input the string from the user
    cout << "Enter the string: ";
    cin >> str;

    // Call the lps function and print the result
    int result = solution.lps(str);
    cout << "The length of the longest proper prefix which is also a suffix is: " << result << endl;

    return 0;
}
