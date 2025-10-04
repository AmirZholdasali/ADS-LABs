#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];
    map<int, int> count;

    for(int i = 0; i<n; i++) {
        int m;
        cin >> m;
        arr[i] = m;
        if(count.find(m) != count.end()) {
            count[m]++;
        }
        else{
            count[m] = 1;
        }
    }

    // for (auto &p : count) {
    //     cout << p.first << " : " << p.second << endl;
    // }

    set<int> maxkey;
    int maxval = -1;
    for(auto &p : count) {
        if(p.second > maxval) {
            maxval = p.second;
        }
    }

    // cout << maxval << endl;

    for(auto &p : count) {
        if(p.second == maxval){
            maxkey.insert(p.first);
        }
    }

    for (auto it = maxkey.rbegin(); it != maxkey.rend(); ++it) {
        cout << *it << " ";
    }



    return 0;
}
