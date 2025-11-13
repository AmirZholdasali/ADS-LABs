#include <iostream>
#include <vector>

std::vector<int> rabinKarp(const std::string& text, const std::string& pattern) {
    const int p = 31;         // простое число для хеширования
    const int m = 1e9 + 9;    // модуль для избежания переполнения

    int n = text.size();
    int k = pattern.size();

    long long patternHash = 0;
    long long textHash = 0;
    long long pPow = 1; // p^(k-1)
    std::vector<int> v;

    // вычисляем хеш шаблона и первого окна текста
    for (int i = 0; i < k; i++) {
        patternHash = (patternHash * p + pattern[i]) % m;
        textHash = (textHash * p + text[i]) % m;
        if (i < k - 1) pPow = (pPow * p) % m;
    }

    // скользящее окно
    for (int i = 0; i <= n - k; i++) {
        if (patternHash == textHash) {
            if (text.substr(i, k) == pattern)
                v.push_back(i); // нашли в позиции i
        }
        if (i < n - k) {
            textHash = (textHash - text[i] * pPow) % m;
            textHash = (textHash * p + text[i + k]) % m;
            if (textHash < 0) textHash += m;
        }
    }

    return v; // не найдено
}

int main(){

    std::string s, x;
    std::cin >> s;
    std::vector<int> sv(s.size());
    std::vector<int> temp;
    int n, m;
    std::cin >> n;
    while(n--){
        std::cin >> x;
        temp = rabinKarp(s, x);
        m = x.size();
        for (int pos : temp) {
            std::fill(sv.begin() + pos, sv.begin() + pos + m, 1);
        }
    }

    for (int num : sv) {
        if (num != 1) {std::cout << "NO"; return 0;}
    }

    std::cout << "YES";

}