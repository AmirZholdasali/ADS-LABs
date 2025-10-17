#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int n, x;
    std::priority_queue<int> stones;

    cin >> n;
    for(int i = 0; i<n ;i++){
        cin >> x;
        stones.push(x);
    }

    while(stones.size() > 1){
        int y;
        int x;
        y = stones.top();
        stones.pop();
        x = stones.top();
        stones.pop();

        y -= x;
        stones.push(y);
    }

    cout << stones.top();
}