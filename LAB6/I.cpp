#include <iostream>
#include <string>
#include <algorithm>

void heapify(std::string &s, int n, int i){
    int largest = i;
    int l = i*2 + 1;
    int r = i*2 + 2;
    if(l < n && s[l] > s[largest]) largest = l;
    if(r < n && s[r] > s[largest]) largest = r;
    if(largest != i){
        std::swap(s[i], s[largest]);
        heapify(s, n, largest);
    }
}

void buildMaxHeap(std::string &s, int n){
    for(int i = n/2 - 1 ; i >= 0 ; --i) heapify(s, n, i);
}

void heapSort(std::string &s){
    int n = s.length();
    buildMaxHeap(s, n);
    for(int i = n-1 ; i>0 ; --i){
        std::swap(s[i], s[0]);
        heapify(s, i, 0);
    }
}

int main(){
    std::string s;
    std::cin >> s;
    heapSort(s);
    std::cout << s;
}