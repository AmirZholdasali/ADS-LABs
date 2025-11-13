#include <iostream>
#include <map>

int rabinKarp(const std::string& text, const std::string& pattern, int start) {
    const int p = 31;
    const int m = 1e9 + 9;
    int n = text.size(), k = pattern.size();

    if (k + start > n) return -1;

    long long patternHash = 0, textHash = 0, pPow = 1;

    for (int i = 0; i < k; i++) {
        patternHash = (patternHash * p + pattern[i]) % m;
        textHash = (textHash * p + text[start + i]) % m;
        if (i < k - 1) pPow = (pPow * p) % m;
    }

    for (int i = start; i <= n - k; i++) {
        if (patternHash == textHash && text.substr(i, k) == pattern)
            return i;

        if (i < n - k) {
            textHash = (textHash - text[i] * pPow) % m;
            textHash = (textHash * p + text[i + k]) % m;
            if (textHash < 0) textHash += m;
        }
    }

    return -1;
}

int main(){
    std::string s1, s2, key;
    std::cin >> s1 >> s2 >> key;
    std::map<int, int> freq;
    int k = key.size(), a = 0-k, b = 0-k;
    while(true){
        a = rabinKarp(s1, key, a+k);
        if (a == -1) break;
        freq[a]++;
    }

    while(true){
        b = rabinKarp(s2, key, b+k);
        if (b == -1) break;
        freq[b]++;
    }

    int cnt = 0;
    for (auto p : freq) if (p.second == 2) cnt++;
    std::cout << cnt;
    


}