#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m, t, x;
    int test[10005];
    map<int, pair<int, int>> mp;
    map<int, bool> ok;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) cin >> test[i];

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
            mp[x] = {i - 1, j - 1};
            ok[x] = true;
        }
    }
    
    for(int i = 1; i <= t; i++){
        if(ok[test[i]] == 1) cout << mp[test[i]].first << ' ' << mp[test[i]].second << endl;
        else cout << -1 << endl;
    }
    
    
    return 0;
}
