#include <iostream>
#include <string>
#include <vector>

using namespace std;

void RemoveSubString(string& S, string& T) {
    string result = ""; // This acts as our 'stack'
    int t_len = T.length();

    for (char c : S) {
        result += c; // Add the current character

        // Check if the end of 'result' matches 'T'
        if (result.length() >= t_len && result.substr(result.length() - t_len) == T) {
            // If it matches, "pop" the substring by resizing
            // This is significantly faster than .erase()
            result.resize(result.length() - t_len); 
        }
    }
    S = result; // Update the original string
}

int main() {
    // Optimize I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    // Read both strings
    if (!(cin >> str1 >> str2)) return 0;

    RemoveSubString(str1, str2);
    
    cout << str1 << endl;
    return 0;
}