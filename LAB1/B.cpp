#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int queue[N];

    for(int i = 0; i < N; i++){
        cin >> queue[i];
    }

    int res[N];

    for(int i = 0; i<N; i++){
        int min = -1;
        bool cont = false;
        for(int j = i-1; j>=0; j--){
            if (queue[j] <= queue[i]){
                min = queue[j];
                cont = true;
                break;
            }
        }
        res[i] = min;
    }

    for(int i = 0; i<N; i++){
        cout << res[i] << " ";
    }

    return 0;
}
