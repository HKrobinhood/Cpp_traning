#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    struct Student* ptr = new Student[n]; // 动态分配结构体数组

    for (int i = 0; i < n; ++i) {
        cout << "\nEntering details for student " << (i + 1) << ":\n";

        cout << "Enter ID: ";
        cin >> ptr[i].id;
        cin.ignore(); // 清除换行符，避免影响后续输入

        cout << "Enter Name: ";
        getline(cin, ptr[i].name);

        cout << "Enter Grade: ";
        cin >> ptr[i].grade;
    }

    cout << "\nStudent details:\n";
    for (int i = 0; i < n; ++i) {
        cout << "ID: " << ptr[i].id << ", Name: " << ptr[i].name << ", Grade: " << ptr[i].grade << endl;
    }

    delete[] ptr; // 释放动态分配的内存
    return 0;
}

