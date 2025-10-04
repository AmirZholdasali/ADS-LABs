#include <iostream>
#include <string>
using namespace std;

int main() {

    string str1;
    string str2;
    cin >> str1;
    cin >> str2;

    for (int i = 0; i < str1.size(); i++){
        if (str1[i] == '#'){
            str1.erase(i - 1, 2);
            i -= 2;
        }
    }

    for (int i = 0; i < str2.size(); i++){
        if (str2[i] == '#'){
            str2.erase(i - 1, 2);
            i -= 2;
        }
    }

    if (str1 == str2) cout << "Yes";
    else cout << "No";

    return 0;
}
