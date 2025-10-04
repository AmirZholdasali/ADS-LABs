#include <iostream>
#include <string>
using namespace std;


int main(){
    string str;
    cin >> str;

    while(true){

        for(int i = 0; i < str.size(); i++){
            if (str[i] == str[i+1]){
                str.erase(i, 2);
                if(!str.empty())
                    i = -1;
                else{
                    cout << "YES";
                    return 0;
                }

            }
            if(i == str.size() - 1){
                cout << "NO";
                return 0;
            }
        }


    }

    return 0;
}
