#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using std::cout;
using std::cin;
using std::endl;

int main(){
    unsigned long long result = 0;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> arrays;
    int n;
    unsigned long long x;
    cin >> n;
    for(int i = 0; i<n ; i++){
        cin >> x;
        arrays.push(x);
    }

    while(arrays.size() > 1){
        long long temp = 0;
        temp += arrays.top();
        arrays.pop();

        temp += arrays.top();
        arrays.pop();

        result += temp;
        arrays.push(temp);

    }

    cout << result;
    
}