#include <iostream>
#include <vector>
#include <algorithm> // std::sort

int findKthElement(const std::vector<int>& nums, int k) {
    // 拷贝原数组，避免直接修改
    std::vector<int> sortedNums = nums;
    
    // 对数组进行升序排序
    std::sort(sortedNums.begin(), sortedNums.end());
    
    // 找到倒数第 k 个元素
    int n = sortedNums.size();
    return sortedNums[n - k];
}

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = findKthElement(nums, k);
    
    std::cout << "The " << k << "th last element is: " << result << std::endl;
    return 0;
}
