#include <iostream>
using namespace std;

// 定义二叉搜索树节点结构
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// 创建一个新节点
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();//使用 new 运算符动态分配内存，创建一个新的 BstNode 节点 neweNode
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 插入新节点到BST
BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        // 如果树为空，创建新节点作为根节点
        return GetNewNode(data);
    }
    if (data <= root->data) {
        // 递归插入到左子树
        root->left = Insert(root->left, data);
    } else {
        // 递归插入到右子树
        root->right = Insert(root->right, data);
    }
    return root;
}

// 查找BST中的最小值
int FindMin(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// 查找BST中的最大值
int FindMax(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// 查找节点的高度
int FindHeight(BstNode* root) {
    if (root == NULL) {
        return -1; // 空树的高度为-1
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// 中序遍历BST（递增顺序）
void InorderTraversal(BstNode* root) {
    if (root == NULL) return;
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

// 主函数
int main() {
    BstNode* root = NULL;  // 初始化空树

    // 插入节点
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 12);
    root = Insert(root, 18);

    // 打印中序遍历（应输出：3 5 7 10 12 15 18）
    cout << "BST: ";
    InorderTraversal(root);
    cout << endl;

    // 查找最小值和最大值
    cout << "Minimum value: " << FindMin(root) << endl;
    cout << "Maximum value: " << FindMax(root) << endl;

    // 查找树的高度
    cout << "Height of the tree: " << FindHeight(root) << endl;

    return 0;
}
