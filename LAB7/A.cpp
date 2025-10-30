#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void merge(std::vector<std::string>& A, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    
    std::vector<std::string> L(n1);
    std::vector<std::string> R(n2);

    for(int i = 0; i < n1 ; i++) L[i] = A[l + i];
    for(int i = 0; i < n2 ; i++) R[i] = A[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if (L[i].length() <= R[j].length()){
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

void mergeSort(std::vector<std::string>& A, int l, int r){
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(A, l, m);
    mergeSort(A, m+1, r);

    merge(A, l, m, r);
}

int main(){
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string line;
    while(n--){
        std::vector<std::string> A;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string word;
        while(iss >> word)
            A.push_back(word);

        mergeSort(A, 0, (int)A.size() - 1);
        for(std::string c : A) std::cout << c << ' ';
        std::cout << "\n";
    }

}