#include <iostream>
using namespace std;

// Узел списка
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

int main() {
    Node* head = nullptr; // голова списка
    Node* tail = nullptr; // хвост списка

    // Пример добавления элементов
    int s, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        Node* node = new Node(s);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int d, p;
    cin >> d;
    cin >> p;

    Node* ins = new Node(d);

    if(p == 0){
        ins->next = head;
        head = ins;
    }
    else{
        Node* first = head;
        Node* second = head;
        for(int i = 0; i<p; i++){
            if (i<p-1){
                first = first->next;
                second = second->next;
            }
            else if (i == p-1){
                second = second->next;
            }
        }
        first->next = ins;
        ins->next = second;
    }

    // Пример обхода списка
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    return 0;
}
