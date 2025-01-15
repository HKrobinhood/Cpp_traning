/* 变量生命周期问题*/


#include <iostream>
#include <limits>

// 动态内存管理实现
int* findMaxDynamic(const int* arr, int size) {
    if (size <= 0) {
        return nullptr;
    }
    int* maxValue = new int; // 动态分配内存
    *maxValue = std::numeric_limits<int>::min();

    for (int i = 0; i < size; ++i) {
        if (arr[i] > *maxValue) {
            *maxValue = arr[i];
        }
    }
    return maxValue;
}

// static变量实现
int* findMaxStatic(const int* arr, int size) {
    if (size <= 0) {
        return nullptr;
    }
    static int maxValue; // 使用static变量
    maxValue = std::numeric_limits<int>::min();

    for (int i = 0; i < size; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return &maxValue;
}

int main() {
    int arr[] = {1, 5, 2, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    // 使用动态内存管理实现
    int* maxDynamic = findMaxDynamic(arr, size);
    if (maxDynamic) {
        std::cout << "Max value (dynamic): " << *maxDynamic << std::endl;
        delete maxDynamic; // 释放动态分配的内存
    } else {
        std::cout << "Array is empty (dynamic)." << std::endl;
    }

    // 使用static变量实现
    int* maxStatic = findMaxStatic(arr, size);
    if (maxStatic) {
        std::cout << "Max value (static): " << *maxStatic << std::endl;
    } else {
        std::cout << "Array is empty (static)." << std::endl;
    }

    return 0;
}
