#include <bits/stdc++.h>
using namespace std;

void buildOrder(vector<int>& nums, int l, int r, vector<int>& order) {
    if (l > r) return;
    int mid = (l + r) / 2;
    order.push_back(nums[mid]);
    buildOrder(nums, l, mid - 1, order);
    buildOrder(nums, mid + 1, r, order);
}

int main(){

    int n, x;
    cin >> n;
    vector<int> nums;
    vector<int> order;
    for(int i = 0; i< (pow(2, n) - 1); i++){
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    buildOrder(nums, 0, nums.size()-1, order);

    for(int x : order){
        cout << x << " ";
    }



}