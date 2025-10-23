#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

bool isVowel(char c){
    std::string vowel = "aeiou";
    if(vowel.find(c) != std::string::npos) return true;
    else return false;
}

void heapify(std::string &abc, int n, int i){
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if(l < n && abc[l] > abc[largest]) largest = l;
    if(r < n && abc[r] > abc[largest]) largest = r;

    if(largest != i){
        std::swap(abc[i], abc[largest]);
        heapify(abc, n, largest);
    }
}

void buildMaxHeap(std::string &abc){
    int n = abc.length();
    for(int i = n/2 - 1 ; i >= 0; --i){
        heapify(abc, n, i);
    }
}

void heapSort(std::string &abc){
    int n = abc.length();
    if (n < 2) return;

    buildMaxHeap(abc);

    for(int i = n-1 ; i > 0 ; --i){
        std::swap(abc[0], abc[i]);
        heapify(abc, i, 0);
    }
}

int main(){
    int n;
    std::string abc;
    std::string res1 = "";
    std::string res2 = "";
    cin >> n >> abc;

    for (char c : abc) if (isVowel(c)) res1 += c;
    for (char c : abc) if (!isVowel(c)) res2 += c;

    heapSort(res1);
    heapSort(res2);

    cout << res1 + res2;
}