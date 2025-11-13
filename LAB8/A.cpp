#include <iostream>
#include <vector>
#include <set>
using ll = long long;

const ll MOD = 1000000007;
const ll BASE = 11;

std::string get_hash(const std::string &s) {
    ll h = 0, p = 1;
    for (char c : s) {
        h = (h + (c - 47) * p) % MOD;
        p = (p * BASE) % MOD;
    }
    return std::to_string(h);
}

int main(){

    int n;
    std::string s;
    std::vector<std::string> v;
    std::set<std::string> st;
    std::cin >> n;

    for (int i = 0 ; i < n * 2; i++) {
        std::cin >> s;
        v.push_back(s);
        st.insert(s);
    }

    int cnt = 0;

    for (int i = 0 ; i < v.size() ; i++){
        if (cnt == n) break;
        std::string hs = get_hash(v[i]);
        if (st.find(hs) != st.end()) {
            std::cout << "Hash of string " << '"' << v[i] << '"' << " is " << hs << "\n";
            cnt++;
        }
    }

}