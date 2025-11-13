#include <iostream>
#include <map>
#include <algorithm>
#include <string>

int rabinKarp(const std::string& text, const std::string& pattern) {
    const int p = 31;        
    const int m = 1000000009;

    int n = (int)text.size();
    int k = (int)pattern.size();
    if (k > n) return 0;

    long long patternHash = 0;
    long long textHash = 0;
    long long pPow = 1; // p^(k-1)
    int cnt = 0;

    for (int i = 0; i < k; i++) {
        patternHash = (patternHash * p + (unsigned char)pattern[i]) % m;
        textHash = (textHash * p + (unsigned char)text[i]) % m;
        if (i < k - 1) pPow = (pPow * p) % m;
    }

    for (int i = 0; i <= n - k; i++) {
        if (patternHash == textHash) {
            if (text.substr(i, k) == pattern)
                cnt++;
        }
        if (i < n - k) {
            textHash = (textHash - (long long)(unsigned char)text[i] * pPow) % m;
            textHash = (textHash * p + (unsigned char)text[i + k]) % m;
            if (textHash < 0) textHash += m;
        }
    }
    return cnt;
}

int main(){
    while (true) {
        int n;
        if (!(std::cin >> n)) return 0;
        if (n == 0) return 0;

        std::map<std::string, std::pair<int,int>> m;
        std::string s;
        
        for (int i = 0 ; i < n ; i++) {
            std::cin >> s;
            m[s].second++;
        }

        std::string text;
        std::cin >> text;

        
        for (auto &p : m) {
            const std::string &key = p.first;
            p.second.first = rabinKarp(text, key);
        }

        
        auto itMax = std::max_element(
            m.begin(), m.end(),
            [](auto &a, auto &b){ return a.second.first < b.second.first; }
        );

        int max_val = itMax == m.end() ? 0 : itMax->second.first;
        std::cout << max_val << "\n";

        for (auto &p : m) {
            if (p.second.first == max_val) {
                for (int t = 0; t < p.second.second; ++t) {
                    std::cout << p.first << "\n";   
                }
            }
        }
    }
}
