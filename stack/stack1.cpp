#include <iostream>
#include <stack>  // 引入栈容器

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void reversePrint(Node* head) {
    std::stack<Node*> S;  // 定义栈 S

    // 遍历链表并将节点压入栈
    Node* temp = head;
    while (temp != NULL) {
        S.push(temp);
        temp = temp->next;
    }

    // 依次弹出并打印（实现逆序打印）
    while (!S.empty()) {
        Node* node = S.top();
        std::cout << node->data << " ";
        S.pop();
    }
}

int main() {
    // 创建链表 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    reversePrint(head);  // 逆序打印：3 2 1

    return 0;
}
