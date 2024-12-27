#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;

    int cnt = 0;
    for(int i = 0; i < (int)a.size(); i++){
        if(a[i] == '('){
            for(int j = i + 1; j < (int)a.size(); j++){
                if(a[j] == ')'){
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
    
    return 0;
}