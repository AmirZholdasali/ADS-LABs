#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long f;
    cin >> n >> f;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long l = 1;
    long long r = *max_element(a.begin(), a.end());

    while (l < r) {
        long long mid = l + (r - l) / 2;
        long long cnt = 0;

        for (int i = 0; i < n; ++i) {
            cnt += (a[i] + mid - 1) / mid;
            if (cnt > f) break;
        }

        if (cnt <= f) r = mid;
        else l = mid + 1;
    }

    cout << l;
    return 0;
}
