#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

struct Row {
    std::vector<int> nums;
    int sum;
};

bool cmp(const Row &a, const Row &b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    return a.nums < b.nums;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();

    std::vector<Row> rows(n);
    for (int i = 0; i < n; ++i) {
        std::string line;
        getline(std::cin, line);
        std::istringstream iss(line);
        int x, s = 0;
        while (iss >> x) {
            rows[i].nums.push_back(x);
            s += x;
        }
        rows[i].sum = s;
    }

    std::sort(rows.begin(), rows.end(), cmp);

    for (auto &r : rows) {
        for (int x : r.nums) std::cout << x << " ";
        std::cout << "\n";
    }
}
