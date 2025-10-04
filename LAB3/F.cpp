#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, P, x;
    cin >> N;
    vector<int> comp(N);
    for(int i = 0; i<N; i++) {
        cin >> comp[i];
    }

    cin >> P;
    vector<int> rpow(P);
    for(int i = 0; i<P; i++) {
        cin >> rpow[i];
    }

    int sum;
    int cnt;
    for(int i = 0; i<P; i++) {
        sum = 0;
        cnt = 0;
        for(int j = 0; j<N; j++){
            if (rpow[i] >= comp[j]){
                cnt++;
                sum += comp[j];
            }
        }
        cout << cnt << " " << sum << endl;
    
    }
    return 0;
}
