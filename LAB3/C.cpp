#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    cin >> q;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }

    vector<pair<pair<int,int>, pair<int,int>>> v(q);
    for (int i = 0; i < q; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v[i] = {{a,b},{c,d}};
    }

    for (auto &p : v) {
        int cnt = 0;
        for (int i = 0; i<n ; i++){
            int val = nums[i];
            if ((p.first.first <= val && val <= p.first.second) || (p.second.first <= val && val <= p.second.second)) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }


    return 0;
}
