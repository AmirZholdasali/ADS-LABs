#include <iostream>
#include <map>
using namespace std;

struct Node{
    char val;
    Node* next;
    Node(char x) : val(x), next(nullptr){}
};

int main(){

    int T, N;
    char c;
    cin >> T;
    int cnt = 0;

    while(T--){
        map<char, int> m;
        cin >> N;
        Node *head = nullptr, *tail = nullptr;
        for(int i = 0; i<N; i++){
            cin >> c;
            Node* node = new Node(c);
            if(head == nullptr) head = tail = node;
            else{
                tail->next = node;
                tail = node;
            }
        
        m[c]++;
        Node* cur = head;
        while(cur != nullptr && m[cur->val] > 1) {
            cur = cur->next;
        }
        if(cur == NULL) cout << -1 << ' ';
        else cout << cur->val << ' ';

        }
        
        cout << endl;



    }

    return 0;
}
