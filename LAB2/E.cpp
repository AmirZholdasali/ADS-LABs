#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    vector<string> result;
    unordered_set<string> seen;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (seen.insert(x).second) {   
            result.push_back(x);       
        }
    }

    cout << "All in all: " << result.size() << endl;
    cout << "Students:" << endl;

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i] << endl;
    }

    return 0;
}
