#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;

void comN(std::vector<int> A, std::vector<int> B, std::vector<int> &res){
    int nA = A.size();
    int nB = B.size();
    for(int i = 0; i < nA ; i++){
        for(int j = 0; j < nB ; j++){
            if (A[i] == B[j]){
                res.push_back(A[i]);
                B.erase(B.begin() + j);
                --nB;
                break;
            }
        }
    }
}

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
    if (n < 2) return;

    buildMaxHeap(A);

    for (int i = n-1 ; i > 0 ; --i){
        std::swap(A[i], A[0]);
        heapify(A, i, 0);
    }
}

int main(){
    int n, m, x;
    std::vector<int> nV;
    std::vector<int> mV;
    std::vector<int> res;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> x;
        nV.push_back(x);
    }
    for(int i = 0 ; i < m ; i++){
        cin >> x;
        mV.push_back(x);
    }

    heapSort(nV);
    heapSort(mV);

    if(nV.size() > mV.size()) comN(mV, nV, res);
    else comN(nV, mV, res);


    for(int n : res) cout << n << " ";


}