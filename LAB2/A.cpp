#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i<n; i++){
        int m;
        cin >> m;
        arr[i] = m;
    }

    int k;
    cin >> k;
    int res;
    int nearest = 20000;
    for (int i = 0; i<n; i++){
        if (abs(k - arr[i]) < nearest){
            nearest = abs(k - arr[i]);
            res = i;
        }
    }

    cout << res;


    return 0;
}
