#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// двойной хэш
const ll P1 = 31, M1 = 1000000007LL;
const ll P2 = 37, M2 = 1000000009LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;
    int n = (int)s.size();

    // p_pow1[i] = P1^i % M1, p_pow2 similarly
    vector<ll> p1(n), p2(n);
    p1[0] = 1; p2[0] = 1;
    for (int i = 1; i < n; ++i) {
        p1[i] = (p1[i-1] * P1) % M1;
        p2[i] = (p2[i-1] * P2) % M2;
    }

    // префиксные хэши: h1[k] = хэш первых k символов (k от 0 до n)
    vector<ll> h1(n+1, 0), h2(n+1, 0);
    for (int i = 0; i < n; ++i) {
        // безопасная числовая роль символа: используем unsigned char -> 1..255
        ll val = (ll)(unsigned char)s[i] + 1; // +1 чтобы не было нулей
        h1[i+1] = (h1[i] + val * p1[i]) % M1;
        h2[i+1] = (h2[i] + val * p2[i]) % M2;
    }

    // множество пар хэшей
    unordered_set<unsigned long long> seen;
    seen.reserve(n * 2);

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int l = i;
            int r = i + len;
            // raw = h[r] - h[l] (может быть отрицательным)
            ll raw1 = (h1[r] + M1 - h1[l]) % M1;
            ll raw2 = (h2[r] + M2 - h2[l]) % M2;

            // нормализуем: raw = p^l * inner, хотим получить inner*p^{n-1}
            // множитель = p^{n-1-l}
            ll norm1 = (raw1 * p1[n - 1 - l]) % M1;
            ll norm2 = (raw2 * p2[n - 1 - l]) % M2;

            // Склеиваем два 32-битных значения в одно 64-битное для хранения в unordered_set
            unsigned long long key = ( (unsigned long long)norm1 << 32 ) ^ (unsigned long long)norm2;
            seen.insert(key);
        }
    }

    cout << seen.size() << '\n';
    return 0;
}
