#include <iostream>
#include <vector>

std::vector<int> LPS(std::string pattern){
    int m = pattern.size();
    std::vector<int> lps(m, 0);
    int i = 1;
    int j = 0;

    while(i < m){
        if (pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if (j != 0)
                j = lps[j-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> lps = LPS(pattern);

    int i = 0; // индекс текста
    int j = 0; // индекс шаблона

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return true;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; // откатываемся по LPS
            } else {
                i++; // двигаем текст, если j == 0
            }
        }
    }
    return false;
}

int main(){
    std::string A, B;
    std::cin >> A >> B;
    int Bsize = B.size();
    if (A.size() > Bsize) {std::cout << 1; std::exit(0);}
    std::string a = A;
    int cnt = 1;
    while (A.size() < Bsize){
        A += a;
        cnt++;
    }
    
    if (KMP(A, B)) {std::cout << cnt; std::exit(0);}
    if (KMP(A+a, B)) {std::cout << cnt + 1; std::exit(0);}
    std::cout << -1;
}