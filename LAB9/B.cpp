#include <iostream>
#include <vector>

std::vector<int> LPS(const std::string &pattern){
    int m = pattern.size();
    std::vector<int> lps(m);
    int i = 1;
    int j = 0;

    while (i < m){
        if (pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if (j != 0) j = lps[j-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int KMP(const std::string &text, const std::string &pattern){
    int n = text.size();
    int m = pattern.size();
    std::vector<int> lps = LPS(pattern);
    int i = 0;
    int j = 0;
    int cnt = 0;

    while (i < n){
        if (text[i] == pattern[j]){
            i++;
            j++;
            if (j == m){
                cnt++;
                j = lps[j-1];
            }
        }
        else{
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
    return cnt;
}

int main(){
    std::string pattern, text;
    int n;
    std::cin >> pattern >> n >> text;

    if (KMP(text, pattern) >= n) std::cout << "YES";
    else std::cout << "NO";
}