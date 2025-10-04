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
    //
    sort(nums.begin(), nums.end());

    vector<pair<pair<int,int>, pair<int,int>>> v(q);
    for (int i = 0; i < q; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v[i] = {{a,b},{c,d}};
    }

    int cnt;
    for (auto &p : v) {
        cnt = 0;
        cnt += upper_bound(nums.begin(), nums.end(), p.first.second) - lower_bound(nums.begin(), nums.end(), p.first.first);
        cnt += upper_bound(nums.begin(), nums.end(), p.second.second) - lower_bound(nums.begin(), nums.end(), p.second.first);
        
        int L = max(p.first.first, p.second.first);
        int R = min(p.first.second, p.second.second);
        if (L <= R) {
        cnt -= upper_bound(nums.begin(), nums.end(), R)
             - lower_bound(nums.begin(), nums.end(), L);
    }

        cout << cnt << endl;
    }


    return 0;
}
