#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if (n%2 == 0) return false;
    if (n == 2) return true;

    for (int i = 3; i <= sqrt(n); i += 2){
        if (n%i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int n;
    cin >> n;

    int res_cnt = 0;

    for (int i = 2; i <= 10005; i++){
        if (isPrime(i)) res_cnt++;
        if (res_cnt == n-1) {
            n = i;
            res_cnt = 0;
            break;
        }
    }

    for (int i = 2; i <= 10005; i++){
        if (isPrime(i)) res_cnt++;
        if (res_cnt == n-1) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
