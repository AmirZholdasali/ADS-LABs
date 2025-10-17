#include <iostream>
#include <queue>
#include <functional>
using std::cout;
using std::cin;
using std::endl;

int main(){
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int n, x, m;
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        cin >> x;
        pq.push(x);
    }

    int cnt = 0;

    while(pq.top() < m && pq.size() > 1){
        int least = pq.top();
        pq.pop();

        int sleast = pq.top();
        pq.pop();


        int temp = least + 2 * sleast;

        pq.push(temp);
        cnt++;
    }

    if (pq.top() < m) cout << -1;
    else cout << cnt;
}