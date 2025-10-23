#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;

void heapify(std::vector<int> &A, int n, int i){
    int smallest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;

    if(l < n && A[l] < A[smallest]) smallest = l;
    if(r < n && A[r] < A[smallest]) smallest = r;

    if(i != smallest){
        std::swap(A[i], A[smallest]);
        heapify(A, n, smallest);
    }
}

void buildMaxHeap(std::vector<int> &A){
    int n = static_cast<int>(A.size());
    for(int i = n/2 - 1 ; i >= 0 ; --i){
        heapify(A, n, i);
    }
}

void reverseHeapSort(std::vector<int> &A){
    int n = static_cast<int>(A.size());
    if (n < 2) return;

    buildMaxHeap(A);

    for(int i = n - 1; i > 0 ; --i){
        std::swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main(){
    int n, m, x;
    cin >> n >> m;
    std::vector<std::vector<int>> A(n, std::vector<int>(m));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> x;
            A[i][j] = x;
        }
    }

    std::vector<std::vector<int>> B;

    // cout << " ---- " << endl;
    for(int k = 0; k < m ; k++){
        std::vector<int> col;
        for (int i = 0; i < n; i++) {
            col.push_back(A[i][k]);
        }
        reverseHeapSort(col);

        B.push_back(col);
    }

    for(int j = 0; j < n ; j++){
        for(int i = 0; i < m ; i++){
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }

}