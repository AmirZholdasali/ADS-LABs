#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

int length(Node* head) {
    int count = 0;
    Node* cur = head;
    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }
    return count;
}
 
Node* insert(Node* head, Node* node, int p){

    if(p == 0){
        node->next = head;
        head = node;
        return head;
    }
    Node* prev = head;
    for (int i = 0; i < p - 1; i++) {
        prev = prev->next;
    }

    node->next = prev->next;
    prev->next = node;

    return head;
}
 
Node* remove(Node* head, int p){
    
    if(p == 0) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }

    Node* prev = head;
    for(int i = 0; i<p-1; i++){
        prev = prev->next;
    }

    Node* cur = prev->next;
    prev->next = cur->next;
    delete cur;


    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if (p1 == p2) return head;
    Node* cur = head;
    for(int i = 0; i<p1 ; i++) cur = cur->next;
    int value = cur->val;
    head = remove(head, p1);
    head = insert(head, new Node(value), p2);
    return head;
}
 
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    Node* nxt = nullptr;

    while (cur != nullptr) {
        nxt = cur->next;    
        cur->next = prev;   
        prev = cur;         
        cur = nxt;          
    }

    return prev;
}
 
void print(Node* head){
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int k){
    int n = length(head);
    Node* cur = head;

    for (int i = 0; i < n - 1; i++) {
        cur = cur->next;
    }

    cur->next = head;

    cur = head;
    for (int i = 0; i < k - 1; i++) {
        cur = cur->next;
    }

    Node* newHead = cur->next;
    cur->next = nullptr;

    return newHead;
}
 
Node* cyclic_right(Node* head, int k){
    int n = length(head);
    Node* cur = head;

    for (int i = 0; i < n - 1; i++) {
        cur = cur->next;
    }

    cur->next = head;

    cur = head;
    for (int i = 0; i < n - k - 1; i++) {
        cur = cur->next;
    }

    Node* newHead = cur->next;
    cur->next = nullptr;

    return newHead;
}
 
int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}
