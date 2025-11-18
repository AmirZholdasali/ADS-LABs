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

int KMP(std::string text, const std::string &pattern){
    int n = text.size();
    int m = pattern.size();
    std::vector<int> lps = LPS(pattern);
    int i = 0;
    int j = 0;
    int cnt = 0;
    bool flag = false;

    while (i < n){
        if (text[i] == pattern[j]){
            i++;
            j++;
            if (i == n && j != 0 && j != m){
                cnt = j;
                text = text.substr(0, m-j);
                i = 0;
            }
            if (j == m){
                flag = true;
                break;
                // j = lps[j-1];
            }
        }
        else{
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
    if (flag) return cnt;
    else return -1;
}

int main(){
    std::string A, B;
    std::cin >> A >> B;
    std::cout << KMP(A, B);

}
