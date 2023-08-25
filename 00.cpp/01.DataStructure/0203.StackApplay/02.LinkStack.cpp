#include <iostream>
#include <cstdlib> // 包含 <cstdlib> 头文件以使用 malloc 和 free 函数

using namespace std;

#define ElemType char

typedef struct StackNode {
    ElemType data;
    struct StackNode* next;
} StackNode, *LinkStack;

void InitStack(LinkStack& S) {
    S = NULL; // 初始化栈为空
}

bool StackEmpty(LinkStack S) {
    if (S == NULL) {
        return true; // 栈为空
    } else {
        return false; // 栈不为空
    }
}

bool Push(LinkStack& S, ElemType x) {
    StackNode* p = (StackNode*)malloc(sizeof(StackNode)); // 分配一个新节点
    p->data = x; // 将数据存入新节点
    p->next = S; // 新节点指向当前栈顶元素
    S = p; // 更新栈顶指针
    return true;
}

bool Pop(LinkStack& S, ElemType& x) {
    if (S == NULL) {
        return false; // 栈为空，无法弹出元素
    }
    StackNode* p = S; // 保存当前栈顶节点
    x = p->data; // 将栈顶元素赋值给 x
    S = S->next; // 更新栈顶指针
    free(p); // 释放原栈顶节点的内存
    return true;
}

bool BracketCheck(char str[], int length) {
    LinkStack S;
    InitStack(S); // 初始化栈

    for (int i = 0; i < length; i++) { // 注意循环条件是 i < length
        // 扫描到左括号
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]); // 将左括号入栈
        } 
        else 
        {
            if (StackEmpty(S)) {
                return false; // 当前栈为空，说明有右括号没有匹配的左括号
            }
            char topElem;
            Pop(S, topElem); // 弹出栈顶元素
            if (str[i] == ')' && topElem != '(') {
                return false; // 右括号与栈顶元素不匹配
            }
            if (str[i] == ']' && topElem != '[') {
                return false; // 右括号与栈顶元素不匹配
            }
            if (str[i] == '}' && topElem != '{') {
                return false; // 右括号与栈顶元素不匹配
            }
        }
    }
    return StackEmpty(S); // 最终栈为空，说明所有括号匹配成功
}


int main() {
    char str[10] = "{[()]}";
    cout << BracketCheck(str, 6);
    return 0;
}