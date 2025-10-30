#include <iostream>
#include <vector>

void merge(std::vector<int> &A, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1 ; i++) L[i] = A[l + i];
    for (int j = 0; j < n2 ; j++) R[j] = A[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            ++i;
        }
        else{
            A[k] = R[j];
            ++j;
        }
        ++k;
    }

    while(i < n1){
        A[k] = L[i];
        ++i;
        ++k;
    }

    while(j < n2){
        A[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int> &A, int l, int r){
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(A, l, m);
    mergeSort(A, m+1, r);

    merge(A, l, m, r);
}

int main(){
    int n, m, x;
    std::cin >> n;
    std::vector<int> A;

    while(n--){
        std::cin >> x;
        A.push_back(x);
    }

    std::cin >> m;
    while(m--){
        std::cin >> x;
        A.push_back(x);
    }

    mergeSort(A, 0, (int)A.size()-1);

    for(int i : A) std::cout << i << ' ';
}