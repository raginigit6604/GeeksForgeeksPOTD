#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  
    bool ispar(string x) {
        int n = x.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (x[i] == '(' || x[i] == '{' || x[i] == '[') {
                st.push(x[i]);
            } 
            else if (!st.empty() && x[i] == ')' && st.top() == '(') {
                st.pop();
            } 
            else if (!st.empty() && x[i] == '}' && st.top() == '{') {
                st.pop();
            } 
            else if (!st.empty() && x[i] == ']' && st.top() == '[') {
                st.pop();
            } 
            else {
                return false;
            }
        }
        return st.empty();  // If stack is empty, brackets are balanced
    }
};

int main() {
    string exp;
    Solution sol;

    // Input expression
    cout << "Enter an expression: ";
    cin >> exp;

    // Check if the brackets are balanced
    if (sol.ispar(exp)) {
        cout << "balanced" << endl;
    } else {
        cout << "not balanced" << endl;
    }

    return 0;
}
