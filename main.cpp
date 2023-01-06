#include <iostream>
#include <string>

struct Node {
    int key;
    struct Node *next;
};

struct List {
    Node *head;
    Node *tail;
    int size;

    List() {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->next = nullptr;
        size = 0;
    }

    void push(int element) {
        Node *pNode = new Node;
        pNode->key = element;
        pNode->next = head->next;
        head->next = pNode;
        size++;
    }

    void pop() {
        head->next = head->next->next;
        size--;
    }

    int top() {
        return head->next->key;
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    List list;
    bool flag;
    std::string order;
    std::cin >> order;
    for (int i = 0; i < order.size(); i++) {
        flag = true;
        if (order[i] == '(' || order[i] == '[') {
            list.push(order[i]);
        } else {
            if (order[i] == ')') {
                if (list.top() == '(') {
                    list.pop();
                } else {
                    std::cout << "NO" << "\n";
                    flag = false;
                    break;
                }
            }
            else if (order[i] == ']') {
                if (list.top() == '[') {
                    list.pop();
                } else {
                    std::cout << "NO" << "\n";
                    flag = false;
                    break;
                }
            }else{
                std::cout << "NO" << "\n";
                flag = false;
                break;
            }
        }

    }
    if (flag) {
        if (list.size == 0) {
            std::cout << "YES"<< '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }
    return 0;
}