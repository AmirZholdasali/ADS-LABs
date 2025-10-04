#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x;
    int last = 0;
    cin >> n >> m;
    vector<int> ends;
    // vector<int> mist;
    for (int i = 0; i<n; i++) {
        cin >> x;
        last += x;
        ends.push_back(last); //создали вектор хранящий конец каждого блока (отсортирован)
    }
    for (int i = 0; i<m; i++) {
        cin >> x;
        cout << (lower_bound(ends.begin(), ends.end(), x) - ends.begin()) + 1 << endl;
    }

    return 0;


}
