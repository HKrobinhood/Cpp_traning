#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered; // 用于存储清理后的字符串

        // Step 1: 过滤字符串，保留字母数字字符并转换为小写
        for (char c : s) {
            if (isalnum(c)) { // 检查是否为字母数字
                filtered += tolower(c); // 转换为小写并加入新字符串
            }
        }

        // Step 2: 检查是否为回文
        int left = 0, right = filtered.size() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false; 
            }
            left++;
            right--;
        }

        return true; 
    }
};

int main() { 
    Solution solution;
    string s;

    // 使用 getline 读取整行输入
    cin>>s;

    if(solution.isPalindrome(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
   
