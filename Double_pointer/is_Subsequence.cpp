#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        // Traverse both strings
        while (i < s.length() && j < t.length()) {
            // If characters match, move the pointer for s
            if (s[i] == t[j]) {
                i++;
            }
            // Always move the pointer for t
            j++;
        }

        // If we've gone through the entirety of s, it's a subsequence
        return i == s.length();
    }
};

int main() {
    Solution test1;

    if (test1.isSubsequence("zci", "szeching")) {
        cout << "True";
    } else {
        cout <<"false";
    }

    return 0;
}
