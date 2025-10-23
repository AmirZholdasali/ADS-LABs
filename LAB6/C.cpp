#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

void heapify(std::vector<int> &A, int n, int i){
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;

    if(l < n && A[l] > A[largest]) largest = l;
    if(r < n && A[r] > A[largest]) largest = r;


    if(largest != i){
        std::swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void buildMaxHeap(std::vector<int> &A){
    int n = static_cast<int>(A.size());
    for(int i = n/2 - 1 ; i >= 0 ; --i){
        heapify(A, n, i);
    }
}

void heapSort(std::vector<int> &A){
    int n = static_cast<int>(A.size());
    if (n<2) return;

    buildMaxHeap(A);

    for(int i = n-1 ; i>0 ; --i){
        std::swap(A[i], A[0]);
        heapify(A, i, 0);

    }
}

void resful(std::vector<int> &A, std::vector<std::pair<int, int>> &res){
    int max = INT_MAX;
    int n = static_cast<int>(A.size());

    for(int i = 0 ; i < n-1 ; i++) if ( std::abs(A[i] - A[i+1]) < max) max = abs(A[i] - A[i+1]);

    for(int i = 0 ; i < n-1 ; i++) if (std::abs(A[i] - A[i+1]) == max) res.push_back(std::make_pair(A[i], A[i+1]));
}


int main(){
    int n, x;
    std::vector<int> A;
    std::vector<std::pair<int, int>> res;
    cin >> n;
    for(int i = 0; i<n ; i++){
        cin >> x;
        A.push_back(x);
    }

    heapSort(A);

    // for(int n : A) cout << n << ' ';

    resful(A, res);

    for(auto n : res) cout << n.first << ' ' << n.second << ' ';

}