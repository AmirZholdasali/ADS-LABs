#include <iostream>
#include <vector>
#include <algorithm>

void heapify(std::vector<char> &A, int n, int i){
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

void buildMaxHeap(std::vector<char> &A){
    int n = static_cast<int>(A.size());
    for(int i = n/2 - 1 ; i >= 0 ; --i){
        heapify(A, n, i);
    }
}

void heapSort(std::vector<char> &A){
    int n = static_cast<int>(A.size());
    if (n < 2) return;

    buildMaxHeap(A);

    for(int i = n-1 ; i > 0 ; --i){
        std::swap(A[i], A[0]);
        heapify(A, i, 0);
    }
}

int main(){
    char a, x;
    int n;
    std::cin >> n;
    std::vector<char> A;
    for(int i = 0; i < n ; i++){
        std::cin >> x;
        A.push_back(x);
    }

    std::cin >> a;

    heapSort(A);

    for(int i = 0 ; i < n ; i++){
        if (A[i] > a){
            std::cout << A[i];
            return 0;
        }
    }
    std::cout << A[0];

}