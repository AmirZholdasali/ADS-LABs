#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<int> qK, qS;
    
    int n;
    string str;
    char K = 'K', S = 'S';

    cin >> n;
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == K) {
            qK.push(i);
        }
        if(str[i] == S) {
            qS.push(i);
        }
    }

    while(!qK.empty() && !qS.empty()){
        int ik = qK.front();
        int is = qS.front();
        qK.pop();
        qS.pop();
        
        if(ik < is){
            qK.push(ik + n);
        }
        else{
            qS.push(is + n);
        }
    }

    if(qK.empty()){
        cout << "SAKAYANAGI" << endl;
    }
    else{
        cout << "KATSURAGI" << endl;
    }
    return 0;
}
