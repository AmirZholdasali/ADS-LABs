#include <iostream>
#include <functional>
#include <queue>
using std::cout;
using std::endl;
using std::cin;

int main(){
    std::priority_queue<unsigned long long> pq;
    int n;
    long long l, x;
    unsigned long long result = 0;
    cin >> n;
    cin >> l;
    for(int i = 0 ; i < n ; i++){
        cin >> x;
        pq.push(x);
    }

    for(long long i = 0; i < l ; i++){
        long long temp = pq.top();
        pq.pop();
        result += temp;
        temp--;
        pq.push(temp);
    }

    cout << result;
}