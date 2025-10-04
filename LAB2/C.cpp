#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr){}
};

int main(){

    int n, x, cnt = 1;
    cin >> n;

    Node *head = nullptr, *tail = nullptr;

    for(int i = 0; i<n; i++){
        cin >> x;
        Node *node = new Node(x);
        if(head == nullptr) head = tail = node;
        else{
            tail->next = node;
            tail = node;
        }
    }

    Node *cur = head;
    while(cur != nullptr){
        if(cnt % 2 == 1) cout << cur->data << ' ';
        cur = cur->next;
        cnt++;
    }


    return 0;
}
