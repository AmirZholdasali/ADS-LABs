#include <iostream>
#include <deque>
using namespace std;

int main() {
    int num;
    cin >> num; 

    while (num--) {
        int t;
        cin >> t;  
        deque<int> deck;

        for (int i = t; i >= 1; i--) {
            deck.push_front(i);


            for (int j = 0; j < i; j++) {
                if (!deck.empty()) {
                    int temp = deck.back();
                    deck.pop_back();
                    deck.push_front(temp);
                }
            }
        }

        for (int k = 0; k < t; k++) {
            cout << deck[k] << " ";
        }
        cout << endl;
    }

    return 0;
}
