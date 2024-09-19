#include <bits/stdc++.h>
using namespace std;

// Function to reverse words in a given string.
string reverseWords(string str) {
    string word = "";
    vector<string> words;
    
    // Traverse through the string and collect words separated by dots.
    for (char ch : str) {
        if (ch == '.') {
            words.push_back(word);
            word = "";
        } else {
            word += ch;
        }
    }
    // Push the last word into the vector.
    words.push_back(word);
    
    // Now reverse the vector of words.
    reverse(words.begin(), words.end());
    
    // Join the words back into a single string separated by dots.
    string result = "";
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) {
            result += ".";
        }
    }
    
    return result;
}

int main() {
    // Test case input
    string str = "i.like.this.program.very.much";
    string result = reverseWords(str);
    cout << "Reversed words: " << result << endl;
    
    return 0;
}
