#include <iostream>
#include <string>

using namespace std;

struct Node{
    string data;
    Node* next;
    Node(string x) : data(x), next(nullptr){}


};

int main() {

    int n, k, cnt = 0;
    cin >> n >> k;

    Node *head = nullptr, *tail = nullptr;

    string s;
    for(int i = 0; i<n; i++){
        cin >> s;
        Node *node = new Node(s);
        if(head == nullptr) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }

    }
    Node *cur = head;
    while(cur != nullptr){
        if(cnt >= k) cout << cur->data << ' ';
        cur = cur->next;
        cnt++;
    }
    cnt = 0; cur = head;
    while(cnt < k) {
        cout << cur->data << ' ';
        cur = cur->next;
        cnt++;
    }


    return 0;
}
