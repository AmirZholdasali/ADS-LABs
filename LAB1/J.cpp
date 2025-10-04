#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<int> dq;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "!") break;

        if (cmd == "+") {
            int x; cin >> x;
            dq.push_front(x);
        } 
        else if (cmd == "-") {
            int x; cin >> x;
            dq.push_back(x);
        } 
        else if (cmd == "*") {
            if (dq.empty()) {
                cout << "error" << endl;
            } else if (dq.size() == 1) {
                cout << dq.front() + dq.back() << endl;
                dq.pop_front();
            } else {
                cout << dq.front() + dq.back() << endl;
                dq.pop_front();
                dq.pop_back();
            }
        }
    }
    return 0;
}
