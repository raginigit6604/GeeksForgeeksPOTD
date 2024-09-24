#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow (string s, string p) {
        int n = s.length();
        int m = p.length();
        
        // If p's length is greater than s's length, no window can exist
        if (m > n) {
            return "-1";
        }
        
        // Arrays to store the frequency of characters
        int p_count[26] = {0};  // Frequency of characters in string p
        int window_count[26] = {0};  // Frequency of characters in the current window in s
        
        // Fill the frequency array for string p
        for (char c : p) {
            p_count[c - 'a']++;
        }
        
        // Variables for sliding window
        int left = 0, right = 0;
        int min_len = INT_MAX;  // To store the minimum length of a valid window
        int start_idx = -1;  // To store the starting index of the smallest window
        
        // To track how many characters are matched in the window
        int match_count = 0;
        
        // Traverse the string s with the right pointer
        while (right < n) {
            // Add the character at the right pointer to the window
            window_count[s[right] - 'a']++;
            
            // Check if this character matches its count in p
            if (window_count[s[right] - 'a'] <= p_count[s[right] - 'a']) {
                match_count++;
            }
            
            // When a valid window is found (i.e., all characters of p are matched)
            while (match_count == m) {
                // Update the minimum window size and starting index
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }
                
                // Shrink the window by moving the left pointer
                window_count[s[left] - 'a']--;
                
                // If shrinking the window breaks the valid window condition
                if (window_count[s[left] - 'a'] < p_count[s[left] - 'a']) {
                    match_count--;
                }
                
                // Move the left pointer
                left++;
            }
            
            // Expand the window by moving the right pointer
            right++;
        }
        
        // If no valid window was found, return "-1"
        return (start_idx == -1) ? "-1" : s.substr(start_idx, min_len);
    }
};

int main() {
    Solution sol;
    string s = "timetopractice";
    string p = "toc";
    cout << sol.smallestWindow(s, p) << endl;  // Output: toprac
    
    s = "zoomlazapzo";
    p = "oza";
    cout << sol.smallestWindow(s, p) << endl;  // Output: apzo
    
    return 0;
}
