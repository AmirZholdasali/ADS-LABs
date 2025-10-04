#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, num, f;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    cin >> f;
    sort(arr.begin(), arr.end());
    bool b = binary_search(arr.begin(), arr.end(), f);
    if(b) cout << "Yes";
    else cout << "No";
    return 0;
}
