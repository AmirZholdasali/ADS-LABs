#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q1, q2;
    int el1, el2;
    
    for(int i = 0; i < 5; i++) {
        cin >> el1;
        q1.push(el1);
    }
    
    for(int j = 0; j < 5; j++) {
        cin >> el2;
        q2.push(el2);
    }
    int count = 0;
    
    while(count <= 1000000 && !q1.empty() && !q2.empty()){
        count++;
        
        int a = q1.front(), b = q2.front();
        q1.pop(); q2.pop();
        
        if((a == 0 && b == 9) || (a > b && (a != 9 || b != 0))){
            q1.push(a);
            q1.push(b);
        } 
        else {
            q2.push(a);
            q2.push(b);
        }
        
    }
    if(count >= 1000000) cout << "blin nichiya";
    else if(q1.empty()) cout << "Nursik" << ' ' << count;
    else cout << "Boris" << ' ' << count;
    return 0;
}
